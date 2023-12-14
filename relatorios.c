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


void relat_vendas_cpf_cli(Vendas*);
void relat_vendas_cpf_colab(Vendas*);


void menu_relatorios(void) {
    char opcao;
    do {
        opcao = tela_relat();
        switch(opcao) {
            case '1':   tela_relat_cli();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '2':   tela_relat_colab();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '3':   tela_relat_prod();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '4':   tela_relat_vendas();
                        break;
          } 		
    } while (opcao != '0');
}






char tela_relat(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///                                                                         ///\n");
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ===============   MENU RELATORIOS   ===============           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CLIENTES - Relatorios                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            2. COLABORADORES - Relatorios                                ///\n");
    printf("///                                                                         ///\n");
    printf("///            3. PRODUTOS - Relatorios                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///            4. VENDAS - Relatorios                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>       Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    //printf(">>>>>>  Processando... <<<<<\n");
    sleep(1);
    return op;
 }





 void tela_relat_cli(void){
    char opcao;

    do {
        opcao = relat_cli();
        switch(opcao) {
            case '1':   relat_todos_clientes();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '2':   relat_cli_inativos();;
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '3':   relat_cli_alfa();
                        break;
            //case '4':   relat_clientes_por_cidade();
                        //printf("\n");
                        //printf("\t\t\t>>> Tecle <ENTER> para voltarr...\n");
                        //getchar();
                        //break;
          } 		
    } while (opcao != '0');
}



char relat_cli(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///                                                                         ///\n");
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ===========    RELATORIOS - CLIENTES    ===========           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CLIENTES ATIVOS                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///            2. CLIENTES INATIVOS                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            3. CLIENTES - ORDEM ALFABETICA                               ///\n");
    printf("///                                                                         ///\n");
    //printf("///            4. CLIENTES por CIDADE                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>       Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    sleep(1);
    return op;
 }




void relat_todos_clientes(void) {
    FILE* fp;
    Cliente* cliente;
    system("clear||cls");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------");
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
    printf("------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "CLIENTE");
    printf("||");
    printf("%-25s", "CIDADE");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    //printf("%-11s", "DATA NASC.");
    //printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------");
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
        //printf("%-11s", cliente->nasc_cli);
        //printf("||");
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
    printf("------------------------------------------------------------------------------------------------------------------");
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
    printf("------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "CLIENTE");
    printf("||");
    printf("%-25s", "CIDADE");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------------");
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
        //printf("%-11s", cliente->nasc_cli);
        //printf("||");
        printf("%-33s", cliente->email_cli);
        printf("\n");
      }
    }
   fclose(fp);
   free(cliente);
}





void relat_cli_alfa(void) {
    FILE* fp = fopen("cli.dat", "rb");
    Cliente* novo_cli;
    Cliente* lista;
    system("clear||cls");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Erro ao abrir o arquivo!\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        printf(">>> Talvez ainda nao existam clientes para listar...\n");
        printf(">>> Cadastre clientes e volte aqui...\n");
        getchar();
    }
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                   ===================================================                     \n");
    printf("                   = = = =    CLIENTES  -  ORDEM ALFABETICA    = = = =                     \n");
    printf("                   ===================================================                     \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "NOME DO CLIENTE");
    printf("||");
    printf("%-15s", "TELEFONE");
    printf("||");
    printf("%-40s", "E-MAIL");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("\n");

    
    
    lista = NULL;
    novo_cli = (Cliente*)malloc(sizeof(Cliente));
    if (novo_cli == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Erro ao alocar a memoria!\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    while(fread(novo_cli, sizeof(Cliente), 1, fp) == 1) {
        novo_cli->prox = NULL;
        if ((lista == NULL) || (strcmp(novo_cli->nome_cli, lista->nome_cli) < 0)) {
            novo_cli->prox = lista;
            lista = novo_cli;
        } else {
            Cliente* ant = lista;
            Cliente* atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome_cli, novo_cli->nome_cli) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novo_cli;
            novo_cli->prox = atual;
        }
        novo_cli = (Cliente*)malloc(sizeof(Cliente));
        if (novo_cli == NULL) {
            printf(">>> Processando...\n");
            sleep(1);
            printf(">>> Houve um erro ao alocar a memoria!\n");
            printf(">>> Tecle <ENTER> para voltar...\n");
            getchar();
    }
  }
  fclose(fp);
  novo_cli = lista;
  while(novo_cli != NULL)  {
    //printf("\n");
    printf("%-12s", novo_cli->cpf_cli);
    printf("||");
    printf("%-40s", novo_cli->nome_cli);
    printf("||");
    printf("%-15s", novo_cli->fone_cli);
    printf("||");
    printf("%-40s", novo_cli->email_cli);
    printf("\n");
    novo_cli = novo_cli->prox;
  }
  novo_cli = lista;
  while (lista != NULL) {
    lista = lista->prox;
    free(novo_cli);
    novo_cli = lista;
  }
  fclose(fp);
  
  printf("\n");
  printf("\n");
  printf(">>> Tecle <ENTER> para voltar...\n");
  getchar();
}








void tela_relat_colab(void){
    char opcao;

    do {
        opcao = relat_colab();
        switch(opcao) {
            case '1':   relat_todos_colab();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   relat_colab_inativos();;
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   relat_colab_alfa();
                        break;
          } 		
    } while (opcao != '0');
}



char relat_colab(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///                                                                         ///\n");
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ========    RELATORIOS - COLABORADORES    =========           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. COLABORADORES ATIVOS                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            2. COLABORADORES DESLIGADOS                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            3. COLABORADORES - ORDEM ALFABETICA                          ///\n");
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



void relat_todos_colab(void) {
    FILE* fp;
    Colab* colab;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
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
    printf("-----------------------------------------------------------------------------------------------------------------------");
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
    printf("-----------------------------------------------------------------------------------------------------------------------");
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
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = =  RELATORIO | COLABORADORES DESLIGADOS   = = =                    \n");
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
    printf("-----------------------------------------------------------------------------------------------------------------------");
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
    printf("-----------------------------------------------------------------------------------------------------------------------");
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





void relat_colab_alfa(void) {
    FILE* fp = fopen("colab.dat", "rb");
    Colab* novo_colab;
    Colab* lista;
    system("clear||cls");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Erro ao abrir o arquivo!\n");
        printf(">>> Talvez ainda nao existam colaboradores para listar...\n");
        printf(">>> Cadastre colaboradores e volte aqui...\n");
        getchar();
    }
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("                                                                                                          \n");
    printf("                   ===================================================                                    \n");
    printf("                   = = =   COLABORADORES  |  ORDEM ALFABETICA    = = =                                    \n");
    printf("                   ===================================================                                    \n");
    printf("                                                                                                          \n");
    printf("                                                                                                          \n");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "COLABORADOR(A)");
    printf("||");
    printf("%-15s", "TELEFONE");
    printf("||");
    printf("%-40s", "E-MAIL");
    printf("\n");
    printf("------------------------------------------------------------------------------------------------------------");
    printf("\n");
    novo_colab = (Colab*)malloc(sizeof(Colab));
    if (novo_colab == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Erro ao alocar a memória!\n");
        printf(">>> Tecle <ENTER> para continuar...\n");
        getchar();

    }
    while(fread(novo_colab, sizeof(Colab), 1, fp) == 1) {
        novo_colab->prox = NULL;
        if ((lista == NULL) || (strcmp(novo_colab->nome_colab, lista->nome_colab) < 0)) {
            novo_colab->prox = lista;
            lista = novo_colab;
        } else {
            Colab* ant = lista;
            Colab* atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome_colab, novo_colab->nome_colab) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novo_colab;
            novo_colab->prox = atual;
        }
        novo_colab = (Colab*)malloc(sizeof(Colab));
        if (novo_colab == NULL) {
            printf(">>> Processando...\n");
            sleep(1);
            printf(">>> Houve um erro ao alocar a memória!\n");
            printf(">>> Tecle <ENTER> para continuar...\n");
            getchar();

    }
  }
  fclose(fp);
  novo_colab = lista;
  while(novo_colab != NULL) {
    printf("%-12s", novo_colab->cpf_colab);
    printf("||");
    printf("%-40s", novo_colab->nome_colab);
    printf("||");
    printf("%-15s", novo_colab->fone_colab);
    printf("||");
    printf("%-40s", novo_colab->email_colab);
    printf("\n");
    novo_colab = novo_colab->prox;
  }
  novo_colab = lista;
  while (lista != NULL) {
    lista = lista->prox;
    free(novo_colab);
    novo_colab = lista;
  }
  fclose(fp);
  printf("\n");
  printf(">>> Tecle <ENTER> para voltar...\n");
  getchar();
}








