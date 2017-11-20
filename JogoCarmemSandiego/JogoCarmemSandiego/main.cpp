#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "FuncoesAdmin.h"
#include "LeituraDeArquivos.h"

//NIVEL DE DIFICULDADE - Enum para os Niveis de Dificuldade
typedef enum {
	iniciante,
	intermediario,
	avancado,
} nivelDificuldade;

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
	if (horas%24 < 10) {
		printf("0%i:00\n\n", horas%24);
	}
	else {
		printf("%i:00\n\n", horas%24);
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

//MENU INTERPOL - NAO TA FUNCIONANDO Funcao para Pesquisar Suspeitos no Database
void Interpol() {
	char leitura[30], opcaoYN, compativel[30];
	int menu, suspeitosRestantes = 0, rSexo, rHobby, rCabelo, rDestaque, rCarro;
	Vilao vilao, cmpDados;
	FILE *dadosSuspeitos = fopen("DadosDosSuspeitos.txt", "r");

	//Pergunta se o Usuario quer Procurar por um Suspeito
	printf("Deseja buscar o suspeito do caso? (Y/N)\n");
	getchar();
	scanf("%c", &opcaoYN);
	
	while (opcaoYN != 'y'&& opcaoYN != 'Y' && opcaoYN != 'n'&& opcaoYN != 'N') {
		printf("Opcao invalida\nDigite uma opcao valida (Y/N)\n");
		getchar();
		scanf("%c", &opcaoYN);
	}

	//Caso a Opcao seja SIM...
	if (opcaoYN == 'y' || opcaoYN == 'Y') {
		//O usuario digita as informacoes sobre o Suspeito
		//Sexo
		printf("Escolha o sexo:\n");
		printf("1- MASCULINO    2- FEMININO     3- DESCONHECIDO\n");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			strcpy(cmpDados.sexo, "Masculino\n");
			break;
		case 2:
			strcpy(cmpDados.sexo, "Feminino\n");
			break;
		case 3:
			strcpy(cmpDados.sexo, "desconhecido\n");
			break;
		default:
			break;
		}

		//Hobby
		printf("Escolha o hobby:\n");
		printf("1- MUSICA   2- VIAJAR  3- FILMES   4- DANCA    5- DESCONHECIDO\n");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			strcpy(cmpDados.hobby, "Musica\n");
			break;
		case 2:
			strcpy(cmpDados.hobby, "Viajar\n");
			break;
		case 3:
			strcpy(cmpDados.hobby, "Filmes\n");
			break;
		case 4:
			strcpy(cmpDados.hobby, "Danca\n");
			break;
		case 5:
			strcpy(cmpDados.hobby, "desconhecido\n");
			break;
		default:
			break;
		}

		//Cabelo
		printf("Escolha a cor do cabelo:\n");
		printf("1- PRETO    2- CASTANHO     3- LOIRO    4- RUIVO    5- DESCONHECIDO\n");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			strcpy(cmpDados.corCabelo, "Preto\n");
			break;
		case 2:
			strcpy(cmpDados.corCabelo, "Castanho\n");
			break;
		case 3:
			strcpy(cmpDados.corCabelo, "Loiro\n");
			break;
		case 4:
			strcpy(cmpDados.corCabelo, "Ruivo\n");
			break;
		case 5:
			strcpy(cmpDados.corCabelo, "desconhecido\n");
			break;
		default:
			break;
		}

		//Destaque
		printf("Escolha uma caracteristica de destaque:\n");
		printf("1- ANEL    2- JOIA     3- TATTOO    4- BENGALA     5-DESCONHECIDO \n");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			strcpy(cmpDados.destaque, "Anel\n");
			break;
		case 2:
			strcpy(cmpDados.destaque, "Joia\n");
			break;
		case 3:
			strcpy(cmpDados.destaque, "Tattoo\n");
			break;
		case 4:
			strcpy(cmpDados.destaque, "Bengala\n");
			break;
		case 5:
			strcpy(cmpDados.destaque, "desconhecido\n");
			break;
		default:
			break;
		}

		//Carro
		printf("Escolha um carro:\n");
		printf("1- CONVERSIVEL    2- JIPE     3- LIMOUSINE     4- ESPORTIVO     5- DESCONHECIDO\n");
		scanf("%i", &menu);
		switch (menu) {
		case 1:
			strcpy(cmpDados.carro, "Conversivel\n");
			break;
		case 2:
			strcpy(cmpDados.carro, "Jipe\n");
			break;
		case 3:
			strcpy(cmpDados.carro, "Limousine\n");
			break;
		case 4:
			strcpy(cmpDados.carro, "Esportivo\n");
			break;
		case 5:
			strcpy(cmpDados.carro, "desconhecido\n");
			break;
		default:
			break;
		}

		//Procura pelas Caracteristicas no Database
		while (!feof(dadosSuspeitos)) {
			fgets(vilao.nome, sizeof(vilao.nome), dadosSuspeitos);
			fgets(vilao.sexo, sizeof(vilao.sexo), dadosSuspeitos);
			fgets(vilao.hobby, sizeof(vilao.hobby), dadosSuspeitos);
			fgets(vilao.corCabelo, sizeof(vilao.corCabelo), dadosSuspeitos);
			fgets(vilao.destaque, sizeof(vilao.destaque), dadosSuspeitos);
			fgets(vilao.carro, sizeof(vilao.carro), dadosSuspeitos);

			//Compara Sexo
			if (strcmp(vilao.sexo, cmpDados.sexo) == 0) {
				rSexo = 1;
			}
			else {
				if (strcmp(cmpDados.sexo, "desconhecido\n") == 0) {
					rSexo = 2;
				}
				else {
					rSexo = 0;
				}
			}

			//Compara Hobby
			if (strcmp(vilao.hobby, cmpDados.hobby) == 0) {
				rHobby = 1;
			}
			else {
				if (strcmp(cmpDados.hobby, "desconhecido\n") == 0) {
					rHobby = 2;
				}
				else {
					rHobby = 0;
				}
			}

			//Compara Cabelo
			if (strcmp(vilao.corCabelo, cmpDados.corCabelo) == 0) {
				rCabelo = 1;
			}
			else {
				if (strcmp(cmpDados.corCabelo, "desconhecido\n") == 0) {
					rCabelo = 2;
				}
				else {
					rCabelo = 0;
				}
			}

			//Compara Destaque
			if (strcmp(vilao.destaque, cmpDados.destaque) == 0) {
				rDestaque = 1;
			}
			else {
				if (strcmp(cmpDados.destaque, "desconhecido\n") == 0) {
					rDestaque = 2;
				}
				else {
					rDestaque = 0;
				}
			}

			//Compara Carro
			if (strcmp(vilao.carro, cmpDados.carro) == 0) {
				rCarro = 1;
			}
			else {
				if (strcmp(cmpDados.carro, "desconhecido\n") == 0) {
					rCarro = 2;
				}
				else {
					rCarro = 0;
				}
			}

			//Caso um Vilao do Arquivo seja compativel com os dados lidos, o programa imprime seu Nome na tela
			if (rSexo != 0 && rHobby != 0 && rCabelo != 0 && rDestaque != 0 && rCarro != 0) {
				strcpy(compativel, vilao.nome);
				printf("%s", compativel);
				suspeitosRestantes++;
			}
			fgets(leitura, sizeof(leitura), dadosSuspeitos); //IMPORTANT - pula o \n que separa os viloes no arquivo
		}
		//Caso so exista um suspeito restante, o programa imprime na tela, notificando o jogador de que ele pode prender o suspeito
		if (suspeitosRestantes == 1) {
			printf("Voce tem permissao para prender %s\n\n", compativel);
		}
		if (suspeitosRestantes == 0) {
			printf("Nao foi encontrado nenhum suspeito com essas caracteristicas\n\n");
		}
	}

	//opcao N: caso o usuario nao queira pesquisar por um suspeito no programa principal, ele volta ao menu anterior, sem perder tempo
	else {
		printf("Voltando para o menu...\n");
	}
}



