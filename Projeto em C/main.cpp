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

//MENU INTERPOL - Funcao para Pesquisar Suspeitos no Database
void interpol() {
	char leitura[30], opcaoYN, lixo, compativel[30];
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

//CASO ALEATORIO - Funcao que sorteia um caso e retorna o numero sorteado
int SorteioCaso(int dificuldade) {
	int caso, maximo = 1;
	char leitura[500], cmp[20];
	FILE *listaCasos;
	srand(time(NULL));

	sprintf(cmp, "Caso %i:\n", maximo);

	//switch para determinar qual arquivo sera lido
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
		printf("error...\n");
		break;
	}
	//determina o numero de casos existente no nivel de dificuldade do jogador
	while (!feof(listaCasos)) {
		fgets(leitura, sizeof(leitura), listaCasos);
		if (strcmp(leitura, cmp) == 0) {
			maximo++;
			sprintf(cmp, "Caso %i:\n", maximo);
		}
	}
	maximo--;
	//caso so exista um unico caso na dificuldade escolhida
	if (maximo == 1) {
		caso = 1;
	}
	//caso exista mais de um caso na dificuldade escolhida
	else {
		caso = rand() % (maximo - 1) + 1; //sorteio de um numero entre 1 e (maximo - 1)
	}

	return caso;
}

//IDENTIFICAÇÃO DO JOGADOR - Funcao para identificar o nome lido no arquivo e, no caso de um novo agente, cadastra-lo no mesmo
int identificarAgente(char nomeAgente[]) {
	FILE *agentes, *admin;
	int id = 0, nivel, sucesso;
	char leitura[30], opcaoYN;
	char lerNivel[5];
	nivelDificuldade nivelAgente;

	agentes = fopen("DadosDosAgentes.txt", "r");

	//Busca o nome do agente no arquivo. Caso seja encontrado, o loop para, se nao, ao final do loop o novo nome sera cadastrado
	while (!feof(agentes) && id == 0) {
		fgets(leitura, sizeof(leitura), agentes);
		strtok(leitura, "\n");
		//Caso o nome lido seja encontrado, a variavel id indica que o nome foi encontrado
		if (strcmp(leitura, nomeAgente) == 0) {
			id = 1;
		}
		//Caso nao encontre, o programa pula a proxima linha, que possui o nivel do jogador antes de recomecar o loop
		else {
			fgets(lerNivel, sizeof(lerNivel), agentes);
		}
	}

	//Agente ja existente
	if (id == 1) {
		printf("Agente identificado.\nBem-vindo, agente %s\n", nomeAgente);
		fscanf(agentes, "%i", &nivel);
		return nivel - 1;

	}
	//Cadastro de novo agente, caso ele deseje
	if (id == 0) {
		getchar();

		admin = fopen("DadosDoAdministrador.txt", "r");
		fscanf(admin, "%s", leitura);
		if (strcmp(leitura, nomeAgente) == 0) {
			sucesso = opcaoAdmin(nomeAgente);
			if (sucesso == 1) {
				return 5;
			}
			else {
				return 4;
			}
		}

		printf("Nao achamos o seu nome na lista\nGostaria de registra-lo?(Y/N)\n");
		scanf("%c", &opcaoYN);
		if (opcaoYN == 'y' || opcaoYN == 'Y') {
			fclose(agentes);
			agentes = fopen("DadosDosAgentes.txt", "a");
			fprintf(agentes, "%s\n1\n", nomeAgente);
			fflush(agentes);
			printf("O seu nome foi salvo\nBem-vindo a agencia, %s!\n", nomeAgente);
			nivelAgente = iniciante;
		}
		else {
			if (opcaoYN == 'n' || opcaoYN == 'N') {
				return 3;
			}
			else {
				return 4;
			}
		}
	}
	return nivelAgente;
}

