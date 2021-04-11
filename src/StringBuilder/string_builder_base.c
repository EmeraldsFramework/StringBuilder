#include "headers/string_builder_base.h"

string *string_new(char *initial_string) {
    string *sb = (string*)calloc(1, sizeof(*sb));
    sb->list = linked_list_new();
    sb->length = 0;
    string_add(sb, initial_string);

    return sb;
}

void string_add(string *sb, const char *str) {
    linked_list_add(sb->list, (void*)str);
}

void string_addf(string *sb, const char *f, ...) {
    #define BIG_NUMBA 16384 /* TODO -> BOUNDS CHECKS */
    signed int result = 0;
    char buf[BIG_NUMBA];
    va_list args;

    va_start(args, f);
        result = vsnprintf(buf, sizeof(buf), f, args);
    va_end(args);

    if(result < 0) return;

    string_add(sb, buf);
}

char *string_get(string *sb) {
    char *buf = NULL;
    char *c = NULL;
    void *head = NULL;
    struct llnode **probe = NULL;

    buf = (char*)malloc(sizeof(char) * (sb->length + 1));
    if(buf == NULL) return NULL;

    c = buf;
    probe = (&sb->list->head);

    /* Dereference once */
    while(*probe) {
        void *item = (*probe)->item;
        size_t item_len = strlen((char*)item);
        memcpy(c, (char*)item, sizeof(char) * item_len);
        c += item_len;

        /* Traverse tothe next node */
        probe = (struct llnode**)&(*probe)->next;
    }

    *c = '\0';

    return buf;
}

void string_delete(string *sb) {
    linked_list_free(sb->list);
    sb->length = 0;
}

void string_free(string *sb) {
    string_delete(sb);
    free(sb);
}
