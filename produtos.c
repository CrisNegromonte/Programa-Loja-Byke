#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "produtos.h"
#include "util.h"


// Funcoes
void ler_cod(char*);
void ler_desc(char*);
void ler_marca(char*);
void ler_cor(char*);
void ler_quant(int*);
void ler_valor(float*);


void menu_produtos(void) {
    Produto* produto;
	char op;
	do {
		op = tela_produtos();
		switch(op) {
			case '1': 	produto = cadastrar_produto();
                  grava_prod(produto);
					 	      break;
			case '2': 	produto = pesquisar_produto();
                  exibe_prod(produto);
                  break;
			case '3': 	alterar_produto();
						      break;
			case '4': 	excluir_produto();
						      break;
      case '5':   lista_prod();
                  getchar();
                  break;
		} 		
	} while (op != '0');
}


char tela_produtos(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///             Developed by @CrisNegromonte -- since Ago, 2023             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = = = =    TELA PRODUTOS    = = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR novo produto                                    ///\n");
    printf("///            2. PESQUISAR um produto                                      ///\n");
    printf("///            3. ATUALIZAR um produto                                      ///\n");
    printf("///            4. EXCLUIR um produto                                        ///\n");
    printf("///            5. LISTAR todos os produtos                                  ///\n");
    printf("///            0. VOLTAR ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>>>      Escolha a opcao desejada: ");
    scanf("%c", &op);
  	getchar();
	  printf("\n");
    printf(">>>>>>  Processando...  <<<<<<<\n");
    sleep(1);
	  return op;
}

Produto* cadastrar_produto(void) {
    Produto* produto;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///             Developed by @CrisNegromonte -- since Ago, 2023             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///             = = = = = = =  CADASTRAR PRODUTO  = = = = = = =             ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    produto = (Produto*) malloc(sizeof(Produto));
    ler_cod(produto->cod);
    ler_desc(produto->desc);
    ler_cor(produto->cor);
    ler_marca(produto->marca);
    ler_quant(&(produto->quant));
    ler_valor(&(produto->valor));
    produto->status = 'a';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf(">>>  Realizando cadastro...  <<<\n");
    sleep(1);
    printf(">>>  Cadastro efetivado!  <<<\n");
    printf(">>>  Tecle <ENTER> para voltar ao menu...  <<<\n");
    getchar();
    return produto;
}



