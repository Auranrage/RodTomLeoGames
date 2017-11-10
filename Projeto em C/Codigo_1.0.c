#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//enum para os niveis de dificuldade
typedef enum {
    iniciante,
    intermediario,
    avancado,
} nivelDificuldade;

//funcao para verificar se a cidade lida ja esta cadastrada. Caso nao esteja, o usuario pode cadastra-la
int cadastroCidade(char nomeCidade[]) {
    //variaveis com cmp sao somente para leitura do arquivo
    int booleanCidade = 0, opcaoN = 0, cmp, booleanCadastro = 0, qtdeCidades = 0;
    FILE *listaCidades = fopen("ListaDeCidades.txt", "r");
    char cmpCidade[50], opcaoYN;
    
    while (!feof(listaCidades)) {
        fgets(cmpCidade, sizeof(cmpCidade), listaCidades);
        qtdeCidades++;
    }
    rewind(listaCidades);
    
    while (booleanCidade != 1) {
        
        //caso o usuario tenha escolhido para nao cadastrar a cidade
        if(opcaoN == 1) {
            rewind(listaCidades);
            printf("Cidade roubada: ");
            fgets(nomeCidade, sizeof(nomeCidade), stdin);
            strtok(nomeCidade, "\n");
        }
        
        //loop para verificar se a cidade ja foi cadastrada
        while (!feof(listaCidades)) {
            fscanf(listaCidades, " %i", &cmp);
            fgets(cmpCidade, sizeof(cmpCidade), listaCidades);
            strtok(cmpCidade, "\n");
            memmove(cmpCidade, cmpCidade+1, strlen(cmpCidade)); //retira o espaco no comeco da string
            if(strcmp(nomeCidade, cmpCidade) == 0) {
                booleanCidade = 1;
            }
        }
        
        if(booleanCidade == 0) {
            printf("Cidade não cadastrada. Deseja cadastrar essa cidade? (Y/N)\n");
            scanf("%c", &opcaoYN);
            
            //loop para caso a opcao entrada seja invalida (diferente de y ou n)
            while (opcaoYN != 'y' && opcaoYN != 'Y' && opcaoYN != 'n' && opcaoYN != 'N') {
                printf("Opcao invalida\n");
                printf("Cidade não cadastrada. Deseja cadastrar essa cidade? (Y/N)\n");
                fflush(stdin);
                scanf("%c", &opcaoYN);
            }
            
            //cadastro de nova cidade
            if(opcaoYN == 'y' || opcaoYN == 'Y') {
                fclose(listaCidades);
                listaCidades = fopen("ListaDeCidades.txt", "a");
                strtok(nomeCidade, "\n");
                fprintf(listaCidades, "%i %s\n", qtdeCidades, nomeCidade);
                fflush(listaCidades);
                qtdeCidades++;
                booleanCidade = 1;
                booleanCadastro = 1;
                getchar();
            }
            //caso o usuario nao queira cadastrar a cidade lida
            else {
                getchar();
                opcaoN = 1;
            }
        }
    }
    return booleanCadastro; //indica se a cidade lida foi cadastrada no arquivo
}

