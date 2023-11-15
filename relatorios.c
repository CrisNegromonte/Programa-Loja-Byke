#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "relatorios.h"
#include "cliente.h"
#include "vendedor.h"
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
            case '2':   relat_todos_vendedores();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
                        getchar();
                        break;
            case '3':   relat_todos_produtos();
                        printf("\n");
                        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
                        getchar();
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
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = =       SISTEMA LOJA DO CICLISTA      = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =   TELA RELATORIOS   = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Relatorio de Todos os Clientes                            ///\n");
    printf("///            2. Relatorio de Todos os Vendedores                          ///\n");
    printf("///            3. Relatorio de Todos os Produtos                            ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>>>>> Processando... <<<<<<<\n");
    sleep(1);
    return op;
 }


void relat_todos_clientes(void) {
    FILE* fp;
    Cliente* cliente;
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("||                                                                                                                 ||\n");
    printf("||                                = = = = = = = = = = = = = = = = = = = = = = = =                                  ||\n");
    printf("||                                = = =   RELATORIO || TODOS OS CLIENTES    = = =                                  ||\n");
    printf("||                                = = = = = = = = = = = = = = = = = = = = = = = =                                  ||\n");
    printf("||                                                                                                                 ||\n");
    printf("||                                                                                                                 ||\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
      printf("\t\t\t>>>>>>>>  Processando...   <<<<<<<<\n");
      sleep(1);
      printf("\t\t\t>>> ERRO ao abrir o arquivo!\n");
      printf("\t\t\t>>> Verifique se ja existe cliente cadastrado! \n");
      printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
      getchar();
    }
    printf("---------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "CLIENTE");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC.");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(cliente, sizeof(Cliente), 1, fp)) { 
      if (cliente->status != 'i') {
        printf("%-12s", cliente->cpf);
        printf("||");
        printf("%-40s", cliente->nome);
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



void relat_todos_vendedores(void) {
    FILE* fp;
    Vendedor* vendedor;
    system("clear||cls");
    printf("\n");
    printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\n");
    printf("||                                                                                                                 ||\n");
    printf("||                                = = = = = = = = = = = = = = = = = = = = = = = =                                  ||\n");
    printf("||                                = =   RELATORIO || TODOS OS VENDEDORES(AS)  = =                                  ||\n");
    printf("||                                = = = = = = = = = = = = = = = = = = = = = = = =                                  ||\n");
    printf("||                                                                                                                 ||\n");
    printf("||                                                                                                                 ||\n");
    vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    fp = fopen("vendedor.dat", "rb");
    if (fp == NULL) {
      printf("\t\t\t>>>>>>>>  Processando...   <<<<<<<<\n");
      sleep(1);
      printf("\t\t\t>>> ERRO ao abrir o arquivo!\n");
      printf("\t\t\t>>> Verifique se ja existe vendedor(a) cadastrado(a)! \n");
      printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
      getchar();
    }
    printf("---------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("%-12s", "CPF");
    printf("||");
    printf("%-40s", "VENDEDOR(A)");
    printf("||");
    printf("%-12s", "TELEFONE");
    printf("||");
    printf("%-11s", "DATA NASC.");
    printf("||");
    printf("%-33s", "E-MAIL");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------------------");
    printf("\n");
    while (fread(vendedor, sizeof(Vendedor), 1, fp)) { 
      if (vendedor->status != 'i') {
        printf("%-12s", vendedor->cpf);
        printf("||");
        printf("%-40s", vendedor->nome);
        printf("||");
        printf("%-12s", vendedor->fone);
        printf("||");
        printf("%-11s", vendedor->nasc);
        printf("||");
        printf("%-33s", vendedor->email);
        printf("\n");
      }
    }
   fclose(fp);
   free(vendedor);
}




void relat_todos_produtos(void) {
    FILE* fp;
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("||///////////////////////////////////////////////////////////////////////////////////////////////||\n");
    printf("||                                                                                               ||\n");
    printf("||                      = = = = = = = = = = = = = = = = = = = = = = = =                          ||\n");
    printf("||                      = = =   RELATORIO || TODOS OS PRODUTOS    = = =                          ||\n");
    printf("||                      = = = = = = = = = = = = = = = = = = = = = = = =                          ||\n");
    printf("||                                                                                               ||\n");
    printf("||                                                                                               ||\n");
    produto = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
        printf("\t\t\t>>> Processando...\n");
        sleep(1);
        printf("\t\t\t>>> ERRO ao abrir o arquivo!\n");
        printf("\t\t\t>>> Verifique se ja existe produto cadastrado! \n");
        printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
        getchar();
    }
     printf("---------------------------------------------------------------------------------------------------");
     printf("\n");
     printf("%-14s", "CODIGO");
     printf("||");
     printf("%-35s", "DESCRICAO");
     printf("||");
     printf("%-12s", "COR");
     printf("||");
     printf("%-12s", "MARCA");
     printf("||");
     printf("%-9s", "VALOR");
     printf("||");
     printf("%-5s", "ESTOQUE");
     printf("\n");
     printf("---------------------------------------------------------------------------------------------------");
     printf("\n"); 
     while (fread(produto, sizeof(Produto), 1, fp)) { 
        if (produto->status != 'i') {
          printf("%-14s", produto->cod);
          printf("||");
          printf("%-35s", produto->desc);
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


