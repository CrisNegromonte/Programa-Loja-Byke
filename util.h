#ifndef UTIL_H
#define UTIL_H

void delay(int);
void limpaTela(void);
int ehDigito(char);
int ehLetra(char);
int ehBissexto(int);
int ehValido(char);
int validarData(int, int, int);
int validarCpf(char*);
int validarNome(char*);
int validarQuant(char*);
int validarNumInteiro(char*);
int validarEmail(char*);
int validarFone(char*);

#endif 