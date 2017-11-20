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
void ranking5() {
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

//RANKING GERAL
void rankingGeral(int menu) {
		FILE *arqAgentes = fopen("DadosDosAgentes.txt", "r");
		char nomeAgente[50], leitura[50], ordenar[50], nomes[1000][50];
		int pontos, nivel, qtde = 0, contador1 = 0, contador2 = 0, aux, colocacao[1000], jogador[1000], cmp = 3;

		//loop para contar qtde de agentes no arquivo
		while (!feof(arqAgentes)) {
			fgets(leitura, sizeof(leitura), arqAgentes);
			fgets(leitura, sizeof(leitura), arqAgentes);
			fgets(leitura, sizeof(leitura), arqAgentes);
			qtde++;
		}
		rewind(arqAgentes);

		switch (menu) {
		case 1:
			//por nome
			//loop while para leitura e armazenamento dos nomes no arquivo
			while (!feof(arqAgentes)) {
				fgets(nomeAgente, sizeof(nomeAgente), arqAgentes);
				strtok(nomeAgente, "\n");
				fgets(leitura, sizeof(leitura), arqAgentes);
				fgets(leitura, sizeof(leitura), arqAgentes);
				strcpy(nomes[contador1], nomeAgente);
				contador1++;
			}
			//ordenacao em ordem alfabetica
			for (contador1 = 1; contador1 < qtde; contador1++) {
				for (contador2 = 1; contador2 < qtde; contador2++) {
					if (strcmp(nomes[contador2 - 1], nomes[contador2]) > 0) {
						strcpy(ordenar, nomes[contador2 - 1]);
						strcpy(nomes[contador2 - 1], nomes[contador2]);
						strcpy(nomes[contador2], ordenar);
					}
				}
			}
			printf("         RANKING\n");
			for (contador1 = 0; contador1 < qtde; contador1++) {
				printf("%s\n", nomes[contador1]);

			}
			break;
		case 2:
			//por nivel
			printf("         RANKING\n");
			while (cmp > 0) {
				while (!feof(arqAgentes)) {
					fgets(nomeAgente, sizeof(nomeAgente), arqAgentes);
					fscanf(arqAgentes, "%i", &nivel);
					fgets(leitura, sizeof(leitura), arqAgentes);
					fgets(leitura, sizeof(leitura), arqAgentes);
					contador1--;
					if (nivel == cmp) {
						strtok(nomeAgente, "\n");
						printf("%s", nomeAgente);
						for (contador2 = 0; contador2 < (20 - strlen(nomeAgente)); contador2++) {
							printf(" ");
						}
						printf("%i\n", nivel);
					}

				}
				rewind(arqAgentes);
				cmp--;
			}
			break;
		case 3:
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
			printf("         RANKING\n");
			while (contador1 < qtde) {
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
			break;
		default:
			break;
		}

	}


//CIDADE ERRADA - Funcao para quando o usuario escolher uma idade errada
void CidadeErrada(char escolhida[], char anterior[]) {
	FILE *cidades = fopen("ListaDeCidades.txt", "r");
	char aleatorio1[50], aleatorio2[50], leitura[500], ogEscolha[50], ogAnterior[50];
	int menu, ordem, random, max = 0, erros = 1;

	strcpy(ogAnterior, anterior);
	strcpy(ogEscolha, escolhida);

	//Define a qtde de cidades registradas no arquivo
	while (!feof(cidades)) {
		fgets(leitura, sizeof(leitura), cidades);
		max++;
	}
	rewind(cidades);

	//Enquanto o jogador ainda estiver em uma cidade errada
	while (erros > 0) {

		printf("\nBem vindo a %s", escolhida);

		strcpy(aleatorio1, escolhida);
		strcpy(aleatorio2, escolhida);

		//Sorteio de duas cidades aleatorias
		while (strcmp(aleatorio2, aleatorio1) == 0 || strcmp(aleatorio1, anterior) == 0 || strcmp(aleatorio1, escolhida) == 0 || strcmp(aleatorio2, anterior) == 0 || strcmp(aleatorio2, escolhida) == 0) {
			//Sorteio da primeira cidade aleatoria
			random = rand() % max;
			for (int i = 0; i < random; i++) {
				fgets(leitura, sizeof(leitura), cidades);
			}
			strcpy(aleatorio1, leitura);
			rewind(cidades);

			//Sorteio da segunda cidade aleatoria
			random = rand() % max;
			for (int i = 0; i < random; i++) {
				fgets(leitura, sizeof(leitura), cidades);
			}
			strcpy(aleatorio2, leitura);
			rewind(cidades);
		}
		//Sorteio de ordem das cidades no menu
		ordem = rand() % 3;
		switch (ordem) {
		case 0:
			printf("1- %s2- %s3- %s", anterior, aleatorio1, aleatorio2);
			scanf("%i", &menu);
			//cidade certa escolhida
			if (menu == 1) {
				erros--;
				strcpy(leitura, anterior);
				strcpy(anterior, escolhida);
				strcpy(escolhida, leitura);
			}
			//Cidade errada escolhida
			else {
				erros++;
				if (menu == 2) {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio1);
				}
				else {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio2);
				}
			}
			break;
		case 1:
			printf("1- %s2- %s3- %s", aleatorio2, anterior, aleatorio1);
			scanf("%i", &menu);
			//Cidade certa
			if (menu == 2) {
				erros--;
				strcpy(leitura, anterior);
				strcpy(anterior, escolhida);
				strcpy(escolhida, leitura);
			}
			//Cidade errada
			else {
				erros++;
				if (menu == 1) {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio2);
				}
				else {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio1);
				}
			}

			break;
		case 2:
			printf("1- %s2- %s3- %s", aleatorio2, aleatorio1, anterior);
			scanf("%i", &menu);
			//Cidade certa
			if (menu == 3) {
				erros--;
				strcpy(leitura, anterior);
				strcpy(anterior, escolhida);
				strcpy(escolhida, leitura);
			}
			//Cidade errada
			else {
				erros++;
				if (menu == 1) {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio2);
				}
				else {
					strcpy(anterior, escolhida);
					strcpy(escolhida, aleatorio1);
				}
			}
			break;
		default:
			printf("Error...\n");
			break;
		}
		if (erros == 1) {
			strcpy(anterior, ogAnterior);
		}
	}
	//Por algum motivo, mesmo sendo uma funcao void sem retorno, os valores em departPlane eram alteraidos por essa funcao
	//Entao eu salvei os valores originais e depois eles sao salvos nas suas repectivas variaveis
	strcpy(anterior, ogAnterior);
	strcpy(escolhida, ogEscolha);
}