
typedef struct produto Produto;

struct produto {
    char cod[14];
	char desc[40];
	char cor[12];
    char marca[12];
	int quant;
	float valor;
	char status;
	char sit[20];
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

void ler_cod(char*);
void ler_desc(char*);
void ler_marca(char*);
void ler_cor(char*);
void ler_quant(int*);
void ler_valor(float*);