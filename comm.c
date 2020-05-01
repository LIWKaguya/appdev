#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>
#include "comm.h"

// number of peaks
// maximum decibel value 
// put those in a php url and store there
void sendpost(char *url, char *post) // so here we is the function that we can send the information that we want to 
{									// send specific information toward an predetermined URL 
	CURL *curl; 
	CURLcode res; 

	curl_global_init(CURL_GLOBAL_ALL); 

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed:%s\n", 
			curl_easy_strerror(res));
		}
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup(); 
}
