
typedef struct venda Vendas;


struct venda {
    
    long int cod_p;
	char cpf_cli[12];
    char cpf_colab[12];
    //int cupom;
	char cupom[6];
	char desc_p[40];
	int quant_p;
	int quant;
    //int quant;
	float valor_p;
	float preco;
	char status;
	char dataHora[40];
	char situacao[20];
    //struct vendas *prox;
};


void menu_vendas(void); 
char tela_vendas(void);

void grava_venda(Vendas* venda);
void exibe_venda(Vendas* venda);



void ler_cupom(char*);
void ler_cpf_cli (char*);
void ler_cpf_colab (char*);
void ler_Datahora(char*);
void ler_desc_p(char*);

Vendas* efetuar_venda(void);
Vendas* consultar_venda(void);
void excluir_venda(void);
void listar_vendas(void);



