#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//struct com informacoes sobre o vilao do caso (Interpol)
struct vilaoLeitura {
    char nome[50], sexo[20], hobby[20], cabelo[20], destaque[20], carro[25];
};

//strcut para comparar dados lidos com o database
struct cmpVilao {
    char nome[50], sexo[20], hobby[20], cabelo[20], destaque[20], carro[25];
};

//enum para os niveis de dificuldade (Interpol)
typedef enum {
    iniciante,
    intermediario,
    avancado,
} nivelDificuldade;

//funcao para pesquisar suspeitos no database
void interpol() {
    char leitura[50], opcaoYN, compativel[50];
    int menu, suspeitosRestantes = 0, rSexo, rHobby, rCabelo, rDestaque, rCarro;
    struct vilaoLeitura vilao;
    struct cmpVilao cmpDados;
    FILE *dadosSuspeitos = fopen("DadosDosSuspeitos.txt", "r");
    
    //pergunta se o usuario quer procurar por um suspeito
    printf("Deseja buscar o suspeito do caso? (Y/N)\n");
    scanf("%c", &opcaoYN);
    while (opcaoYN != 'y'&& opcaoYN != 'Y' && opcaoYN != 'n'&& opcaoYN != 'N') {
        printf("Opcao invalida\nDigite uma opcao valida (Y/N)\n");
        getchar();
        scanf("%c", &opcaoYN);
    }
    
    //caso a opcao seja sim...
    if (opcaoYN == 'y' || opcaoYN == 'Y') {
        //o usuario digita as informacoes sobre o suspeito
        //sexo
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
        
        //hobby
        printf("Escolha o hobby:\n");
        printf("1- GOLF    2- MUSICA     3- VIAJAR  4- FILMES   5- DANCA    6- DESCONHECIDO\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                strcpy(cmpDados.hobby, "Gold\n");
                break;
            case 2:
                strcpy(cmpDados.hobby, "Musica\n");
                break;
            case 3:
                strcpy(cmpDados.hobby, "Viajar\n");
                break;
            case 4:
                strcpy(cmpDados.hobby, "Filmes\n");
                break;
            case 5:
                strcpy(cmpDados.hobby, "Danca\n");
                break;
            case 6:
                strcpy(cmpDados.hobby, "desconhecido\n");
                break;
            default:
                break;
        }
        
        //cabelo
        printf("Escolha a cor do cabelo:\n");
        printf("1- PRETO    2- CASTANHO     3- LOIRO    4- RUIVO    5- DESCONHECIDO\n");
        scanf("%i", &menu);
        switch (menu) {
            case 1:
                strcpy(cmpDados.cabelo, "Preto\n");
                break;
            case 2:
                strcpy(cmpDados.cabelo, "Castanho\n");
                break;
            case 3:
                strcpy(cmpDados.cabelo, "Loiro\n");
                break;
            case 4:
                strcpy(cmpDados.cabelo, "Ruivo\n");
                break;
            case 5:
                strcpy(cmpDados.cabelo, "desconhecido\n");
                break;
            default:
                break;
        }
        
        //destaque
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
        
        //carro
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
        
        //procura pelas caracteristicas no database
        while (!feof(dadosSuspeitos)) {
            fgets(vilao.nome, sizeof(vilao.nome), dadosSuspeitos);
            fgets(vilao.sexo, sizeof(vilao.sexo), dadosSuspeitos);
            fgets(vilao.hobby, sizeof(vilao.hobby), dadosSuspeitos);
            fgets(vilao.cabelo, sizeof(vilao.cabelo), dadosSuspeitos);
            fgets(vilao.destaque, sizeof(vilao.destaque), dadosSuspeitos);
            fgets(vilao.carro, sizeof(vilao.carro), dadosSuspeitos);
            
            //compara sexo
            if(strcmp(vilao.sexo, cmpDados.sexo) == 0) {
                rSexo = 1;
            }
            else {
                if(strcmp(cmpDados.sexo, "desconhecido\n") == 0) {
                    rSexo = 2;
                }
                else {
                    rSexo = 0;
                }
            }
            
            //compara hobby
            if(strcmp(vilao.hobby, cmpDados.hobby) == 0) {
                rHobby = 1;
            }
            else {
                if(strcmp(cmpDados.hobby, "desconhecido\n") == 0) {
                    rHobby = 2;
                }
                else {
                    rHobby = 0;
                }
            }
            
            //compara cabelo
            if(strcmp(vilao.cabelo, cmpDados.cabelo) == 0) {
                rCabelo = 1;
            }
            else {
                if(strcmp(cmpDados.cabelo, "desconhecido\n") == 0) {
                    rCabelo = 2;
                }
                else {
                    rCabelo = 0;
                }
            }
            
            //compara destaque
            if(strcmp(vilao.destaque, cmpDados.destaque) == 0) {
                rDestaque = 1;
            }
            else {
                if(strcmp(cmpDados.destaque, "desconhecido\n") == 0) {
                    rDestaque = 2;
                }
                else {
                    rDestaque = 0;
                }
            }
            
            //compara carro
            if(strcmp(vilao.carro, cmpDados.carro) == 0) {
                rCarro = 1;
            }
            else {
                if(strcmp(cmpDados.carro, "desconhecido\n") == 0) {
                    rCarro = 2;
                }
                else {
                    rCarro = 0;
                }
            }
            
            //caso um vilao do arquivo seja compativel com os dados lidos, o programa imprime seu nome na tela
            if (rSexo != 0 && rHobby != 0 && rCabelo != 0 && rDestaque != 0 && rCarro != 0) {
                strcpy(compativel, vilao.nome);
                printf("%s", compativel);
                suspeitosRestantes++;
            }
            fgets(leitura, sizeof(leitura), dadosSuspeitos); //pula o \n que separa os viloes no arquivo
        }
        //caso so exista um suspeito restante, o programa imprime na tela, notificando o jogador de que ele pode prender o suspeito
        if(suspeitosRestantes == 1) {
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

int sorteioCaso(int dificuldade) {
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
            listaCasos = fopen("CasosDificeis.txt", "r");
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
    if(maximo == 1) {
        caso = 1;
    }
    //caso exista mais de um caso na dificuldade escolhida
    else {
        caso = rand() % (maximo - 1) + 1; //sorteio de um numero entre 1 e (maximo - 1)
    }
    
    return caso;
}

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
    char lerNivel[5];
    nivelDificuldade nivelAgente;
    
    agentes = fopen("DadosDosAgentes.txt", "r");
    
    //busca o nome do agente no arquivo. Caso seja encontrado, o loop para, se nao, ao final do loop o novo nome sera cadastrado
    while (!feof(agentes) && id == 0) {
        fgets(leitura, sizeof(leitura), agentes);
        strtok(leitura, "\n");
        //caso o nome lido seja encontrado, a var id indica que o nome foi encontrado
        if(strcmp(leitura, nomeAgente) == 0) {
            id = 1;
        }
        //caso nao encontre, o programa pula a proxima linha, que possui o nivel do jogador antes de recomecar o loop
        else {
            fgets(lerNivel, sizeof(lerNivel), agentes);
        }
    }
    
    //agente ja existente
    if(id == 1) {
        printf("Agente identificado.\nBem-vindo, agente %s\n", nomeAgente);
        fscanf(agentes, "%i", &nivel);
        return nivel - 1;
        
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
            numeroCaso = sorteioCaso(nivelAgente+1);
            nivelCaso = fopen("CasosFaceis.txt", "r");
            break;
        case 1:
            printf("Nivel: Intermediario\n");
            numeroCaso = sorteioCaso(nivelAgente+1);
            nivelCaso = fopen("CasosMedios.txt", "r");
            break;
        case 2:
            printf("Nivel: Avancado\n");
            numeroCaso = sorteioCaso(nivelAgente+1);
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
        if(strcmp(leitura, cmp) == 0) {
            break;
        }
    }
    fgets(tesouro, sizeof(tesouro), nivelCaso);
    fgets(sexo, sizeof(sexo), nivelCaso);
    dadosSuspeitos = fopen("DadosDosSuspeitos.txt", "r");
    while (!feof(dadosSuspeitos)) {
        fgets(leitura, sizeof(leitura), dadosSuspeitos);
        if(strcmp(leitura, sexo) == 0) {
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
