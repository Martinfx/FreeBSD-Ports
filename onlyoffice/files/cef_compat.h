/*
 * Compatibility with newer CEF releases (the FreeBSD port builds against
 * www/cef, which is much newer than the CEF 109 the sources are written for).
 *
 * - include/base/cef_basictypes.h is gone: provide its int64 & co. typedefs.
 * - Since CEF 122 frame identifiers are strings ("<child id>-<frame token>",
 *   the same in every process) instead of int64.  The sources keep passing
 *   frame ids around as int64 (in process messages and to JS), so the string
 *   is mapped to a stable number below 2^53 (exact as a JS number too), and
 *   frames are looked up by that number.
 */

#ifndef ASC_CEF_COMPAT_H
#define ASC_CEF_COMPAT_H

#include <cstdint>
#include <string>
#include <vector>

#include "include/cef_version.h"
#include "include/cef_browser.h"
#include "include/cef_frame.h"

// The sources are written for CEF 109.  The code paths for newer releases are
// marked with CEF_VERSION_ABOVE_128 (like CEF_VERSION_ABOVE_86/102).
#if CEF_VERSION_MAJOR >= 128 && !defined(CEF_VERSION_ABOVE_128)
#define CEF_VERSION_ABOVE_128
#endif

#ifdef CEF_VERSION_ABOVE_128

#if defined(__LP64__) && !defined(__APPLE__) && !defined(__OpenBSD__)
typedef long int64;
typedef unsigned long uint64;
#else
typedef long long int64;
typedef unsigned long long uint64;
#endif

#ifndef _INT32
#define _INT32
typedef int int32;
#endif
#ifndef _UINT32
#define _UINT32
typedef unsigned int uint32;
#endif
#ifndef _INT16
#define _INT16
typedef short int16;
#endif
#ifndef _UINT16
#define _UINT16
typedef unsigned short uint16;
#endif

#endif // CEF_VERSION_ABOVE_128

namespace NSCefCompat
{
#ifdef CEF_VERSION_ABOVE_128
	inline int64 FrameIdFromString(const CefString& id)
	{
		std::string s = id.ToString();
		if (s.empty())
			return -1;

		// FNV-1a
		uint64 h = 14695981039346656037ULL;
		for (std::string::const_iterator i = s.begin(); i != s.end(); ++i)
		{
			h ^= (unsigned char)(*i);
			h *= 1099511628211ULL;
		}
		return (int64)(h & 0x1FFFFFFFFFFFFFULL);
	}

	inline int64 GetFrameId(CefRefPtr<CefFrame> frame)
	{
		return frame ? FrameIdFromString(frame->GetIdentifier()) : -1;
	}

	inline void GetFrameIdentifiers(CefRefPtr<CefBrowser> browser, std::vector<int64>& ids)
	{
		std::vector<CefString> arIds;
		browser->GetFrameIdentifiers(arIds);
		for (std::vector<CefString>::const_iterator i = arIds.begin(); i != arIds.end(); ++i)
			ids.push_back(FrameIdFromString(*i));
	}

	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, int64 id)
	{
		std::vector<CefString> arIds;
		browser->GetFrameIdentifiers(arIds);
		for (std::vector<CefString>::const_iterator i = arIds.begin(); i != arIds.end(); ++i)
		{
			if (FrameIdFromString(*i) == id)
				return browser->GetFrameByIdentifier(*i);
		}
		return nullptr;
	}

	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, const CefString& name)
	{
		return browser->GetFrameByName(name);
	}
	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, const char* name)
	{
		return browser->GetFrameByName(name);
	}
	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, const std::string& name)
	{
		return browser->GetFrameByName(name);
	}
	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, const std::wstring& name)
	{
		return browser->GetFrameByName(name);
	}
#else
	inline int64 GetFrameId(CefRefPtr<CefFrame> frame)
	{
		return frame ? frame->GetIdentifier() : -1;
	}
	inline void GetFrameIdentifiers(CefRefPtr<CefBrowser> browser, std::vector<int64>& ids)
	{
		browser->GetFrameIdentifiers(ids);
	}
	template<typename T>
	inline CefRefPtr<CefFrame> GetFrame(CefRefPtr<CefBrowser> browser, const T& id)
	{
		return browser->GetFrame(id);
	}
#endif
}

#endif // ASC_CEF_COMPAT_H
