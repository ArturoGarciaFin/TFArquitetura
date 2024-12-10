#include <stdio.h>
#include <stdint.h>

// Numero de iteracoes
#define LOOPS 10000000 
// Periodo do padrao para Branch A
#define PATTERN_LENGTH_A 2  
 // Periodo do padrao para Branch B
#define PATTERN_LENGTH_B 3  

int main() {
    volatile int a = 0;
    for (unsigned long i = 0; i < LOOPS; ++i) {
        // Branch A
        if ((i % PATTERN_LENGTH_A) != 0)
            a++;

        // Branch B
        if ((i % PATTERN_LENGTH_B) != 0)
            a++;

        // "Spy" branch de A e B
        if (((i % PATTERN_LENGTH_A) != 0) && ((i % PATTERN_LENGTH_B) != 0))
            a++;
    }
    return 0;
}