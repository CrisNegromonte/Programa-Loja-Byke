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
                  printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
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
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =           ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = =   MENU COLABORADORES    = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR um(a) novo(a) colaborador(a)                    ///\n");
    printf("///            2. PESQUISAR os dados de um(a) colaborador(a)                ///\n");
    printf("///            3. ATUALIZAR o cadastro de um(a) colaborador(a)              ///\n");
    printf("///            4. EXCLUIR um colaborador(a) do sistema                      ///\n");
    printf("///            5. LISTAR todos os colaboradores                             ///\n");
    printf("///            0. VOLTAR ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Digite a opcao desejada: ");
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
    ler_cpf_colab(colab->cpf);
    ler_nome_colab(colab->nome);
    ler_func_colab(colab->func);
    ler_email_colab(colab->email);
    ler_nasc_colab(colab->nasc);
    ler_fone_colab(colab->fone);
    colab-> status = 'a';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Realizando cadastro...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro efetivado!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return colab;
}


Colab* pesquisar_colab(void) {
    FILE* fp;
    Colab* colab;
    char cpf[12];
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
    printf(">>>  Digite o CPF do(a) colaborador(a) (Apenas Numeros/11 Dig.):  ");
    fgets (cpf, 12, stdin);
    getchar();
    colab = (Colab*) malloc(sizeof(Colab));
    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
      printf("Erro na abertura do arquivo!\n");
      printf("Nao foi possivel continuar...\n");
      printf("\t\t\t*** Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
        while(!feof(fp)) {
          fread(colab, sizeof(Colab), 1, fp);
          if((strcmp(colab->cpf, cpf) == 0) && (colab->status != 'i')) {
            exibe_colab(colab);
            printf("\t\t\t*** Tecle <ENTER> para continuar...\n");
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
    char cpf[12];
    Colab* colab = (Colab*) malloc(sizeof(Colab));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = =   ALTERAR COLABORADOR(A)  = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf(">>>   Digite o CPF do(a) colaborador(a) (Apenas Numeros):  ");
    fgets(cpf, 12, stdin);
    getchar();
    fp = fopen("colab.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t>>> Processando...\n");
      sleep(1);
      printf("\t\t\t>>> Erro na abertura do arquivo!\n");
      printf("\t\t\t>>> Nao foi possivel continuar...\n");
      printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(colab, sizeof(Colab), 1, fp) == 1) {
        if(strcmp(colab->cpf, cpf) == 0) {
          printf("\n");
          printf("\t\t\t>>> Colaborador(a) Encontrado(a) <<<\n");
          printf("\t\t\t>>> Atualize o Cadastro <<<\n");
          printf("\n");
          ler_nome_colab(colab->nome);
          ler_nome_colab(colab->func);
          ler_email_colab(colab->email);
          ler_nasc_colab(colab->nasc);
          ler_fone_colab(colab->fone);
          colab-> status = 'a';
          fseek(fp, -sizeof(Colab), SEEK_CUR);
          fwrite(colab, sizeof(Colab), 1, fp);
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
        printf("\t\t\t Colaborador(a) atualizado(a) com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...  <<<\n");
  getchar();
  fclose(fp);
  free(colab);
}



void excluir_colab(void) {
    char cpf[12];
    Colab* colab = (Colab*) malloc(sizeof(Colab));
    FILE* fp;
    int sim = 0;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            = = = = =   SISTEMA LOJA DE BICICLETAS    = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///              Developed by @CrisNegromonte -- since Ago, 2023            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = =  EXCLUIR  COLABORADOR(A)  = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf(">>>   Digite o CPF do(a) colaborador(a) (Apenas Numeros):  ");
    fgets(cpf, 12, stdin);
    getchar();
    fp = fopen("colab.dat", "r+b");
    if (fp == NULL) {
      printf("\t\t\t>>>   Processando...  <<<\n");
      sleep(1);
      printf("\t\t\t>>> Erro na abertura do arquivo!\n");
      printf("\t\t\t>>> Nao foi possivel continuar...\n");
      printf("\t\t\t>>> Tecle <ENTER> para voltar...\n");
      getchar();
    } else {
      while (fread(colab, sizeof(Colab), 1, fp) == 1) {
        if(strcmp(colab->cpf, cpf) == 0) {
          printf("\n");
          printf("\t\t\t>>> Colaborador(a) Encontrado(a) <<<\n");
          printf("\n");
          colab->status = 'i';
          fseek(fp, -sizeof(Colab), SEEK_CUR);
          fwrite(colab, sizeof(Colab), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf("\t\t\t Colaborador(a) nao encontrado!\n");
    } else {
        printf("\n");
        printf("\t\t\t Colaborador(a) excluido(a) com sucesso!\n");
    }
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  fclose(fp);
  free(colab);
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio

void ler_cpf_colab (char* cpf) {
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
void ler_nome_colab (char* nome) {
  fflush(stdin);
  printf("Digite o nome: ");
  fgets(nome, 38, stdin); 
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
    fgets(nome, 38, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(nome);
    if (tam > 0 && nome[tam - 1] == '\n') {
      nome[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}



void ler_func_colab (char* func) {
  fflush(stdin);
  printf("Digite a funcao: ");
  fgets(func, 15, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(func);
  if (tam > 0 && func[tam - 1] == '\n') {
    func[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarFunc(func)) {
    printf("Nome de funcao invalido: %s\n", func);
    printf("Informe um nome valido de funcao (somente caracteres): ");
    fflush(stdin);
    fgets(func, 15, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(func);
    if (tam > 0 && func[tam - 1] == '\n') {
      func[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
void ler_email_colab (char* email) {
    fflush(stdin);
    printf("Digite o email: ");
    fgets(email, 33, stdin);
    while (!validarEmail(email)) {
        printf("Erro! Digite novamente um email valido: ");
        fgets(email, 33, stdin);
        fflush(stdin);
    }
}


// Funcao feita parcialmente pelo chat GPT, adaptada por mim
void ler_nasc_colab (char* nasc) {
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
void ler_fone_colab (char* fone) {
    fflush (stdin);
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone, 12, stdin);

    while (!validarFone (fone)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone, 12, stdin);
    
    }
} 

void grava_colab(Colab* colab) {
  FILE* fp;
  fp = fopen("colab.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Processando...  <<<\n");
    sleep(1);
    printf("\t\t\t>>>  Erro! Nao foi possivel continuar!  <<< \n");
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
    printf("//////////////////////////////////////////////////////");
    printf("\n");
    printf("     = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("     = = =      LISTAGEM |  COLABORADORES      = = =\n");
    printf("     = = = = = = = = = = = = = = = = = = = = = = = =\n");
    printf("\n");                                                                        
    colab = (Colab*) malloc(sizeof(Colab));
    fp = fopen("colab.dat", "rb");
    if (fp == NULL) {
      printf("Erro na abertura!/n");
      printf("Talvez ainda nao exista colaborador(a) cadastrado(a)!\n");
      printf("Realize um cadastro para continuar...\n");
      exit(1);
  }
  while (fread(colab, sizeof(Colab), 1, fp)) { 
    if (colab->status != 'i') {
      exibe_colab(colab);
    }
  }
  fclose(fp);
  free(colab);
	   
}



void exibe_colab(Colab* colab) {
      char sit[20];
      if ((colab == NULL) || (colab->status == 'i')) {
           printf(">>>>>>>>>>  COLABORADOR(A) INEXISTENTE!   <<<<<<<<<\n");
           printf("==================================================== ");
           printf("\n");
           printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
           getchar();
      }else{
           printf("==================================================== ");
           printf("\n");
           printf("|| CPF: ");
           printf("%s" ,colab->cpf);
           printf("\n");
           printf("|| COLABORADOR(A): ");
           printf("%s" ,colab->nome);
           printf("\n");
           printf("|| FUNCAO: ");
           printf("%s" ,colab->func);
           printf("\n");
           printf("|| TELEFONE: ");
           printf("%s" ,colab->fone);
           printf("\n");
           printf("|| DATA DE NASC.: ");
           printf("%s" ,colab->nasc);
           printf("\n");
           printf("|| E-MAIL: ");
           printf("%s" ,colab->email);
           if (colab->status == 'a') {
             strcpy(sit, "Colaborador(a) Ativo(a)");
           } else {
             strcpy(sit, "Colaborador(a) Inativo(a)");
        }
        printf("|| STATUS: %s\n", sit);
        printf("\n");
      }
}