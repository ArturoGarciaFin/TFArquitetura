#include <stdio.h>
#include <stdint.h>

#define NBTB 512      	// Número estimado de entradas no BTB (pode ser ajustado)
#define LOOPS 1000000 	// Número de iterações para o microbenchmark

void test_btb(int distance) {

	volatile int counter = 0;
	volatile int branch_taken[NBTB] = {0};  // Array que simula as ramificações

	int i, j;

	for (i = 0; i < LOOPS; i++) {
    	for (j = 0; j < NBTB; j += distance) {
        	// Ramificação condicional que SEMPRE é tomada
        	if (branch_taken[j] == 0)
            	counter++;
    	}
	}

	printf("Teste completo para distância: %d\n", distance);
}

int main() {

	int distance;

	// Dobrando a distância a cada iteração para testar diferentes mapeamentos no BTB
	for (distance = 1; distance <= NBTB; distance *= 2)
    	test_btb(distance);

	printf("Teste do BTB concluído.\n");
	return 0;
}