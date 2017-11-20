#include "LeituraDeArquivos.h"


//ARQUIVO PARA CASO - Transforma as informações no txt em um objeto do código
CasoFacil arquivoParaObjetoCasoFacil(int numero) {
	int i = 0;
	FILE *arquivo;
	char auxiliar[30], numeroEmString[2];
	CasoFacil caso;

	caso.numeroDoCaso = numero;
	sprintf(numeroEmString, "%d", caso.numeroDoCaso);

	arquivo = fopen("CasosFaceis.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo de casos!\n");
		caso.numeroDoCaso = 0;
		return caso;
	}

	while (!feof(arquivo)) {
		fgets(auxiliar, sizeof(auxiliar), arquivo);
		strtok(auxiliar, "\n");

		if (strcmp(auxiliar, numeroEmString) == 0) {
			fgets(caso.tesouro, sizeof(caso.tesouro), arquivo);
			fgets(caso.vilaoDoCaso.nome, sizeof(caso.vilaoDoCaso.nome), arquivo);
			fgets(caso.cidade[0].nome, sizeof(caso.cidade[0].nome), arquivo);

			fgets(caso.dica[0], sizeof(caso.dica[0]), arquivo);
			fgets(caso.dica[1], sizeof(caso.dica[1]), arquivo);
			fgets(caso.dica[2], sizeof(caso.dica[2]), arquivo);
			fgets(caso.dica[3], sizeof(caso.dica[3]), arquivo);
			fgets(caso.cidade[1].nome, sizeof(caso.cidade[1].nome), arquivo);

			fgets(caso.dica[4], sizeof(caso.dica[4]), arquivo);
			fgets(caso.dica[5], sizeof(caso.dica[5]), arquivo);
			fgets(caso.dica[6], sizeof(caso.dica[6]), arquivo);
			fgets(caso.cidade[2].nome, sizeof(caso.cidade[2].nome), arquivo);
			break;
		}
	}

	arquivo = fopen("DadosDosSuspeitos.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo de suspeitos!\n");
		caso.numeroDoCaso = 0;
		return caso;
	}

	while (!feof(arquivo)) {
		fgets(auxiliar, sizeof(auxiliar), arquivo);
		//strtok(auxiliar, "\n");

		if (strcmp(auxiliar, caso.vilaoDoCaso.nome) == 0) {
			fgets(caso.vilaoDoCaso.sexo, sizeof(caso.vilaoDoCaso.sexo), arquivo);
			fgets(caso.vilaoDoCaso.hobby, sizeof(caso.vilaoDoCaso.hobby), arquivo);
			fgets(caso.vilaoDoCaso.cabelo, sizeof(caso.vilaoDoCaso.cabelo), arquivo);
			fgets(caso.vilaoDoCaso.destaque, sizeof(caso.vilaoDoCaso.destaque), arquivo);
			fgets(caso.vilaoDoCaso.carro, sizeof(caso.vilaoDoCaso.carro), arquivo);
			break;
		}
	}

	arquivo = fopen("ListaDeCidades.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo de cidades!\n");
		caso.numeroDoCaso = 0;
		return caso;
	}

	while (!feof(arquivo)) {
		
		fgets(auxiliar, sizeof(auxiliar), arquivo);
		//strtok(auxiliar, "\n");

		for (i = 0; i < 3; i++) {		
			if (strcmp(auxiliar, caso.cidade[i].nome) == 0) {
				fgets(caso.cidade[i].breveDescricao, sizeof(caso.cidade[i].breveDescricao), arquivo);
			}
		}
	}
	strtok(caso.tesouro, "\n");
	strtok(caso.vilaoDoCaso.nome, "\n");
	strtok(caso.vilaoDoCaso.sexo, "\n");
	strtok(caso.vilaoDoCaso.hobby, "\n");
	strtok(caso.vilaoDoCaso.cabelo, "\n");
	strtok(caso.vilaoDoCaso.destaque, "\n");
	strtok(caso.vilaoDoCaso.carro, "\n");
	strtok(caso.cidade[0].nome, "\n");
	strtok(caso.cidade[0].breveDescricao, "\n");
	strtok(caso.cidade[1].nome, "\n");
	strtok(caso.cidade[1].breveDescricao, "\n");
	strtok(caso.cidade[2].nome, "\n");
	strtok(caso.cidade[2].breveDescricao, "\n");
	return caso;
}