typedef struct colab Colab;

struct colab {
    char cpf[12];
    char nome[38];
    char func[15];
    char email[33];
    char nasc[11];
    char fone[12];
    char sit[20];
    char status;
};

typedef struct Node3 {
    Colab colab;
    struct Node3 *prox;
} Node3;

char tela_colab(void);
void menu_colab(void);

Colab* cadastrar_colab(void);
Colab* pesquisar_colab(void);
void alterar_colab(void);
void excluir_colab(void);
void lista_colab(void);

void grava_colab(Colab* colab);
void exibe_colab(Colab* colab);

void ler_cpf_colab (char*);
void ler_nome_colab (char*);
void ler_func_colab (char*);
void ler_email_colab (char*);
void ler_nasc_colab (char*);
void ler_fone_colab (char*);


