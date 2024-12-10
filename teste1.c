# include <stdio.h>
# include <stdint.h>

# define NBTB 512
# define LOOPS 1000000

void test_btb (int distance) {
	volatile int counter = 0;
	
	// Simula as ramificacoes
	volatile int branch_taken[NBTB] = {0};
	int i, j;

	for (i = 0; i < LOOPS ; i ++) {
		for (j = 0; j < NBTB; j += distance ) {
			// Condicional que sempre eh tomada
			if ( branch_taken [ j ] == 0)
				counter ++;
		}
	}
	printf (" Teste completo para distancia: %d\n", distance ) ;
}

int main () {
	int distance;
	// Testa mapeamentos no BTB
	for (distance = 1; distance <= NBTB; distance *= 2)
	test_btb (distance) ;
	printf ("Teste do BTB concluido.\n") ;
	return 0;
}