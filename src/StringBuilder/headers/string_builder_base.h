#ifndef __string_BASE_H_
#define __STRING_BUILDER_BASE_H_

#include <stdlib.h> /* malloc, calloc, free */
#include <string.h> /* memcpy, strlen */
#include <stdarg.h> /* va_args, va_start, va_end */
#include "../../../libs/Bool/export/Bool.h"
#include "../../../libs/LinkedList/export/LinkedList.h"

typedef struct _string {
	linked_list *list;
	size_t length;
} string;

string *string_new(char *initial_string);

void string_add(string *sb, const char *str);

void string_addf(string *sb, const char *f, ...);

char *string_get(string *sb);

void string_delete(string *sb);

void string_free(string *sb);

#endif
