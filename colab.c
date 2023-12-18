#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "colab.h"
#include "util.h"

//////
////// Funções
//////
void ler_cpf_colab (char*);
void ler_nome_colab (char*);
void ler_func_colab (char*);
void ler_email_colab (char*);
void ler_nasc_colab (char*);
void ler_fone_colab (char*);


void menu_colab(void) {
  Colab* colab;
	char op;
	do {
		op = tela_colab();
		switch(op) {
			case '1': 	colab = cadastrar_colab();
                  grava_colab(colab);
                  getchar();
					      	break;
			case '2': 	colab = pesquisar_colab();
                  exibe_colab(colab);
						      break;
			case '3': 	alterar_colab();
						      break;
			case '4': 	excluir_colab();
					      	break;
      case '5':   lista_colab();
                  printf("\n");
                  printf(">>> Tecle <ENTER> para voltar ao menu...\n");
                  getchar();
                  break;
		} 		
	} while (op != '0');
}



char tela_colab(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = =   MENU COLABORADORES    = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR colaborador(a)                                  ///\n");
    printf("///            2. PESQUISAR colaborador(a)                                  ///\n");
    printf("///            3. ATUALIZAR colaborador(a)                                  ///\n");
    printf("///            4. EXCLUIR colaborador(a)                                    ///\n");
    printf("///            5. LISTAR todos os colaboradores                             ///\n");
    printf("///            0. VOLTAR ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>>>>>   Digite a opcao desejada: ");
    scanf("%c", &op);
	  getchar();
  	printf("///                                                                         ///\n");
	  printf("///                                                                         ///\n");
  	printf("///////////////////////////////////////////////////////////////////////////////\n");
  	printf("\n");
  	// delay(1);
	  return op;
}

Colab* cadastrar_colab(void) {
    Colab* colab;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = = =   CADASTRAR COLABORADOR(A)  = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    colab = (Colab*) malloc(sizeof(Colab));
    ler_cpf_colab(colab->cpf_colab);
    ler_nome_colab(colab->nome_colab);
    ler_func_colab(colab->func_colab);
    ler_email_colab(colab->email_colab);
    ler_nasc_colab(colab->nasc_colab);
    ler_fone_colab(colab->fone_colab);
    colab-> status_colab = 'a';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf(">>> Realizando cadastro...  <<<\n");
    sleep(1);
    printf(">>> Cadastro efetivado!  <<<\n");
    printf(">>> Tecle <ENTER> para continuar...  <<<\n");
    getchar();
    return colab;
}


Colab* pesquisar_colab(void) {
    FILE* fp;
    Colab* colab;
    char cpf_colab[12];
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           ===================================================           ///\n");
    printf("///           = = = = =    PESQUISAR COLABORADOR(A)   = = = = = =           ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>> Digite o CPF do colaborador (apenas 11 numeros):  ");
    fgets (cpf_colab, 12, stdin);
    getchar();
    colab = (Colab*) malloc(sizeof(Colab));
    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
      printf(">>>  Erro na abertura do arquivo!  <<<\n");
      printf(">>>  Talvez ainda nao exista nenhum cadastro efetivado...  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
      printf(">>>  Tecle <ENTER> para sair...  <<<\n");
      getchar();
    } else {
        while(!feof(fp)) {
          fread(colab, sizeof(Colab), 1, fp);
          if((strcmp(colab->cpf_colab, cpf_colab) == 0) && (colab->status_colab != 'i')) {
            exibe_colab(colab);
            getchar();
            printf(">>> Tecle <ENTER> para voltar ao menu...  <<<\n");
            getchar();
            fclose(fp);
            free(colab);
            return colab;
          } 
        }
    }
    fclose(fp);
    free(colab);
    return NULL;
}


