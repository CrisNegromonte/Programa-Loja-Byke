typedef struct cliente Cliente;

struct cliente {
    char cpf[12];
    char nome[50];
    char email[40];
    char nasc[11];
    char fone[12];
};

void menu_clientes(void);
char tela_clientes(void);

void cadastrar_cliente(void);
void pesquisar_cliente(void);
void alterar_cliente(void);
void excluir_cliente(void);

void ler_cpf (char*);
void ler_nome (char*);
void ler_email (char*);
void ler_nasc (char*);
void ler_fone (char*);

