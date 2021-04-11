#include "../export/StringBuilder.h"
#include "../libs/Vector/export/Vector.h"

#include <stdio.h>

void print_strings(string *element) {
    printf("%s\n", string_get(element));
}

int main(void) {
    char *format_buf_p = NULL;
    string *str_to_split = NULL;
    string *delimeter_to_use = NULL;
    vector *list_of_tokens = NULL;
    string *one = NULL;
    string *two = NULL;
    string *three = NULL;
    string *format_buf = NULL;

    printf("TESTING STRING SPLIT\n");
    str_to_split = string_new("cut me in pieces");
	delimeter_to_use = string_new(" ");
    list_of_tokens = string_split(str_to_split, delimeter_to_use);
    string_free(delimeter_to_use);
	vector_map(list_of_tokens, (vector_lambda)print_strings);
    printf("ORIGINAL: %s\n", string_get(str_to_split));
    string_free(str_to_split);
    vector_free(list_of_tokens);
    printf("\n");

    printf("TESTING STRING EQUALITY\n");
    one = string_new("test");
    two = string_new("test");
    three = string_new("testss");
    if(string_equals(one, two))
        printf("strings `one(\"test\")` and `two(\"test\")` are equal\n\n");
    if(string_equals(one, three))
        printf("strings `one(\"test\")` and `three(\"testss\")` are equal\n\n");
    else
        printf("strings `one(\"test\")` and `three(\"testss\")` are NOT equal\n\n");
    string_free(one);
    string_free(two);
    string_free(three);

    printf("TESTING STRING ADD FORMAT\n");
    format_buf = string_new("");
    string_addf(format_buf, "%d plus %d is %d, %s, (%g - %g = %g)", 1, 1, 1+1, "This is nice", 5.3, 1.1, 5.3-1.1);
    printf("%s\n", (format_buf_p = string_get(format_buf)));

    free(format_buf_p);
}

