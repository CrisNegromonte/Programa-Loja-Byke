
typedef struct produtos Produtos;

struct produtos {
    char cod[12];
    char nome[50];
    char cor[12];
    char marca[15];
    char valor[10];
    char quant[5];
};

char tela_produtos(void);
void menu_produtos(void);
void cadastrar_produto(void);
void pesquisar_produto(void);
void alterar_produto(void);
void excluir_produto(void);

void ler_cod_p (char*);
void ler_nome_p (char*);
void ler_cor_p (char*);
void ler_marca_p (char*);
void ler_valor_p (char*);
void ler_quant_p (char*);