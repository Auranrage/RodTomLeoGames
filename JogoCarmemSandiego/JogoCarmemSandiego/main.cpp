#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "LeituraDeArquivos.h"
#include "FuncoesAuxiliares.h"
#include "FuncoesAdmin.h"

//MENU VIAJAR
int ProximaCidade(int numCidadeAtual, char cidadeAtual[], char cidadeProxima[], char cidadeAnterior[]) {
	FILE *arquivoCidades = fopen("ListaDeCidades.txt", "r");
	char aleatorio1[50], aleatorio2[50], leitura[500], descricao[500];
	int max = 0, cidadeAleatoria, ordem, menu;
	bool booleanCidade = false;

	//Define a qtde de cidades registradas no arquivo
	while (!feof(arquivoCidades)) {
		fgets(leitura, sizeof(leitura), arquivoCidades);
		fgets(descricao, sizeof(descricao), arquivoCidades);
		max++;
	}
	rewind(arquivoCidades);

	
	strcpy(aleatorio1, cidadeProxima);
	strcpy(aleatorio2, cidadeProxima);
	
	//////////////////////SE FOR A PRIMEIRA CIDADE////////////////
	if (numCidadeAtual == 0) {
		//Sorteio de duas cidades aleatorias
		while (strcmp(aleatorio2, aleatorio1) == 0 || strcmp(aleatorio1, cidadeAtual) == 0 || strcmp(aleatorio1, cidadeProxima) == 0 || strcmp(aleatorio2, cidadeAtual) == 0 || strcmp(aleatorio2, cidadeProxima) == 0) {
			//sorteio da primeira cidade aleatoria
			cidadeAleatoria = NumeroRandomico(max);
			for (int i = 0; i < cidadeAleatoria; i++) {
				fgets(leitura, sizeof(leitura), arquivoCidades);
				fgets(descricao, sizeof(descricao), arquivoCidades);
			}
			strcpy(aleatorio1, leitura);
			strtok(aleatorio1, "\n");
			rewind(arquivoCidades);

			//Sorteio da segunda cidade aleatoria
			cidadeAleatoria = NumeroRandomico(max);
			for (int i = 0; i < cidadeAleatoria; i++) {
				fgets(leitura, sizeof(leitura), arquivoCidades);
				fgets(descricao, sizeof(descricao), arquivoCidades);
			}
			strcpy(aleatorio2, leitura);
			strtok(aleatorio2, "\n");
			rewind(arquivoCidades);
		}

		//sorteio de ordem de cidades impressas na tela
		ordem = NumeroRandomico(3);

		//enquanto o usuario nao escolhe a primeira cidade correta
		while (booleanCidade != true) {
			printf("\nVoce esta no aeroporto de %s. Para onde deseja viajar?", cidadeAtual);
			switch (ordem) {
			case 1:
				printf("\n1- %s\n2- %s\n3- %s\n\n", cidadeProxima, aleatorio1, aleatorio2);
				scanf("%i", &menu);
				getchar();

				if (menu == 1) {
					booleanCidade = true;
				}
				else {
					if (menu == 2) {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio1, atual);
						printf("Atual reccebida = %s", atual);
						*/
					}
					else {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio2, atual);
						printf("Atual reccebida = %s", atual);
						*/
					}
				}
				break;
			case 2:
				printf("\n1- %s\n2- %s\n3- %s\n\n", aleatorio1, cidadeProxima, aleatorio2);
				scanf("%i", &menu);
				getchar();
				if (menu == 2) {
					booleanCidade = true;
				}
				else {
					if (menu == 1) {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio1, atual);
						printf("Atual reccebida = %s", atual);*/
					}
					else {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio2, atual);
						printf("Atual reccebida = %s", atual);
						*/
					}
				}
				break;
			case 3:
				printf("\n1- %s\n2- %s\n3- %s\n\n", aleatorio1, aleatorio2, cidadeProxima);
				scanf("%i", &menu);
				getchar();
				if (menu == 3) {
					booleanCidade = true;
				}
				else {
					if (menu == 1) {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio1, atual);
						printf("Atual reccebida = %s", atual);
					*/
					}
					else {
						system("cls");
						printf("Cidade errada!");
						/*printf("Atual enviada = %s", atual);
						cidadeErrada(aleatorio2, atual);
						printf("Atual reccebida = %s", atual);
					*/
					}
				}
				break;
			default:
				printf("ordem error...\n");
				break;
			}
		}
		system("cls");
		printf("Voce achou um membro da VILE! Voce deve estar no caminho certo!\n\n");
		return numCidadeAtual + 1;
	}
	/////////////////////SE NAO FOR A PRIMEIRA CIDADE//////////////////////
	else { 
			//sorteio de duas cidades aleatorias
			while (strcmp(aleatorio2, aleatorio1) == 0 || strcmp(aleatorio1, cidadeAtual) == 0 || strcmp(aleatorio1, cidadeProxima) == 0 || strcmp(aleatorio1,cidadeAnterior) == 0 || strcmp(aleatorio2, cidadeAtual) == 0 || strcmp(aleatorio2, cidadeProxima) == 0 || strcmp(aleatorio2, cidadeAnterior) == 0) {
				
				//sorteio da primeira cidade aleatoria
				cidadeAleatoria = NumeroRandomico(max);
				
				for (int i = 0; i < cidadeAleatoria; i++) {
					fgets(leitura, sizeof(leitura), arquivoCidades);
					fgets(descricao, sizeof(descricao), arquivoCidades);
				}
				strcpy(aleatorio1, leitura);
				strtok(aleatorio1, "\n");
				rewind(arquivoCidades);

				//sorteio da segunda cidade aleatoria
				cidadeAleatoria = NumeroRandomico(max);
				for (int i = 0; i < cidadeAleatoria; i++) {
					fgets(leitura, sizeof(leitura), arquivoCidades);
					fgets(descricao, sizeof(descricao), arquivoCidades);
				}
				strcpy(aleatorio2, leitura);
				strtok(aleatorio2, "\n");
				rewind(arquivoCidades);
			}

			//sorteio da ordem das cidades
			ordem = NumeroRandomico(4);

			//enquanto o usuario nao escolher uma cidade certa
			while (booleanCidade != true) {
				printf("\nVoce esta no aeroporto de %s. Para onde deseja viajar?\n\n", cidadeAtual);
				switch (ordem) {
				case 1:
					printf("1- %s\n2- %s\n3- %s\n4- %s\n", cidadeProxima, cidadeAnterior, aleatorio1, aleatorio2);
					scanf("%i", &menu);
					getchar();

					//switch para opcao que o usuario escolher
					switch (menu) {
					case 1:
						booleanCidade = true;
						break;
					case 2:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(anterior, atual);
						break;
					case 3:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio1, atual);
						break;
					case 4:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio2, atual);
						break;
					default:
						break;
					}
					break;
				case 2:
					printf("1- %s\n2- %s\n3- %s\n4- %s\n", aleatorio1, cidadeProxima, aleatorio2, cidadeAnterior);
					scanf("%i", &menu);
					getchar();

					switch (menu) {
					case 1:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio1, atual);
						break;
					case 2:
						booleanCidade = 1;
						break;
					case 3:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio2, atual);
						break;
					case 4:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(anterior, atual);
						break;
					default:
						break;
					}
					break;
				case 3:
					printf("1- %s\n2- %s\n3- %s\n4- %s\n", cidadeAnterior, aleatorio1, aleatorio2, cidadeProxima);
					scanf("%i", &menu);
					getchar();

					switch (menu) {
					case 1:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(anterior, atual);
						break;
					case 2:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio1, atual);
						break;
					case 3:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio2, atual);
						break;
					case 4:
						booleanCidade = 1;
						break;
					default:
						break;
					}
					break;
				case 4:
					printf("1- %s\n2- %s\n3- %s\n4- %s\n", aleatorio1, cidadeAnterior, cidadeProxima, aleatorio2);
					scanf("%i", &menu);
					getchar();

					switch (menu) {
					case 1:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio1, atual);
						break;
					case 2:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(anterior, atual);
						break;
					case 3:
						booleanCidade = 1;
						break;
					case 4:
						system("cls");
						printf("Cidade errada!");
						//cidadeErrada(aleatorio2, atual);
						break;
					default:
						break;
					}
					break;
				default:
					printf("ordem2 error");
					break;
				}
			}
			
			system("cls");
			printf("Voce achou um membro da VILE! Voce deve estar no caminho certo!\n\n");
			return numCidadeAtual + 1;
		}
	}

