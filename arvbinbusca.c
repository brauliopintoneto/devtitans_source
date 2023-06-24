#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* busca (Arv* r, int v)
{
  if (r == NULL) return NULL;
  else if (r->info > v) return busca(r->esq,v);
  else if (r->info < v) return busca(r->dir,v);
  else return r;
}


Arv* insere (Arv* a, int v)
{
  if (a==NULL) {
    a = (Arv*)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq,v);
  else /* v < a->info */
    a->dir = insere(a->dir,v);
  return a;
}

int vazia(Arv* a) {
  return 0;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}


void imprime (Arv* r)
{
  if (r == NULL) {
    return;
  }

  imprime(r->esq);
  if (r != NULL) {
    printf("%d ", r->info);
  }  
  imprime(r->dir);
}



int main(void)
{
  Arv * root, * item;
  
  root = item = insere(NULL, 1);
  item = insere(item, 2);
  imprime(root);
  printf("\n");
  item = insere(item, 3);
  imprime(root);
  printf("\n");
  item = insere(item, 5);
  imprime(root);
  printf("\n");
  item = insere(item, 15);
  imprime(root);
  printf("\n");
  item = insere(item, 7);
  imprime(root);
  printf("\n");
  return 0;
}
