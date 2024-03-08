#include "arvore.h"

Arvore *cria_arv_vazia(void)
{
  return NULL;
}

Arvore *constroi_arv(char c, Arvore *e, Arvore *d)
{
  Arvore *no = (Arvore *)malloc(sizeof(Arvore));
  no->info = c;
  no->esq = e;
  no->dir = d;
  return no;
}

int verifica_arv_vazia(Arvore *a)
{
  return (a == NULL);
}

void arv_libera(Arvore *a)
{
  if (!verifica_arv_vazia(a))
  {
    arv_libera(a->esq);
    arv_libera(a->dir);
    free(a);
  }
}

//========= Exercício 2 - pré-ordem ====
void pre_order(Arvore *a)
{
  if (verifica_arv_vazia(a))
    return;

  printf("%c\t", a->info);
  pre_order(a->esq);
  pre_order(a->dir);
}

//========= Exercício 2 - in-ordem ====
void in_order(Arvore *a)
{
  if (verifica_arv_vazia(a))
    return;

  in_order(a->esq);
  printf("%c\t", a->info);
  in_order(a->dir);
}

//========= Exercício 2 - pós-ordem ====
void pos_order(Arvore *a)
{
  if (verifica_arv_vazia(a))
    return;

  pos_order(a->esq);
  pos_order(a->dir);
  printf("%c\t", a->info);
}

//========= Exercício 3 - pertence ====
int pertence_arv(Arvore *a, char c)
{
  // pré-ordem
  if (verifica_arv_vazia(a))
    return 0;

  if (a->info == c)
    return 1;

  return pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
  /*
  a linha de cima pode ser substituida por essa aqui:
    if (pertence_arv(a->esq, c))
      return 1;
    return pertence_arv(a->dir, c);
  */
}

//========= Exercício 4 - conta nós ====
int conta_nos(Arvore *a)
{
  // pŕé-ordem
  if (verifica_arv_vazia(a))
    return 0;

  return 1 + conta_nos(a->esq) + conta_nos(a->dir);
}

//========= Exercício 5 - calcula altura ====
int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int calcula_altura_arvore(Arvore *a)
{
  if (verifica_arv_vazia(a)) // arvore vazia tem altura -1
    return -1;

  return 1 + max(calcula_altura_arvore(a->esq), calcula_altura_arvore(a->dir));
}

//========= Exercício 6 - conta folhas ====
int conta_nos_folha(Arvore *a)
{
  if (verifica_arv_vazia(a))
    return 0;

  if (verifica_arv_vazia(a->esq) && verifica_arv_vazia(a->dir))
    return 1;

  return conta_nos_folha(a->esq) + conta_nos_folha(a->dir);
}

int main(int argc, char *argv[])
{

  Arvore *a = constroi_arv('a',
                           constroi_arv('b',
                                        cria_arv_vazia(),
                                        constroi_arv('d', cria_arv_vazia(), cria_arv_vazia())),
                           constroi_arv('c',
                                        constroi_arv('e', cria_arv_vazia(), cria_arv_vazia()),
                                        constroi_arv('f', cria_arv_vazia(), cria_arv_vazia())));

  // Ex 2
  printf("Pré-Ordem: ");
  pre_order(a);
  printf("\nIn-Ordem: ");
  in_order(a);
  printf("\nPós-Ordem: ");
  pos_order(a);
  printf("\n");
  printf("'b' Pertence? %d\n", pertence_arv(a, 'b'));
  printf("'z' Pertence? %d\n", pertence_arv(a, 'z'));
  printf("Número de nós: %d\n", conta_nos(a));
  printf("Altura da Árvore: %d\n", calcula_altura_arvore(a));
  printf("Nós-folha: %d\n", conta_nos_folha(a));

  arv_libera(a);

  return 0;
}