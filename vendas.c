
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "vendas.h"
#include "produtos.h"
#include "relatorios.h"
#include "cliente.h"
#include "colab.h"
#include "util.h"


void ler_cupom(char*);
void ler_cpf_cli (char*);
void ler_cpf_colab (char*);
void ler_Datahora(char*);
void ler_desc_p(char*);
//void ler_desc_p(char*);



void menu_vendas(void) {
  Vendas* venda;
	char op;
	do {
		op = tela_vendas();
		switch(op) {
			case '1': 	venda = efetuar_venda();
                  grava_venda(venda);
                  free(venda);
                  //getchar();
					      	break;
			case '2': 	venda = consultar_venda();
                  exibe_venda(venda);
                  free(venda);
						      break;
			case '3': 	excluir_venda();
						      break;
      case '4': 	listar_vendas();
						      break;
			
		} 		
	} while (op != '0');
}






char tela_vendas(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = = = =       VENDAS        = = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. EFETUAR venda                                             ///\n");
    printf("///            2. PESQUISAR venda                                           ///\n");
    printf("///            3. EXCLUIR venda                                             ///\n");
    printf("///            4. LISTAR vendas                                             ///\n");
    printf("///            0. VOLTAR ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf(">>>>>>>>>      Escolha a opcao desejada: ");
    scanf(" %c", &op);
    //fflush(stdin);
  	getchar();
	  printf("\n");
    //printf(">>>>>>  Processando...  <<<<<<<\n");
    
	  return op;
}


 Vendas* efetuar_venda(void) {
    
    Vendas* venda;
    char* desc_p;
    char* nome_cli;
    char* nome_colab;
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = = =     EFETUAR  VENDA      = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("\n");
    venda = (Vendas*) malloc(sizeof(Vendas)); 
    
    printf("Codigo do Produto: ");
    scanf("%ld", &venda->cod_p);
    getchar();

    desc_p = get_prod(venda->cod_p);
    printf("Produto: %s\n", desc_p); 
    
    ler_cpf_cli(venda->cpf_cli); 
    nome_cli = get_cli(venda->cpf_cli);
    printf("Cliente: %s\n", nome_cli);

    ler_cpf_colab(venda->cpf_colab); 
    nome_colab = get_colab(venda->cpf_colab);
    printf("Vendedor(a): %s\n", nome_colab);

    
    printf("Quantidade: ");
    scanf("%d", &venda->quant_p);
    getchar();

    venda->quant_p = get_est_prod(venda->cod_p, venda->quant_p);

    venda->valor_p = get_val_prod(venda->cod_p);

    printf("Valor (un): R$ %.2f\n", venda->valor_p);
    getchar();

    venda->preco = venda->quant_p * venda->valor_p;

    printf("Valor Total: R$ %.2f\n", venda->preco);

    venda->status = 'a'; 
    ler_Datahora(venda->dataHora);
    printf("Data/Hora da Venda: %s\n", venda->dataHora);

    ler_cupom(venda->cupom);
    //printf("Digite um ID para gerar o Cupom da venda (5 dig.) : ");
    //scanf("%d", &venda->cupom);
    //getchar();
     
    printf("                               Venda Efetivada!                                \n");
    sleep(1);
    printf("===============================================================================\n");
    printf("                  Tecle <ENTER> para voltar ao menu anterior...                \n");
    printf("\n");
    //sleep(1);
    getchar();
    return venda;
}




Vendas* consultar_venda(void) {
    FILE* fp;
    Vendas* venda;
    char cupom[6];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = = =    CONSULTAR  VENDA     = = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("\n");
    printf(">>>>  Digite o ID da venda (cupom) para consultar: ");
    //scanf("%d", &cupom);
    fgets (cupom, 6, stdin);
    getchar();
    //printf("\n");
    venda = (Vendas*) malloc(sizeof(Vendas));
    fp = fopen("vendas.dat", "rb");
    if (fp == NULL) {
      printf(">>>   Erro na abertura do arquivo!   <<<\n");
      printf(">>>   Talvez ainda nao exista venda efetuada...   <<<\n");
      printf(">>>   Efetue uma venda e volte aqui...   <<<\n");
      printf(">>>   Tecle <ENTER> para voltar...   <<<\n");
      getchar();
    } else {
        while(fread(venda, sizeof(Vendas), 1, fp) == 1) {
        //while(!feof(fp)) {
            fread(venda, sizeof(Vendas), 1, fp);
            if((strcmp(venda->cupom, cupom) == 0) && (venda->status != 'e')) {
            //if(venda->cupom == cupom) {
              exibe_venda(venda);
              printf("===============================================================================\n");
              printf("                 Tecle <ENTER> para voltar ao menu anterior...                 \n");
              getchar();
              fclose(fp);
              free(venda);
              return venda;
            } 
        }
    }
    fclose(fp);
    free(venda); 
    return NULL;
}



void excluir_venda(void) {
  //int cupom;
  char cupom[6];
  Vendas* venda = (Vendas*) malloc(sizeof(Vendas));
  FILE* fp;
  int achado = 0;
  system("clear||cls");
  printf("\n");
  printf("///////////////////////////////////////////////////////////////////////////////\n");
  printf("///                                                                         ///\n");
  printf("///           ===================================================           ///\n");
  printf("///           = = = = = = =     EXCLUIR  VENDA      = = = = = = =           ///\n");
  printf("///           ===================================================           ///\n");
  printf("\n");
  printf(">>>>  Digite o ID da venda (cupom) para excluir: ");
  fgets(cupom, 6, stdin);
  //scanf("%d", &cupom);
  getchar();
  fp = fopen("vendas.dat", "r+b");
 
  if (fp == NULL) {
    printf(">>>  Processando...  <<<\n");
    sleep(1);
    printf(">>>   Erro na abertura do arquivo!    <<<\n");
    printf(">>>   Nao foi possivel continuar...   <<<\n");
    printf(">>>   Tecle <ENTER> para voltar...    <<<\n");
    getchar();
  } else {
    while (fread(venda, sizeof(Vendas), 1, fp) == 1) {
      //while(venda->cupom == cupom) {
      if(strcmp(venda->cupom, cupom) == 0) {
        printf("\n");
        printf("================================ \n");
        printf(">>>    Venda Encontrada! \n");
        printf("\n");
        venda->status = 'e';
        fseek(fp, -sizeof(Vendas), SEEK_CUR);
        fwrite(venda, sizeof(Vendas), 1, fp);
        achado = 1;
        break;
      }
    }
  }
  if (!achado) {
      printf("\n");
      printf(">>>  Cupom Fiscal  encontrado!  <<<\n");
  } else {
      printf("\n");
      exibe_venda(venda);
      printf("\n");
      printf("====================================   <<<\n");
      printf(">>>  Venda excluida com sucesso!       <<<\n");
  }
  getchar();
  printf("\n");
  printf(">>>  Tecle <ENTER> para continuar...   <<<\n");
  getchar();
  fclose(fp);
}



// Funcoes aux


void ler_cupom (char* cupom) {
    fflush(stdin);
    printf("Digite um ID para gerar o cupom da venda (5 dig.): ");
    fgets (cupom, 6, stdin);
    while (!validarCupom (cupom)) {
       printf("Erro! Digite novamente: ");
       fgets (cupom, 6, stdin);
    }
    getchar();
}


//void ler_cpf_cli (char* cpf) {
   // fflush(stdin);
   // printf("Digite o CPF (apenas numeros): ");
   // fgets (cpf, 12, stdin);
   // while (!validarCpf (cpf)) {
       // printf("Erro! Digite novamente: ");
       // fgets (cpf, 12, stdin);
    //}
    //getchar();
//}



void grava_venda(Vendas* venda) {
  FILE* fp;
  fp = fopen("vendas.dat", "ab");
  if (fp == NULL) {
    printf(">>> Processando...\n");
    sleep(1);
    printf(">>> Erro!\n");
    printf(">>> Não foi possivel continuar...\n");
    getchar();
  }
  fwrite(venda, sizeof(Vendas), 1, fp);
  fclose(fp);
}



void ler_Datahora(char* dataHora) {
    time_t tempoAtual;
    struct tm *infoTempo;
    time(&tempoAtual);
    infoTempo = localtime(&tempoAtual);
    strftime(dataHora, 20, "%d/%m/%Y %H:%M:%S", infoTempo);
}




void listar_vendas(void) {
  FILE* fp;
  Vendas* venda;
  system("clear||cls");
  printf("\n ======================   TODAS AS VENDAS   ===================== \n");
  venda = (Vendas*) malloc(sizeof(Vendas));
  system("clear||cls");
  fp = fopen("vendas.dat", "rb");
  if (fp == NULL) {
    printf(">>>   Erro na abertura do arquivo!/n");
    printf(">>>   Talvez ainda nao exista vendas efetuadas...\n");
    printf(">>>   Efetue uma venda e volte aqui...\n");
    exit(1);
  }
  while (fread(venda, sizeof(Vendas), 1, fp)) { 
    if (venda->status != 'e') {
      exibe_venda(venda);
      printf(">>>  Tecle <ENTER> para continuar...\n");
      getchar();
    }
  }
  fclose(fp);
  free(venda);
}







void exibe_venda(Vendas *venda) {
     char situacao[20];
     
     //printf("===============================================================================\n");
     //printf("                                                                               \n");
  if ((venda == NULL) || (venda->status == 'e')) {
       printf("\n >>>  Cupom nao encontrado!  <<<\n");
       printf("\n");
       printf(">>>   Tecle <ENTER> para continuar...   <<<\n");
       getchar();
  } else {
       printf("=================================================================\n");
       printf("\n");
       printf(">>> CUPOM FISCAL: ");
       printf("%s" , venda->cupom);
       printf("\n");
       printf(">>> CPF/CLIENTE: ");
       printf("%s" ,venda->cpf_cli);
       printf("\n");
       printf(">>> CPF/VEND.: ");
       printf("%s" ,venda->cpf_colab);
       printf("\n");
       printf(">>> COD. PRODUTO: ");
       printf("%ld" ,venda->cod_p);
       printf("\n");
       printf(">>> QUANTIDADE: ");
       printf("%d" ,venda->quant_p);
       printf("\n");
       printf(">>> VALOR UN: ");
       printf("%.2f" ,venda->valor_p);
       printf("\n");
       printf(">>> VALOR TOTAL: ");
       printf("%.2f" ,venda->preco);
       printf("\n");
       printf(">>> DATA/HORA: ");
       printf("%s" ,venda->dataHora);
       printf("\n");
    if (venda->status == 'a') {
       strcpy(situacao, "Ativa");
    } else {
       strcpy(situacao, "Excluida");
    }
    printf(">>> STATUS DA VENDA: %s\n", situacao);
    printf("\n");
  }   
}




//Funcao inspirada nos Cods de: https://github.com/AronSilva04  e  https://github.com/maricaico
char* get_prod(const long int cod_p) {
   Produto produto;
   FILE* fp = fopen("produtos.dat", "rb");
   if (fp == NULL) {
     printf(">>> Processando...\n");
     sleep(1);
     printf(">>> Houve um erro ao abrir o arquivo!\n");
      printf(">>> Talvez nao exista produto com esse codigo!\n");
     printf(">>> Tecle <ENTER> para voltar...\n");
     getchar();
   }
   while (fread(&produto, sizeof(produto), 1, fp) == 1) {
     if(produto.cod_p == cod_p) { 
       char* x = (char*)malloc(strlen(produto.desc_p) + 1);
       if (x == NULL) {
       printf("Ocorreu um erro....\n");
       fclose(fp);
       return NULL;
     }
     strcpy(x, produto.desc_p);
     fclose(fp);
     return x;
      
    }
   }
   fclose(fp);
   return NULL;
}



//Funcao inspirada nos Cods de: https://github.com/AronSilva04  e  https://github.com/maricaico

int get_est_prod(long int cod_p, int quant_p) {
  Produto* produto;
  FILE* fp = fopen("produtos.dat", "r+b");

  if (fp == NULL) {
    printf(">>>  Processando...  <<<\n");
    sleep(1);
    printf(">>>  Houve um erro ao abrir o arquivo!   <<<\n");
    printf(">>>  Tecle <ENTER> para continuar...   <<<\n");
    getchar();
  }
  produto = (Produto*) malloc(sizeof(Produto));
  while (fread(produto, sizeof(Produto), 1, fp) == 1) {
     if (produto->cod_p == cod_p) {
      if (produto->quant_p == 0) {
        printf(">>>  Produto zerado!   <<<");
        printf("\n>>>  Venda Cancelada!  <<<\n");
        fclose(fp);
        return 0;
      }
      else if (quant_p > produto->quant_p) {
        do {
          printf("A quantidade excede o estoque! Estoque atual: %d\n", produto-> quant_p);
          printf("Quantidade: ");
          scanf("%d", &quant_p);
          getchar();
        }while (quant_p > produto->quant_p);
      }
      produto->quant_p -= quant_p;
      fseek(fp, -sizeof(Produto), SEEK_CUR);
      fwrite(produto, sizeof(Produto), 1, fp);
    }
  }
  fclose(fp);
  return quant_p;
}



//Funcao inspirada nos Cods de: https://github.com/AronSilva04  e  https://github.com/maricaico

float get_val_prod(long int cod_p) {
  Produto* produto;
  float valor_p;
  FILE* fp = fopen("produtos.dat", "rb");
  if (fp == NULL) {
    printf(">>>   Processando...   <<<\n");
    sleep(1);
    printf(">>>   Houve um erro ao abrir o arquivo!   <<<\n");
    printf(">>>   Tecle <ENTER> para continuar...   <<<\n");
    getchar();
  }
  produto = (Produto*) malloc(sizeof(Produto));
  while (fread(produto, sizeof(Produto), 1, fp) == 1) {
    if (produto->cod_p == cod_p) {
      valor_p = produto->valor_p;
      fclose(fp);
      free(produto);
      return valor_p;
    }
  }
  fclose(fp);
  free(produto);
  return 0;
}








