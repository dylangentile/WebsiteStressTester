#pragma once
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, std::string> HTTPheader;


HTTPheader stringToHeader(std::string theHeaderString);

class Response
{
public:
	Response(std::string header, std::string body);
	Response(const Response& copy);
	~Response();

	std::string dump();

	HTTPheader mHeader;
	std::string mBody;

};