//procedimento para cadastrar novos viloes
void cadastroVilao(char vilao[]) {
    FILE *listaSuspeitos;
    int menu, booleanVilao = 0, opcaoN = 0;
    char leitura[50], opcaoYN, sexo[15], hobby[20], cabelo[15], destaque[20], carro[25];
    //booleanVilao == 1 -> vilao cadastrado
    
    listaSuspeitos = fopen("DadosDosSuspeitos.txt", "r");
    
    while (booleanVilao != 1) {
        if (opcaoN == 1) {
            printf("Vilao do caso: ");
            gets(vilao);
            strcat(vilao, "\n");
        }
        
        //verifica se o nome ja foi cadastrado
        while (!feof(listaSuspeitos) && booleanVilao != 1) {
            fgets(leitura, sizeof(leitura), listaSuspeitos);
            if (strcmp(leitura, vilao) == 0) {
                booleanVilao = 1;
            }
        }
        if (booleanVilao == 0) {
            rewind(listaSuspeitos);
            printf("O vilao nao foi encontrado. Voce gostaria de cadastrar um novo vilao?(Y/N)\n");
            scanf(" %c", &opcaoYN);
            //loop para caso a opcao entrada seja invalida (diferente de y ou n)
            while (opcaoYN != 'y' && opcaoYN != 'Y' && opcaoYN != 'n' && opcaoYN != 'N') {
                getchar();
                printf("Opcao invalida\n");
                printf("O vilao nao foi encontrado. Voce gostaria de cadastrar um novo vilao?(Y/N)\n");
                scanf(" %c", &opcaoYN);
            }
            
            //cadastro de novo suspeito
            if(opcaoYN == 'y' || opcaoYN == 'Y') {
                getchar();
                strtok(vilao, "\n");
                printf("Escolha o sexo\n1- MASCULINO  2- FEMININO\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        strcpy(sexo, "Masculino");
                        break;
                    case 2:
                        strcpy(sexo, "Feminino");
                    default:
                        break;
                }
                printf("Escolha o hobby\n1- GOLF  2- MUSICA  3- VIAJAR  4- FILMES  5- DANCA\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        strcpy(hobby, "Golf");
                        break;
                    case 2:
                        strcpy(hobby, "Musica");
                        break;
                    case 3:
                        strcpy(hobby, "Viajar");
                        break;
                    case 4:
                        strcpy(hobby, "Filmes");
                        break;
                    case 5:
                        strcpy(hobby, "Danca");
                        break;
                    default:
                        break;
                }
                printf("Escolha o cabelo\n1- PRETO  2- CASTANHO 3- LOIRO  4- RUIVO\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        strcpy(cabelo, "Preto");
                        break;
                    case 2:
                        strcpy(cabelo, "Castanho");
                        break;
                    case 3:
                        strcpy(cabelo, "Loiro");
                        break;
                    case 4:
                        strcpy(cabelo, "Ruivo");
                        break;
                    default:
                        break;
                }
                printf("Escolha o destaque\n1- ANEL  2- JOIAS  3- TATTOO  4- BENGALA\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        strcpy(destaque, "Anel");
                        break;
                    case 2:
                        strcpy(destaque, "Joias");
                        break;
                    case 3:
                        strcpy(destaque, "Tattoo");
                        break;
                    case 4:
                        strcpy(destaque, "Bengala");
                        break;
                    default:
                        break;
                }
                printf("Escolha o carro\n1- CONVERSIVEL  2- JIPE  3- LIMOUSINE 4- ESPORTIVO\n");
                scanf("%i", &menu);
                switch (menu) {
                    case 1:
                        strcpy(carro, "Conversivel");
                        break;
                    case 2:
                        strcpy(carro, "Jipe");
                        break;
                    case 3:
                        strcpy(carro, "Limousine");
                        break;
                    case 4:
                        strcpy(carro, "Esportivo");
                        break;
                    default:
                        break;
                }
                fclose(listaSuspeitos);
                listaSuspeitos = fopen("DadosDosSuspeitos.txt", "a");
                fprintf(listaSuspeitos, "\n%s\n%s\n%s\n%s\n%s\n%s\n", vilao, sexo, hobby, cabelo, destaque, carro);
                fflush(listaSuspeitos);
                printf("Vilao cadastrado\n");
                booleanVilao = 1;
            }
            //caso o usuario nao deseje cadastrar o nove nome, o programa ira ler outro nome
            if(opcaoYN == 'n' || opcaoYN == 'N') {
                getchar();
                opcaoN = 1;
            }
        }
    }
}

