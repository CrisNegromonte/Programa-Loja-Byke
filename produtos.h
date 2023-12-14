
typedef struct produto Produto;

struct produto {
    //char cod_p[14];
	long int cod_p;
	char desc_p[40];
	char cor_p[12];
    char marca_p[12];
	int quant_p;
	float valor_p;
	char status_p;
	char sit_p[20];
    struct Produto* prox; // Adicionando o ponteiro para o próximo produto
};



char tela_produtos(void);
void menu_produtos(void);

Produto* cadastrar_produto(void);
Produto* pesquisar_produto(void);
void alterar_produto(void);
void excluir_produto(void);
void lista_prod(void);


void grava_prod(Produto* produto);
void exibe_prod(Produto *produto);

//void ler_cod_p(long int*);
//void ler_cod_p(char*);
void ler_desc_p(char*);
void ler_marca_p(char*);
void ler_cor_p(char*);
void ler_quant_p(int*);
void ler_valor_p(float*);


char* get_prod(const long int cod_p);
int get_est_prod(long int cod_p, int quant_p);
float get_val_prod(long int cod_p);