void tela_relat_prod(void){
    char opcao;

    do {
        opcao = relat_prod();
        switch(opcao) {
            case '1':   relat_todos_prod();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '2':   relat_prod_inativos();;
                        printf("\n");
                        printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '3':   relat_prod_por_marca();;
                        printf("\n");
                        //printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '4':   relat_prod_por_cor();;
                        printf("\n");
                        //printf(">>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
          } 		
    } while (opcao != '0');
}



char relat_prod(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///                                                                         ///\n");
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ===========    RELATORIOS - PRODUTOS    ===========           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. PRODUTOS - ATIVOS                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            2. PRODUTOS - INATIVOS                                       ///\n");
    printf("///                                                                         ///\n");
    printf("///            3. PRODUTOS - por MARCA                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            4. PRODUTOS - por COR                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>       Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    //printf(">>>>>>  Processando... <<<<<\n");
    sleep(1);
    return op;
 }




void relat_todos_prod(void) {
    FILE* fp;
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =   RELATORIO ||  PRODUTOS  ATIVOS    = = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("\n");
    produto = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Verifique se ja existe produto cadastrado! \n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
    }
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-14s", "CODIGO");
     printf("||");
     printf("%-40s", "DESCRICAO");
     printf("||");
     printf("%-12s", "COR");
     printf("||");
     printf("%-12s", "MARCA");
     printf("||");
     printf("%-11s", "VALOR");
     printf("||");
     printf("%-5s", "ESTOQUE");
     printf("\n");
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n"); 
     while (fread(produto, sizeof(Produto), 1, fp)) { 

        if (produto->status_p == 'a') {
          printf("%-14ld", produto->cod_p);
          printf("||");
          printf("%-40s", produto->desc_p);
          printf("||");
          printf("%-12s", produto->cor_p);
          printf("||");
          printf("%-12s", produto->marca_p);
          printf("||");
          printf("%-11.2f", produto->valor_p);
          printf("||");
          printf("%-5d", produto->quant_p);
          printf("\n");

        }
     }
     //fclose(fp);
     //free(produto);
 }






