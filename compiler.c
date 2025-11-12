#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/asm_builder.h"
#include "Headers/compiler.h"

int find_redundancy(char * source, char character, int * index) {
    int result = 0;

    for (int i = *index; source[i] != '\0'; i++) {
        if (source[i] != character) break;

        result++;
        *index += 1;
    }

    *index -= 1;

    return result;
}

asm_builder compile(char * source) {
    asm_builder builder;
    asm_init(&builder);

    size_t current_loop = 0;
    size_t indentations = 0;

    for (int i = 0; source[i] != '\0'; i++) {
        char operator = source[i];

        switch (operator) {
            case '+':
                asm_append(&builder, GAS_INCREMENT_REGISTER, find_redundancy(source, '+', &i));
                
                break;
            case '-':
                asm_append(&builder, GAS_DECREMENT_REGISTER, find_redundancy(source, '-', &i));

                break;
            case '>':
                asm_append(&builder, GAS_INCREMENT_POINTER, find_redundancy(source, '>', &i));

                break;
            case '<':
                asm_append(&builder, GAS_DECREMENT_POINTER, find_redundancy(source, '<', &i));
                
                break;
            case '[':
                asm_append(&builder, GAS_OPEN_JEZ, current_loop);

                break;
            case ']':
                asm_append(&builder, GAS_COMP_JEZ, current_loop);
                current_loop++;

                break;
            case '.':
                asm_append(&builder, GAS_PUTB);

                break;
        }
    }

    return builder;
}