#include "response.h"
#include <vector>
#include <iostream>

using namespace std;

std::string toRawString(std::string const& in)
{
	std::string ret = in;
	while(true)
	{
		auto p = ret.find('\r');
		if ( p != ret.npos )
			ret.replace(p, 1, "\\r");
		else
			break;
	}

	return ret;
}


HTTPheader stringToHeader(string theHeaderString)
{
	std::cout << toRawString(theHeaderString) << "\n\n";
	vector<string> argVector;
	string currentParse = "";
	HTTPheader theHeader;
	for(auto it = theHeaderString.begin(); it != theHeaderString.end(); ++it)
	{
		if(*it == '\n')
		{
			argVector.push_back(currentParse);
			currentParse.clear();
			currentParse = "";
		}
		else
		{
			currentParse.push_back(*it);
		}
	}

	for(auto it = argVector.begin(); it != argVector.end(); ++it)
	{
		NeverUseAGoto:
		if(it == argVector.end())
			break;
		string current = *it;

		
        if(current == "\r" || current == "\n")
            continue;
		if(it == argVector.begin())
		{
			std::string x = "";
			for(auto strIt = current.begin(); strIt != current.end(); ++strIt)
			{
				if(*strIt == ' ')
				{
					x.push_back(*(strIt + 1));
					x.push_back(*(strIt + 2));
					x.push_back(*(strIt + 3));
					break;
				}
			}
			theHeader.insert(make_pair("STATUS_CODE", x));
		}
		else
		{
			auto strIt = current.begin();
			
			string key = "", value = "";

			while(*strIt != ' ')
			{
				if(strIt == current.end())
				{
					cerr << "Invalid http response (ignored): '" << toRawString(current) << "'\n\n";
					goto NeverUseAGoto;
				}
				if(*strIt != ':')
					key.push_back(*strIt);
				
				++strIt;
			}

			while(strIt != current.end())
			{
                if(*strIt != '\r')
                    value.push_back(*strIt);
				++strIt;
			}

			theHeader.insert(make_pair(key, value));
		}
	}

	return theHeader;
}


Response::Response(string header, string body)
{
	mBody = body;
	mHeader = stringToHeader(header);
}

Response::Response(const Response& copy)
{
	this->mBody = copy.mBody;
	this->mHeader = copy.mHeader;
}

Response::~Response()
{

}


string
Response::dump()
{
	std::string ans = "";
	for(auto it = mHeader.begin(); it != mHeader.end(); ++it)
	{
		ans += it->first + ": " + it->second + "\n";
	}

	ans += "\n\n";
	ans += mBody;
	return ans;
}


















