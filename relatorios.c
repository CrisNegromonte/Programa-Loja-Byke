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
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '2':   relat_cli_inativos();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '3':   relat_clientes_por_cidade();
                        break;
            case '4':   relat_todos_colab();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '5':   relat_colab_inativos();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '6':   relat_colab_por_funcao();
                        break;
            case '7':   relat_todos_produtos();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '8':   relat_prod_inativos();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '9':   relat_produtos_por_marca();
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
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ===============   TELA RELATORIOS   ===============           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CLIENTES - Ativos                                         ///\n");
    printf("///            2. CLIENTES - Inativos                                       ///\n");
    printf("///            3. CLIENTES - por Cidade                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            4. COLABORADORES - Ativos                                    ///\n");
    printf("///            5. COLABORADORES - Inativos                                  ///\n");
    printf("///            6. COLABORADORES - por Funcao                                ///\n");
    printf("///                                                                         ///\n");
    printf("///            7. PRODUTOS - Ativos                                         ///\n");
    printf("///            8. PRODUTOS - Inativos                                       ///\n");
    printf("///            9. PRODUTOS - por Marca                                      ///\n");
    printf("///                                                                         ///\n");
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
    printf("                   = = = =    RELATORIO || CLIENTES ATIVOS     = = = =                     \n");
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
      if (cliente->status_cli != 'i') {
        printf("%-12s", cliente->cpf_cli);
        printf("||");
        printf("%-40s", cliente->nome_cli);
        printf("||");
        printf("%-25s", cliente->cidade_cli);
        printf("||");
        printf("%-12s", cliente->fone_cli);
        printf("||");
        printf("%-11s", cliente->nasc_cli);
        printf("||");
        printf("%-33s", cliente->email_cli);
        printf("\n");
      }
    }
   fclose(fp);
   free(cliente);
}






void relat_cli_inativos(void) {
    FILE* fp;
    Cliente* cliente;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                   ===================================================                     \n");
    printf("                   = = = =  RELATORIO ||  CLIENTES  INATIVOS   = = = =                     \n");
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
      if (cliente->status_cli != 'a') {
        printf("%-12s", cliente->cpf_cli);
        printf("||");
        printf("%-40s", cliente->nome_cli);
        printf("||");
        printf("%-25s", cliente->cidade_cli);
        printf("||");
        printf("%-12s", cliente->fone_cli);
        printf("||");
        printf("%-11s", cliente->nasc_cli);
        printf("||");
        printf("%-33s", cliente->email_cli);
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
    printf("                    = = =    RELATORIO || COLABORADORES ATIVOS    = = =                    \n");
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
      if (colab->status_colab != 'i') {
        printf("%-12s", colab->cpf_colab);
        printf("||");
        printf("%-40s", colab->nome_colab);
        printf("||");
        printf("%-15s", colab->func_colab);
        printf("||");
        printf("%-12s", colab->fone_colab);
        printf("||");
        printf("%-11s", colab->nasc_colab);
        printf("||");
        printf("%-33s", colab->email_colab);
        printf("\n");
      }
    }
   fclose(fp);
   free(colab);
}






void relat_colab_inativos(void) {
    FILE* fp;
    Colab* colab;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = =   RELATORIO || COLABORADORES INATIVOS   = = =                    \n");
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
      if (colab->status_colab != 'a') {
        printf("%-12s", colab->cpf_colab);
        printf("||");
        printf("%-40s", colab->nome_colab);
        printf("||");
        printf("%-15s", colab->func_colab);
        printf("||");
        printf("%-12s", colab->fone_colab);
        printf("||");
        printf("%-11s", colab->nasc_colab);
        printf("||");
        printf("%-33s", colab->email_colab);
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
    printf("                    = = = =   RELATORIO ||  PRODUTOS  ATIVOS    = = = =                    \n");
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
        if (produto->status_p != 'i') {
          printf("%-14s", produto->cod_p);
          printf("||");
          printf("%-40s", produto->desc_p);
          printf("||");
          printf("%-12s", produto->cor_p);
          printf("||");
          printf("%-12s", produto->marca_p);
          printf("||");
          printf("%-9.2f", produto->valor_p);
          printf("||");
          printf("%-5d", produto->quant_p);
          printf("\n");
        }
     }
     fclose(fp);
     free(produto);
 }