//MENU INVESTIGAR
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

//MENU INTERPOL - Funcao para Pesquisar Suspeitos no Database
int Interpol(Botoes botoes) {
	char leitura[50], opcaoYN, compativel[50], menu;
	int prisao = 0, suspeitosRestantes = 0, rSexo, rHobby, rCabelo, rDestaque, rCarro;
	Vilao vilao, cmpDados;
	FILE *dadosSuspeitos = fopen("DadosDosSuspeitos.txt", "r");

	//Pergunta se o usuario quer procurar por um suspeito
	system("cls");
	printf("Deseja buscar o suspeito do caso? (Y/N)\n");
	scanf("%c", &opcaoYN);
	getchar();
	while (opcaoYN != 'y'&& opcaoYN != 'Y' && opcaoYN != 'n'&& opcaoYN != 'N') {
		system("cls");
		printf("Opcao invalida\nDigite uma opcao valida (Y/N)\n");
		scanf("%c", &opcaoYN);
		getchar();
	}

	//Caso a opcao seja sim...
	if (opcaoYN == 'y' || opcaoYN == 'Y') {
		//O usuario digita as informacoes sobre o suspeito
		//Sexo
		system("cls");
		printf("\nEscolha o sexo:\n");
		printf("%c- MASCULINO    %c- FEMININO     %c- DESCONHECIDO\n", botoes.botao1, botoes.botao2, botoes.botao0);
		scanf("%c", &menu);
		getchar();
		
		if (menu == botoes.botao1) {
			strcpy(cmpDados.sexo, "Masculino\n");
		}
		else if (menu == botoes.botao2) {
			strcpy(cmpDados.sexo, "Feminino\n");
		}
		else if (menu == botoes.botao0) {
			strcpy(cmpDados.sexo, "desconhecido\n");
		}

		//Hobby
		printf("\nEscolha o hobby:\n");
		printf("%c- MUSICA     %c- VIAJAR  %c- FILMES   %c- DANCA   %c- DESCONHECIDO\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao4, botoes.botao0);
		scanf("%c", &menu);
		getchar();

		if (menu == botoes.botao1) {
			strcpy(cmpDados.hobby, "Musica\n");
		}		
		else if (menu == botoes.botao2) {
			strcpy(cmpDados.hobby, "Viajar\n");
		}
		else if (menu == botoes.botao3) {
			strcpy(cmpDados.hobby, "Filmes\n");
		}
		else if (menu == botoes.botao4) {
			strcpy(cmpDados.hobby, "Danca\n");
		}
		else if (menu == botoes.botao0) {
			strcpy(cmpDados.hobby, "desconhecido\n");
		}

		//Cabelo
		printf("\nEscolha a cor do cabelo:\n");
		printf("%c- PRETO    %c- CASTANHO     %c- LOIRO    %c- RUIVO    %c- DESCONHECIDO\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao4, botoes.botao0);
		scanf("%c", &menu);
		getchar();

		if (menu == botoes.botao1) {
			strcpy(cmpDados.cabelo, "Preto\n");
		}
		else if (menu == botoes.botao2) {
			strcpy(cmpDados.cabelo, "Castanho\n");
		}
		else if (menu == botoes.botao3) {
			strcpy(cmpDados.cabelo, "Loiro\n");
		}
		else if (menu == botoes.botao4) {
			strcpy(cmpDados.cabelo, "Ruivo\n");
		}
		else if (menu == botoes.botao0) {
			strcpy(cmpDados.cabelo, "desconhecido\n");
		}

		//Destaque
		printf("\nEscolha uma caracteristica de destaque:\n");
		printf("%c- ANEL    %c- JOIA     %c- TATTOO    %c- BENGALA     %c-DESCONHECIDO \n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao4, botoes.botao0);
		scanf("%c", &menu);
		getchar();

		if (menu == botoes.botao1) {
			strcpy(cmpDados.destaque, "Anel\n");
		}
		else if (menu == botoes.botao2) {
			strcpy(cmpDados.destaque, "Joia\n");
		}
		else if (menu == botoes.botao3) {
			strcpy(cmpDados.destaque, "Tattoo\n");
		}
		else if (menu == botoes.botao4) {
			strcpy(cmpDados.destaque, "Bengala\n");
		}
		else if (menu == botoes.botao0) {
			strcpy(cmpDados.destaque, "desconhecido\n");
		}

		//Carro
		printf("\nEscolha um carro:\n");
		printf("%c- CONVERSIVEL    %c- JIPE     %c- LIMOUSINE     %c- ESPORTIVO    %c- DESCONHECIDO\n", botoes.botao1, botoes.botao2, botoes.botao3, botoes.botao4, botoes.botao0);
		scanf("%c", &menu);
		getchar();

		if (menu == botoes.botao1) {
			strcpy(cmpDados.carro, "Conversivel\n");
		}
		else if (menu == botoes.botao2) {
			strcpy(cmpDados.carro, "Jipe\n");
		}
		else if (menu == botoes.botao3) {
			strcpy(cmpDados.carro, "Limousine\n");
		}
		else if (menu == botoes.botao4) {
			strcpy(cmpDados.carro, "Esportivo\n");
		}
		else if (menu == botoes.botao0) {
			strcpy(cmpDados.carro, "desconhecido\n");
		}
		
		system("cls"); //Limpa a tela
		printf("Suspeitos encontrados:\n");
		
		//Procura pelas caracteristicas no database
		while (!feof(dadosSuspeitos)) {
			fgets(vilao.nome, sizeof(vilao.nome), dadosSuspeitos);
			fgets(vilao.sexo, sizeof(vilao.sexo), dadosSuspeitos);
			fgets(vilao.hobby, sizeof(vilao.hobby), dadosSuspeitos);
			fgets(vilao.cabelo, sizeof(vilao.cabelo), dadosSuspeitos);
			fgets(vilao.destaque, sizeof(vilao.destaque), dadosSuspeitos);
			fgets(vilao.carro, sizeof(vilao.carro), dadosSuspeitos);

			//Compara sexo
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

			//Compara hobby
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

			//Compara cabelo
			if (strcmp(vilao.cabelo, cmpDados.cabelo) == 0) {
				rCabelo = 1;
			}
			else {
				if (strcmp(cmpDados.cabelo, "desconhecido\n") == 0) {
					rCabelo = 2;
				}
				else {
					rCabelo = 0;
				}
			}

			//Compara destaque
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

			//Compara carro
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

			//Caso um vilao do arquivo seja compativel com os dados lidos, o programa imprime seu nome na tela
			if (rSexo != 0 && rHobby != 0 && rCabelo != 0 && rDestaque != 0 && rCarro != 0) {
				strcpy(compativel, vilao.nome);
				printf("%s", compativel);
				suspeitosRestantes++;
			}
			fgets(leitura, sizeof(leitura), dadosSuspeitos); //pula o \n que separa os viloes no arquivo
		}
		//Caso so exista um suspeito restante, o programa imprime na tela, notificando o jogador de que ele pode prender o suspeito
		if (suspeitosRestantes == 1) {
			printf("\nVoce tem permissao para prender %s\n\n\n", compativel);
			return 1;
		}
		else if (suspeitosRestantes == 0) {
			printf("\nNenhum suspeito foi encontrado com essas caracteristicas\n\n\n");
		}
		else {
			printf("\nVoce precisa de mais informacoes para prender um deles\n\n\n");
		}
		system("pause");
		system("cls");
	}

	//opcao N: caso o usuario nao queira pesquisar por um suspeito no programa principal, ele volta ao menu anterior, sem perder tempo
	else {
		system("cls");
		printf("Voltando para o menu...\n");
	}
	return 0;
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

//MENU PARA CASO FACIL
void MenuJogoFacil(CasoFacil caso, Botoes botoes){
	int menu, horas = 8, fimJogo = 0, cidadeAtual = 0, vilaoEncontrado = 0;
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

		printf("Bem vindo a %s\n%s\n\n\n", caso.cidade[cidadeAtual].nome,caso.cidade[cidadeAtual].breveDescricao);
		printf("O que voce deseja fazer, agente?\n\n");
		printf("1- Viajar   2- Investigar   3- Interpol\n");
		scanf("%i", &menu);
		getchar();
		switch (menu) {
		case 1:
			//VIAJAR
			if (cidadeAtual == 0) {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[0].nome, caso.cidade[1].nome, "nada");
			}
			else if (cidadeAtual == 1) {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[1].nome, caso.cidade[2].nome, caso.cidade[0].nome);
			}
			else {
				system("cls");
				printf("Parece que o aeroporto esta fechado por medo dos ladroes da VILE. Tente investigar a cidade.\n\n");
			}
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
			vilaoEncontrado = Interpol(botoes);
			horas = horas + 4;
			//Vilao encontrado é um inteiro que é 1 quando encontra o suspeito e 0 quando nao encontra
			//Ou seja, se só tiver um suspeito no arquivo com as caracteristicas, vilaoEncontrado = 1
			//Se nao, vilaoEncontrado = 0
			break;
		default:
			break;
		}
	}

	printf("Parabens detetive! Voce prendeu o suspeito!\n\n");
}

//MENU PARA CASO MEDIO
void MenuJogoMedio(CasoMedio caso, Botoes botoes) {
	int menu, horas = 8, fimJogo = 0, cidadeAtual = 0, vilaoEncontrado = 0, intParaDicas = 3;
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

		printf("Bem vindo a %s\n%s\n\n\n", caso.cidade[cidadeAtual].nome, caso.cidade[cidadeAtual].breveDescricao);
		printf("O que voce deseja fazer, agente?\n\n");
		printf("1- Viajar   2- Investigar   3- Interpol\n");
		scanf("%i", &menu);
		getchar();
		switch (menu) {
		case 1:
			//VIAJAR
			if (cidadeAtual == 0) {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[0].nome, caso.cidade[1].nome, "nada");
			}
			else if (cidadeAtual == 4){
				system("cls");
				printf("Parece que o aeroporto esta fechado por medo dos ladroes da VILE. Tente investigar a cidade.\n\n");
			}
			else {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[cidadeAtual].nome, caso.cidade[cidadeAtual+1].nome, caso.cidade[cidadeAtual-1].nome);
			}
			break;
		case 2:
			//INVESTIGAR
			if (cidadeAtual == 0) {
				system("cls");
				horas = InvestigarCidade(caso.dica[0], caso.dica[1], caso.dica[2], caso.dica[3], cidadeAtual, horas, botoes);
			}
			else if (cidadeAtual == 4){
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
			else {
				system("cls");
				intParaDicas = 3 * cidadeAtual;
				horas = InvestigarCidade(caso.dica[intParaDicas+1], caso.dica[intParaDicas+2], caso.dica[intParaDicas+3], "Nada", cidadeAtual, horas, botoes);
			}
			break;
		case 3:
			//INTERPOL
			vilaoEncontrado = Interpol(botoes);
			horas = horas + 4;
			//Vilao encontrado é um inteiro que é 1 quando encontra o suspeito e 0 quando nao encontra
			//Ou seja, se só tiver um suspeito no arquivo com as caracteristicas, vilaoEncontrado = 1
			//Se nao, vilaoEncontrado = 0
			break;
		default:
			break;
		}
	}

	printf("Parabens detetive! Voce prendeu o suspeito!\n\n");
}

