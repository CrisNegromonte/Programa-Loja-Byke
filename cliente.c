
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
void ler_cpf (char*);
void ler_nome (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);


void menu_clientes(void) {
  Cliente* cli;
	char op;
	do {
		op = tela_clientes();
		switch(op) {
			case '1': 	cli = cadastrar_cliente();
                  cad_cli(cli);
						      break;
			case '2': 	pesquisar_cliente();
						      break;
			case '3': 	alterar_cliente();
						      break;
			case '4': 	excluir_cliente();
						      break;
      case '5': 	lista_clientes();
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
    printf("///            = = = = = = = = =  MENU CLIENTE = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo cliente                                 ///\n");
    printf("///            2. Pesquisar os dados de um cliente                          ///\n");
    printf("///            3. Atualizar o cadastro de um cliente                        ///\n");
    printf("///            4. Excluir um cliente do sistema                             ///\n");
    printf("///            5. Listar todos os clientes                                  ///\n");
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
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
    printf("///            = = = = = = =  Cadastrar Cliente  = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    
    cliente = (Cliente*) malloc(sizeof(Cliente));

    ler_cpf(cliente->cpf);

    ler_nome(cliente->nome);

    ler_email(cliente->email);

    ler_nasc(cliente->nasc);

    ler_fone(cliente->fone);
    
    cliente->status = 'a';
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Realizando cadastro...\n");
    sleep(1);
    printf("\t\t\t>>> Cadastro efetivado!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return cliente;
}
  

void pesquisar_cliente(void) {
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
    printf("///            = = = = = = = = Pesquisar Cliente = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do cliente (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
     //delay(1);
}


void alterar_cliente(void) {
    char cpf[12];

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
    printf("///            = = = = = = =   Alterar Cliente   = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***             Digite o CPF do cliente (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	  // delay(1);
   
}


void excluir_cliente(void) {
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
    printf("///            = = = = = = =  Excluir Cliente  = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do cliente (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	    //delay(1);
}



// Funcoes

void ler_cpf (char* cpf) {
    fflush(stdin);
    printf("Digite o CPF (somente numeros): ");
    fgets (cpf, 12, stdin);
    while (!validarCpf (cpf)) {
        printf("Invalido! Digite um CPF valido (somente numeros): ");
        fgets (cpf, 12, stdin);
    }
    getchar();
}

// Funcao retirada do programa exemplo do Prof. Flavius Gorgonio

void ler_nome(char* nome) {
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

// Funcao retirada do programa exemplo do Prof. Flavius Gorgonio
void ler_email(char* email) {
    fflush(stdin);
    printf("Digite o email: ");
    fgets(email, 40, stdin);
    while (!validarEmail(email)) {
        printf("Erro! Digite novamente um email valido: ");
        fgets(email, 40, stdin);
        fflush(stdin);
    }
}

// Funcao parcialmente feita pelo chat GPT, adaptada por mim
void ler_nasc(char* nasc) {
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
void ler_fone (char* fone) {
    fflush (stdin);
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone, 12, stdin);

    while (!validarFone (fone)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone, 12, stdin);
    
    }
} 

/// Arquivos

void cad_cli(Cliente* cliente) {
  FILE* fp;
  fp = fopen("cli.dat", "ab");
  if (fp == NULL) {
    printf("\t\t\t>>> Realizando operação...\n");
    sleep(1);
    printf("\t\t\t>>> Erro na abertura!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  else {
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
  }
}

void lista_clientes(void) {
  FILE* fp;
  Cliente* cliente;
  printf("\n = Lista de Clientes = \n");
  cliente = (Cliente*) malloc(sizeof(Cliente));
  fp = fopen("cli.dat", "rb");
  if (fp == NULL) {
    printf("\t\t\t>>> Analisando os dados...\n");
    sleep(1);
    printf("\t\t\t>>> Erro ao abrir o arquivo!\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
  }
  while (fread(cliente, sizeof(Cliente), 1, fp)) { 
    if (cliente->status != 'i') {
      exibe_cliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
}


void exibe_cliente(Cliente* cli) {
      if (cli == NULL) {
              printf("\n= = Cliente Inexistente = = =\n");
      } else {
            printf("\n= = = Cliente Cadastrado = = =\n");
            printf("CPF: %s\n", cli->cpf);
            printf("Nome do cliente: %s\n", cli->nome);
            printf("E-mail: %s\n", cli->email);
            printf("Data de Nasc: %s\n", cli->nasc);
            printf("Telefone: %s\n", cli->fone);
            printf("Status: %d\n", cli->status);
      }
      printf("In\nTecle ENTER para continuar!\n\n");
      getchar();
}
