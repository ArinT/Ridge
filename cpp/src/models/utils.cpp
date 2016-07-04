#include <stdlib.h>

#include "utils.h"

int utils::randint(int min, int max) {
    return rand() % (max - min + 1) + min;
};
