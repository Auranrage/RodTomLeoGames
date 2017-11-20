#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//NIVEL DE DIFICULDADE - Enum para os Niveis de Dificuldade
typedef enum {
	iniciante,
	intermediario,
	avancado,
} nivelDificuldade;

void PrintDasHoras(int horas);
int NumeroRandomico(int maximo);
int SorteioCaso(int dificuldade);
void ranking5();
void rankingGeral(int menu);
void CidadeErrada(char escolhida[], char anterior[]);