void relat_prod_inativos(void) {
    FILE* fp;
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
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
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-14s", "CODIGO");
     printf("||");
     printf("%-40s", "DESCRICAO");
     printf("||");
     printf("%-12s", "COR");
     printf("||");
     printf("%-12s", "MARCA");
     printf("||");
     printf("%-11s", "VALOR");
     printf("||");
     printf("%-5s", "ESTOQUE");
     printf("\n");
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n"); 
     while (fread(produto, sizeof(Produto), 1, fp)) { 
        if (produto->status_p == 'i') {
          printf("%-14ld", produto->cod_p);
          printf("||");
          printf("%-40s", produto->desc_p);
          printf("||");
          printf("%-12s", produto->cor_p);
          printf("||");
          printf("%-12s", produto->marca_p);
          printf("||");
          printf("%11.2f", produto->valor_p);
          printf("||");
          printf("%-5d", produto->quant_p);
          printf("\n");
        }
     }
     fclose(fp);
     free(produto);
 }










void relat_prod_por_marca(void) {
    char marca_p[12];
    printf("\nDigite a marca desejada: ");
    scanf("%11s", marca_p);
    getchar();

    FILE* fp;
    Produto produto;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =   RELATORIO || PRODUTOS POR MARCA   = = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-15s", "CODIGO");
     printf("||");
     printf("%-42s", "DESCRICAO");
     printf("||");
     printf("%-14s", "COR");
     printf("||");
     printf("%-14s", "MARCA");
     printf("||");
     printf("%-11s", "VALOR");
     printf("||");
     printf("%-7s", "ESTOQUE");
     printf("\n");
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n"); 

    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Verifique se já existe um produto cadastrado!\n");
        printf(">>> ATENCAO: Nao usar acentuacao ou caracteres especiais.\n");
        printf("\n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
        return;
    }

    int encontrou = 0; // Flag para verificar se pelo menos um produto foi encontrado



    while (fread(&produto, sizeof(Produto), 1, fp)) {
        if (produto.status_p != 'i' && strcmp(produto.marca_p, marca_p) == 0) {
            encontrou = 1; // Indica que um produto foi encontrado


            printf("%-14ld || %-40s || %-12s || %-12s || %-9.2f || %-5d\n",
                   produto.cod_p, produto.desc_p, produto.cor_p,
                   produto.marca_p, produto.valor_p, produto.quant_p);
        }
    }

    fclose(fp);

    if (!encontrou) {
        printf(">>> Nenhum produto encontrado para a marca '%s'!\n", marca_p);
        printf("\n>>> Por favor, verifique se digitou corretamente!\n");
        printf(">>> ATENCAO: Caracteres sensiveis a maiusculas e minusculas.\n");
        printf(">>> ATENCAO: Nao usar acentos ou caracteres especiais.\n");
    }

    printf("\n>>> Tecle <ENTER> para voltar ao menu... <<<\n");
    getchar();
}