//IDENTIFICAÇÃO DO JOGADOR - Funcao para identificar o nome lido no arquivo e, no caso de um novo agente, cadastra-lo no mesmo
Jogador IdentificarAgente(char nomeAgente[]) {
	FILE *agentes, *admin;
	int id = 0, nivel, sucesso;
	char leitura[30], opcaoYN;
	char pulaLinha[5];
	nivelDificuldade nivelAgente;
	Jogador jogador;

	agentes = fopen("DadosDosAgentes.txt", "r");

	//Busca o nome do agente no arquivo. Caso seja encontrado, o loop para, se nao, ao final do loop o novo nome sera cadastrado
	while (!feof(agentes) && id == 0) {
		fgets(leitura, sizeof(leitura), agentes);
		strtok(leitura, "\n");
		//Caso o nome lido seja encontrado, a variavel id indica que o nome foi encontrado
		if (strcmp(leitura, nomeAgente) == 0) {
			id = 1;
		}
		//Caso nao encontre, o programa pula as 2 proximas linhas, que possui o nivel do jogador antes de recomecar o loop.
		else {
			fgets(pulaLinha, sizeof(pulaLinha), agentes);
			fgets(pulaLinha, sizeof(pulaLinha), agentes);
		}
	}

	//Agente ja existente
	if (id == 1) {
		printf("Agente identificado.\nBem-vindo, agente %s\n", nomeAgente);
		strcpy(jogador.nome, nomeAgente);
		fscanf(agentes, "%i", &jogador.patente);
		fscanf(agentes, "%i", &jogador.pontos);
		return jogador;

	}
	//Cadastro de novo agente, caso ele deseje
	if (id == 0) {
		getchar();
		printf("Nao achamos o seu nome na lista\nGostaria de registra-lo?(Y/N)\n");
		scanf("%c", &opcaoYN);
		if (opcaoYN == 'y' || opcaoYN == 'Y') {
			fclose(agentes);
			agentes = fopen("DadosDosAgentes.txt", "a");
			fprintf(agentes, "%s\n1\n0\n", nomeAgente);
			fflush(agentes);
			printf("O seu nome foi salvo\nBem-vindo a agencia, %s!\n", nomeAgente);
			nivelAgente = iniciante;
		}
		else {
			if (opcaoYN == 'n' || opcaoYN == 'N') {
				jogador.patente = 4;
				return jogador;
			}
			else {
				jogador.patente = 5;
				return jogador;
			}
		}
	}
	jogador.patente = nivelAgente;
	return jogador;
}

