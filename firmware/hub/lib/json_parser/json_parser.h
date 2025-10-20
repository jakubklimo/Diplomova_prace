/*----------- json_parser.h -----------*/

#pragma once

#include <map>
#include <WString.h>

std::map<String, String> parseJson(const String& input);
String createJson(const std::map<String, String>& data);