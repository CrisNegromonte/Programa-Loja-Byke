#ifndef CLIENTE_H
#define CLIENTE_H
#endif // CLIENTE

typedef struct cliente Cliente;

struct cliente {
    char cpf[12];
    char nome[40];
    char cidade[25];
    char email[33];
    char nasc[11];
    char fone[12];
    char sit[20];
    char status;
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

void ler_cpf (char*);
void ler_nome (char*);
void ler_cidade (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);
