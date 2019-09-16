#include <iostream>
#include <curl/curl.h>

using namespace std;


int main(int argc, char const *argv[])
{
	CURL *curl = curl_easy_init();
	if(curl) {
	  CURLcode res;
	  curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
	  res = curl_easy_perform(curl);
	  curl_easy_cleanup(curl);
	}
	else
	{
		cout << "oof!";
	}
	return 0;
}