void alterar_colab(void) {
    char cpf_colab[12];
    Colab* colab = (Colab*) malloc(sizeof(Colab));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = =    ATUALIZAR COLABORADOR    = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>  Digite o CPF do colaborador (apenas 11 numeros):  ");
    fgets(cpf_colab, 12, stdin);
    getchar();
    fp = fopen("colab.dat", "r+b");
    if (fp == NULL) {
      printf(">>> Processando...  <<<\n");
      sleep(1);
      printf(">>>  Erro na abertura do arquivo! <<<\n");
      printf(">>>  Talvez ainda nao exista nenhum cadastro efetivado...  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
      printf(">>>  Tecle <ENTER> para sair...  <<<\n");
      getchar();
    } else {
      while (fread(colab, sizeof(Colab), 1, fp) == 1) {
        if(strcmp(colab->cpf_colab, cpf_colab) == 0) {
          printf("\n");
          printf(">>>  Colaborador Encontrado!  <<<\n");
          printf(">>>  Atualize o Cadastro...  <<<\n");
          printf("\n");
          printf("\n");
          ler_nome_colab(colab->nome_colab);
          ler_func_colab(colab->func_colab);
          ler_email_colab(colab->email_colab);
          ler_nasc_colab(colab->nasc_colab);
          ler_fone_colab(colab->fone_colab);
          colab-> status_colab = 'a';
          fseek(fp, -sizeof(Colab), SEEK_CUR);
          fwrite(colab, sizeof(Colab), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf(">>>  CPF nao encontrado!   <<<\n");
    } else {
        printf("\n");
        printf(">>>  cadastro atualizado com sucesso!  <<<\n");
        getchar();
    }
  printf("\n");
  printf(">>>  Tecle <ENTER> para voltar ao menu...  <<<\n");
  getchar();
  fclose(fp);
  free(colab);
}



void excluir_colab(void) {
    char cpf_colab[12];
    Colab* colab = (Colab*) malloc(sizeof(Colab));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = =   EXCLUIR  COLABORADOR(A)   = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>> Digite o CPF do colaborador (apenas 11 numeros): ");
    fgets(cpf_colab, 12, stdin);
    getchar();
    fp = fopen("colab.dat", "r+b");
    if (fp == NULL) {
      printf(">>>   Processando...  <<<\n");
      sleep(1);
      printf(">>>  Erro na abertura do arquivo! <<<\n");
      printf(">>>  Talvez ainda nao exista nenhum cadastro efetivado...  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui...  <<<\n");
      printf(">>>  Tecle <ENTER> para sair...  <<<\n");
      getchar();
    } else {
      while (fread(colab, sizeof(Colab), 1, fp) == 1) {
        if(strcmp(colab->cpf_colab, cpf_colab) == 0) {
          printf("\n");
          printf(">>>  Cadastro Encontrado!  <<<\n");
          printf("\n");
          colab->status_colab = 'i';
          fseek(fp, -sizeof(Colab), SEEK_CUR);
          fwrite(colab, sizeof(Colab), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf(">>>  Cadastro Nao Encontrado!  <<<\n");
    } else {
        printf("\n");
        printf(">>>  Cadastro excluido com sucesso!  <<<\n");
    }
  printf("\n");
  printf(">>>  Tecle <ENTER> para voltar ao menu...  <<<\n");
  getchar();
  fclose(fp);
  free(colab);
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio

void ler_cpf_colab (char* cpf_colab) {
    fflush(stdin);
    printf("Digite o CPF do Colaborador (11 digitos): ");
    fgets (cpf_colab, 12, stdin);
    while (!validarCpf (cpf_colab)) {
        printf("Invalido! Digite um CPF valido (somente numeros): ");
        fgets (cpf_colab, 12, stdin);
    }
    getchar();
}

// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_nome_colab (char* nome_colab) {
  fflush(stdin);
  printf("Digite o nome (sem acentos): ");
  fgets(nome_colab, 38, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(nome_colab);
  if (tam > 0 && nome_colab[tam - 1] == '\n') {
    nome_colab[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome_colab)) {
    printf("Nome invalido: %s\n", nome_colab);
    printf("Informe um nome valido (sem acentos): ");
    fflush(stdin);
    fgets(nome_colab, 38, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(nome_colab);
    if (tam > 0 && nome_colab[tam - 1] == '\n') {
      nome_colab[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}



void ler_func_colab (char* func_colab) {
  fflush(stdin);
  printf("Digite a funcao (sem acentos) ");
  fgets(func_colab, 15, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(func_colab);
  if (tam > 0 && func_colab[tam - 1] == '\n') {
    func_colab[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarFunc(func_colab)) {
    printf("Nome de funcao invalido: %s\n", func_colab);
    printf("Informe um nome valido de funcao (sem acentos): ");
    fflush(stdin);
    fgets(func_colab, 15, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(func_colab);
    if (tam > 0 && func_colab[tam - 1] == '\n') {
      func_colab[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_email_colab (char* email_colab) {
    fflush(stdin);
    printf("Digite o email: ");
    fgets(email_colab, 33, stdin);
    while (!validarEmail(email_colab)) {
        printf(">>> Erro! Digite novamente um email valido: ");
        fgets(email_colab, 33, stdin);
        fflush(stdin);
    }
}


// Funcao feita parcialmente pelo chat GPT, adaptada por mim
void ler_nasc_colab (char* nasc_colab) {
  int dia, mes, ano;
  char dd[3], mm[3], aaaa[5];

  while (1) {
    fflush(stdin);
    printf("Data de nascimento (dd/mm/aaaa): ");
    fgets(nasc_colab, 11, stdin);

    // Verificar o formato da data
    if (sscanf(nasc_colab, "%2[^/]/%2[^/]/%4[^/]", dd, mm, aaaa) == 3) {
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
void ler_fone_colab (char* fone_colab) {
    fflush (stdin);
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone_colab, 12, stdin);

    while (!validarFone (fone_colab)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone_colab, 12, stdin);
    
    }
} 

void grava_colab(Colab* colab) {
  FILE* fp;
  fp = fopen("colab.dat", "ab");
  if (fp == NULL) {
    printf(">>> Processando...  <<<\n");
    sleep(1);
    printf(">>>  Erro! Nao foi possivel continuar!  <<< \n");
    getchar();
  }
  fwrite(colab, sizeof(Colab), 1, fp);
  fclose(fp);
  free(colab);
}



void lista_colab(void) {
    FILE* fp;
    Colab* colab;
    system("clear||cls");
    printf("////////////////////////////////////////////////////////////////");
    printf("\n");
    printf("==============================================================\n");
    printf("  = = = = = =   LISTA |  TODOS OS COLABORADORES  = = = = = =  \n");
    printf("==============================================================\n");
    printf("\n");                                                                        
    colab = (Colab*) malloc(sizeof(Colab));
    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
      printf("Erro!\n");
      printf("Talvez ainda nao exista colaborador(a) cadastrado(a)!\n");
      printf("Realize um cadastro e retorne aqui...\n");
      //printf("Tecle <ENTER> para voltar ao menu anterior...\n");
      getchar();
  }
  while (fread(colab, sizeof(Colab), 1, fp)) { 
    if (colab->status_colab != 'i') {
      exibe_colab(colab);
    }
  }
  fclose(fp);
  free(colab);
	   
}



void exibe_colab(Colab* colab) {
      char sit_colab[20];
      if ((colab == NULL) || (colab->status_colab == 'i')) {
           printf(">>>>>>>>>>  COLABORADOR(A) INEXISTENTE!   <<<<<<<<<\n");
           printf("==================================================== ");
           printf("\n");
           printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
           getchar();
      }else{
           printf("=========================================================== ");
           printf("\n");
           printf("|| CPF: ");
           printf("%s" ,colab->cpf_colab);
           printf("\n");
           printf("|| COLABORADOR(A): ");
           printf("%s" ,colab->nome_colab);
           printf("\n");
           printf("|| FUNCAO: ");
           printf("%s" ,colab->func_colab);
           printf("\n");
           printf("|| TELEFONE: ");
           printf("%s" ,colab->fone_colab);
           printf("\n");
           printf("|| DATA DE NASC.: ");
           printf("%s" ,colab->nasc_colab);
           printf("\n");
           printf("|| E-MAIL: ");
           printf("%s" ,colab->email_colab);
           if (colab->status_colab == 'a') {
             strcpy(sit_colab, "Ativo");
           } else {
             strcpy(sit_colab, "Inativo");
        }
        printf("|| STATUS: %s\n", sit_colab);
        printf("\n");
      }
}