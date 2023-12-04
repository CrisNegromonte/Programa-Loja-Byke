
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "util.h"

//////
////// Funções
//////
void ler_cpf_cli (char*);
void ler_nome_cli (char*);
void ler_email_cli (char*);
void ler_nasc_cli (char*);
void ler_fone_cli (char*);


void menu_clientes(void) {
  Cliente* cliente;
	char op;
	do {
		 op = tela_clientes();
		 switch(op) {
			  case '1': 	cliente = cadastrar_cliente();
                    grava_cli(cliente);
                    getchar();
						        break;
			  case '2': 	cliente = pesquisar_cliente();
                    exibe_cliente(cliente);
                    break;
			  case '3': 	alterar_cliente();
						        break;
			  case '4': 	excluir_cliente();
						        break;
        case '5': 	lista_clientes();
                    printf(">>>  Tecle <ENTER> para continuar...  <<<\n");
                    getchar();
						        break;
	  	} 		
	} while (op != '0');
}


char tela_clientes(void) {
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
    printf("///            = = = = = = = =   MENU CLIENTE    = = = = = = =              ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CADASTRAR novo cliente                                    ///\n");
    printf("///            2. PESQUISAR  um cliente                                     ///\n");
    printf("///            3. ATUALIZAR um cliente                                      ///\n");
    printf("///            4. EXCLUIR um cliente                                        ///\n");
    printf("///            5. LISTAR todos os clientes                                  ///\n");
    printf("///            0. VOLTAR ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf(">>>>>>>>>  Escolha a opcao desejada e tecle enter: ");
    scanf("%c", &op);
	  getchar();
	  printf("///                                                                         ///\n");
	  printf("///                                                                         ///\n");
	  printf("///////////////////////////////////////////////////////////////////////////////\n");
	  printf("\n");
	  // delay(1);
    return op;
}

Cliente* cadastrar_cliente(void) {
    Cliente* cliente;
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
    printf("///             = = = = = = =  CADASTRAR CLIENTE  = = = = = = =             ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    ler_cpf_cli(cliente->cpf_cli);
    ler_nome_cli(cliente->nome_cli);
    ler_cidade_cli(cliente->cidade_cli);
    ler_email_cli(cliente->email_cli);
    ler_nasc_cli(cliente->nasc_cli);
    ler_fone_cli(cliente->fone_cli);
    cliente->status_cli = 'a';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf(">>> Realizando cadastro...  <<<\n");
    sleep(1);
    printf("\n>>> Cadastro efetivado!  <<<\n");
    printf("\n>>> Tecle <ENTER> para voltar ao menu...  <<<\n");
    getchar();
    return cliente;
}
  

Cliente* pesquisar_cliente(void) {
    FILE* fp;
    Cliente* cliente;
    char cpf_cli[12];
    system("clear||cls");
    printf("\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///           ===================================================            ///\n");
    printf("///           ==========  SISTEMA LOJA DE BICICLETAS   ==========            ///\n");
    printf("///           ===================================================            ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///             ===============================================              ///\n");
    printf("///             = = = = = =    PESQUISAR CLIENTE    = = = = = =              ///\n");
    printf("///             ===============================================              ///\n");
    printf("///                                                                          ///\n");
    printf("\n");
    printf("\n");
    printf(">>>   Digite o CPF do cliente (11 digitos): ");
    fgets (cpf_cli, 12, stdin);
    getchar();
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
      printf(">>>  Erro na abertura do arquivo!  <<<\n");
      printf(">>>  Talvez ainda nao exista cliente cadastrado...  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui.  <<<\n");
      getchar();
    } else {
       while(!feof(fp)) {
         fread(cliente, sizeof(Cliente), 1, fp);
         if((strcmp(cliente->cpf_cli, cpf_cli) == 0) && (cliente->status_cli != 'i')) {
           exibe_cliente(cliente);
           printf(">>> Tecle <ENTER> para voltar ao menu...  <<<\n");
           getchar();
           fclose(fp);
           free (cliente);
           return cliente;
        }
      }
   }
   fclose(fp);
   free (cliente);
   return NULL;
}


void alterar_cliente(void) {
    char cpf_cli[12];
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
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
    printf("///             ===============================================             ///\n");
    printf("///             = = = = = =   ATUALIZAR CLIENTE   = = = = = = =             ///\n");
    printf("///             ===============================================             ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(">>>>>>>>>>  Digite o CPF do cliente (11 digitos): ");
    fgets(cpf_cli, 12, stdin);
    getchar();
    fp = fopen("cli.dat", "r+b");
    if (fp == NULL) {
      printf(">>>  Processando...  <<<\n");
      sleep(1);
      printf(">>>  Erro na abertura do arquivo!  <<<\n");
      printf(">>>  Talvez ainda nao exista cliente cadastrado...  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui.  <<<\n");
      getchar();
    } else {
      while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
        if(strcmp(cliente->cpf_cli, cpf_cli) == 0) {
          printf("\n");
          printf(">>>  Cliente Encontrado! <<<\n");
          printf(">>>  Realize as alteracoes... <<<\n");
          printf("\n");

          ler_nome_cli(cliente->nome_cli);
          ler_cidade_cli(cliente->cidade_cli);
          ler_fone_cli(cliente->fone_cli);
          ler_email_cli(cliente->email_cli);
          ler_nasc_cli(cliente->nasc_cli);
          ler_fone_cli(cliente->fone_cli);
          cliente->status_cli = 'a';

          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(cliente, sizeof(Cliente), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf(">>>  CPF nao encontrado!  <<<\n");
    } else {
        printf("\n");
        printf(">>>  Cliente atualizado com sucesso!  <<<\n");
    }
  printf("\n");
  printf(">>>  Tecle <ENTER> para voltar ao menu...  <<<\n");
  getchar();
  fclose(fp);
}


void excluir_cliente(void) {
    char cpf_cli[12];
    Cliente* cliente_a = (Cliente*) malloc(sizeof(Cliente));
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
    printf("///            = = = = = = =   EXCLUIR CLIENTE   = = = = = = = =            ///\n");
    printf("///           ===================================================           ///\n");
    printf("///                                                                         ///\n");
    printf("\n");
    printf("\n");
    printf(" >>>>>>>>  Digite o CPF do cliente (11 digitos):  ");
    fgets(cpf_cli, 12, stdin);
    getchar();
    fp = fopen("cli.dat", "r+b");
    if (fp == NULL) {
      printf(">>> Processando as informacoes... <<<\n");
      sleep(1);
      printf(">>> ERRO na busca!  <<<\n");
      printf(">>> Talvez ainda nao exista cliente cadastrado!  <<<\n");
      printf(">>>  Realize um cadastro e volte aqui.  <<<\n");
      getchar();
    } else {
      while (fread(cliente_a, sizeof(Cliente), 1, fp) == 1) {
        if(strcmp(cliente_a->cpf_cli, cpf_cli) == 0) {
          printf("\n");
          printf(">>>  Cliente Encontrado!  <<<\n");
          printf("\n");
          cliente_a->status_cli = 'i';
          fseek(fp, -sizeof(Cliente), SEEK_CUR);
          fwrite(cliente_a, sizeof(Cliente), 1, fp);
          sim = 1;
          break;
        }
      }
    }
    if (!sim) {
        printf("\n");
        printf(">>>  CPF nao encontrado!  <<<\n");
    } else {
        printf("\n");
        printf(">>>  Cliente excluido com sucesso!  <<<\n");
    }
  printf("\n");
  printf(">>> Tecle <ENTER> para voltar ao menu...  <<<\n");
  getchar();
  fclose(fp);
}



// Funcoes abaixo adaptadas do programa exemplo do Prof. Flavius Gorgonio

void lista_clientes(void) {
    FILE* fp;
    Cliente* cliente;
    system("clear||cls");
    printf("////////////////////////////////////////////////////////////////");
    printf("\n");
    printf("   ===========================================================\n");
    printf("   = = = = = = =    LISTA |  TODOS OS CLIENTES   = = = = = = =\n");
    printf("   ===========================================================\n");
    printf("\n");      
    printf("\n");                                                                  
    cliente = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cli.dat", "rb");
    if (fp == NULL) {
      printf(">>>  Erro na abertura!  <<<\n");
      printf(">>>  Talvez ainda nao exista clientes cadastrados!  <<<\n");
      printf(">>>  Cadastre um cliente e retorne aqui...  <<<\n");
      getchar();
  }
  while (fread(cliente, sizeof(Cliente), 1, fp)) { 
    if (cliente->status_cli != 'i') {
      exibe_cliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
	   
}

// Funcoes

void ler_cpf_cli (char* cpf_cli) {
    fflush(stdin);
    printf(">>> Digite o CPF (somente os 11 digitos): ");
    fgets (cpf_cli, 12, stdin);
    while (!validarCpf (cpf_cli)) {
        printf(">>> Invalido! Digite um CPF valido (somente os 11 digitos): ");
        fgets (cpf_cli, 12, stdin);
    }
    getchar();
}

// Funcao retirada do programa exemplo do Prof. Flavius Gorgonio

void ler_nome_cli(char* nome_cli) {
  fflush(stdin);
  printf("Digite o nome (sem acentos): ");
  fgets(nome_cli, 40, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(nome_cli);
  if (tam > 0 && nome_cli[tam - 1] == '\n') {
    nome_cli[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarNome(nome_cli)) {
    printf("Nome invalido: %s\n", nome_cli);
    printf("Informe um nome valido (somente caracteres/sem acentos): ");
    fflush(stdin);
    fgets(nome_cli, 40, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(nome_cli);
    if (tam > 0 && nome_cli[tam - 1] == '\n') {
      nome_cli[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}



void ler_cidade_cli(char* cidade_cli) {
  fflush(stdin);
  printf("Cidade (sem acentos): ");
  fgets(cidade_cli, 25, stdin); 
  // Remove o caractere de nova linha do final, se houver
  int tam = strlen(cidade_cli);
  if (tam > 0 && cidade_cli[tam - 1] == '\n') {
    cidade_cli[tam - 1] = '\0';
    fflush(stdin);
  }
  while (!validarCidade(cidade_cli)) {
    printf("Cidade invalida: %s\n", cidade_cli);
    printf("Informe um nome de cidade valido (somente caracteres/sem acentos): ");
    fflush(stdin);
    fgets(cidade_cli, 25, stdin); 
    // Remove o caractere de nova linha do final, se houver
    tam = strlen(cidade_cli);
    if (tam > 0 && cidade_cli[tam - 1] == '\n') {
      cidade_cli[tam - 1] = '\0';
      fflush(stdin);
    }
  } 
}




// Funcao retirada do programa exemplo do Prof. Flavius Gorgonio
void ler_email_cli(char* email_cli) {
    fflush(stdin);
    printf("Digite o email: ");
    fgets(email_cli, 33, stdin);
    while (!validarEmail(email_cli)) {
        printf("Erro! Digite novamente um email valido: ");
        fgets(email_cli, 33, stdin);
        fflush(stdin);
    }
}

// Funcao parcialmente feita pelo chat GPT, adaptada por mim
void ler_nasc_cli(char* nasc_cli) {
  int dia, mes, ano;
  char dd[3], mm[3], aaaa[5];

  while (1) {
    fflush(stdin);
    printf("Data de nascimento (dd/mm/aaaa): ");
    fgets(nasc_cli, 11, stdin);

    // Verificar o formato da data
    if (sscanf(nasc_cli, "%2[^/]/%2[^/]/%4[^/]", dd, mm, aaaa) == 3) {
      // Converter partes para inteiros
      sscanf(dd, "%d", &dia);
      sscanf(mm, "%d", &mes);
      sscanf(aaaa, "%d", &ano);

      if (validarData(dia, mes, ano) && strlen(aaaa) == 4) {
        break;  // Data valida fornecida pelo usuario com um ano de quatro digitos
      } else {
        printf("Data invalida: %d/%d/%d\n", dia, mes, ano);
        printf("Informe uma data valida no formato dd/mm/aaaa:\n\n");
      }
    } else {
      printf("Formato de data invalido. Use o formato dd/mm/aaaa.\n");
    }
  }
}


// Funcao retirada do programa exemplo do Prof. Flavius Gorgonio
void ler_fone_cli (char* fone_cli) {
    fflush (stdin);
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone_cli, 12, stdin);

    while (!validarFone (fone_cli)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone_cli, 12, stdin);
    
    }
} 

/// Arquivos

void grava_cli(Cliente* cliente) {
  FILE* fp;
  fp = fopen("cli.dat", "ab");
  if (fp == NULL) {
    printf(">>> Realizando operacao...  <<<\n");
    sleep(1);
    printf(">>> Erro na abertura!  <<<\n");
    printf(">>> Tecle <ENTER> para sair...  <<<\n");
    getchar();
  }
  fwrite(cliente, sizeof(Cliente), 1, fp);
  fclose(fp);
  free(cliente);
}


// Funcao adaptada do programa exemplo do Prof. Flavius Gorgonio
      
void exibe_cliente(Cliente* cliente) {
      char sit_cli[20];
      if ((cliente == NULL) || (cliente->status_cli == 'i')) {
           printf(">>>>>>>>>>>>>>   CLIENTE INEXISTENTE! <<<<<<<<<<<<<\n");
           printf("==================================================== ");
           printf("\n");
           printf(">>>  Tecle <ENTER> para continuar...  <<<\n");
           getchar();
      }else{
           printf("============================================================= ");
           printf("\n");
           printf("|| CPF: ");
           printf("%s" ,cliente->cpf_cli);
           printf("\n");
           printf("|| CLIENTE: ");
           printf("%s" ,cliente->nome_cli);
           printf("\n");
           printf("|| TELEFONE: ");
           printf("%s" ,cliente->fone_cli);
           printf("\n");
           printf("|| CIDADE: ");
           printf("%s" ,cliente->cidade_cli);
           printf("\n");
           printf("|| DATA DE NASC.: ");
           printf("%s" ,cliente->nasc_cli);
           printf("\n");
           printf("|| E-MAIL: ");
           printf("%s" ,cliente->email_cli);
           if (cliente->status_cli == 'a') {
             strcpy(sit_cli, "Ativo");
           } else {
             strcpy(sit_cli, "Inativo");
        }
        printf("|| STATUS CLIENTE: %s\n", sit_cli);
        printf("\n");
      }
}



           