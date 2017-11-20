#include "FuncoesAuxiliares.h"

//PRINT DAS HORAS E DO DIA
void PrintDasHoras(int horas) {
	int dia = horas / 24;

	//Print do dia
	if (dia == 0) {
		printf("Segunda-feira, ");
	}
	else if (dia == 1) {
		printf("Terca-feira, ");
	}
	else if (dia == 2) {
		printf("Quarta-feira, ");
	}
	else if (dia == 3) {
		printf("Quinta-feira, ");
	}
	else if (dia == 4) {
		printf("Sexta-feira, ");
	}
	else if (dia == 5) {
		printf("Sabado, ");
	}
	else if (dia == 6) {
		printf("Domingo, ");
	}

	//Print da hora
	if (horas % 24 < 10) {
		printf("0%i:00\n\n", horas % 24);
	}
	else {
		printf("%i:00\n\n", horas % 24);
	}
}

//NUMERO RANDOMICO - Cria um numero randomico entre 1 e maximo
int NumeroRandomico(int maximo) {
	int numAleatorio;
	int divisor = RAND_MAX / maximo;		//int divisor = RAND_MAX/(limit+1). Nesse programa, limit+1 da errado.
											//Nao entendi porque no site falava que precisava do +1. Usando divisao por 5 funciona
	do {
		numAleatorio = (rand() % divisor) + 1;
	} while (numAleatorio > maximo);				// Colocar 5 no lugar do limit

	return numAleatorio;
}

//CASO ALEATORIO - Funcao que sorteia um caso e retorna o numero sorteado
int SorteioCaso(int dificuldade) {
	int caso, maximo = 1;
	char leitura[500], cmp[20];
	FILE *listaCasos;

	sprintf(cmp, "%i\n", maximo);

	//Switch para determinar qual arquivo sera lido
	switch (dificuldade) {
	case 1:
		listaCasos = fopen("CasosFaceis.txt", "r");
		break;
	case 2:
		listaCasos = fopen("CasosMedios.txt", "r");
		break;
	case 3:
		listaCasos = fopen("CasosDificieis.txt", "r");
		break;
	default:
		printf("ERRO! - Nao foi possivel abrir o arquivo para a funcao sorteio caso.\n");
		break;
	}
	//Determina o numero de casos existente no nivel de dificuldade do jogador
	while (!feof(listaCasos)) {
		fgets(leitura, sizeof(leitura), listaCasos);
		if (strcmp(leitura, cmp) == 0) {
			maximo++;
			sprintf(cmp, "%i\n", maximo);
		}
	}
	maximo--;
	//Caso so exista um unico caso na dificuldade escolhida
	if (maximo == 1) {
		caso = 1;
	}
	//Caso exista mais de um caso na dificuldade escolhida
	else {
		caso = NumeroRandomico(maximo);
	}

	return caso;
}

//RANKING TOP 5 - funcao que imprime o ranking na tela
void ranking() {
	FILE *arqAgentes = fopen("DadosDosAgentes.txt", "r");
	char nomeAgente[50], leitura[50];
	int pontos, qtde = 0, contador1 = 0, contador2 = 0, aux, colocacao[1000], jogador[1000];


	//loop para contar qtde de agentes no arquivo
	while (!feof(arqAgentes)) {
		fgets(leitura, sizeof(leitura), arqAgentes);
		fgets(leitura, sizeof(leitura), arqAgentes);
		fgets(leitura, sizeof(leitura), arqAgentes);
		qtde++;
	}
	qtde--;
	rewind(arqAgentes);
	printf("Qtde = %i\n", qtde);

	//loop para zerar colocacao
	for (contador1 = 0; contador1 < qtde; contador1++) {
		colocacao[contador1] = 0;
		jogador[contador1] = contador1 + 1;
	}
	contador1 = 0;

	//armazenar pontos nas matrizes
	while (!feof(arqAgentes)) {
		fgets(leitura, sizeof(leitura), arqAgentes);
		fgets(leitura, sizeof(leitura), arqAgentes);
		fscanf(arqAgentes, "%i", &pontos);
		colocacao[contador1] = pontos;
		fgets(leitura, sizeof(leitura), arqAgentes);
		contador1++;
	}
	rewind(arqAgentes);

	//bubble sort para colocacao[]
	for (contador1 = 0; contador1 < qtde - 1; contador1++) {
		for (contador2 = 0; contador2 < qtde - 1 - contador1; contador2++) {
			if (colocacao[contador2] < colocacao[contador2 + 1]) {
				aux = colocacao[contador2 + 1];
				colocacao[contador2 + 1] = colocacao[contador2];
				colocacao[contador2] = aux;
				aux = jogador[contador2 + 1];
				jogador[contador2 + 1] = jogador[contador2];
				jogador[contador2] = aux;
			}
		}
	}

	//imprime o ranking na tela
	contador1 = 0;
	system("cls");
	printf("         TOP 5\n");
	while (contador1 < 5) {
		for (contador2 = 0; contador2 < jogador[contador1]; contador2++) {
			fgets(nomeAgente, sizeof(nomeAgente), arqAgentes);
			strtok(nomeAgente, "\n");
			fgets(leitura, sizeof(leitura), arqAgentes);
			fgets(leitura, sizeof(leitura), arqAgentes);
		}
		rewind(arqAgentes);
		printf("%s", nomeAgente);
		for (contador2 = 0; contador2 < (20 - strlen(nomeAgente)); contador2++) {
			printf(" ");
		}
		printf("%ipts\n", colocacao[contador1]);
		contador1++;
	}
}