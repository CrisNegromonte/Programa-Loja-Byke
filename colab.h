typedef struct colab Colab;

struct colab {
    char cpf_colab[12];
    char nome_colab[38];
    char func_colab[15];
    char email_colab[33];
    char nasc_colab[11];
    char fone_colab[12];
    char sit_colab[20];
    char status_colab;
    Colab* prox;
};



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