void relat_prod_inativos(void) {
    FILE* fp;
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =   RELATORIO || PRODUTOS INATIVOS    = = = =                    \n");
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
        if (produto->status_p != 'a') {
          printf("%-14s", produto->cod_p);
          printf("||");
          printf("%-40s", produto->desc_p);
          printf("||");
          printf("%-12s", produto->cor_p);
          printf("||");
          printf("%-12s", produto->marca_p);
          printf("||");
          printf("%-9.2f", produto->valor_p);
          printf("||");
          printf("%-5d", produto->quant_p);
          printf("\n");
        }
     }
     fclose(fp);
     free(produto);
 }






void relat_produtos_por_marca(void) {
    char marca_p[12];
    printf("\n");
    printf("Digite a marca desejada(sem acentos): ");
    scanf("%11s", marca_p);
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
        if (produto.status_p != 'i' && strcmp(produto.marca_p, marca_p) == 0) {
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
        printf(">>> Nenhum produto encontrado para a marca '%s'!\n", marca_p);
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
        printf("%-14s", atual->produto.cod_p);
        printf("||");
        printf("%-40s", atual->produto.desc_p);
        printf("||");
        printf("%-12s", atual->produto.cor_p);
        printf("||");
        printf("%-12s", atual->produto.marca_p);
        printf("||");
        printf("%-9.2f", atual->produto.valor_p);
        printf("||");
        printf("%-5d", atual->produto.quant_p);
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
    char cidade_cli[25];
    printf("Digite a cidade(sem acentos): ");
    scanf("%11s", cidade_cli);
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
        // char cidade1[25];
        // char cidade2[25];
        // strcpy(cidade1, cliente.cidade);
        // strcpy(cidade2, cidade);
        // toupper() ver funcao que converte string inteira em maiusculas
        if (cliente.status_cli != 'i' && strcmp(cliente.cidade_cli, cidade_cli) == 0) {
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
        printf(">>> Nenhum cliente encontrado na cidade '%s'!\n", cidade_cli);
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
        printf("%-25s", atual->cliente.cidade_cli);
        printf("||");
        printf("%-12s", atual->cliente.cpf_cli);
        printf("||");
        printf("%-40s", atual->cliente.nome_cli);
        printf("||");
        printf("%-12s", atual->cliente.fone_cli);
        printf("||");
        printf("%-11s", atual->cliente.nasc_cli);
        printf("||");
        printf("%-33s", atual->cliente.email_cli);
        printf("\n");

        Node2* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó da lista
    }
    printf("\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para voltar ao menu...\n");
    getchar();
}




void relat_colab_por_funcao(void) {
    char func_colab[15];
    printf("Digite a funcao (sem acentos): ");
    scanf("%15s", func_colab);
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
        if (colab.status_colab != 'i' && strcmp(colab.func_colab, func_colab) == 0) {
            Node3* novo = (Node3*)malloc(sizeof(Node3));
            if (novo == NULL) {
                printf(">>> Erro de alocacao de memoria! <<<\n");
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
        printf(">>> Nenhum colaborador(a) encontrado(a) na funcao '%s'!\n", func_colab);
        printf("\n");
        printf(">>> Por favor, verifique se digitou corretamente! <<<\n");
        printf(">>> ATENCAO: Caracteres sensives a Maiuscula e Minuscula. <<<\n");
        printf(">>> ATENCAO: Nao usar acentuacao ou caracteres especiais. <<<\n");
        printf("\n");
        printf(">>> Tecle <ENTER> para voltar ao menu anterior... <<<\n");
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
        printf("%-15s", atual->colab.func_colab);
        printf("||");
        printf("%-12s", atual->colab.cpf_colab);
        printf("||");
        printf("%-40s", atual->colab.nome_colab);
        printf("||");
        printf("%-12s", atual->colab.fone_colab);
        printf("||");
        printf("%-11s", atual->colab.nasc_colab);
        printf("||");
        printf("%-33s", atual->colab.email_colab);
        printf("\n");

        Node3* temp = atual;
        atual = atual->prox;
        free(temp); // Libera cada nó da lista
    }
    printf("\n");
    printf("\n");
    printf(">>> Tecle <ENTER> para voltar ao menu... <<<\n");
    getchar();
}









    