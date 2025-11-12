#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "Headers/asm_builder.h"

void asm_init(asm_builder * builder) {
    builder->content = malloc(INITIAL_CAP);
    builder->length = 0;
    builder->cap = INITIAL_CAP;
}   

void asm_append(asm_builder * builder, const char * raw, ...) {
    va_list arg_list;
    va_start(arg_list, raw);

    while (1) {
        size_t available = builder->cap - builder->length;
        
        va_list arg_list_copy;
        va_copy(arg_list_copy, arg_list);

        int needed = vsnprintf(builder->content + builder->length, available, raw, arg_list_copy);
        if (needed < 0) break;

        if ((size_t)needed < available) {
            builder->length += needed;
            break;
        }

        builder->cap *= 2;
        builder->content = realloc(builder->content, builder->cap);
    }
}

void asm_write_to_file(asm_builder * builder, FILE * file) {
    fwrite(builder->content, 1, builder->length, file);
}

void asm_free(asm_builder * builder) {
    free(builder->content);
}