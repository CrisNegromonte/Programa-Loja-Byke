
typedef struct produto Produto;

struct produto {
    char cod[15];
	char desc[50];
    char marca[25];
    char cor[25];
	int quant;
	float valor;
	char status;
	char sit[20];
};

char tela_produtos(void);
void menu_produtos(void);

Produto* cadastrar_produto(void);
Produto* pesquisar_produto(void);
void alterar_produto(void);
void excluir_produto(void);

void grava_prod(Produto* produto);
void exibe_prod(Produto *produto);
void lista_prod(void);

void ler_cod(char*);
void ler_desc(char*);
void ler_marca(char*);
void ler_cor(char*);
void ler_quant(int*);
void ler_valor(float*);