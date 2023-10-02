
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "util.h"

/////
////// Funcoes do Modulo Cliente
//////
void ler_cpf (char*);
void ler_nome (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);



void menu_clientes(void) {
	char op;
	do {
		op = tela_clientes();
		switch(op) {
			case '1': 	cadastrar_cliente();
						break;
			case '2': 	pesquisar_cliente();
						break;
			case '3': 	alterar_cliente();
						break;
			case '4': 	excluir_cliente();
						break;
		} 		
	} while (op != '0');
}


void cadastrar_cliente_f(void) {
	// em desenvolvimento
	cadastrar_cliente();
}


void pesquisar_cliente_f(void) {
	// em desenvolvimento
	pesquisar_cliente();
}


void alterar_cliente_f(void) {
	// em desenvolvimento
	alterar_cliente();
}


void excluir_cliente_f(void) {
	//  em desenvolvimento
	excluir_cliente();
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
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opcao desejada: ");
    scanf("%c", &op);
	getchar();
	printf("///                                                                       ///\n");
	printf("///                                                                       ///\n");
	printf("/////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	// delay(1);
	return op;
}

void cadastrar_cliente(void) {
    char cpf[12];
	char nome[50];
	char email[40];
	char nasc[11];
	char fone[12];

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
    ler_cpf(cpf);

    ler_nome(nome);

    ler_email(email);

    ler_nasc(nasc);

    ler_fone(fone);
   
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    printf("***                Digite o CPF (Apenas Números):  ");
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
    printf("***                Digite o CPF (Apenas Números):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	   delay(1);
   
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
    printf("***                Digite o CPF (Apenas Números):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	    delay(1);
}



// Funcoes

void ler_cpf (char* cpf) {
    fflush(stdin);
    printf("Digite o CPF (Apenas Números): ");
    fgets (cpf, 12, stdin);
    while (!validarCpf (cpf)) {
        printf("Erro! Digite novamente: ");
        fgets (cpf, 12, stdin);
    }
    getchar();
}

// Funcoes retiradas do programa exemplo do Prof. Flavius Gorgonio

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
    printf("Nome inválido: %s\n", nome);
    printf("Informe um novo nome: ");
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


void ler_email(char* email) {
    fflush(stdin);
    printf("Digite o Email: ");
    fgets(email, 40, stdin);
    while (!validarEmail(email)) {
        printf("Erro! Digite novamente: ");
        fgets(email, 40, stdin);
        fflush(stdin);
    }
}


void ler_nasc(char* nasc) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Data de nascimento: ");
  fgets(nasc, 11, stdin); 
  getchar();
  
  strncpy(dd, &nasc[0], 2);
  sscanf(dd, "%d", &dia);
  
  strncpy(mm, &nasc[3], 2);
  sscanf(mm, "%d", &mes);

  strncpy(aa, &nasc[6], 4);
  sscanf(aa, "%d", &ano);

  while (!validarData(dia, mes, ano)) {
    printf("Data inválida: %d/%d/%d\n", dia, mes, ano);
    printf("Informe uma nova data\n\n");
    printf("Data de nascimento: ");
    fgets(nasc, 11, stdin);
    fflush(stdin);
    getchar();
    strncpy(dd, &nasc[0], 2);
    sscanf(dd, "%d", &dia);
    strncpy(mm, &nasc[3], 2);
    sscanf(mm, "%d", &mes);
    strncpy(aa, &nasc[6], 4);
    sscanf(aa, "%d", &ano);
    
  } 
}




void ler_fone (char* fone) {
    fflush (stdin);
    printf("Digite o Telefone (Apenas Números): ");
    fgets (fone, 12, stdin);

    while (!validarFone (fone)) {
        printf("Erro! Digite novamente: ");
        fgets (fone, 12, stdin);
    
    }
} 