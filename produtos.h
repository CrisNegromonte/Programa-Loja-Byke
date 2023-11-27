
typedef struct produto Produto;

struct produto {
    char cod_p[14];
	char desc_p[40];
	char cor_p[12];
    char marca_p[12];
	int quant_p;
	float valor_p;
	char status_p;
	char sit_p[20];
    struct Produto* prox; // Adicionando o ponteiro para o próximo produto
};

typedef struct Node {
    Produto produto;
    struct Node* prox;
} Node;

char tela_produtos(void);
void menu_produtos(void);

Produto* cadastrar_produto(void);
Produto* pesquisar_produto(void);
void alterar_produto(void);
void excluir_produto(void);

void grava_prod(Produto* produto);
void exibe_prod(Produto *produto);
void lista_prod(void);

void ler_cod_p(char*);
void ler_desc_p(char*);
void ler_marca_p(char*);
void ler_cor_p(char*);
void ler_quant_p(int*);
void ler_valor_p(float*);