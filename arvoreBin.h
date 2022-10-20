#ifndef ARVOREBIN_H
#define ARVOREBIN_H
// estrutura arvore
struct arvore {
  int info;
  struct arvore *esq; // ponteiros do tipo arvore que aponta para os filhos a
                      // direita e a esquerda
  struct arvore *dir;
};
typedef struct arvore
    Arvore; // usando a função typedef para mudar o nome da estrutura

// cabeçario das funções
Arvore *cria_ArvBin();

Arvore *inserir(Arvore *raiz, int valor);

void Imprimir_in_ordem(Arvore *a);

void Imprimir_pre_ordem(Arvore *a);

void Imprimir_pos_ordem(Arvore *a);

int contNosFolha(Arvore *raiz);
int contNosInternos(Arvore *raiz);
int contNosDir(Arvore *raiz);
int contNosEsq(Arvore *raiz);

#endif
