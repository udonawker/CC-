#include "text_converter.hpp"
#ifdef WIN32
#include <windows.h>
#include <vector>
#endif

std::string text_converter::utf8_to_sjis(const std::string& src_utf8)
{
#ifdef WIN32
	int length_unicode = ::MultiByteToWideChar(CP_UTF8, 0, src_utf8.c_str(), src_utf8.size() + 1, nullptr, 0);
	std::vector<wchar_t> buf_unicode(length_unicode);
	::MultiByteToWideChar(CP_UTF8, 0, src_utf8.c_str(), src_utf8.size() + 1, buf_unicode.data(), length_unicode);
	int length_sjis = ::WideCharToMultiByte(CP_THREAD_ACP, 0, buf_unicode.data(), -1, nullptr, 0, nullptr, nullptr);
	std::vector<char> buf_sjis(length_sjis);
	::WideCharToMultiByte(CP_THREAD_ACP, 0, buf_unicode.data(), length_unicode + 1, buf_sjis.data(), length_sjis, nullptr, nullptr);
	return std::move(std::string(buf_sjis.data()));
#else
	return std::move(std::string(src_utf8));
#endif
}
std::string text_converter::sjis_to_utf8(const std::string& src_sjis)
{
#ifdef WIN32
	int length_unicode = ::MultiByteToWideChar(CP_THREAD_ACP, 0, src_sjis.c_str(), src_sjis.size() + 1, nullptr, 0);
	std::vector<wchar_t> buf_unicode(length_unicode);
	::MultiByteToWideChar(CP_THREAD_ACP, 0, src_sjis.c_str(), src_sjis.size() + 1, buf_unicode.data(), length_unicode);
	int length_utf8 = ::WideCharToMultiByte(CP_UTF8, 0, buf_unicode.data(), -1, nullptr, 0, nullptr, nullptr);
	std::vector<char> buf_utf8(length_utf8);
	::WideCharToMultiByte(CP_UTF8, 0, buf_unicode.data(), length_unicode + 1, buf_utf8.data(), length_utf8, nullptr, nullptr);
	return std::move(std::string(buf_utf8.data()));
#else
	return std::move(std::string(src_sjis));
#endif
}
