/*----------- json_parser.cpp -----------*/

#include "json_parser.h"

std::map<String, String> parseJson(const String& input){
    std::map<String, String> result;

    String s = input;
    s.trim();

    if(s.startsWith("{") && s.endsWith("}")){
        s = s.substring(1, s.length() - 1);
    } else {
        return result;
    }

    int start = 0;
    while(start < s.length()){
        int colon = s.indexOf(':', start);
        if(colon == -1) break;

        String key = s.substring(start, colon);
        key.trim();
        key.replace("\"", "");

        int comma = s.indexOf(',', colon + 1);
        String value;
        if(comma == -1){
            value = s.substring(colon + 1);
            start = s.length();
        } else {
            value = s.substring(colon + 1, comma);
            start = comma + 1;
        }

        value.trim();
        value.replace("\"", "");

        result[key] = value;
    }

    return result;
}

String createJson(const std::map<String, String>& data){
    String json = "{";
    bool first = true;

    for (auto const& kv : data) {
        if (!first) {
            json += ", ";
        }
        json += "\"" + kv.first + "\": \"" + kv.second + "\"";
        first = false;
    }

    json += "}";
    return json;
}