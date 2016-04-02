#include <stdio.h>

#include "obf.h"


//int main(int argc, char** argv) {
int main() {

    uint8_t src[4] = {0, 1, 2, 3};
    uint8_t dest[8];

    cypher(dest, 8, src, 4, 12345);

    printf("%d,%d,%d,%d,%d,%d,%d,%d\n", 
            dest[0], dest[1], dest[2], dest[3], dest[4], dest[5], dest[6], dest[7]);
    

    return 0;
}
