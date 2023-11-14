#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"


#define true 1
#define false 0

/// Pausa
void delay(int segundos) {
  int tempo = 1000 * segundos;
  clock_t inicio = clock();
  while (clock() < inicio + tempo) {
    // apenas dá um pequeno tempo
  }
}


// Limpa a Tela
void limpaTela(void) {
  if (system("clear") || system("cls")) {

  }
}


/// Se caractere recebido for um digito (entre 0 e 9), retorna 1
/// Caso contrario, retorna 0
int ehDigito(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  } else {
    return false;
  }
}



int ehBissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return true;
  } else if (aa % 400 == 0) {
    return true;
  } else {
    return false;
  }
}


/// Adaptacao da funcao do professsor Flavius Gorgonio (programa exemplo)
/// Se string exclusivamente alfabetico e for letra entre 'A' e 'Z' ou 'a' e 'z', retorna 1
/// Caso nao, retorna 0
int ehLetra(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    return true;
  } else if (c == ' ' || c == 13) {
    return true;
  } else {
    return false;
  }
}


int ehValido(char c) {
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    return true;
  } else if (c == ' ' || c == 13) {
    return true;
  } else if (c >= '0' && c <= '9') {
    return true;
  }  else if (c == '.' || c == '_' || c == '@') {
    return true;
  } else { 
    return false;
  }
}

/// Adaptacao da funcao do professsor Flavius Gorgonio (programa exemplo)
/// Se mes e ano correspondem a uma data valida retorna 1, incluindo anos bissextos
/// Caso contrario retorna 0

int validarData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return false;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return false;
  return true;
}

/// Adaptacao da funcao do professsor Flavius Gorgonio (programa exemplo)

int validarNome(char* nome) {
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehLetra(nome[i])) {
      return false;
    }

  }
  return true;
}

/// Funcao do professsor Flavius Gorgonio (programa exemplo)

int validarFone(char* fone) {
  int tam;

  tam = strlen(fone);
  if (tam < 11 || tam > 12) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
      return false;
    }
  }
  return true;

}

/// Funcao do professsor Flavius Gorgonio (programa exemplo)
int validarQuant(char* x) {
  int tam;

  tam = strlen(x);
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(x[i])) {
      return false;
    }
  }
  return true;
}

int validarCod(char* cod) {
  int tam;

  tam = strlen(cod);
  if (tam < 12 || tam > 13) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(cod[i])) {
      return false;
    }
  }
  return true;
}


int validarDesc(char* desc) {
  for (int i=0; desc[i]!='\0'; i++) {
    if (!ehLetra(desc[i])) {
      return false;
    }

  }
  return true;
}

int validarCor(char* cor) {
  for (int i=0; cor[i]!='\0'; i++) {
    if (!ehLetra(cor[i])) {
      return false;
    }

  }
  return true;
}


int validarMarca(char* marca) {
  for (int i=0; marca[i]!='\0'; i++) {
    if (!ehLetra(marca[i])) {
      return false;
    }

  }
  return true;
}


/// Funcao do professsor Flavius Gorgonio (programa exemplo)

int validarCpf(char* cpf) {
  int tam;

  tam = strlen(cpf);
  if (tam < 11 || tam > 12) {
    return false;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(cpf[i])) {
      return false;
    }
  }
  return true;
}

// Função baseada no código de https://github.com/DayXL/Atividade-projeto-bonelaria.git

int validarNumInteiro(char* numero) {
    int i = 0;

    while (numero[i] != '\0') {
        if ((numero[i] >= '0') && (numero[i] <= '9')) {
            i = i + 1;

        }

        else {
            return false;

        }

    }

    return true;

}

// Funcao feita pelo Chatgpt

int validarEmail(char* email) {
  int tam = strlen(email);
  int contemArroba = 0;
   // Verifica se o email tem pelo menos um caractere '@' e um ponto '.'
  for (int i = 0; i < tam; i++) {
    if (email[i] == '@') {
      contemArroba = 1;
    } else if (email[i] == '.') {
      if (contemArroba) {
        return true;
      }
    } else if (!ehValido(email[i])) {
      return false;
    }
  }
  return false;
}

