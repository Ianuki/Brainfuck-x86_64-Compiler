/* 
    CLI app for the BR compiler
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Headers/compiler.h"

int main(int argc, char ** argv) {
    if (argc < 3) {
        printf("Missing arguments.\n");

        return 1;
    }
    
    FILE * file = fopen(argv[1], "rb");

    if (!file) {
        printf("Failed to open file.");

        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    
    char * source_code = (char *)malloc(size + 1);

    if (source_code == NULL) {
        printf("Malloc error.");
        fclose(file);

        return 1;
    }

    source_code[size] = (char)0;

    fread(source_code, 1, size, file);
    fclose(file);

    asm_builder builder = compile(source_code);
    printf("%s", builder.content);

    free(source_code);

    return 0;
}
