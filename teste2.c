#include <stdio.h>

// Numero de iteracoes
#define LOOPS 10000000 
#define PATTERN_LENGTH 2

int main() {
    volatile int a = 0;
    for (unsigned long i = 0; i < LOOPS; ++i) {
        // "Spy" branch com padrao
        if ((i % PATTERN_LENGTH) != 0) 
            a++;
    }
    return 0;
}