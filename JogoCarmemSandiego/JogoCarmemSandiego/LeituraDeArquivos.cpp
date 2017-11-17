#include "LeituraDeArquivos.h"


//ARQUIVO PARA CASO - Transforma as informações no txt em um objeto do código
CasoFacil arquivoParaObjetoCasoFacil(int numero) {
	FILE *arquivo;
	char auxiliar[10], numeroEmString[2];
	CasoFacil caso;

	caso.numeroDoCaso = numero;
	sprintf(numeroEmString, "%d", caso.numeroDoCaso);

	arquivo = fopen("CasosFaceis.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo!\n");
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
	return caso;
}