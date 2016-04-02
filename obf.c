#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "obf.h"


static int init_count = 0;


error_t cypher(
        uint8_t* dest,
        size_t destsz,
        uint8_t* src,
        size_t srcsz,
        int key) {

    if (srcsz > SRC_MAX_SIZE) {
        return SRC_SIZE_TOO_LARGE;
    }

    if (destsz < (srcsz + 4)) {
        return DEST_SIZE_TOO_SMALL;
    }

    // initializes random with a statically incremented value
    srand(time(NULL) + init_count);
    init_count++;

    // sets the 4 bytes of the random value in the first bytes of the target.
    int prefix = rand();
    memcpy(dest, &prefix, 4);

    srand(key);

    for (uint32_t i = 0; i < srcsz; i++) {
        uint8_t rnd = (uint8_t)rand();
        dest[i + 4] = dest[i] ^ src[i] ^ rnd;
    }

    return NO_ERROR;
}

