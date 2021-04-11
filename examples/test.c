#include "../export/StringBuilder.h"

#include <stdio.h>

int main(void) {
    char *str = NULL;
    string *sb = string_new("");

    string_addf(sb, "%s, %s, %s, %d %g\n", "one", "two", "three", 4, 5.0);
    string_add(sb, "something more");
    str = string_get(sb);
    printf("%s\n", str);
    free(str);
}

