///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Serido                     ///
///               Departamento de Computacao e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programacao                      /// 
///                      Docente: Flavius Gorgonio                          ///                     
///                      PROJETO LOJA DO CICLISTA                           ///
///        Developed by Katia Cristina N. Maia -- since Ago, 2023           ///
///////////////////////////////////////////////////////////////////////////////
///                          VERSAO - SEMANA 7                              ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "cliente.h"
#include "colab.h"
#include "produtos.h"
#include "vendas.h"
#include "relatorios.h"
#include "infos.h"
#include "util.h"


char menu_principal(void);


/////
// Programa principal

int main(void){
    char op;
    do {
        op = menu_principal();
        switch(op){
            case '1': 	menu_clientes();
                        break;
            case '2': 	menu_colab();
                        break;
            case '3': 	menu_produtos();
                        break;
            case '4': 	menu_vendas();
                        break;
            case '5': 	menu_relatorios();
                        break;
            case '6': 	tela_informacoes();
                        break;
        } 		
	} while (op != '0');
	return 0;    
}



char menu_principal(void) {
	char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serido                     ///\n");
    printf("///               Departamento de Computacao e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programacao                      ///\n");
    printf("///                      Docente: Flavius Gorgonio                          ///\n");
    printf("///                       SISTEMA LOJA DO CICLISTA                          ///\n");
    printf("///           Developed by @CrisNegromonte -- since Ago, 2023               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///          ==========  SISTEMA LOJA DE BICICLETAS   ==========            ///\n");
    printf("///         >> Para melhor visualizacao, navegue em tela cheia <<           ///\n");
    printf("///          ===================================================            ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. CLIENTES                                                  ///\n");
    printf("///            2. COLABORADORES                                             ///\n");
    printf("///            3. PRODUTOS                                                  ///\n");
    printf("///            4. VENDAS                                                    ///\n");
    printf("///            5. RELATORIOS                                                ///\n");
    printf("///            6. Informacoes Sobre o Sistema                               ///\n");
    printf("///            0. ENCERRAR SISTEMA                                          ///\n");
    printf("///                                                                         ///\n");
	printf("///           Digite a opcao desejada: ");
	scanf("%c", &op);
	getchar();
	printf("///                                                                         ///\n");
	printf("///                                                                         ///\n");
	printf("///////////////////////////////////////////////////////////////////////////////\n");
	printf("\n");
	// delay(1);
	return op;
}





