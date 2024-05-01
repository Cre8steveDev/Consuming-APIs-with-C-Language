#include "quotes.h"

/**
 * handle_single_quote - handles the request and returns the data string
 * Return - a String of the data retrieved and parsed
 */

char *handle_single_quote()
{
	CURL *curl;
	CURLcode response;
	char *sendOUtData;

	static string data_struct;
	data_struct.data = malloc(1);
	data_struct.len = 0;

	curl_global_init(CURL_GLOBAL_ALL);

	// Initializ curl on the variable
	curl = curl_easy_init();

	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.quotable.io/random");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data_struct);

		response = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		parse_result(data_struct.data);
		return data_struct.data;
	}

	printf("\n\nSorry, an error occured");
	system("clear");
	return NULL;
}