//CIDADE ERRADA - Funcao para quando o usuario escolher uma idade errada
void CidadeErrada(char escolhida[], char anterior[]) {
	FILE *cidades = fopen("cidades.txt", "r");
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

//FUNCAO DE VIAJAR DO JOGO - Nao ta funcionando
void DepartPlane(int dificuldade, int caso) {
	//Declaracao variaveis
	FILE *arquivoCaso, *arquivoCidades = fopen("cidades.txt", "r");
	char anterior[50], atual[50], destino[50];
	char aleatorio1[50], aleatorio2[50], leitura[500];
	int lerNivel, ordem, menu, cidadeAleatoria, max = 0, booleanCidade = 0, restantes;
	srand(time(NULL));

	//Define a qtde de cidades no registradas no arquivo
	while (!feof(arquivoCidades)) {
		fgets(leitura, sizeof(leitura), arquivoCidades);
		max++;
	}
	rewind(arquivoCidades);

	//Switch para ver qual arquivo de caso sera lido
	switch (dificuldade) {
	//Nivel Facil
	case 1:
		arquivoCaso = fopen("CasosFaceis.txt", "r");
		restantes = 1;
		fscanf(arquivoCaso, "%i", &lerNivel);
		if (lerNivel != caso) {
			while (!feof(arquivoCaso) && lerNivel != caso) {
				for (int i = 0; i < 13; i++) {
					fgets(leitura, sizeof(leitura), arquivoCaso);
				}
				fscanf(arquivoCaso, "%i", &lerNivel);
			}
		}
		break;
	//Nivel Medio
	case 2:
		arquivoCaso = fopen("CasosMedios.txt", "r");
		restantes = 3;
		fscanf(arquivoCaso, "%i", &lerNivel);
		if (lerNivel != caso) {
			while (!feof(arquivoCaso) && lerNivel != caso) {
				for (int i = 0; i < 21; i++) {
					fgets(leitura, sizeof(leitura), arquivoCaso);
				}
				fscanf(arquivoCaso, "%i", &lerNivel);
			}
		}
		break;
	//Nivel Dificil
	case 3:
		arquivoCaso = fopen("CasosDificieis.txt", "r");
		restantes = 5;
		fscanf(arquivoCaso, "%i", &lerNivel);
		if (lerNivel != caso) {
			while (!feof(arquivoCaso) && lerNivel != caso) {
				for (int i = 0; i < 29; i++) {
					fgets(leitura, sizeof(leitura), arquivoCaso);
				}
				fscanf(arquivoCaso, "%i", &lerNivel);
			}
		}
		break;
	default:
		restantes = 0;
		printf("Error switch dificuldade\n");
		break;
	}


	//Pula as 3 primeiras linhas do arquivo para ler a primeira cidade
	fgets(leitura, sizeof(leitura), arquivoCaso);
	fgets(leitura, sizeof(leitura), arquivoCaso);
	fgets(leitura, sizeof(leitura), arquivoCaso);

	//Leitura da primeira ciadade
	fgets(atual, sizeof(atual), arquivoCaso);

	//Pula as primeiras quatro dicas
	fgets(leitura, sizeof(leitura), arquivoCaso);
	fgets(leitura, sizeof(leitura), arquivoCaso);
	fgets(leitura, sizeof(leitura), arquivoCaso);
	fgets(leitura, sizeof(leitura), arquivoCaso);

	//Leitura do proximo destino correto
	fgets(destino, sizeof(destino), arquivoCaso);

	strcpy(aleatorio1, destino);
	strcpy(aleatorio2, destino);

	//Sorteio de duas cidades aleatorias
	while (strcmp(aleatorio2, aleatorio1) == 0 || strcmp(aleatorio1, atual) == 0 || strcmp(aleatorio1, destino) == 0 || strcmp(aleatorio2, atual) == 0 || strcmp(aleatorio2, destino) == 0) {
		//sorteio da primeira cidade aleatoria
		cidadeAleatoria = rand() % max;
		for (int i = 0; i < cidadeAleatoria; i++) {
			fgets(leitura, sizeof(leitura), arquivoCidades);
		}
		strcpy(aleatorio1, leitura);
		rewind(arquivoCidades);

		//Sorteio da segunda cidade aleatoria
		cidadeAleatoria = rand() % max;
		for (int i = 0; i < cidadeAleatoria; i++) {
			fgets(leitura, sizeof(leitura), arquivoCidades);
		}
		strcpy(aleatorio2, leitura);
		rewind(arquivoCidades);
	}


	//Sorteio de ordem de cidades impressas na tela
	ordem = rand() % 3;

	//Enquanto o usuario nao escolhe a primeira cidade correta
	while (booleanCidade != 1) {
		printf("\nBem vindo a %s", atual);
		switch (ordem) {
		case 0:
			printf("\n1- %s2- %s3- %s\n", destino, aleatorio1, aleatorio2);
			scanf("%i", &menu);
			if (menu == 1) {
				booleanCidade = 1;
			}
			else {
				if (menu == 2) {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio1, atual);
					printf("Atual reccebida = %s", atual);
				}
				else {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio2, atual);
					printf("Atual reccebida = %s", atual);
				}
			}
			break;
		case 1:
			printf("\n1- %s2- %s3- %s\n", aleatorio1, destino, aleatorio2);
			scanf("%i", &menu);
			if (menu == 2) {
				booleanCidade = 1;
			}
			else {
				if (menu == 1) {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio1, atual);
					printf("Atual reccebida = %s", atual);
				}
				else {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio2, atual);
					printf("Atual reccebida = %s", atual);
				}
			}
			break;
		case 2:
			printf("\n1- %s2- %s3- %s\n", aleatorio1, aleatorio2, destino);
			scanf("%i", &menu);
			if (menu == 3) {
				booleanCidade = 1;
			}
			else {
				if (menu == 1) {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio1, atual);
					printf("Atual reccebida = %s", atual);
				}
				else {
					printf("Atual enviada = %s", atual);
					CidadeErrada(aleatorio2, atual);
					printf("Atual reccebida = %s", atual);
				}
			}
			break;
		default:
			printf("ordem error...\n");
			break;
		}
	}

	//|=======================================================================================|
	//|================================= FIM PRIMEIRA CIDADE =================================|
	//|=======================================================================================|

	strcpy(anterior, atual);
	strcpy(atual, destino);

	printf("\nVoce achou um membro da VILE! Voce deve estar no caminho certo!\n\n");

	//Enqunato houver cidades restantes no caso
	while (restantes > 0) {
		//Pula as 3 dicas no arquivo caso
		fgets(leitura, sizeof(leitura), arquivoCaso);
		fgets(leitura, sizeof(leitura), arquivoCaso);
		fgets(leitura, sizeof(leitura), arquivoCaso);
		//Le o proximo destino correto
		fgets(destino, sizeof(destino), arquivoCaso);

		strcpy(aleatorio1, destino);
		strcpy(aleatorio2, destino);

		booleanCidade = 0;

		//Sorteio de duas cidades aleatorias
		while (strcmp(aleatorio2, aleatorio1) == 0 || strcmp(aleatorio1, atual) == 0 || strcmp(aleatorio1, destino) == 0 || strcmp(aleatorio2, atual) == 0 || strcmp(aleatorio2, destino) == 0) {
			//Sorteio da primeira cidade aleatoria
			cidadeAleatoria = rand() % max;
			for (int i = 0; i < cidadeAleatoria; i++) {
				fgets(leitura, sizeof(leitura), arquivoCidades);
			}
			strcpy(aleatorio1, leitura);
			rewind(arquivoCidades);

			//Sorteio da segunda cidade aleatoria
			cidadeAleatoria = rand() % max;
			for (int i = 0; i < cidadeAleatoria; i++) {
				fgets(leitura, sizeof(leitura), arquivoCidades);
			}
			strcpy(aleatorio2, leitura);
			rewind(arquivoCidades);
		}
		//Sorteio da ordem das cidades
		ordem = rand() % 4;

		//Enquanto o usuario nao escolher uma cidade certa
		while (booleanCidade != 1) {
			printf("\nBem vindo a %s", atual);
			switch (ordem) {
			case 0:
				printf("1- %s2- %s3- %s4- %s", destino, anterior, aleatorio1, aleatorio2);
				scanf("%i", &menu);
				//switch para opcao que o usuario escolher
				switch (menu) {
				case 1:
					booleanCidade = 1;
					break;
				case 2:
					CidadeErrada(anterior, atual);
					break;
				case 3:
					CidadeErrada(aleatorio1, atual);
					break;
				case 4:
					CidadeErrada(aleatorio2, atual);
					break;
				default:
					break;
				}
				break;
			case 1:
				printf("1- %s2- %s3- %s4- %s", aleatorio1, destino, aleatorio2, anterior);
				scanf("%i", &menu);
				switch (menu) {
				case 1:
					CidadeErrada(aleatorio1, atual);
					break;
				case 2:
					booleanCidade = 1;
					break;
				case 3:
					CidadeErrada(aleatorio2, atual);
					break;
				case 4:
					CidadeErrada(anterior, atual);
					break;
				default:
					break;
				}
				break;
			case 2:
				printf("1- %s2- %s3- %s4- %s", anterior, aleatorio1, aleatorio2, destino);
				scanf("%i", &menu);
				switch (menu) {
				case 1:
					CidadeErrada(anterior, atual);
					break;
				case 2:
					CidadeErrada(aleatorio1, atual);
					break;
				case 3:
					CidadeErrada(aleatorio2, atual);
					break;
				case 4:
					booleanCidade = 1;
					break;
				default:
					break;
				}
				break;
			case 3:
				printf("1- %s2- %s3- %s4- %s", aleatorio1, anterior, destino, aleatorio2);
				scanf("%i", &menu);
				switch (menu) {
				case 1:
					CidadeErrada(aleatorio1, atual);
					break;
				case 2:
					CidadeErrada(anterior, atual);
					break;
				case 3:
					booleanCidade = 1;
					break;
				case 4:
					CidadeErrada(aleatorio2, atual);
					break;
				default:
					break;
				}
				break;
			default:
				printf("ordem error");
				break;
			}
		}
		restantes--;
		if (restantes > 0) {
			printf("\nVoce achou um membro da VILE! Voce deve estar no caminho certo!\n\n");
		}
	}
}

