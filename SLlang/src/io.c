#include "include/io.h"
#include <stdlib.h>
#include <stdio.h>


char* get_file_contents(const char* filepath)
{
    FILE* f = fopen(filepath, "rb");

    if (f == NULL)
    {
        printf("Error reading file %s\n", filepath);
        exit(2);    
    }
    
    fseek(f, 0, SEEK_END);
    long length = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buffer = malloc(length + 1);
    if (buffer == NULL){
        fclose(f);
        return NULL;
    }
        
    fread(buffer, 1, length, f);
    buffer[length] = 0;
    fclose(f);
    return buffer;
    
}
