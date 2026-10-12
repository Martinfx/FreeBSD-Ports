#!/usr/bin/env python3
#
# Write build/config/gclient_args.gni the way gclient does when it syncs a
# checkout: every variable that DEPS lists in gclient_gn_args, with its value
# from the vars of DEPS.  A plain string there is a condition that gclient
# evaluates (Str() marks a literal string).  The Vivaldi source tarball comes
# without this file and nothing in it is run through gclient.
#
# usage: gclient_args.py DEPS gclient_args.gni [name=value ...]

import sys


class Str(str):
    pass


def Var(name):
    return '{%s}' % name


# What gclient defines for a checkout of a Linux desktop build on x64.
BUILTIN = {
    'checkout_android': False,
    'checkout_chromeos': False,
    'checkout_fuchsia': False,
    'checkout_ios': False,
    'checkout_linux': True,
    'checkout_mac': False,
    'checkout_win': False,
    'checkout_x64': True,
    'checkout_x86': False,
    'checkout_arm': False,
    'checkout_arm64': False,
    'host_os': 'linux',
    'host_cpu': 'x64',
    'target_os': 'linux',
    'target_cpu': 'x64',
}


class Scope(dict):
    def __init__(self, deps_vars, overrides):
        super().__init__()
        self.deps_vars = deps_vars
        self.overrides = overrides

    def __missing__(self, name):
        if name in self.overrides:
            return self.overrides[name]
        if name in BUILTIN:
            return BUILTIN[name]
        if name in self.deps_vars:
            return evaluate(self.deps_vars[name], self)
        # gclient fails here; an unknown checkout_* is simply not wanted
        return False


def evaluate(value, scope):
    if isinstance(value, Str) or not isinstance(value, str):
        return value
    return eval(value, {'__builtins__': {}}, scope)


def gn_value(value):
    if isinstance(value, bool):
        return 'true' if value else 'false'
    if isinstance(value, str):
        return '"%s"' % value.replace('\\', '\\\\').replace('"', '\\"')
    return str(value)


def main():
    deps_file, out_file = sys.argv[1], sys.argv[2]
    overrides = {}
    for arg in sys.argv[3:]:
        name, value = arg.split('=', 1)
        overrides[name] = {'true': True, 'false': False}.get(value, value)

    deps = {'Var': Var, 'Str': Str}
    with open(deps_file) as f:
        exec(f.read(), deps)
    scope = Scope(deps.get('vars', {}), overrides)

    names = list(deps.get('gclient_gn_args', []))
    names += [n for n in overrides if n not in names]
    with open(out_file, 'w') as f:
        f.write("# Generated from '%s'\n" % deps_file)
        for name in names:
            f.write('%s = %s\n' % (name, gn_value(scope[name])))


if __name__ == '__main__':
    main()