void relat_prod_por_cor(void) {
      char cor_p[12];
    printf("\nDigite a COR desejada: ");
    scanf("%11s", cor_p);
    getchar();

    FILE* fp;
    Produto produto;

    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    = = = =    RELATORIO || PRODUTOS POR COR    = = = =                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-15s", "CODIGO");
     printf("||");
     printf("%-42s", "DESCRICAO");
     printf("||");
     printf("%-14s", "COR");
     printf("||");
     printf("%-14s", "MARCA");
     printf("||");
     printf("%-11s", "VALOR");
     printf("||");
     printf("%-7s", "ESTOQUE");
     printf("\n");
     printf("-----------------------------------------------------------------------------------------------------------------------");
     printf("\n"); 

    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf(">>> ERRO ao abrir o arquivo!\n");
        printf(">>> Verifique se já existe um produto cadastrado!\n");
        printf(">>> ATENCAO: Nao usar acentuacao ou caracteres especiais.\n");
        printf("\n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
        return;
    }

    int encontrou = 0; // Flag para verificar se pelo menos um produto foi encontrado

      while (fread(&produto, sizeof(Produto), 1, fp)) {
        if (produto.status_p != 'i' && strcmp(produto.cor_p, cor_p) == 0) {
            encontrou = 1; // Indica que um produto foi encontrado


            printf("%-14ld || %-40s || %-12s || %-12s || %-9.2f || %-5d\n",
                   produto.cod_p, produto.desc_p, produto.cor_p,
                   produto.marca_p, produto.valor_p, produto.quant_p);
        }
    }

    fclose(fp);

    if (!encontrou) {
        printf(">>> Nenhum produto encontrado para a marca '%s'!\n", cor_p);
        printf("\n>>> Por favor, verifique se digitou corretamente!\n");
        printf(">>> ATENCAO: Caracteres sensiveis a maiusculas e minusculas.\n");
        printf(">>> ATENCAO: Nao usar acentos ou caracteres especiais.\n");
    }

    printf("\n>>> Tecle <ENTER> para voltar ao menu... <<<\n");
    getchar();
}
 









//void relat_clientes_por_cidade(void) {
    




//void relat_colab_por_funcao(void) {
    




