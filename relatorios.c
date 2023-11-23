#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "relatorios.h"
#include "cliente.h"
#include "colab.h"
#include "vendas.h"
#include "produtos.h"

void menu_relatorios(void) {
    char op;
    do{
        op = tela_relat();
        switch (op) {
            case '1':   relat_todos_clientes();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '2':   relat_clientes_por_cidade();
                        break;
            case '3':   relat_todos_colab();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '4':   relat_colab_por_funcao();
                        break;
            case '5':   relat_todos_produtos();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '6':   relat_produtos_por_marca();
                        break;

        } 		
    } while (op != '0');
}



char tela_relat(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = = = =   TELA RELATORIOS   = = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CLIENTES - geral                                          ///\n");
    printf("///            2. CLIENTES - por CIDADE                                     ///\n");
    printf("///            3. COLABORADORES - geral                                     ///\n");
    printf("///            4. COLABORADORES - por FUNCAO                                ///\n");
    printf("///            5. PRODUTOS - geral                                          ///\n");
    printf("///            6. PRODUTOS - por MARCA                                      ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>       Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf(">>>>>>  Processando... <<<<<\n");
    sleep(1);
    return op;
 }


void relat_todos_clientes(void) {
    FILE* fp;
    Cliente* cliente;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                   ===================================================                     \n");
    printf("                   = = = =   RELATORIO || TODOS OS CLIENTES    = = = =                     \n");
    printf("                   ===================================================                     \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
      printf(">>>>>>>>  Processando...   <<<<<<<<\n");
      sleep(1);
      printf(">>> ERRO ao abrir o arquivo!\n");
      printf(">>> Verifique se ja existe cliente cadastrado! \n");
      printf(">>> Tecle <ENTER> para voltar...\n");
      getchar();
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "CLIENTE");
    printf("||");
    printf("%-25s", "CIDADE");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC.");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(cliente, sizeof(Cliente), 1, fp)) { 
      if (cliente->status != 'i') {
        printf("%-12s", cliente->cpf);
        printf("||");
        printf("%-40s", cliente->nome);
        printf("||");
        printf("%-25s", cliente->cidade);
        printf("||");
        printf("%-12s", cliente->fone);
        printf("||");
        printf("%-11s", cliente->nasc);
        printf("||");
        printf("%-33s", cliente->email);
        printf("\n");
      }
    }
   fclose(fp);
   free(cliente);
}



void relat_todos_colab(void) {
    FILE* fp;
    Colab* colab;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = =   RELATORIO || TODOS OS COLABORADORES   = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("\n");
    colab = (Colab*) malloc(sizeof(Colab));
    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
      printf(">>>>>>>>  Processando...   <<<<<<<<\n");
      sleep(1);
      printf(">>> ERRO ao abrir o arquivo!\n");
      printf(">>> Verifique se ja existe colaborador(a) cadastrado(a)! \n");
      printf(">>> Tecle <ENTER> para voltar...\n");
      getchar();
    }
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "COLABORADOR(A)");
    printf("||");
    printf("%-15s", "FUNCAO");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC.");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(colab, sizeof(Colab), 1, fp)) { 
      if (colab->status != 'i') {
        printf("%-12s", colab->cpf);
        printf("||");
        printf("%-40s", colab->nome);
        printf("||");
        printf("%-15s", colab->func);
        printf("||");
        printf("%-12s", colab->fone);
        printf("||");
        printf("%-11s", colab->nasc);
        printf("||");
        printf("%-33s", colab->email);
        printf("\n");
      }
    }
   fclose(fp);
   free(colab);
}




