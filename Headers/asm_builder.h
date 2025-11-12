#ifndef _ASM_BUILDER_
#define _ASM_BUILDER_

#include <stdlib.h>

typedef struct {
    char * content;
    size_t length;
    size_t cap;
} asm_builder;

#define INITIAL_CAP 8192 /* 1024 bytes */

void asm_init(asm_builder *);
void asm_append(asm_builder *, const char *, ...);
void asm_to_file(asm_builder *);
void asm_free(asm_builder *);

#endif