#ifndef CLI_H
#define CLI_H

typedef struct cliente Cliente;

struct cliente {
    char cpf[12];
    char nome[50];
    char email[40];
    char nasc[11];
    char fone[12];
    char status;
};

void menu_clientes(void);
char tela_clientes(void);
Cliente* cadastrar_cliente(void);
void cad_cli(Cliente*);
void pesquisar_cliente(void);
void alterar_cliente(void);
void excluir_cliente(void);
void lista_clientes(void);
void exibe_cliente(Cliente* cliente);

void ler_cpf (char*);
void ler_nome (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);

#endif