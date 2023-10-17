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
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
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
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
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
    printf("///            = = = = = = =  EXCLUIR  VENDEDOR  = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("***            Digite o CPF do vendedor (Apenas Numeros):  ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
	    //delay(1);
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