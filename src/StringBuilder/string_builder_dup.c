#include "headers/string_builder_dup.h"

string *string_dup(string *sb) {
    string *dup = NULL;

    /* TODO -> CHECK NULLITY */
    if(sb == NULL) return NULL;
    dup = string_new(string_get(sb));

    return dup;
}
