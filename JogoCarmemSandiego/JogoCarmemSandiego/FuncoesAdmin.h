#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Botoes {
	char botao1;
	char botao2;
	char botao3;
	char botao4;
	char botao0;
};

int cadastroCidade(char nomeCidade[]);
void cadastroVilao(char vilao[]);
void cadastroDicas(int nivelDificuldade);
int cadastrarCaso();
void editarDados(FILE *admin);
void opcaoAdmin(Botoes botoes);
