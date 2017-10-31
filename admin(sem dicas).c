#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enum para os niveis de dificuldade
typedef enum {
    iniciante,
    intermediario,
    avancado,
} nivelDificuldade;

//procedimento para editar dados do admin
void editarDados(FILE *admin) {
    char nome[30], login[30], senha[30];
    
    admin = fopen("admin.txt", "w");
    
    //leitura dos novos dados
    printf("Digite um novo nome: ");
    fgets(nome, sizeof(nome), stdin);
    strtok(nome, "\n");
    printf("Digite um novo login: ");
    fgets(login, sizeof(login), stdin);
    strtok(login, "\n");
    printf("Digite uma nova senha: ");
    fgets(senha, sizeof(senha), stdin);
    strtok(senha, "\n");
    
    //novos dados sao registrados no arquivo
    fprintf(admin, "%s %s\n%s", login, senha, nome);
    
    fclose(admin);
}

//Funcao de criptografia da senha
int criptografia()
{
	FILE *criptoSenha, *admin;
	char c;
	admin = fopen("admin.txt", "r");
	criptoSenha = fopen("criptosenha.txt", "w+");
	while (!feof(admin) || c != ' ')
	{
		c = fgetc(admin);
	}
	do
	{
		c = fgetc(admin);
		if (c % 2 != 0)
		{
			c += 2;
			if (c == 123)
			{
				c = 97;
			}
			if (c == 91)
			{
				c = 65;
			}
			if (c == 59)
			{
				c = 49;
			}
		}
		else
		{
			c -= 2;
			if (c == 96)
			{
				c = 122;
			}
			if (c == 64)
			{
				c = 90;
			}
			if (c == 46)
			{
				c = 56;
			}
		}
		fprintf(criptoSenha, "%c", c);
	} while (!feof(admin));
	return 0;
}

int descriptografia()
{
	FILE *descriptoSenha, *criptoSenha;
	char c;
	criptoSenha = fopen("criptoSenha.txt", "r");
	criptoSenha = fopen("descriptosenha.txt", "w+");
	while (!feof(criptoSenha) || c != ' ')
	{
		c = fgetc(criptoSenha);
	}
	do
	{
		c = fgetc(criptoSenha);
		if (c % 2 != 0)
		{
			c -= 2;
			if (c == 95)
			{
				c = 121;
			}
			if (c == 63)
			{
				c = 89;
			}
			if (c == 47)
			{
				c = 57;
			}
		}
		else
		{
			c += 2;
			if (c == 124)
			{
				c = 98;
			}
			if (c == 92)
			{
				c = 66;
			}
			if (c == 58)
			{
				c = 48;
			}
		}
		fprintf(descriptoSenha, "%c", c);
	} while (!feof(criptoSenha));
	return 0;
}

int cadastrarCaso() {
    FILE *listaCasos = fopen("caso.txt", "r");
    int numeroCaso = 1, dificuldade;
    char tesouro[50], pais[30], vilao[50], leitura[100], cmpCaso[20];
    
    sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
    
    while (!feof(listaCasos)) {
        fgets(leitura, sizeof(leitura), listaCasos);
        if (strcmp(leitura, cmpCaso) == 0) {
            numeroCaso++;
            sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
        }
    }
    
    fclose(listaCasos);
    
    listaCasos = fopen("caso.txt", "a");
    
    printf("Tesouro roubado: ");
    fgets(tesouro, sizeof(tesouro), stdin);
    strtok(tesouro, "\n");
    printf("Pais roubado: ");
    fgets(pais, sizeof(pais), stdin);
    strtok(pais, "\n");
    printf("Vilao do caso: ");
    fgets(vilao, sizeof(vilao), stdin);
    strtok(vilao, "\n");
    printf("Nivel do caso (1/2/3): ");
    scanf("%i", &dificuldade);
    
    fprintf(listaCasos, "\n%s%s\n%s\n%s\n%d\n", cmpCaso, tesouro, pais, vilao, dificuldade);
    
    fclose(listaCasos);
    
    printf("Caso cadastrado com suecesso!\n");
    
    return 0;
}

