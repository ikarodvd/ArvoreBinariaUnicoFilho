#include "arvoreBin.h"
#include <stdio.h>
#include <stdlib.h>
// função para criar uma arvore vazia
Arvore *cria_ArvBin() {
  Arvore *raiz =
      (Arvore *)malloc(sizeof(Arvore)); // fazendo o alocamento na memoria
  if (raiz != NULL) { // se a raiz não estiver vazia será atribuido nulo para
                      // ela ficar vazia.
    raiz = NULL; // quando for inserindo conteudo na arvore, isso aqui vai ser
                 // substituído por um nó
  }
  return raiz; // retorta a raiz
}
// Função para inserir elementos na arvore
Arvore *inserir(Arvore *raiz, int valor) {
  if (raiz ==
      NULL) { // se a raiz for igual a nula será feita a alocação dinamica
    raiz = (Arvore *)malloc(sizeof(Arvore));
    raiz->info = valor; // atribuindo valor
    raiz->esq = NULL;
    raiz->dir = NULL;
  } else if (valor < raiz->info) {
    raiz->esq = inserir(raiz->esq, valor);
  } else {
    raiz->dir = inserir(raiz->dir, valor);
  }
  return raiz;
}
/*Começa visitando o filho da esquerda, quando voltar do filho faz o tratamento
 * da raiz e depois vai para o filho da direita*/
void Imprimir_in_ordem(Arvore *a) {
  if (a != NULL) {
    Imprimir_in_ordem(a->esq);
    printf("%d, ", a->info);
    Imprimir_in_ordem(a->dir);
  }
}
/*Começa a partir do princípio de visitar a raiz, executar a tarefa que tem que
 * fazer primeiro, depois visita o nó da esquerda e o no da direita, faz o
 * tratamento da raiz, visita esquerda e visita direita*/
void Imprimir_pre_ordem(Arvore *a) {
  if (a != NULL) {
    printf("%d, ", a->info);
    Imprimir_pre_ordem(a->esq);
    Imprimir_pre_ordem(a->dir);
  }
}
/*começa visitando o filho da esquerda, visita o filho da direita e só depois
 * que faz o tratamento da raiz*/
void Imprimir_pos_ordem(Arvore *a) {
  if (a != NULL) {
    Imprimir_pos_ordem(a->esq);
    Imprimir_pos_ordem(a->dir);
    printf("%d, ", a->info);
  }
}

// CONTA QUANTIDADE DE NÓS INTERNOS
int contNosInternos(Arvore *raiz) {
  if (raiz == NULL) {
    return 0;
  }
  if (raiz->dir == NULL || raiz->esq == NULL) {
    return 0;
  } else {
    return 1 + contNosInternos(raiz->esq) + contNosInternos(raiz->dir);
  }
}

// CONTA QUANTIDADE DE NÓS EXTERNO (FOLHAS)
int contNosFolha(Arvore *raiz) {
  if (raiz == NULL) {
    return 0;
  }
  if (raiz->dir == NULL || raiz->esq == NULL) {
    return 1;
  } else {
    return contNosFolha(raiz->esq) + contNosFolha(raiz->dir);
  }
}

int contNosDir(Arvore *raiz) {
  if (raiz == NULL)
    return -1;

  if (raiz->dir != NULL) {
    return abs(contNosDir(raiz->dir) + contNosDir(raiz->dir));
  }
}

int contNosEsq(Arvore *raiz) {
  if (raiz == NULL)
    return -1;

  if (raiz->esq != NULL) {
    return abs(contNosEsq(raiz->esq) + contNosEsq(raiz->esq));
  }
}
