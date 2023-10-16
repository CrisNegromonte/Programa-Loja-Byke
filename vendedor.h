typedef struct vendedor Vendedor;

struct vendedor {
    char cpf[12];
    char nome[50];
    char email[40];
    char nasc[11];
    char fone[12];
};

char tela_vendedores(void);
void menu_vendedores(void);

void cadastrar_vendedor(void);
void pesquisar_vendedor(void);
void alterar_vendedor(void);
void excluir_vendedor(void);

void ler_cpf_vendedor (char*);
void ler_nome_vendedor (char*);
void ler_email_vendedor (char*);
void ler_nasc_vendedor (char*);
void ler_fone_vendedor (char*);
