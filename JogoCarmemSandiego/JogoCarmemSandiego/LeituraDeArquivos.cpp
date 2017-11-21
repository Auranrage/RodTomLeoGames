#include "LeituraDeArquivos.h"


//ARQUIVO PARA CASO FACIL- Transforma as informações no txt em um objeto do código
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

//ARQUIVO PARA CASO MEDIO- Transforma as informações no txt em um objeto do código
CasoMedio arquivoParaObjetoCasoMedio(int numero) {
	int i = 0;
	FILE *arquivo;
	char auxiliar[30], numeroEmString[2];
	CasoMedio caso;

	caso.numeroDoCaso = numero;
	sprintf(numeroEmString, "%d", caso.numeroDoCaso);

	arquivo = fopen("CasosMedios.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo de casos medios!\n");
		caso.numeroDoCaso = 0;
		return caso;
	}

	//informacoes do arquivo de caso medio
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

			fgets(caso.dica[7], sizeof(caso.dica[7]), arquivo);
			fgets(caso.dica[8], sizeof(caso.dica[8]), arquivo);
			fgets(caso.dica[9], sizeof(caso.dica[9]), arquivo);
			fgets(caso.cidade[3].nome, sizeof(caso.cidade[3].nome), arquivo);

			fgets(caso.dica[10], sizeof(caso.dica[10]), arquivo);
			fgets(caso.dica[11], sizeof(caso.dica[11]), arquivo);
			fgets(caso.dica[12], sizeof(caso.dica[12]), arquivo);
			fgets(caso.cidade[4].nome, sizeof(caso.cidade[4].nome), arquivo);
			break;
		}
	}

	//Le o suspeito
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

		for (i = 0; i < 5; i++) {
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
	strtok(caso.cidade[3].nome, "\n");
	strtok(caso.cidade[3].breveDescricao, "\n");
	strtok(caso.cidade[4].nome, "\n");
	strtok(caso.cidade[4].breveDescricao, "\n");
	return caso;
}

//ARQUIVO PARA CASO DIFICIL- Transforma as informações no txt em um objeto do código
CasoDificil arquivoParaObjetoCasoDificil(int numero) {
	int i = 0;
	FILE *arquivo;
	char auxiliar[30], numeroEmString[2];
	CasoDificil caso;

	caso.numeroDoCaso = numero;
	sprintf(numeroEmString, "%d", caso.numeroDoCaso);

	arquivo = fopen("CasosDificieis.txt", "r");
	if (arquivo == NULL) {
		printf("ERRO! - Impossivel abrir o arquivo de casos medios!\n");
		caso.numeroDoCaso = 0;
		return caso;
	}

	//informacoes do arquivo de caso medio
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

			fgets(caso.dica[7], sizeof(caso.dica[7]), arquivo);
			fgets(caso.dica[8], sizeof(caso.dica[8]), arquivo);
			fgets(caso.dica[9], sizeof(caso.dica[9]), arquivo);
			fgets(caso.cidade[3].nome, sizeof(caso.cidade[3].nome), arquivo);

			fgets(caso.dica[10], sizeof(caso.dica[10]), arquivo);
			fgets(caso.dica[11], sizeof(caso.dica[11]), arquivo);
			fgets(caso.dica[12], sizeof(caso.dica[12]), arquivo);
			fgets(caso.cidade[4].nome, sizeof(caso.cidade[4].nome), arquivo);

			fgets(caso.dica[13], sizeof(caso.dica[13]), arquivo);
			fgets(caso.dica[14], sizeof(caso.dica[14]), arquivo);
			fgets(caso.dica[15], sizeof(caso.dica[15]), arquivo);
			fgets(caso.cidade[5].nome, sizeof(caso.cidade[5].nome), arquivo);

			fgets(caso.dica[16], sizeof(caso.dica[16]), arquivo);
			fgets(caso.dica[17], sizeof(caso.dica[17]), arquivo);
			fgets(caso.dica[18], sizeof(caso.dica[18]), arquivo);
			fgets(caso.cidade[6].nome, sizeof(caso.cidade[6].nome), arquivo);
			break;
		}
	}

	//Le o suspeito
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
	//Le as descricoes das cidades
	while (!feof(arquivo)) {

		fgets(auxiliar, sizeof(auxiliar), arquivo);
		//strtok(auxiliar, "\n");

		for (i = 0; i < 5; i++) {
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
	strtok(caso.cidade[3].nome, "\n");
	strtok(caso.cidade[3].breveDescricao, "\n");
	strtok(caso.cidade[4].nome, "\n");
	strtok(caso.cidade[4].breveDescricao, "\n");
	strtok(caso.cidade[5].nome, "\n");
	strtok(caso.cidade[5].breveDescricao, "\n");
	strtok(caso.cidade[6].nome, "\n");
	strtok(caso.cidade[6].breveDescricao, "\n");
	return caso;
}