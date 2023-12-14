#ifndef RELATORIOS_H
#define RELATORIOS_H




void menu_relatorios(void);

char tela_relat(void);
void tela_relat_cli(void);
char relat_cli(void);
void relat_todos_clientes(void);
void relat_cli_inativos(void);
void relat_cli_alfa(void);
//void relat_clientes_por_cidade(void);

void tela_relat_colab(void);
char relat_colab(void);
void relat_todos_colab(void);
void relat_colab_inativos(void);
void relat_colab_alfa(void);
//voidrelat_colab_por_funcao(void);

void tela_relat_prod(void);
char relat_prod(void);
void relat_todos_prod(void);
void relat_prod_inativos(void);
void relat_prod_por_marca(void);
void relat_prod_por_cor(void);


void tela_relat_vendas(void);
char relat_vendas(void);
void relat_todas_vendas(void);
void relat_vendas_exc(void);
//void relat_vendas_cpf_colab
//void relat_vendas_cpf_cli

char *get_cli(const char *cpf_cli);
char *get_colab(const char *cpf_colab);


#endif // RELATORIOS_H