int opcaoAdmin(char login[]) {
    char nome[50], senha[40], checarLogin[20], checarSenha[40];
    int menu;
    FILE *dadosAdmin;
    
    printf("Senha: ");
    scanf("%s", &senha);
    
    dadosAdmin = fopen("admin.txt", "r");
    
    fscanf(dadosAdmin, "%s %s", &checarLogin, &checarSenha);
    if(strcmp(checarLogin, login) == 0 && strcmp(checarSenha, senha) == 0) {
        fgets(nome, sizeof(nome), dadosAdmin);
        fgets(nome, sizeof(nome), dadosAdmin);
        
        printf("Bem vindo %s\n", nome);
        printf("O que voce deseja fazer hoje?\n");
        printf("1- ALTERAR CADASTRO   2- CRIAR CASO   3-SAIR\n");
        
        scanf("%i", &menu);
        while (menu != 3) {
            getchar();
            switch (menu)
            {
                //editar dados do admin
                case 1:
                    editarDados(dadosAdmin);
                    break;
                    //Criar caso
                case 2:
                    cadastrarCaso();
                    break;
                    //finaliza o programa
                case 3:
                    printf("Saindo...\n");
                    break;
                default:
                    printf("Opcao invalida\n");
                    break;
            }
            printf("Deseja fazer mais alguma operação, %s?\n", nome);
            printf("1- ALTERAR CADASTRO   2- CRIAR CASO   3-SAIR\n");
            scanf("%i", &menu);
        }
        return 1;
    }
    else {
        printf("Senha incorreta\n");
        return 0;
    }
}

//funcao para identificar o nome lido no arquivo e, no caso de um novo agente, cadastra-lo no mesmo arquivo
//a funcao retorna o nivel do agente
int identificarAgente(char nomeAgente[]) {
    FILE *agentes, *admin;
    int id = 0, nivel, sucesso;
    char leitura[30], opcaoYN;
    nivelDificuldade nivelAgente;
    
    agentes = fopen("agentes.txt", "r");
    
    //busca o nome do agente no arquivo. Caso seja encontrado, o loop para, se nao, ao final do loop o novo nome sera cadastrado
    while (!feof(agentes) && id == 0) {
        fgets(leitura, sizeof(leitura), agentes);
        strtok(leitura, "\n");
        if(strcmp(leitura, nomeAgente) == 0) {
            id = 1;
        }
    }
    
    //agente ja existente
    if(id == 1) {
        printf("Agente identificado.\nBem-vindo, agente %s\n", nomeAgente);
        fscanf(agentes, "%i", &nivel);
        nivelAgente = nivel - 1;
        
    }
    //cadastro de novo agente, caso ele deseje
    if(id == 0) {
        getchar();
        
        admin = fopen("admin.txt", "r");
        fscanf(admin, "%s", leitura);
        if(strcmp(leitura, nomeAgente) == 0) {
            sucesso = opcaoAdmin(nomeAgente);
            if(sucesso == 1) {
                return 5;
            }
            else {
                return 4;
            }
        }
        else {
            
        }
        printf("Nao achamos o seu nome na lista\nGostaria de registra-lo?(Y/N)\n");
        scanf("%c", &opcaoYN);
        if(opcaoYN == 'y' || opcaoYN == 'Y') {
            fclose(agentes);
            agentes = fopen("agentes.txt", "a");
            fprintf(agentes, "%s\n1\n", nomeAgente);
            printf("O seu nome foi salvo\nBem-vindo a agencia, %s!\n", nomeAgente);
            nivelAgente = iniciante;
        }
        else {
            if(opcaoYN == 'n' || opcaoYN == 'N') {
                return 3;
            }
            else {
                return 4;
            }
        }
    }
    
    return nivelAgente;
}

int main() {
    char agente[20], opcaoYN;
    int nivelAgente;
    
    printf("Bem-vindo agente. Por favor, idenfitique-se: ");
    scanf("%s", &agente);
    
    //imrpime o nivel de dificuldade, dependendo do retorno da funcao indentificarAgente
    nivelAgente = identificarAgente(agente);
    switch (nivelAgente) {
        case 0:
            printf("Nivel: Iniciante\n");
            //sorteio casos nivel iniciante
            break;
        case 1:
            printf("Nivel: Intermediario\n");
            //sorteio casos nivel intermediario
            break;
        case 2:
            printf("Nivel: Avancado\n");
            //sorteio casos nivel intermediario
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
    
    
    
    system("pause");
}