//procedimento para cadastro de dicas
void cadastroDicas(int nivelDificuldade) {
    int cidadeCaso, i, j, qtdeCidades = 0, cidadeCadastrada;
    char cidade[30], dica[500], leitura[50];
    FILE *salvarDados, *cidades = fopen("ListaDeCidades.txt", "r");
    getchar();
    
    //loop para determinar qtde de cidades cadastradas
    while (!feof(cidades)) {
        fgets(leitura, sizeof(leitura), cidades);
        qtdeCidades++;
    }
    
    //determina a quantidade de cidades a ser visitada dependendo do nivel de dificuldade
    switch (nivelDificuldade) {
        case 1:
            salvarDados = fopen("CasosFaceis.txt", "a");
            cidadeCaso = 3;
            break;
        case 2:
            salvarDados = fopen("CasosMedios.txt", "a");
            cidadeCaso = 5;
            break;
        case 3:
            salvarDados = fopen("CasosDificeis.txt", "a");
            cidadeCaso = 7;
            break;
        default:
            printf("error\n");
            break;
    }
    
    for (i = 0; i < cidadeCaso; i++) {
        //leitura da primeira cidade com 4 dicas
        if (i == 0) {
            printf("Cidade nº%i: ", i+1);
            fgets(cidade, sizeof(cidade), stdin);
            strtok(cidade, "\n");
            cidadeCadastrada = cadastroCidade(cidade);
            if(cidadeCadastrada == 1) { //caso tenha ocorrido um cadastro de uma nova cidade, o programa atualiza a qtde de cidades cadastradas
                qtdeCidades++;
            }
            fprintf(salvarDados, "%s\n", cidade);
            fflush(salvarDados);
            //leitura das primeiras 4 dicas
            for (j = 0; j < 4; j++) {
                fflush(stdin);
                printf("Dica %i: ", j + 1);
                fgets(dica, sizeof(dica), stdin);
                strtok(dica, "\n");
                fprintf(salvarDados, "%s\n", dica);
                fflush(salvarDados);
            }
        }
        else {
            //leitura da ultima cidade, sem dicas
            if (i == cidadeCaso - 1) {
                printf("Ultima cidade: ");
                fgets(cidade, sizeof(cidade), stdin);
                strtok(cidade, "\n");
                cidadeCadastrada = cadastroCidade(cidade);
                if(cidadeCadastrada == 1) {
                    qtdeCidades++;
                }
                fprintf(salvarDados, "%s\n", cidade);
                fflush(salvarDados);
            }
            //leitura das outras cidades com 3 dicas
            else {
                printf("Cidade nº%i: ", i+1);
                fgets(cidade, sizeof(cidade), stdin);
                strtok(cidade, "\n");
                cidadeCadastrada = cadastroCidade(cidade);
                if(cidadeCadastrada == 1) {
                    qtdeCidades++;
                }
                fprintf(salvarDados, "%s\n", cidade);
                fflush(salvarDados);
                
                //leitura de tres dicas
                for (j = 0; j < 3; j++) {
                    fflush(stdin);
                    printf("Dica %i: ", j + 1);
                    fgets(dica, sizeof(dica), stdin);
                    strtok(dica, "\n");
                    fprintf(salvarDados, "%s\n", dica);
                    fflush(salvarDados);
                }
            }
        }
    }
}

//procedimento para editar dados do admin
void editarDados(FILE *admin) {
    char nome[30], login[30], senha[30];
    
    admin = fopen("DadosDoAdministrador.txt", "w");
    
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
    fflush(admin);
    
    fclose(admin);
}

