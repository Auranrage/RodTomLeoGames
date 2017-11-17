#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vilao Vilao;
typedef struct Cidade Cidade;
typedef struct CasoFacil CasoFacil;
typedef struct CasoMedio CasoMedio;
typedef struct CasoDificil CasoDificil;
typedef struct Jogador Jogador;

//Structs
struct Jogador {
	char nome[30];
	int pontos;
	char patente[30];
};

struct Vilao {
	char nome[30];
	char sexo[10];
	char hobby[10];
	char corCabelo[10];
	char destaque[10];
	char carro[15];
};

struct Cidade {
	char nome[20];
	char breveDescricao[120];
};

struct CasoFacil {
	int numeroDoCaso;
	char tesouro[30];
	Vilao vilaoDoCaso;
	Cidade cidade[3];
	char dica[7][300];
};

struct CasoMedio {
	int numeroDoCaso;
	char tesouro[30];
	Vilao vilaoDoCaso;
	Cidade cidade[5];
	char dica[13][300];
};

struct CasoDificil {
	int numeroDoCaso;
	char tesouro[30];
	Vilao vilaoDoCaso;
	Cidade cidade[7];
	char dica[19][300];
};


CasoFacil arquivoParaObjetoCasoFacil(int numero);