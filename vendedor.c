#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "util.h"
#include "vendedor.h"

/////
////// Ass funcoes
//////
void ler_cpf (char*);
void ler_nome (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);


void menu_vendedores(void) {
	char op;
	do {
		op = tela_vendedores();
		switch(op) {
			case '1': 	cadastrar_vendedor();
						break;
			case '2': 	pesquisar_vendedor();
						break;
			case '3': 	alterar_vendedor();
						break;
			case '4': 	excluir_vendedor();
						break;
		} 		
	} while (op != '0');
}


void cadastrar_vendedor_f(void) {
	// em desenvolvimento
	cadastrar_vendedor();
}


void pesquisar_vendedor_f(void) {
	// em desenvolvimento
	pesquisar_vendedor();
}


void alterar_vendedor_f(void) {
	// em desenvolvimento
	alterar_vendedor();
}


void excluir_vendedor_f(void) {
	//  em desenvolvimento
	excluir_vendedor();
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

void cadastrar_vendedor(void) {
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
    printf("///            = = = = = = =  CADASTRAR VENDEDOR   = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
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


void pesquisar_vendedor(void) {
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
    printf("***                Digite o CPF (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
     //delay(1);
}


void alterar_vendedor(void) {
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
    printf("///            = = = = = = =  ALTERAR VENDEDOR   = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***                Digite o CPF (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	  // delay(1);
   
}


void excluir_vendedor(void) {
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
    printf("///            Informe o CPF (apenas numeros):                              ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// // Funcoes adaptadas e/ou emprestadas do programa exemplo do Prof. Flavius Gorgonio

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


void ler_nasc(char* nasc) {
  int dia, mes, ano;
  char dd[3], mm[3], aa[5];
  fflush(stdin);
  printf("Data de nascimento (dia/mes/ano - XX/XX/XXXX): ");
  fgets(nasc, 11, stdin); 
  getchar();
  
  strncpy(dd, &nasc[0], 2);
  sscanf(dd, "%d", &dia);
  
  strncpy(mm, &nasc[3], 2);
  sscanf(mm, "%d", &mes);

  strncpy(aa, &nasc[6], 4);
  sscanf(aa, "%d", &ano);

  while (!validarData(dia, mes, ano)) {
    printf("Data invalida: %d/%d/%d\n", dia, mes, ano);
    printf("Informe uma data valida:\n\n");
    printf("Data de nascimento (dia/mes/ano - XX/XX/XXXX): ");
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
    printf("Digite o telefone com DDD (somente numeros): ");
    fgets (fone, 12, stdin);

    while (!validarFone (fone)) {
        printf("Invalido! Digite um numero de telefone valido com DDD (somente numeros): ");
        fgets (fone, 12, stdin);
    
    }
} 