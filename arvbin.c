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
    printf("%d ", a->info);    
    a->esq = NULL;
    a->dir = NULL;
    a = NULL;

    free(a); /* libera raiz */    
  }
  return NULL;
}

void imprime_pre (Arv* a)
{
  if (!vazia(a)){
    printf("%d ", a->info);
    imprime_pre(a->esq); 
    imprime_pre(a->dir); 
  }
}

void imprime_in (Arv* a)
{
  if (!vazia(a)){
    imprime_in(a->esq); 
    printf("%d ", a->info);    
    imprime_in(a->dir); 
  }
}

void imprime_pos (Arv* a)
{
  if (!vazia(a)){
    imprime_pos(a->esq);    
    imprime_pos(a->dir);     
    printf("%d ", a->info);
  }
}

Arv * localiza(int value, Arv * parent, Arv * child, int dir)  {

  if (child == NULL) {    
    return NULL;
  }

  if (value == child->info) {
    if (dir) {
      parent->dir = NULL;
    } else {
      parent->esq = NULL;
    }
    return child;
  } else {
    localiza(value, child, child->dir, 1);
    localiza(value, child, child->esq, 0);
  } 

  return NULL;
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
  Arv * node3 = cria(3, cria(66, NULL, NULL), cria(31, NULL, NULL));
  
  // Main Node
  Arv * node = cria(45, cria(5, 
                            cria(12, NULL, NULL), 
                            cria(34, NULL, 
                                cria(67, NULL, NULL))), 
                        cria(80, NULL, 
                            cria(40, NULL, NULL)));
  

  printf("Pré-Fixado: ");
  imprime_pre(node);
  printf("\nIn-Fixado: ");
  imprime_in(node);
  printf("\nPós-Fixado: ");
  imprime_pos(node);

  printf("\n\n\nCriando a árvore da questão 3...\n");
  Arv * sub_node = cria(3, cria(66, NULL, NULL), cria(31, NULL, NULL));

  printf("Inserindo a árvore da questão 3 na árvore principal...\n\n");
  node->dir->esq = sub_node;

  printf("Pré-Fixado: ");
  imprime_pre(node);
  printf("\nIn-Fixado: ");
  imprime_in(node);
  printf("\nPós-Fixado: ");
  imprime_pos(node);

  printf("\n\nQUESTÃO 4: Poda a sub-arvore com raiz igual a 34:\n");  
  Arv * copy = node;
  Arv * dir = localiza(34, copy, copy->dir, 1) ;
  Arv * esq = localiza(34, copy, copy->esq, 0);  
  if (dir != NULL) {
    printf("34 localizado na direita");  
  } else if (esq != NULL) {
    printf("34 localizado na esquerda");  
  }
  printf("\nResult:");
  imprime_in(copy); 
  printf("\n");
  
  if (node == NULL) {
    printf("\n\nArvore liberada com sucesso!\n\n");
  }

  return 0;
}