void relat_todos_produtos(void) {
    FILE* fp;
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =   RELATORIO || TODOS OS PRODUTOS   =  = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("\n");
    produto = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando...\n");
        sleep(1);
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Verifique se ja existe produto cadastrado! \n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
    }
     printf("---------------------------------------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-14s", "CODIGO");
     printf("||");
     printf("%-40s", "DESCRICAO");
     printf("||");
     printf("%-12s", "COR");
     printf("||");
     printf("%-12s", "MARCA");
     printf("||");
     printf("%-9s", "VALOR");
     printf("||");
     printf("%-5s", "ESTOQUE");
     printf("\n");
     printf("---------------------------------------------------------------------------------------------------------------------------------");
     printf("\n"); 
     while (fread(produto, sizeof(Produto), 1, fp)) { 
        if (produto->status != 'i') {
          printf("%-14s", produto->cod);
          printf("||");
          printf("%-40s", produto->desc);
          printf("||");
          printf("%-12s", produto->cor);
          printf("||");
          printf("%-12s", produto->marca);
          printf("||");
          printf("%-9.2f", produto->valor);
          printf("||");
          printf("%-5d", produto->quant);
          printf("\n");
        }
     }
     fclose(fp);
     free(produto);
 }






void relat_produtos_por_marca(void) {
    char marca[12];
    printf("\n");
    printf("Digite a marca desejada(sem acentos): ");
    scanf("%11s", marca);
    getchar();
    FILE* fp;
    Produto produto;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =   RELATORIO || PRODUTOS POR MARCA   = = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");

    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Verifique se já existe um produto cadastrado!\n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
        return;
    }

    Node* inicio = NULL;
    Node* atual = NULL;

    while (fread(&produto, sizeof(Produto), 1, fp)) {
        if (produto.status != 'i' && strcmp(produto.marca, marca) == 0) {
            Node* novo = (Node*)malloc(sizeof(Node));
            if (novo == NULL) {
                printf(">>> Erro de alocacao de memoria! <<<\n");
                return;
            }

            novo->produto = produto;
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;
            } else {
                atual->prox = novo;
            }

            atual = novo;
        }
    }

    fclose(fp);

    if (inicio == NULL) {
        printf(">>> Nenhum produto encontrado para a marca '%s'!\n", marca);
        printf("\n");
        printf(">>> Por favor, verifique se digitou corretamente!\n");
        printf(">>> ATENCAO: Caracteres sensives a Maiuscula e Minuscula.\n");
        printf(">>> ATENCAO: Nao usar acentuacao ou caracteres especiais.\n");
        printf("\n");
        printf(">>> Tecle <ENTER> para voltar ao menu anterior...\n");
        getchar();
        return;
    }

    // Imprime os produtos filtrados por marca
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-14s", "CODIGO");
    printf("||");
    printf("%-40s", "DESCRICAO");
    printf("||");
    printf("%-12s", "COR");
    printf("||");
    printf("%-12s", "MARCA");
    printf("||");
    printf("%-9s", "VALOR");
    printf("||");
    printf("%-5s", "ESTOQUE");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    atual = inicio;
    while (atual != NULL) {
        printf("%-14s", atual->produto.cod);
        printf("||");
        printf("%-40s", atual->produto.desc);
        printf("||");
        printf("%-12s", atual->produto.cor);
        printf("||");
        printf("%-12s", atual->produto.marca);
        printf("||");
        printf("%-9.2f", atual->produto.valor);
        printf("||");
        printf("%-5d", atual->produto.quant);
        printf("\n");

        Node* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó da lista
    }
    printf("\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para voltar ao menu...  <<<\n");
    getchar();
}





