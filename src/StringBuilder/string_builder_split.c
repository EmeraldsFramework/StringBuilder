#include "headers/string_builder_split.h"

vector *string_split(string *sb, string *delimeter) {
    size_t i;
    char *sb_p = NULL;
    char *token = NULL;
    char *delim_p = NULL;
    vector *str_tokens = vector_new();
    string *token_str = string_new("");

    /* Iterate through the chars constructing a string and
		reseting the value once we find the delimeter */
    sb_p = string_get(sb);
    token = strtok(sb_p, (delim_p = string_get(delimeter)));

    while(token != NULL) {
        vector_add(str_tokens, string_new(token));
        token = strtok(NULL, delim_p);
    }

    free(token);
    return str_tokens;
}
