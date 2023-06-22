#include <stdio.h>
#include <stdlib.h>


struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* inicializa(void)
{
  return NULL;
}

Arv* cria(int c, Arv* sae, Arv* sad)
{
  Arv* p=(Arv*)malloc(sizeof(Arv));
  p->info = c;
  p->esq = sae;
  p->dir = sad;
  return p;
}

int vazia(Arv* a)
{
  return a==NULL;
}

Arv* libera (Arv* a){
  if (!vazia(a)){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}

void imprime_pre (Arv* a)
{

}

void imprime_in (Arv* a)
{

}

void imprime_pos (Arv* a)
{

}

int main()
{
  // Left Side of Tree
  Arv * node67 = cria(67, NULL, NULL);
  Arv * node34 = cria(34, NULL, node67);
  Arv * node12 = cria(12, NULL, NULL);
  Arv * node5 = cria(5, node12, node34);
  
  // Right Side Of Tree
  Arv * node40 = cria(40, NULL, NULL);
  Arv * node80 = cria(80, NULL, node40);

  // Main Node
  Arv * node = cria(45, node5, node80);


  printf("Ola Mundo do ArvBin.c\n");
}