//funcao para cadastrar novos casos
int cadastrarCaso() {
    FILE *listaCasos;
    char vilao[50], tesouro[30], cmpCaso[20], leitura[100];
    int dificuldade, numeroCaso = 1;
    
    sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
    
    printf("Tesouro roubado: ");
    fgets(tesouro, sizeof(tesouro), stdin);
    strtok(tesouro, "\n");
    
    printf("Vilao do caso: ");
    fgets(vilao, sizeof(vilao), stdin);
    cadastroVilao(vilao);
    
    printf("Nivel de dificuldade (1/2/3): ");
    scanf("%i", &dificuldade);
    while (dificuldade != 1 && dificuldade != 2 && dificuldade != 3) {
        printf("Opcao invalida\nNivel de dificuldade (1/2/3): ");
        scanf("%i", &dificuldade);
    }
    
    switch (dificuldade) {
        case 1:
            listaCasos = fopen("CasosFaceis.txt", "r");
            //verifica quantos casos ja foram cadastrados nessa dificuldade
            while (!feof(listaCasos)) {
                fgets(leitura, sizeof(leitura), listaCasos);
                if (strcmp(leitura, cmpCaso) == 0) {
                    numeroCaso++;
                    sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
                }
            }
            //comeca a escrtia dos dados inseridos pelo usuario no arquivo
            fclose(listaCasos);
            listaCasos = fopen("CasosFaceis.txt", "a");
            fprintf(listaCasos, "\n%s%s\n%s", cmpCaso, tesouro, vilao);
            fflush(listaCasos);
            break;
        case 2:
            listaCasos = fopen("CasosMedios.txt", "r");
            
            while (!feof(listaCasos)) {
                fgets(leitura, sizeof(leitura), listaCasos);
                if (strcmp(leitura, cmpCaso) == 0) {
                    numeroCaso++;
                    sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
                }
            }
            fclose(listaCasos);
            listaCasos = fopen("CasosMedios.txt", "a");
            fprintf(listaCasos, "\n%s%s\n%s", cmpCaso, tesouro, vilao);
            fflush(listaCasos);
            break;
        case 3:
            listaCasos = fopen("CasosDificeis.txt", "r");
            
            while (!feof(listaCasos)) {
                fgets(leitura, sizeof(leitura), listaCasos);
                if (strcmp(leitura, cmpCaso) == 0) {
                    numeroCaso++;
                    sprintf(cmpCaso, "Caso %i:\n", numeroCaso);
                }
            }
            fclose(listaCasos);
            listaCasos = fopen("CasosDificeis.txt", "a");
            fprintf(listaCasos, "\n%s%s\n%s", cmpCaso, tesouro, vilao);
            fflush(listaCasos);
            break;
        default:
            break;
    }
    
    cadastroDicas(dificuldade);
    
    
    return 0;
    
}

int opcaoAdmin(char login[]) {
    char nome[50], senha[40], checarLogin[20], checarSenha[40];
    int menu;
    FILE *dadosAdmin = fopen("DadosDoAdministrador.txt", "r");
    
    printf("Senha: ");
    scanf("%s", &senha);
    
    fscanf(dadosAdmin, "%s %s", &checarLogin, &checarSenha);
    if(strcmp(checarLogin, login) == 0 && strcmp(checarSenha, senha) == 0) {
        fgets(nome, sizeof(nome), dadosAdmin);
        fgets(nome, sizeof(nome), dadosAdmin);
        
        //imprime menu admin
        printf("Bem vindo %s\n", nome);
        printf("O que voce deseja fazer hoje?\n");
        printf("1- ALTERAR CADASTRO   2- CRIAR CASO   3-SAIR\n");
        
        scanf("%i", &menu);
        while (menu != 3) {
            getchar();
            switch (menu)
            {
                case 1:                                                       //editar dados do admin
                    editarDados(dadosAdmin);
                    break;
                case 2:                                                       //Criar caso
                    cadastrarCaso();
                    break;
                case 3:                                                       //finaliza o programa
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

//funcao para identificar o nome lido no arquivo e, no caso de um novo agente, cadastra-lo no mesmo
int identificarAgente(char nomeAgente[]) {
    FILE *agentes, *admin;
    int id = 0, nivel, sucesso;
    char leitura[30], opcaoYN;
    nivelDificuldade nivelAgente;
    
    agentes = fopen("DadosDosAgentes.txt", "r");
    
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
        
        admin = fopen("DadosDoAdministrador.txt", "r");
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
            agentes = fopen("DadosDosAgentes.txt", "a");
            fprintf(agentes, "%s\n1\n", nomeAgente);
            fflush(agentes);
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
    char agente[20];
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
    
    
    
	system(“pause”);
}