//MENU PARA CASO DIFICIL
void MenuJogoDificil(CasoDificil caso, Botoes botoes) {
	int menu, horas = 8, fimJogo = 0, cidadeAtual = 0, vilaoEncontrado = 0, intParaDicas = 3;
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

		printf("Bem vindo a %s\n%s\n\n\n", caso.cidade[cidadeAtual].nome, caso.cidade[cidadeAtual].breveDescricao);
		printf("O que voce deseja fazer, agente?\n\n");
		printf("1- Viajar   2- Investigar   3- Interpol\n");
		scanf("%i", &menu);
		getchar();
		switch (menu) {
		case 1:
			//VIAJAR
			if (cidadeAtual == 0) {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[0].nome, caso.cidade[1].nome, "nada");
			}
			else if (cidadeAtual == 6) {
				system("cls");
				printf("Parece que o aeroporto esta fechado por medo dos ladroes da VILE. Tente investigar a cidade.\n\n");
			}
			else {
				system("cls");
				cidadeAtual = ProximaCidade(cidadeAtual, caso.cidade[cidadeAtual].nome, caso.cidade[cidadeAtual + 1].nome, caso.cidade[cidadeAtual - 1].nome);
			}
			break;
		case 2:
			//INVESTIGAR
			if (cidadeAtual == 0) {
				system("cls");
				horas = InvestigarCidade(caso.dica[0], caso.dica[1], caso.dica[2], caso.dica[3], cidadeAtual, horas, botoes);
			}
			else if (cidadeAtual == 6) {
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
			else {
				system("cls");
				intParaDicas = 3 * cidadeAtual;
				horas = InvestigarCidade(caso.dica[intParaDicas + 1], caso.dica[intParaDicas + 2], caso.dica[intParaDicas + 3], "Nada", cidadeAtual, horas, botoes);
			}
			break;
		case 3:
			//INTERPOL
			vilaoEncontrado = Interpol(botoes);
			horas = horas + 4;
			//Vilao encontrado é um inteiro que é 1 quando encontra o suspeito e 0 quando nao encontra
			//Ou seja, se só tiver um suspeito no arquivo com as caracteristicas, vilaoEncontrado = 1
			//Se nao, vilaoEncontrado = 0
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
	int nivelAgente, numeroCaso, menu;
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
					casoM = arquivoParaObjetoCasoMedio(SorteioCaso(jogador.patente));
					MenuJogoMedio(casoM, botoes);
					saidaWhile = true;
					break;
				case 3:
					printf("Nivel: Avancado\n");
					casoD = arquivoParaObjetoCasoDificil(SorteioCaso(jogador.patente));
					MenuJogoDificil(casoD, botoes);
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
			system("cls");
			printf("%c - Ranking do top 5\n%c - Ranking Geral\n", botoes.botao1, botoes.botao2);
			scanf("%c", &botaoApertado);
			getchar();
			

			if (botaoApertado == botoes.botao1) {
				ranking5();
			}
			else if (botaoApertado == botoes.botao2) {
				system("cls");
				printf("%c- Por Nome\n%c- Por Nivel\n%c- Por Ranking\n", botoes.botao1, botoes.botao2, botoes.botao3);
				scanf("%c", &botaoApertado);
				getchar();
				
				if (botaoApertado == botoes.botao1) {
					menu = 1;
					system("cls");
					rankingGeral(menu);
				}
				else if (botaoApertado == botoes.botao2) {
					menu = 2;
					system("cls");
					rankingGeral(menu);
				}
				else if (botaoApertado == botoes.botao3) {
					menu = 3;
					system("cls");
					rankingGeral(menu);
				}
				else {
					printf("ERRO! - Opcao invalida!");
				}
			}

			printf("\n\n");
			system("pause");
			system("cls");
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

