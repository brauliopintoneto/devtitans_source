#include <stdio.h>
#include <stdlib.h>

struct arvgen {
  int info;
  struct arvgen *prim;
  struct arvgen *prox;
};
typedef struct arvgen ArvGen;

ArvGen* cria (int info)
{
  ArvGen *a =(ArvGen *)malloc(sizeof(ArvGen));
  a->info = info;
  a->prim = NULL;
  a->prox = NULL;
  return a;
}

void insere (ArvGen* a, ArvGen* f)
{
  f->prox = a->prim;
  a->prim = f;
}

void libera (ArvGen* a)
{
  ArvGen* p = a->prim;
  while (p!=NULL) {
    ArvGen* t = p->prox;
    libera(p);
    p = t;
  }
  free(a);
}

void imprime (ArvGen* a)
{
  ArvGen* p;
  printf("%d ",a->info);
  for (p=a->prim; p!=NULL; p=p->prox)
    imprime(p);
}

int busca (ArvGen* a, int c)
{
  ArvGen* p;
  if (a->info==c)
    return 1;
  else {
    for (p=a->prim; p!=NULL; p=p->prox) {
      if (busca(p,c))
        return 1;
    }
  }
  return 0;
}

int main()
{
  ArvGen * root;
  // Level 0
  ArvGen * node43 = cria(43);
  // Level 1
  ArvGen * node22 = cria(22);
  ArvGen * node21 = cria(21);
  ArvGen * node58 = cria(58);
  ArvGen * node45 = cria(45);
  // Level 2
  ArvGen * node66 = cria(66);
  ArvGen * node31 = cria(31);
  ArvGen * node71 = cria(71);
  ArvGen * node59 = cria(59);
  ArvGen * node12 = cria(12);
  ArvGen * node35 = cria(35);

  insere(node22, node31);
  insere(node22, node66);
  insere(node58, node12);
  insere(node58, node59);
  insere(node58, node71);
  insere(node45, node35);
  insere(node43, node45);
  insere(node43, node58);
  insere(node43, node21);
  insere(node43, node22);
  
  root = node43;

  imprime(root);
  printf("\n");

  printf("Searching item 12: ");
  int search12 = busca(root, 12);
  if (search12 == 1) {
    printf(" founded! \n");
  } else {
    printf(" not founded! \n");
  }
  
  printf("Searching item 88: ");
  int search8 = busca(root, 88);
  if (search8 == 1) {
    printf(" founded! \n");
  } else {
    printf(" not founded! \n");
  }
  libera(root);
}