//FUNCAO PARA INVESTIGAR NA CIDADE
int InvestigarCidade(char dica1[], char dica2[], char dica3[], char dica4[], int cidade, int horas, Botoes botoes) {
	char botaoApertado = '^';
	int aleatorio;

	if (cidade == 0) {
		while (botaoApertado != botoes.botao0) {
			//Lembrar do dia da semana aqui
			PrintDasHoras(horas);

			printf("Escolha um local para investigar:\n\n");
			printf("%c - Prefeitura   %c - Aeroporto   %c - Lojinha  %c - Ruas   %c - Voltar\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao4, botoes.botao0);
			scanf("%c", &botaoApertado);
			getchar();

			if (botaoApertado == botoes.botao1) {
				system("cls");
				printf("%s\n", dica1);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao2) {
				system("cls");
				printf("%s\n", dica2);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao3) {
				system("cls");
				printf("%s\n", dica3);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao4) {
				system("cls");
				printf("%s\n", dica4);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao0) {
				system("cls");
				return horas;
			}
		}
	}

	else if (cidade == 10) {
		
		//Cria um valor aleatorio entre 1 e 3
		aleatorio = NumeroRandomico(3);
		
		switch (aleatorio) {
		case 1:
			//Opcoes
			while (botaoApertado != botoes.botao0) {
				PrintDasHoras(horas);

				printf("Escolha um local para investigar:\n\n");
				printf("%c - Prefeitura   %c - Aeroporto   %c - Ruas   %c - Voltar\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao0);
				scanf("%c", &botaoApertado);
				getchar();

				if (botaoApertado == botoes.botao1) {
					system("cls");
					printf("%s\n", dica1);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao2) {
					system("cls");
					printf("%s\n", dica2);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao3) {
					system("cls");
					printf("%s\n", dica3);
					horas = horas + 1000;
					return horas;
					printf("%s\n", dica3);
					
				}
				else if (botaoApertado == botoes.botao0) {
					system("cls");
					return horas;
				}
			}
			break;
		case 2:
			//Opcoes
			while (botaoApertado != botoes.botao0) {
				PrintDasHoras(horas);

				printf("Escolha um local para investigar:\n\n");
				printf("%c - Prefeitura   %c - Aeroporto   %c - Ruas   %c - Voltar\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao0);
				scanf("%c", &botaoApertado);
				getchar();

				if (botaoApertado == botoes.botao1) {
					system("cls");
					printf("%s\n", dica3);
					horas = horas + 1000;
					return horas;
				}
				else if (botaoApertado == botoes.botao2) {
					system("cls");
					printf("%s\n", dica2);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao3) {
					system("cls");
					printf("%s\n", dica1);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao0) {
					system("cls");
					return horas;
				}
			}
			break;
		case 3:
			//Opcoes
			while (botaoApertado != botoes.botao0) {
				PrintDasHoras(horas);

				printf("Escolha um local para investigar:\n\n");
				printf("%c - Prefeitura   %c - Aeroporto   %c - Ruas   %c - Voltar\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao0);
				scanf("%c", &botaoApertado);
				getchar();

				if (botaoApertado == botoes.botao1) {
					system("cls");
					printf("%s\n", dica1);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao2) {
					
					system("cls");
					printf("%s\n", dica3);
					horas = horas + 1000;
					return horas;
				}
				else if (botaoApertado == botoes.botao3) {
					system("cls");
					printf("%s\n", dica2);
					horas = horas + 4;
				}
				else if (botaoApertado == botoes.botao0) {
					system("cls");
					return horas;
				}
			}
			break;
		}
	}
	
	else {
		while (botaoApertado != botoes.botao0) {
			PrintDasHoras(horas);

			printf("Escolha um local para investigar:\n\n");
			printf("%c - Prefeitura   %c - Aeroporto   %c - Ruas   %c - Voltar\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao0);
			scanf("%c", &botaoApertado);
			getchar();

			if (botaoApertado == botoes.botao1) {
				system("cls");
				printf("%s\n", dica1);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao2) {
				system("cls");
				printf("%s\n", dica2);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao3) {
				system("cls");
				printf("%s\n", dica3);
				horas = horas + 4;
			}
			else if (botaoApertado == botoes.botao0) {
				system("cls");
				return horas;
			}
		}
	}
}

//MENU PARA CASO FACIL
void MenuJogoFacil(CasoFacil caso, Botoes botoes){
	int menu, horas = 8, fimJogo = 0, cidadeAtual = 0;
	char diaSemana[30], cidade[50];
	char dica1[120], dica2[120], dica3[120];


	//Imrprime mensagem inicial do caso
	printf("\n*********** NEWS FLASH ***********\n");
	printf("O tesouro %s foi roubado na cidade de %s. Um suspeito %s foi encontrado no local!\n", caso.tesouro, caso.cidade[0].nome, caso.vilaoDoCaso.sexo);
	printf("Agente, voce deve localizar o suspeito e prende-lo antes que ele escape!\n");
	printf("Voce tem ate as 20:00 do Domingo para prende-lo. Boa sorte!\n\n");
	system("pause");
	system("cls");

	while (fimJogo == 0) {
		PrintDasHoras(horas);

		printf("Bem vindo a %s\n%s\n", caso.cidade[0].nome,caso.cidade[0].breveDescricao);
		printf("O que voce deseja fazer, agente?\n\n");
		printf("1- Viajar   2- Investigar   3- Interpol\n");
		scanf("%i", &menu);
		getchar();
		switch (menu) {
		case 1:
			//VIAJAR
			//DepartPlane(1, 1); 
			//Tem arrumar isso. Pra caso facil a gente sabe que vai ser sempre nivel 1, mas nao sabemos que caso vai ser, porque eu to usando struct nesse menu.
			//Tem que dar return de em qual cidade o jogador esta
			//ciadeAtual = Departplane();
			cidadeAtual = cidadeAtual + 1;
			break;
		case 2:
			//INVESTIGAR
			if (cidadeAtual == 0) {
				system("cls");
				horas = InvestigarCidade(caso.dica[0], caso.dica[1], caso.dica[2], caso.dica[3], cidadeAtual, horas, botoes);
			}
			else if(cidadeAtual == 1) {
				system("cls");
				horas = InvestigarCidade(caso.dica[4], caso.dica[5], caso.dica[6], "Nada", cidadeAtual, horas, botoes);
			}
			else {
				system("cls");
				strcpy(dica1, "Aqui esta muito perigoso! Se eu fosse voce, saia da cidade.\n");
				strcpy(dica2, "Parece que o ladrao esta muito proximo. Continue procurando.\n");
				strcpy(dica3, "Suspeito encontrado!\n");
				cidadeAtual = 10;
				horas = InvestigarCidade(dica1, dica2, dica3, "Nada", cidadeAtual, horas, botoes);

				if (horas > 1000) {
					fimJogo = 1;
				}
			}
			break;
		case 3:
			//INTERPOL
			Interpol();
			//Colocar pra retornar se pode ou nao prender o caso.vilaoDoCaso?
			break;
		default:
			break;
		}
	}

	printf("Parabens detetive! Voce prendeu o suspeito!\n\n");
}


//MAIN
int main() {
	char agente[20], botaoApertado;
	int nivelAgente, numeroCaso;
	bool saidaWhile = false;
	CasoFacil casoF;
	CasoMedio casoM;
	CasoDificil casoD;
	Jogador jogador;
	Botoes botoes; //Botoes comecam como padrao 0, 1, 2, 3 e 4
	botoes.botao0 = '0';
	botoes.botao1 = '1';
	botoes.botao2 = '2';
	botoes.botao3 = '3';
	botoes.botao4 = '4';
	srand(time(NULL));

	//Introduçao
	printf("Em que lugar da Terra esta Carmem Sandiego?\n\n");
	printf("| RodTomLeoGames |\n\n");
	system("pause");
	system("cls");

	//Menu antes do jogo
	while (saidaWhile == false) {	
		printf("%c - Comecar o Jogo\n", botoes.botao1);
		printf("%c - Ranking dos Jogadores\n", botoes.botao2);
		printf("%c - Configuracoes do Jogo\n", botoes.botao3);
		printf("%c - Entrar como administrador\n", botoes.botao4);
		printf("%c - Fechar Programa\n", botoes.botao0);

		scanf("%c", &botaoApertado);
		getchar();
		
		//Fechar o Programa
		if (botaoApertado == botoes.botao0) {

			printf("\nFinalizando...\n\n");
			system("pause");
			exit(0);
			saidaWhile = true;
		}
		
		//Comeca o Jogo
		else if (botaoApertado == botoes.botao1) {
			while (saidaWhile != true) {
				system("cls");
				printf("Bem-vindo agente. Por favor, idenfitique-se: ");
				scanf("%s", &agente);

				//Imrpime o nivel de dificuldade, dependendo do retorno da funcao indentificarAgente
				jogador = IdentificarAgente(agente);
				switch (jogador.patente) {
				case 1:
					printf("Nivel: Iniciante\n");
					casoF = arquivoParaObjetoCasoFacil(SorteioCaso(jogador.patente));
					MenuJogoFacil(casoF, botoes);
					saidaWhile = true;
					break;
				case 2:
					printf("Nivel: Intermediario\n");
					//casoM = arquivoParaObjetoCasoMedio(SorteioCaso(jogador.patente));
					saidaWhile = true;
					break;
				case 3:
					printf("Nivel: Avancado\n");
					//casoD = arquivoParaObjetoCasoDificil(SorteioCaso(jogador.patente));
					saidaWhile = true;
					break;
				case 4:
					system("cls");
					printf("Desculpe, mas um cadastro eh necessario para jogar\n\n");
					break;
				case 5:
					system("cls");
					printf("ERRO! - Ocorreu um erro. Tente novamente.\n");
					break;
				case 6:
					system("cls");
					break;
				default:
					break;
				}
			}
		}
		
		//Ranking dos Jogadores
		else if (botaoApertado == botoes.botao2) {
			printf("Imprimir os jogadores por ordem de pontuacao aqui.\n");
			system("pause");
		}
		
		//Configuracoes do Jogo
		else if (botaoApertado == botoes.botao3) {
			char editor = ' ';
			printf("\n\nEdicao dos Botoes de jogo\n");
			printf("Lembre-se: Como padrao, os botoes 1, 2, 3 e 4 servem para escolher a primeira, a segunda, a terceira e a quarta opcao\ndo menu correspondente.\n");
			printf("Enquanto que o botao 0 serve para sair ou voltar um menu.\n");
			printf("Digite o novo botao e, depois disso, aperte Enter para gravar.\n");
			printf("O sistema soh aceita botoes no formato de char.\n");

			printf("\nBotao 0 = ");
			scanf("%c", &editor);
			getchar();
			botoes.botao0 = editor;

			printf("\nBotao 1 = ");
			scanf("%c", &editor);
			getchar();
			while (editor == botoes.botao0) {
				printf("ERRO! - Esse char ja esta sendo usado por outro botao.\n");
				printf("\nBotao 1 = ");
				scanf("%c", &editor);
				getchar();
			}
			botoes.botao1 = editor;

			printf("\nBotao 2 = ");
			scanf("%c", &editor);
			getchar();
			while (editor == botoes.botao0 || editor == botoes.botao1) {
				printf("ERRO! - Esse char ja esta sendo usado por outro botao.\n");
				printf("\nBotao 2 = ");
				scanf("%c", &editor);
				getchar();
			}
			botoes.botao2 = editor;

			printf("\nBotao 3 = ");
			scanf("%c", &editor);
			getchar();
			while (editor == botoes.botao0 || editor == botoes.botao1 || editor == botoes.botao2) {
				printf("ERRO! - Esse char ja esta sendo usado por outro botao.\n");
				printf("\nBotao 3 = ");
				scanf("%c", &editor);
				getchar();
			}
			botoes.botao3 = editor;

			printf("\nBotao 4 = ");
			scanf("%c", &editor);
			getchar();
			while (editor == botoes.botao0 || editor == botoes.botao1 || editor == botoes.botao2 || editor == botoes.botao3) {
				printf("ERRO! - Esse char ja esta sendo usado por outro botao.\n");
				printf("\nBotao 4 = ");
				scanf("%c", &editor);
				getchar();
			}
			botoes.botao4 = editor;
			system("cls");
		}

		//Entrar como administrador
		else if (botaoApertado == botoes.botao4) {
			opcaoAdmin(botoes);
		}
		else{
			printf("%c", botaoApertado);
			system("cls");
			printf("ERRO! - Opcao invalida\n\n");
		}
	}
	system("pause");
}


