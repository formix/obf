#ifndef OBF_H
#define OBF_H

#include <stddef.h>
#include <stdint.h>


#define SRC_MAX_SIZE 4092


typedef enum {
    NO_ERROR,
    SRC_SIZE_TOO_LARGE,
    DEST_SIZE_TOO_SMALL
} error_t;


error_t cypher(
        uint8_t* dest, 
        size_t destsz, 
        uint8_t* src, 
        size_t srcsz, 
        int key);


/*
void decypher(uint8_t[] target, size_t targetSize, uint8_t[] source, size_t sourceSize);


char[] obfuscate(char[] str, size_t size);
char[] unobfuscate(char[] base64, size_t size);
*/

#endif


