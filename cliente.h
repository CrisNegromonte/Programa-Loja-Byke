#ifndef CLIENTE_H
#define CLIENTE_H
#endif // CLIENTE

typedef struct cliente Cliente;

struct cliente {
    char cpf_cli[12];
    char nome_cli[40];
    char cidade_cli[25];
    char email_cli[33];
    char nasc_cli[11];
    char fone_cli[12];
    char sit_cli[20];
    char status_cli;
    struct Cliente* prox;
};

typedef struct Node2 {
    Cliente cliente;
    struct Node2 *prox;
} Node2;

void menu_clientes(void);
char tela_clientes(void);

Cliente* cadastrar_cliente(void);
Cliente* pesquisar_cliente(void);

void alterar_cliente(void);
void excluir_cliente(void);
void lista_clientes(void);

void exibe_cliente(Cliente* cliente);
void grava_cli(Cliente* cliente);

void ler_cpf_cli (char*);
void ler_nome_cli (char*);
void ler_cidade_cli (char*);
void ler_email_cli (char*);
void ler_nasc_cli (char*);
void ler_fone_cli (char*);