void tela_relat_vendas(void){
    char opcao;
    Vendas* venda_x = NULL;
    Vendas* venda_z = NULL;


    do {
        opcao = relat_vendas();
        switch(opcao) {
            case '1':   relat_todas_vendas();
                        printf("\n");
                        printf(">>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '2':   relat_vendas_exc();;
                        printf("\n");
                        printf(">>> Tecle <ENTER> para continuar...\n");
                        getchar();
                        break;
            case '3':   venda_z = malloc(sizeof(Vendas)); 
                        if (venda_z == NULL) {
                          printf("Erro ao alocar memória para venda_z!\n");
                          exit(EXIT_FAILURE); 
                        }
                        relat_vendas_cpf_cli(venda_z);
                        printf("\n");
                        printf(">>> Tecle <ENTER> para continuar...\n");
                        free(venda_z);
                        getchar();
                        break;
            case '4':   venda_x = malloc(sizeof(Vendas)); 
                        if (venda_x == NULL) {
                          printf("Erro ao alocar memória para venda_z!\n");
                          exit(EXIT_FAILURE); 
                        }
                        relat_vendas_cpf_colab(venda_x);
                        printf("\n");
                        printf(">>> Tecle <ENTER> para continuar...\n");
                        free(venda_x);
                        getchar();
                        break;
          } 		
    } while (opcao != '0');
}



char relat_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///                                                                         ///\n");
    printf("///=========================================================================///\n");
    printf("///                                                                         ///\n");
    printf("///           ============    RELATORIOS - VENDAS    ===========            ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. VENDAS - ATIVAS                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///            2. VENDAS - EXCLUIDAS                                        ///\n");
    printf("///                                                                         ///\n");
    printf("///            3. VENDAS - por CPF do CLIENTE                               ///\n");
    printf("///                                                                         ///\n");
    printf("///            4. VENDAS - por CPF do COLABORADOR                           ///\n");
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




 void relat_todas_vendas(void) {
    FILE* fp;
    Vendas* venda;
    
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    =======    RELATORIO || VENDAS REALIZADAS    ======                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
   
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Houve um erro ao abrir o arquivo!\n");
        printf(">>> Talvez ainda nao exista venda para listar...\n");
        printf(">>> Efetue uma venda e volte aqui...\n");
        getchar();
    }
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-7s", "CUPOM");
    printf("||");
    printf("%-14s", "COD. PROD.");
    printf("||");
    //printf("%-25s", "PRODUTO");
    //printf("||");
    //printf("%-25s", "CLIENTE");
    //printf("||");
    printf("%-14s", "VALOR TOTAL");
    printf("||");
    printf("%-20s", "DATA/HORA");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(venda, sizeof(Vendas), 1, fp)) { 
        if (venda->status != 'e') {
            printf("%-7s", venda->cupom);
            printf("||");
            printf("%-14ld", venda->cod_p);
            printf("||");
            //printf("%-25s", desc_p);
            //printf("||");
            //printf("%-25s", nome_cli);
            //printf("||");
            printf("R$ %-11.2f", venda->preco);
            printf("||");
            printf("%-20s", venda->dataHora);
            printf("\n");
        }
    }
    fclose(fp);
    free(venda);
    getchar();
}





void relat_vendas_exc(void) {
    FILE* fp;
    Vendas* venda;
    
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    =======    RELATORIO || VENDAS EXCLUIDAS     ======                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf("                                                                                           \n");
    
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>> Houve um erro ao abrir o arquivo!\n");
        printf(">>> Talvez ainda nao exista venda para listar...\n");
        printf(">>> Efetue uma venda e volte aqui...\n");
        getchar();
    }
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-7s", "CUPOM");
    printf("||");
    printf("%-14s", "COD. PROD.");
    printf("||");
    //printf("%-25s", "PRODUTO");
    //printf("||");
    //printf("%-25s", "CLIENTE");
    //printf("||");
    printf("%-14s", "VALOR TOTAL");
    printf("||");
    printf("%-20s", "DATA/HORA");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(venda, sizeof(Vendas), 1, fp)) { 
        if (venda->status != 'a') {
            printf("%-7s", venda->cupom);
            printf("||");
            printf("%-14ld", venda->cod_p);
            printf("||");
            //printf("%-25s", desc_p);
            //printf("||");
            //printf("%-25s", nome_cli);
            //printf("||");
            printf("R$ %-11.2f", venda->preco);
            printf("||");
            printf("%-20s", venda->dataHora);
            printf("\n");
        }
    }
    fclose(fp);
    free(venda);
    getchar();
}




void relat_vendas_cpf_cli(Vendas* venda) {
    FILE* fp;
    char* nome_cli;
    char* desc_p;
    char cpf_cli[12];
    system("clear||cls");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    ===    RELATORIO || VENDAS por CLIENTE (CPF)    ===                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf(">>>>>  Digite o CPF do Cliente: ");
    fgets(cpf_cli, 12, stdin);
    printf("\n");
    getchar();
    //venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>>  Erro na abertura do arquivo!\n");
        printf(">>>  Talvez ainda nao haja vendas neste CPF...\n");
        printf(">>> Tecle <ENTER> para voltar...\n");
        getchar();
    }
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-7s", "CUPOM");
    printf("||");
    printf("%-14s", "COD. PROD.");
    printf("||");
    printf("%-25s", "PRODUTO");
    printf("||");
    printf("%-25s", "CLIENTE");
    printf("||");
    printf("%-14s", "VALOR TOTAL");
    printf("||");
    printf("%-20s", "DATA/HORA");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(venda, sizeof(Vendas), 1, fp) == 1){
        if (strcmp(venda->cpf_cli, cpf_cli) == 0){
            nome_cli = get_cli(cpf_cli);
            desc_p = get_prod(venda->cod_p);
            printf("%-7s", venda->cupom);
            printf("||");
            printf("%-14ld", venda->cod_p);
            printf("||");
            printf("%-25s", desc_p);
            printf("||");
            printf("%-25s", nome_cli);
            printf("||");
            printf("R$ %-11.2f", venda->preco);
            printf("||");
            printf("%-20s", venda->dataHora);
            printf("\n");
        }
    }
    fclose(fp);
}






