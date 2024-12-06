#include <stdio.h>

#define PATTERN_LENGTH 16 //Numero a ser mudado dependendo do codigo a ser testado
#define LOOPS 1000000 //Numero de loops

int main() {
	volatile int a = 0;
	for (unsigned long i = 0; i < LOOPS; ++i) {
    	if ((i % PATTERN_LENGTH) != 0)  // "Spy" branch com padrão
        	a++;
	}
	return 0;
}