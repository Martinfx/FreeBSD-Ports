# The cefclient sources (CEF 152) used by the editors, see cef_base.pri.
#
# Left out: cefclient_gtk.cc (the cefclient main()), the GTK print handler
# (printing is done by the application) and the client_app_delegates_common/
# renderer files, the editors have their own implementation of these.

SOURCES += \
    $$CEF_SRC_PATH/tests/shared/browser/client_app_browser.cc \
    $$CEF_SRC_PATH/tests/shared/browser/file_util.cc \
    $$CEF_SRC_PATH/tests/shared/browser/geometry_util.cc \
    $$CEF_SRC_PATH/tests/shared/browser/main_message_loop.cc \
    $$CEF_SRC_PATH/tests/shared/browser/main_message_loop_external_pump.cc \
    $$CEF_SRC_PATH/tests/shared/browser/main_message_loop_std.cc \
    $$CEF_SRC_PATH/tests/shared/common/binary_value_utils.cc \
    $$CEF_SRC_PATH/tests/shared/common/client_app.cc \
    $$CEF_SRC_PATH/tests/shared/common/client_app_other.cc \
    $$CEF_SRC_PATH/tests/shared/common/client_switches.cc \
    $$CEF_SRC_PATH/tests/shared/common/string_util.cc \
    $$CEF_SRC_PATH/tests/shared/renderer/client_app_renderer.cc \
    $$CEF_SRC_PATH/tests/shared/browser/main_message_loop_external_pump_linux.cc \
    $$CEF_SRC_PATH/tests/shared/browser/resource_util_posix.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/base_client_handler.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/binary_transfer_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/binding_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/browser_window.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/bytes_write_handler.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_app_delegates_browser.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_browser.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_handler.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_handler_osr.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_handler_std.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/client_prefs.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/component_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/config_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/default_client_handler.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/dialog_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/hang_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/image_cache.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/main_context.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/main_context_impl.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/media_router_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/osr_renderer.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/preferences_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/response_filter_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/root_window.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/root_window_create.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/root_window_manager.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/root_window_views.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/scheme_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/server_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/task_manager_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/test_runner.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/urlrequest_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/views_menu_bar.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/views_overlay_browser.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/views_overlay_controls.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/views_style.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/views_window.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/window_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/window_test_runner.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/window_test_runner_views.cc \
    $$CEF_SRC_PATH/tests/cefclient/common/scheme_test_common.cc \
    $$CEF_SRC_PATH/tests/cefclient/renderer/client_renderer.cc \
    $$CEF_SRC_PATH/tests/cefclient/renderer/ipc_performance_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/renderer/performance_test.cc \
    $$CEF_SRC_PATH/tests/cefclient/renderer/performance_test_tests.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/browser_window_osr_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/browser_window_std_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/dialog_handler_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/main_context_impl_posix.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/main_message_loop_multithreaded_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/resource_util_linux.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/root_window_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/temp_window_x11.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/util_gtk.cc \
    $$CEF_SRC_PATH/tests/cefclient/browser/window_test_runner_gtk.cc
