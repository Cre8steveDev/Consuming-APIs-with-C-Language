#ifndef QUOTES_H
#define QUOTES_H

/**
 * Standard Library Imports
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct
{
	char *data;
	size_t len;
} string;

/**
 * Installation of the libcurl library
 * sudo apt-get install libcurl4-gnutls-dev
 */
#include <curl/curl.h>

/**
 * HeaderFile for Write Function and others
 */
void print_fake_app_loading(void);
void print_initial_ui(void);
char *parse_result(char *result);
void print_with_max_line_length(const char *str, int max_line_length);

size_t write_callback(char *ptr, size_t size, size_t nmemb, void *data_struct);
void handle_single_quote();

#endif /**Quotes Header File*/