void relat_clientes_por_cidade(void) {
    char cidade[25];
    printf("Digite a cidade(sem acentos): ");
    scanf("%11s", cidade);
    getchar();
    FILE* fp;
    Cliente cliente;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =  RELATORIO || CLIENTES POR CIDADE   = = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
         printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Talvez ainda nao existam cadastrados!\n");
        printf(">>> Realize um cadastro e volte aqui...\n");
        getchar();
        return;
    }

    Node2* inicio = NULL;
    Node2* atual = NULL;

    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (cliente.status != 'i' && strcmp(cliente.cidade, cidade) == 0) {
            Node2* novo = (Node2*)malloc(sizeof(Node2));
            if (novo == NULL) {
                printf(">>> Erro de alocacao de memoria! <<<\n");
                return;
            }

            novo->cliente = cliente;
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;
            } else {
                atual->prox = novo;
            }

            atual = novo;
        }
    }

    fclose(fp);

    if (inicio == NULL) {
        printf("\t\t\t>>> Nenhum cliente encontrado na cidade '%s'!\n", cidade);
        printf("\n");
        printf(">>> Por favor, verifique se digitou corretamente!\n");
        printf(">>> ATENCAO: Caracteres sensives a Maiuscula e Minuscula.\n");
        printf(">>> ATENCAO: Nao usar acentuacao ou caracteres especiais.\n");
        printf("\n");
        printf(">>> Tecle <ENTER> para voltar ao menu anterior...\n");
        getchar();
        return;
    }

    // Imprime os produtos filtrados por marca
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-25s", "CIDADE");
    printf("||");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "NOME");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    atual = inicio;
    while (atual != NULL) {
        printf("%-25s", atual->cliente.cidade);
        printf("||");
        printf("%-12s", atual->cliente.cpf);
        printf("||");
        printf("%-40s", atual->cliente.nome);
        printf("||");
        printf("%-12s", atual->cliente.fone);
        printf("||");
        printf("%-11s", atual->cliente.nasc);
        printf("||");
        printf("%-33s", atual->cliente.email);
        printf("\n");

        Node2* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó da lista
    }
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para voltar ao menu...\n");
    getchar();
}




void relat_colab_por_funcao(void) {
    char func[15];
    printf("Digite a funcao (sem acentos): ");
    scanf("%15s", func);
    getchar();
    FILE* fp;
    Colab colab;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = =  RELATORIO || COLABORADORES POR FUNCAO  = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");

    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Talvez ainda nao existam colaboradores cadastrados!\n");
        printf(">>> Realize um cadastro e volte aqui...\n");
        getchar();
        return;
    }

    Node3* inicio = NULL;
    Node3* atual = NULL;

    while (fread(&colab, sizeof(Colab), 1, fp)) {
        if (colab.status != 'i' && strcmp(colab.func, func) == 0) {
            Node3* novo = (Node3*)malloc(sizeof(Node3));
            if (novo == NULL) {
                printf("\t\t\t>>> Erro de alocacao de memoria! <<<\n");
                return;
            }

            novo->colab = colab;
            novo->prox = NULL;

            if (inicio == NULL) {
                inicio = novo;
            } else {
                atual->prox = novo;
            }

            atual = novo;
        }
    }

    fclose(fp);

    if (inicio == NULL) {
        printf("\t\t\t>>> Nenhum colaborador(a) encontrado(a) na funcao '%s'!\n", func);
        printf("\n");
        printf("\t\t\t>>> Por favor, verifique se digitou corretamente!\n");
        printf("\t\t\t>>> ATENCAO: Caracteres sensives a Maiuscula e Minuscula.\n");
        printf("\t\t\t>>> ATENCAO: Nao usar acentuacao ou caracteres especiais.\n");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para voltar ao menu anterior...\n");
        getchar();
        return;
    }

    // Imprime os produtos filtrados por marca
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("\n");
    printf("%-15s", "FUNCAO");
    printf("||");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "NOME");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    atual = inicio;
    while (atual != NULL) {
        printf("%-15s", atual->colab.func);
        printf("||");
        printf("%-12s", atual->colab.cpf);
        printf("||");
        printf("%-40s", atual->colab.nome);
        printf("||");
        printf("%-12s", atual->colab.fone);
        printf("||");
        printf("%-11s", atual->colab.nasc);
        printf("||");
        printf("%-33s", atual->colab.email);
        printf("\n");

        Node3* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó da lista
    }
    printf("\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para voltar ao menu...\n");
    getchar();
}









    