Produto* pesquisar_produto(void) {
    FILE* fp;
    Produto* produto;
    char cod[14];
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
    printf("///           = = = = = = =    PESQUISAR PRODUTO    = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>>>  Digite o Codigo de Barras (13 numeros): ");
    //getchar();
    fgets (cod, 14, stdin);
    getchar();
    produto = (Produto*) malloc(sizeof(Produto));
    fp = fopen("produtos.dat", "rb");
    if (fp == NULL) {
      printf(">>>  ERRO na busca!  <<<\n");
      printf(">>>  Talvez ainda nao exista produto cadastrado!  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
      printf(">>>  Tecle <ENTER> para sair...  <<<\n");
      getchar();
    } else {
         while(!feof(fp)) {
          fread(produto, sizeof(Produto), 1, fp);
          if((strcmp(produto->cod, cod) == 0) && (produto->status != 'i')) {
            exibe_prod(produto);
            printf(">>>  Tecle <ENTER> para continuar... <<<\n");
            getchar();
            fclose(fp);
            free(produto);
            return produto;
          } 
         }
    }
    fclose(fp);
    free(produto); 
    return NULL;
}
           


void alterar_produto(void) {
    char cod[14];
    Produto* produto = (Produto*) malloc(sizeof(Produto));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          ==========  SISTEMA LOJA DE BICICLETAS   ==========            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          ===================================================            ///\n");
    printf("///          = = = = = = = =   ALTERAR PRODUTO   = = = = = = = =            ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>   Digite o codigo de barras (13 numeros):\n");
    fgets(cod, 14, stdin);
    getchar();
    fp = fopen("produtos.dat", "r+b");
    if (fp == NULL) {
      printf(">>>   Processando...  <<<\n");
      sleep(1);
      printf(">>>  ERRO na busca!  <<<\n");
      printf(">>>  Talvez ainda nao exista produto cadastrado!  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
      printf(">>>  Tecle <ENTER> para sair...  <<<\n");
      getchar();
    } else {
      while (fread(produto, sizeof(Produto), 1, fp) == 1) {
        if(strcmp(produto->cod, cod) == 0) {
          printf("\n");
          printf(">>>  PRODUTO ENCONTRADO!  <<<\n");
          printf(">>>  Atualize o cadastro  <<<\n");
          printf("\n");
          ler_desc(produto->desc);
          ler_cor(produto->cor);
          ler_marca(produto->marca);
          ler_quant(&(produto->quant));
          ler_valor(&(produto->valor));
          produto->status = 'a';
          fseek(fp, -sizeof(Produto), SEEK_CUR);
          fwrite(produto, sizeof(Produto), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf(">>>   Codigo nao encontrado!   <<<\n");
    } else {
        printf("\n");
        printf(">>>   Produto atualizado com sucesso!   <<<\n");
    }
  printf("\n");
  sleep(1);
  printf(">>>  Tecle <ENTER> para voltar ao menu...\n");
  getchar();
  fclose(fp);
  free(produto);
}



void excluir_produto(void) {
    char cod[14];
    Produto* produto = (Produto*) malloc(sizeof(Produto));
    FILE* fp;
    int sim = 0;
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
    printf("///           = = = = = = = =   EXCLUIR PRODUTO   = = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>  Digite o codigo de barras (13 numeros): \n");
    fgets(cod, 14, stdin);
    getchar();
    fp = fopen("produtos.dat", "r+b");
    if (fp == NULL) {
       printf(">>>   Processando as informacoes...   <<<\n");
       sleep(1);
       printf(">>>  ERRO na busca!  <<<\n");
       printf(">>>  Talvez ainda nao exista produto cadastrado!  <<<\n");
       printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
       printf(">>>  Tecle <ENTER> para sair...  <<<\n");
       getchar();
    } else {
      while (fread(produto, sizeof(Produto), 1, fp) == 1) {
        if(strcmp(produto->cod, cod) == 0) {
          printf("\n");
          printf(">>>>  PRODUTO ENCONTRADO!   <<<<\n");
          printf("\n");
          produto->status = 'i';
          fseek(fp, -sizeof(Produto), SEEK_CUR);
          fwrite(produto, sizeof(Produto), 1, fp);
          sim = 1;
          break;
      }
    }
  }
  if (!sim) {
      printf("\n");
      printf(">>>>  Codigo nao encontrado!  <<<< \n");
  } else {
      printf("\n");
      printf(">>>>  Excluido com sucesso!  <<<< \n");
  }
  getchar();
  printf("\n");
  printf(">>>  Tecle <ENTER> para voltar ao menu...\n");
  getchar();
  fclose(fp);
  free(produto);
}




void exibe_prod(Produto *produto) {
    char sit[20];                                                                       ///\n");
    if ((produto == NULL) || (produto->status == 'i')) {
      printf("\n>>>  Produto nao encontrado!  <<<\n");
      printf("\n");
      printf(">>>  Tecle <ENTER> para sair... <<<\n");
      getchar();
    } else {
      printf("============================================================= ");
      printf("\n");
      printf("|| DESCRICAO: ");
      printf("%s" ,produto->desc);
      printf("\n");
      printf("|| CODIGO: ");
      printf("%s" ,produto->cod);
      printf("\n");
      printf("|| COR: ");
      printf("%s" ,produto->cor);
      printf("\n");
      printf("|| MARCA: ");
      printf("%s" ,produto->marca);
      printf("\n");
      printf("|| QUANTIDADE: ");
      printf("%d" ,produto->quant);
      printf("\n");
      printf("|| VALOR: ");
      printf("%.2f" ,produto->valor);
      printf("\n");
      if (produto->status == 'a') {
      strcpy(sit, "Produto Ativo");
      } else {
      strcpy(sit, "Produto Inativo");
    }
    printf("Status do produto: %s\n", sit);
    printf("\n");
  }   
}



// Funcoes adaptadas no codigo do Professor Flavius

void ler_desc(char* desc) {
    fflush(stdin);
    printf("Descricao do produto (sem acentos): ");
    fgets(desc, 40, stdin); 
    int tam = strlen(desc);
    if (tam > 0 && desc[tam - 1] == '\n') {  
        desc[tam - 1] = '\0';
        fflush(stdin);
    }
    while (!validarDesc(desc)) {
        printf("Descricao invalida: %s\n", desc);
        printf("Informe novamente a descricao (sem acentos): ");
        fflush(stdin);
        fgets(desc, 40, stdin); 
        // Remove o caractere de nova linha do final, caso exista
        tam = strlen(desc);
        if (tam > 0 && desc[tam - 1] == '\n') {
            desc[tam - 1] = '\0';
            fflush(stdin);
    }
  } 
}




void ler_cod (char* cod) {
    fflush(stdin);
    printf("Digite o Codigo de Barras (13 digitos): ");
    fgets (cod, 14, stdin);
    while (!validarCod (cod)) {
        printf("Erro no codigo! Digite o codigo com 13 digitos: ");
        fgets (cod, 14, stdin);
    }
    getchar();
}



void ler_cor(char* cor) {
    fflush(stdin);
    printf("Digite a cor do produto (sem acentos): ");
    fgets(cor, 12, stdin); 
    int tam = strlen(cor);
    if (tam > 0 && cor[tam - 1] == '\n') {  
        cor[tam - 1] = '\0';
        fflush(stdin);
    }
    while (!validarDesc(cor)) {
        printf("Cor invalida: %s\n", cor);
        printf("Informe novamente a cor do produto (sem acentos): ");
        fflush(stdin);
        fgets(cor, 12, stdin); 
        // Remove o caractere de nova linha do final, caso exista
        tam = strlen(cor);
        if (tam > 0 && cor[tam - 1] == '\n') {
            cor[tam - 1] = '\0';
            fflush(stdin);
    }
  } 
}




void ler_marca(char* marca) {
    fflush(stdin);
    printf("Digite a marca do produto (sem acentos): ");
    fgets(marca, 12, stdin); 
    int tam = strlen(marca);
    if (tam > 0 && marca[tam - 1] == '\n') {  
        marca[tam - 1] = '\0';
        fflush(stdin);
    }
    while (!validarDesc(marca)) {
        printf("Marca invalida: %s\n", marca);
        printf("Informe novamente a marca (sem acentos): ");
        fflush(stdin);
        fgets(marca, 12, stdin); 
        // Remove o caractere de nova linha do final, caso exista
        tam = strlen(marca);
        if (tam > 0 && marca[tam - 1] == '\n') {
            marca[tam - 1] = '\0';
            fflush(stdin);
    }
  } 
}



void ler_quant(int* quant) {
    printf("Quantidade: ");
    scanf("%d", quant);
    getchar();
}



void ler_valor(float* valor) {
    printf("Digite o valor: R$ ");
    scanf("%f", valor);
    getchar();
}


void grava_prod(Produto* produto) {
  FILE* fp;
  fp = fopen("produtos.dat", "ab");
  if (fp == NULL) {
    printf(">>> Processando as informacoes...  <<<\n");
    sleep(1);
    printf(">>> ERRO !  <<<\n");
    printf(">>> Nao foi possivel continuar... <<<<\n");
    printf(">>>  Tecle <ENTER> para sair... <<<\n");
    getchar();
  }
  fwrite(produto, sizeof(Produto), 1, fp);
  fclose(fp);
}



void lista_prod(void) {
  FILE* fp;
  Produto* produto;
  system("clear||cls");
  printf("//////////////////////////////////////////////////////////////");
  printf("\n");
  printf("=============================================================\n");
  printf("  = = = = = = = =   LISTA PRODUTOS ATIVOS    = = = = = = =   \n");
  printf("=============================================================\n");
  printf("\n");
  produto = (Produto*) malloc(sizeof(Produto));
  fp = fopen("produtos.dat", "rb");
  if (fp == NULL) {
    printf(">>>  Erro na abertura!  <<<\n");
    printf(">>>  Ainda nao exista produto cadastrado!  <<<\n");
    printf(">>>  Cadastre um produto e volte aqui...  <<<\n");
    printf(">>>  Tecle <ENTER> para sair... <<<\n");
    getchar();
  }
  while (fread(produto, sizeof(Produto), 1, fp)) { 
    if (produto->status != 'i') {
      exibe_prod(produto);
    }
  }
  fclose(fp);
  free(produto);
}