void relat_vendas_cpf_colab(Vendas* venda) {
    FILE* fp;
    char* nome_colab;
    char* desc_p;
    char cpf_colab[12];
    system("clear||cls");
    printf("\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------");
    printf("                                                                                           \n");
    printf("                    ===================================================                    \n");
    printf("                    ===   RELATORIO || VENDAS por VENDEDOR (CPF)    ===                    \n");
    printf("                    ===================================================                    \n");
    printf("                                                                                           \n");
    printf(">>>>>  Digite o CPF do Vendedor: ");
    fgets(cpf_colab, 12, stdin);
    printf("\n");
    getchar();
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
        printf(">>> Processando...\n");
        sleep(1);
        printf(">>>  Erro na abertura do arquivo!\n");
        printf(">>>  Talvez ainda nao haja vendas neste CPF...\n");
        printf(">>>  Tecle <ENTER> para voltar...\n");
        getchar();
    }
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-7s", "CUPOM");
    printf("||");
    printf("%-14s", "COD. PROD.");
    printf("||");
    printf("%-25s", "PRODUTO");
    printf("||");
    printf("%-25s", "VENDEDOR");
    printf("||");
    printf("%-14s", "VALOR TOTAL");
    printf("||");
    printf("%-20s", "DATA/HORA");
    printf("\n");
    printf("-----------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(venda, sizeof(Vendas), 1, fp) == 1){
        if (strcmp(venda->cpf_colab, cpf_colab) == 0){
            nome_colab = get_colab(cpf_colab);
            desc_p = get_prod(venda->cod_p);
            printf("%-7s", venda->cupom);
            printf("||");
            printf("%-14ld", venda->cod_p);
            printf("||");
            printf("%-25s", desc_p);
            printf("||");
            printf("%-25s", nome_colab);
            printf("||");
            printf("R$ %-11.2f", venda->preco);
            printf("||");
            printf("%-20s", venda->dataHora);
            printf("\n");
        }
    }
    fclose(fp);
    free(venda);
}









char *get_cli(const char *cpf_cli) {
  Cliente cliente;
  FILE* fp = fopen("cli.dat", "rb");

  if (fp == NULL) {
    printf(">>>   Processando...\n");
    sleep(1);
    printf(">>>   Erro ao abrir o arquivo!\n");
    printf(">>>   Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(&cliente, sizeof(cliente), 1, fp) == 1) {
    if(strcmp(cliente.cpf_cli, cpf_cli) == 0) {
      char *z = (char *)malloc(strlen(cliente.nome_cli) + 1);
      if (z == NULL) {
        printf(">>>  Ocorreu um erro.\n");
        fclose(fp);
        return NULL;
      }
      strcpy(z, cliente.nome_cli);
      fclose(fp);
      return z;
    }
  }
  fclose(fp);
  return NULL;
}




char *get_colab(const char *cpf_colab) {
  Colab colab;
  FILE* fp = fopen("colab.dat", "rb");

  if (fp == NULL) {
    printf(">>>  Processando...\n");
    sleep(1);
    printf(">>>   Erro ao abrir o arquivo!\n");
    printf(">>>   Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(&colab, sizeof(colab), 1, fp) == 1) {
    if(strcmp(colab.cpf_colab, cpf_colab) == 0) {
      char *x = (char *)malloc(strlen(colab.nome_colab) + 1);
      if (x == NULL) {
        printf(">>>  Ocorreu um erro.\n");
        fclose(fp);
        return NULL;
      }
      strcpy(x, colab.nome_colab);
      fclose(fp);
      return x;
    }
  }
  fclose(fp);
  return NULL;
}




    