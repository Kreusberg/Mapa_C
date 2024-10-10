#include <stdio.h>
#include <locale.h>

int main() {
	int n, i, tempo, menorTempo;
	
	i = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	/*
		VARIAVEIS
		n = número de corredores
		i = provavelmente para um laço
		tempo = provavelmente para o tempo atual
		
	*/
	
	// printf("Digite o número de corredores: ");
	// scanf("%d", &n);
	
	// menorTempo = 10000000;
	
	// for (i; i < n; i++) {
	// 	printf("Digite o tempo do corredor nº %d: ", i + 1);
	// 	scanf("%d", &tempo);
		
	// 	if (tempo < menorTempo) {
	// 		menorTempo = tempo;
	// 	}
	// }
	
	// printf("\nO recorde da prova foi de %d segundos", menorTempo);
	
	return 0;

}