//MAIN
int main() {
	char agente[20];
	int nivelAgente, numeroCaso, i;
	CasoFacil casoF;
	bool valido = false;

	//Botoes
	char botao = 'z', botao0, botao1, botao2, botao3, botao4, lixo;
	botao0 = '0';
	botao1 = '1';
	botao2 = '2';
	botao3 = '3';
	botao4 = '4';

	//Tela Inicial do Jogo
	while (agente != 0) {
		printf("Bem-vindo agente. Por favor, idenfitique-se: ");
		scanf("%s", &agente);

		if (strcmp(agente, "0") == 0) {  //Fecha o programa com 0
			return 0;
		}

		//Imrpime o nivel de dificuldade, dependendo do retorno da funcao indentificarAgente
		nivelAgente = identificarAgente(agente);
		switch (nivelAgente) {
		case 0:
			//Casos iniciantes
			printf("Nivel: Iniciante\n");

			//Leitura do arquivo txt e transformaçao em uma Struct/Objeto
			casoF = arquivoParaObjetoCasoFacil(SorteioCaso(nivelAgente + 1));

			//Introduçào ao caso
			printf("\nCaso %i:\n", casoF.numeroDoCaso);
			printf("Tesouro Roubado: %sSupeito: %sEncontre-o e prenda-o em menos de 7 dias!\n\n", casoF.tesouro, casoF.vilaoDoCaso.nome);
			system("pause");
			system("cls");

			//Chegada na primeira cidade
			printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[0].nome);
			printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
			valido = false;
			while (valido != true) {

				fflush(stdin);
				scanf("%c", &lixo);
				scanf("%c", &botao);

				if (botao == botao1) {
					system("cls");
					printf("%s\n", casoF.dica[0]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
				}
				else if (botao == botao2) {
					system("cls");
					printf("%s\n", casoF.dica[1]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
				}
				else if (botao == botao3) {
					system("cls");
					printf("%s\n", casoF.dica[2]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
				}
				else if (botao == botao4) {
					system("cls");
					printf("%s\n", casoF.dica[3]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
				}
				else if (botao == botao0) {
					valido = true;
				}
				else {
					system("cls");
					printf("ERRO - Opcao invalida!\n");
					printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[0].nome);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 4 - Lojinha | 0 = Parar de Investigar\n");
				}
			}

			//Pós invetigação
			system("cls");
			printf("O que fazer agora?\n");
			printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
			valido = false;
			while (valido != true) {
				fflush(stdin);
				scanf("%c", &lixo);
				scanf("%c", &botao);

				if (botao == botao1) {
					system("cls");
					printf("Ir para a tela de invetigacao ainda nao implementado\n");
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
				else if (botao == botao2) {
					system("cls");
					interpol();
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
				else if (botao == botao3) {
					system("cls");
					printf("Escolher proxima cidade de viagem ainda nao implementado\n");
					printf("Viajando para a proxima cidade...\n\n");
					valido = true;
				}
				else {
					system("cls");
					printf("ERRO - Opcao invalida!\n");
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
			}
			system("pause");

			//Chegada na segunda cidade
			system("cls");
			printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[1].nome);
			printf("Escolha um local para investigar.\n1 = Lojinha | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
			valido = false;
			while (valido != true) {
				fflush(stdin);
				scanf("%c", &lixo);
				scanf("%c", &botao);

				if (botao == botao1) {
					system("cls");
					printf("%s\n", casoF.dica[4]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao2) {
					system("cls");
					printf("%s\n", casoF.dica[5]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao3) {
					system("cls");
					printf("%s\n", casoF.dica[6]);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao0) {
					valido = true;
				}
				else {
					system("cls");
					printf("ERRO - Opcao invalida!\n");
					printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[1].nome);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
			}

			//Pós invetigação
			system("cls");
			printf("O que fazer agora?\n");
			printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
			valido = false;
			while (valido != true) {
				fflush(stdin);
				scanf("%c", &lixo);
				scanf("%c", &botao);

				if (botao == botao1) {
					system("cls");
					printf("Ir para a tela de invetigacao ainda nao implementado\n");
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
				else if (botao == botao2) {
					system("cls");
					interpol();
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
				else if (botao == botao3) {
					system("cls");
					printf("Escolher proxima cidade de viagem ainda nao implementado\n");
					printf("Viajando para a proxima cidade...\n\n");
					valido = true;
				}
				else {
					system("cls");
					printf("ERRO - Opcao invalida!\n");
					printf("1 = Investigar | 2 =  Interpol | 3 = Viajar\n");
				}
			}
			system("pause");

			//Chegada na ultima cidade
			system("cls");
			printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[2].nome);
			printf("Escolha um local para investigar.\n1 = Lojinha | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
			valido = false;
			while (valido != true) {
				fflush(stdin);
				scanf("%c", &lixo);
				scanf("%c", &botao);

				if (botao == botao1) {
					system("cls");
					printf("Dica dizendo que o vilao esta por perto 1\n");
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao2) {
					system("cls");
					printf("Dica dizendo que o vilao esta por perto 2\n");
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao3) {
					system("cls");
					printf("Dica dizendo que o vilao esta por perto 3\n");
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
				else if (botao == botao0) {
					valido = true;
				}
				else {
					system("cls");
					printf("ERRO - Opcao invalida!\n");
					printf("Bem vindo a %sCidade conhecida por X.\n", casoF.cidade[2].nome);
					printf("Escolha um local para investigar.\n1 = Banco | 2 =  Centro | 3 = Aeroporto | 0 = Parar de Investigar\n");
				}
			}
			break;

		case 1:
			printf("Nivel: Intermediario\n");
			numeroCaso = SorteioCaso(nivelAgente + 1);
			break;

		case 2:
			printf("Nivel: Avancado\n");
			numeroCaso = SorteioCaso(nivelAgente + 1);
			break;

		case 3:
			system("cls");
			printf("Desculpe, mas um cadastro e necessario para jogar\n\n");
			break;

		case 4:
			system("cls");
			printf("Ocorreu um erro. Tente novamente mais tarde\n\n");
			break;

		case 5:
			printf("Finalizando...\n");
			break;

		default:
			break;
		}
	}

	system("pause");
}


//MAIN E MENU ALTERNATIVO. VOU ANALISAR.
/*
void menuJogo(FILE *dadosCaso)
{
	int menu, horas = 8, fimJogo = 0;
	char diaSemana[30], cidade[50];

	strcpy(diaSemana, "Segunda-Feira");

	while (fimJogo == 0) {
		printf("%s, ", diaSemana);
		if (horas < 10) {
			printf("0%i:00\n\n", horas);
		}
		else {
			printf("%i:00\n\n", horas);
		}
		printf("Bem vindo a %s\n\n", cidade);
		printf("O que voce deseja fazer, agente?\n\n");
		printf("1- Viajar   2- Investigar   3- Interpol\n");
		scanf("%i", &menu);
		getchar();
		switch (menu) {
		case 1:
			//viajar
			break;
		case 2:
			//investigar
			break;
		case 3:
			interpol();
			break;
		default:
			break;
		}
	}
}



int main() {
	char agente[20], leitura[500], cmp[50], tesouro[50], cidade[50], sexo[20];
	int nivelAgente, numeroCaso;
	FILE *nivelCaso, *dadosSuspeitos;

	printf("Bem-vindo agente. Por favor, idenfitique-se: ");
	scanf("%s", &agente);

	//imrpime o nivel de dificuldade, dependendo do retorno da funcao indentificarAgente
	nivelAgente = identificarAgente(agente);
	switch (nivelAgente) {
	case 0:
		printf("Nivel: Iniciante\n");
		numeroCaso = sorteioCaso(nivelAgente + 1);
		nivelCaso = fopen("CasosFaceis.txt", "r");
		break;
	case 1:
		printf("Nivel: Intermediario\n");
		numeroCaso = sorteioCaso(nivelAgente + 1);
		nivelCaso = fopen("CasosMedios.txt", "r");
		break;
	case 2:
		printf("Nivel: Avancado\n");
		numeroCaso = sorteioCaso(nivelAgente + 1);
		nivelCaso = fopen("CasosDificeis.txt", "r");
		break;
	case 3:
		printf("Desculpe, mas um cadastro e necessario para jogar\n");
		return 0;
		break;
	case 4:
		printf("Ocorreu um erro. Tente novamente mais tarde\n");
		break;
	case 5:
		printf("Finalizando...\n");
		break;
	default:
		break;
	}

	//obter informacaos sobre caso para serem impressas na tela na mensagem abaixo
	sprintf(cmp, "Caso %i:\n", numeroCaso);

	while (!feof(nivelCaso)) {
		fgets(leitura, sizeof(leitura), nivelCaso);
		if (strcmp(leitura, cmp) == 0) {
			break;
		}
	}
	fgets(tesouro, sizeof(tesouro), nivelCaso);
	fgets(sexo, sizeof(sexo), nivelCaso);
	dadosSuspeitos = fopen("DadosDosSuspeitos.txt", "r");
	while (!feof(dadosSuspeitos)) {
		fgets(leitura, sizeof(leitura), dadosSuspeitos);
		if (strcmp(leitura, sexo) == 0) {
			fgets(sexo, sizeof(sexo), dadosSuspeitos);
			strtok(sexo, "\n");
			sexo[0] = sexo[0] + 32;
			break;
		}
	}
	fgets(cidade, sizeof(cidade), nivelCaso);
	strtok(tesouro, "\n");
	strtok(cidade, "\n");


	//imrpime mensagem inicial do caso
	printf("\n*********** NEWS FLASH ***********\n");
	printf("O tesouro %s foi roubado na cidade de %s. Um suspeito %s foi encontrado no local\n", tesouro, cidade, sexo);
	printf("Agente, você deve localizar o suspeito e prende-lo antes que ele escape\n");
	printf("Voce tem até as 19:00 do Domingo para prende-lo. Boa sorte!\n\n");

	//funcao menu, precisa mandar o arquivo  certo
	menuJogo(nivelCaso);

	system("pause");
}
*/