#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "vendedor.h"
#include "util.h"

//////
////// Funções
//////
void ler_cpf_v (char*);
void ler_nome_v (char*);
void ler_email_v (char*);
void ler_nasc_v (char*);
void ler_fone_v (char*);


void menu_vendedores(void) {
  Vendedor* vendedor;
	char op;
	do {
		op = tela_vendedores();
		switch(op) {
			case '1': 	vendedor = cadastrar_vendedor();
                  grava_vendedor(vendedor);
					      	break;
			case '2': 	vendedor = pesquisar_vendedor();
                  exibe_vendedor(vendedor);
						      break;
			case '3': 	alterar_vendedor();
						      break;
			case '4': 	excluir_vendedor();
					      	break;
      case '5':   lista_vendedores();
                  getchar();
                  break;
		} 		
	} while (op != '0');
}



char tela_vendedores(void) {
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
    printf("///            = = = = = = = =   MENU VENDEDOR   = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo vendedor                                ///\n");
    printf("///            2. Pesquisar os dados de um vendedor                         ///\n");
    printf("///            3. Atualizar o cadastro de um vendedor                       ///\n");
    printf("///            4. Excluir um vendedor do sistema                            ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
    scanf("%c", &op);
	  getchar();
  	printf("///                                                                        ///\n");
	  printf("///                                                                        ///\n");
  	printf("//////////////////////////////////////////////////////////////////////////////\n");
  	printf("\n");
  	// delay(1);
	  return op;
}

Vendedor* cadastrar_vendedor(void) {
    Vendedor* vendedor;

    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = =     SISTEMA LOJA DO CICLISTA    = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =  CADASTRAR VENDEDOR   = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");

    vendedor = (Vendedor*) malloc(sizeof(Vendedor));

    ler_cpf_v(vendedor->cpf);

    ler_nome_v(vendedor->nome);

    ler_email_v(vendedor->email);

    ler_nasc_v(vendedor->nasc);

    ler_fone_v(vendedor->fone);

    vendedor-> status = 'a';
   
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return vendedor;
}


Vendedor* pesquisar_vendedor(void) {
    FILE* fp;
    Vendedor* vendedor;
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = = =  SISTEMA LOJA DO CICLISTA   = = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =  PESQUISAR VENDEDOR = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
    fgets (cpf, 12, stdin);
    getchar();
    vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    fp = fopen("vendedor.dat", "rb");
    if (fp == NULL) {
      printf("Erro na abertura do arquivo!\n");
      printf("Nao foi possivel continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
        while(!feof(fp)) {
          fread(vendedor, sizeof(Vendedor), 1, fp);
          if((strcmp(vendedor->cpf, cpf) == 0) && (vendedor->status != 'i')) {
            exibe_vendedor(vendedor);
            printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(fp);
            free(vendedor);
            return vendedor;
          } 
        }
    }
    fclose(fp);
    free(vendedor);
    return NULL;
}


void alterar_vendedor(void) {
    char cpf[12];
    Vendedor* vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = = = SISTEMA LOJA DO CICLISTA   = =  = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =  ALTERAR VENDEDOR   = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
    fgets(cpf, 12, stdin);
    getchar();
    fp = fopen("vendedor.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informações...\n");
      sleep(1);
      printf("\t\t\t*** Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Nao foi possivel continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(vendedor, sizeof(Vendedor), 1, fp) == 1) {
        if(strcmp(vendedor->cpf, cpf) == 0) {
          printf("\n");
          printf("\t\t\t*** Vendedor Encontrado ***\n");
          printf("\t\t\t*** Atualize o Cadastro ***\n");
          printf("\n");
          ler_cpf_v(vendedor->cpf);
          ler_nome_v(vendedor->nome);
          ler_email_v(vendedor->email);
          ler_nasc_v(vendedor->nasc);
          ler_fone_v(vendedor->fone);
          vendedor-> status = 'a';
          fseek(fp, -sizeof(Vendedor), SEEK_CUR);
          fwrite(vendedor, sizeof(Vendedor), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf("\t\t\t CPF nao encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\t Vendedor atualizado com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
  free(vendedor);
}



void excluir_vendedor(void) {
    char cpf[12];
    Vendedor* vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = = =  SISTEMA LOJA DO CICLISTA   = = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =  EXCLUIR  VENDEDOR  = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
    fgets(cpf, 12, stdin);
    getchar();
    fp = fopen("vendedor.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t*** Processando as informacoes...\n");
      sleep(1);
      printf("\t\t\t*** Erro na abertura do arquivo!\n");
      printf("\t\t\t*** Nao foi possivel continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(vendedor, sizeof(Vendedor), 1, fp) == 1) {
        if(strcmp(vendedor->cpf, cpf) == 0) {
          printf("\n");
          printf("\t\t\t*** Vendedor Encontrado ***\n");
          printf("\n");
          vendedor->status = 'i';
          fseek(fp, -sizeof(Vendedor), SEEK_CUR);
          fwrite(vendedor, sizeof(Vendedor), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf("\t\t\t Vendedor nao encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\t Vendedor excluido com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
  free(vendedor);
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio

void ler_cpf_v (char* cpf) {
    fflush(stdin);
    printf("Digite o CPF (somente numeros): ");
    fgets (cpf, 12, stdin);
    while (!validarCpf (cpf)) {
        printf("Invalido! Digite um CPF valido (somente numeros): ");
        fgets (cpf, 12, stdin);
    }
    getchar();
}

// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_nome_v (char* nome) {
  fflush(stdin);
  printf("Digite o nome: ");
  fgets(nome, 50, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(nome);
  if (tam > 0 && nome[tam - 1] == '\n') {
    nome[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome)) {
    printf("Nome invalido: %s\n", nome);
    printf("Informe um nome valido (somente caracteres): ");
    fflush(stdin);
    fgets(nome, 50, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(nome);
    if (tam > 0 && nome[tam - 1] == '\n') {
      nome[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_email_v (char* email) {
    fflush(stdin);
    printf("Digite o email: ");
    fgets(email, 40, stdin);
    while (!validarEmail(email)) {
        printf("Erro! Digite novamente um email valido: ");
        fgets(email, 40, stdin);
        fflush(stdin);
    }
}


// Funcao feita parcialmente pelo chat GPT, adaptada por mim
void ler_nasc_v (char* nasc) {
  int dia, mes, ano;
  char dd[3], mm[3], aaaa[5];

  while (1) {
    fflush(stdin);
    printf("Data de nascimento (dia/mes/ano - dd/mm/aaaa): ");
    fgets(nasc, 11, stdin);

    // Verificar o formato da data
    if (sscanf(nasc, "%2[^/]/%2[^/]/%4[^/]", dd, mm, aaaa) == 3) {
      // Converter partes para inteiros
      sscanf(dd, "%d", &dia);
      sscanf(mm, "%d", &mes);
      sscanf(aaaa, "%d", &ano);

      if (validarData(dia, mes, ano) && strlen(aaaa) == 4) {
        break;  // Data valida fornecida pelo usuário com um ano de quatro digitos
      } else {
        printf("Data invalida: %d/%d/%d\n", dia, mes, ano);
        printf("Informe uma data valida no formato dd/mm/aaaa:\n\n");
      }
    } else {
      printf("Formato de data invalido. Use o formato dd/mm/aaaa.\n");
    }
  }
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_fone_v (char* fone) {
    fflush (stdin);
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone, 12, stdin);

    while (!validarFone (fone)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone, 12, stdin);
    
    }
} 

void grava_vendedor(Vendedor* vendedor) {
  FILE* fp;
  fp = fopen("vendedor.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando as informacoes...\n");
    sleep(1);
    printf("\t\t\t>>> Erro! Nao foi possivel continuar! \n");
    getchar();
  }
  fwrite(vendedor, sizeof(Vendedor), 1, fp);
  fclose(fp);
  free(vendedor);
}



void lista_vendedores(void) {
  FILE* fp;
  Vendedor* vendedor;
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = = =  SISTEMA LOJA DO CICLISTA   = = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = =  Lista de Vendedores  = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n"); 
    printf("///                                                                         ///\n");
    vendedor = (Vendedor*) malloc(sizeof(Vendedor));
    fp = fopen("vendedor.dat", "rb");
    if (fp == NULL) {
    printf("Erro na abertura do arquivo!/n");
    printf("Nao foi possivel continuar...\n");
    exit(1);
  }
  while (fread(vendedor, sizeof(Vendedor), 1, fp)) { 
    if (vendedor->status != 'i') {
      exibe_vendedor(vendedor);
      printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
      getchar();
    }
  }
  fclose(fp);
  free(vendedor);
}


void exibe_vendedor(Vendedor* vendedor) {
      char sit[20];
      if ((vendedor == NULL) || (vendedor->status == 'i')) {
           printf("////////////////////////////   Vendedor Inexistente! //////////////////////////\n");
           printf("\n");
           printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
           getchar();
      }else{
           printf("/////////////////////////////  VENDEDOR CADASTRADO:  //////////////////////////\n");
           printf("///                                                                         ///\n");
           printf("CPF: %s\n", vendedor->cpf);
           printf("Nome do vendedor: %s\n", vendedor->nome);
           printf("E-mail: %s\n", vendedor->email);
           printf("Data de Nasc: %s\n", vendedor->nasc);
           printf("Telefone: %s\n", vendedor->fone);
           printf("///                                                                         ///\n");
           if (vendedor->status == 'a') {
             strcpy(sit, "Vendedor Ativo");
           } else {
             strcpy(sit, "Vendedor Inativo");
           }
           printf("Situacao do vendedor: %s\n", sit);
           printf("\n");
  }
}