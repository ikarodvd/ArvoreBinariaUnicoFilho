#include "arvoreBin.h"
#include <stdio.h>

int main() {
  // criando a arvore chamando a função cria_ArvBin
  Arvore *raiz = cria_ArvBin();
  // inserindo elementos pré definidos na arvore
  raiz = inserir(raiz, 65);
  raiz = inserir(raiz, 50);
  raiz = inserir(raiz, 95);
  raiz = inserir(raiz, 55);
  raiz = inserir(raiz, 30);
  raiz = inserir(raiz, 98);
  raiz = inserir(raiz, 60);
  raiz = inserir(raiz, 100);

  // fazendo a impressão dos elementos em ordem
  printf("\n");
  printf("Impressão em ordem: \n");
  Imprimir_in_ordem(raiz);

  // fazendo a impressão dos elementos em pre ordem

  printf("\n");
  printf("Impressão em pre ordem: \n");
  Imprimir_pre_ordem(raiz);

  // fazendo a impressão dos elementos em pos ordem
  printf("\n");
  printf("Impressão em pos ordem: \n");
  Imprimir_pos_ordem(raiz);
  // Imprimindo a quantidade de nos.

  int cont = contNosFolha(raiz);
  printf("\n\nQuantidade de NOS Folhas: %d\n", cont);

  cont = contNosInternos(raiz);
  printf("Quantidade de NOS Internos: %d\n", cont);

  int x;
  printf ("Você deseja verificar se há nós à direita (1) ou à esquerda(2)?\n");
  scanf("%d",&x);

  switch(x){
    case 1:
    printf("\nQuantidade de NOS com apenas um filho à direita: %d\n",
         contNosDir(raiz));
    break;
    case 2: 
      printf("\nQuantidade de NOS com apenas um filho à esquerda: %d\n",
         contNosEsq(raiz));
    break;
    default:
      printf ("Opção inválida!\n");
  }



  return 0;
}
