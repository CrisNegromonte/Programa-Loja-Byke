typedef struct vendedor Vendedor;

struct vendedor {
    char cpf[12];
    char nome[50];
    char email[40];
    char nasc[11];
    char fone[12];
    char sit[20];
    char status;
};

char tela_vendedores(void);
void menu_vendedores(void);

Vendedor* cadastrar_vendedor(void);
Vendedor* pesquisar_vendedor(void);
void alterar_vendedor(void);
void excluir_vendedor(void);

void ler_cpf_v (char*);
void ler_nome_v (char*);
void ler_email_v (char*);
void ler_nasc_v (char*);
void ler_fone_v (char*);

void grava_vendedor(Vendedor* vendedor);
void exibe_vendedor(Vendedor *vendedor);
void lista_vendedores(void);
