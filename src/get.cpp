#include "get.h"

#include <string>
#include <curl/curl.h>

using namespace std;

static size_t StringWriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

Response get(string theURL)
{
	/* init the curl session */ 
	CURL* curl_handle = curl_easy_init();

	/* set URL to get */ 
	curl_easy_setopt(curl_handle, CURLOPT_URL, theURL.c_str());

	/* no progress meter please */ 
	curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

	/* send all data to this function  */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, StringWriteCallback);

	
	std::string headerBuffer, bodyBuffer;
	
	/* we want the headers be written to this file handle */ 
	curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, &headerBuffer);

	/* we want the body be written to this file handle instead of stdout */ 
	curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &bodyBuffer);

	curl_easy_perform(curl_handle);

	curl_easy_cleanup(curl_handle);

	return Response(headerBuffer, bodyBuffer);
}