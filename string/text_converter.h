#ifndef TEXT_CONVERTER_HPP
#define TEXT_CONVERTER_HPP

#include <string>

class text_converter
{
public:
	text_converter() = delete;
	~text_converter() = delete;
	static std::string utf8_to_sjis(const std::string& src_utf8);
	static std::string sjis_to_utf8(const std::string& src_sjis);
};
#endif // TEXT_CONVERTER_HPP
