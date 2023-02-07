/* 2. Escreva uma fun��o que receba como par�metro um ponteiro para a raiz de uma �rvore bin�ria e um valor inteiro
indicando um n�vel, e retorne o n�mero de n�s deste n�vel na �rvore.*/

#include<stdio.h>
#include<stdlib.h>

struct elemento{
    int valor;
    struct elemento *fesq;
    struct elemento *fdir;
};

///NESTE CASO, PRIMEIRO MOSTRA O ELEMENTO E DEPOIS AVAN�A, DANDO PRIORIDADE PARA OS "Fesq"///

void prefixado(struct elemento *arv) {
  if (arv) {
    printf("%d ", arv->valor);
    prefixado(arv->fesq);
    prefixado(arv->fdir);
    }
}

///NESTE CASO, PRIMEIRO MOSTRA O ELEMENTO MAIS DA ESQUERDA, DEPOIS SEU PAI, E POR FIM O SEU///
///ELEMENTO MAIS DA DIREITA///

void central(struct elemento *arv) {
  if (arv) {
    central(arv->fesq);
    printf("%d ", arv->valor);
    central(arv->fdir);
    }
}

///NESTE CASO, SEMPRE TENTA MOSTRAR OS N�S FOLHAS, DANDO PRIORIDADE PARA AS FOLHAS DA///
///ESQUERDA, MOSTRA FILHO DA ESQUERDA, FILHO DA DIREITA E SEU PAI, ASSIM POR DIANTE///

void posfixado(struct elemento *arv) {
  if (arv) {
    posfixado(arv->fesq);
    posfixado(arv->fdir);
    printf("%d ", arv->valor);
    }
}

///ALOCA TODOS OS ELEMENTOS DO VETOR "Armazenada", SENDO QUE O "Fesq" � OS PARES E O "Fdir" S�O OS �MPARES///
///QUALQUER VALOR NO VETOR QUE FOR "-1", SIGNIFICA QUE N�O TEM ELEMENTO NAQUELA POSI��O///

// int armazenada[16] = { 0, 10, 2, 3, 47, 5, 6, 7, 58, 9, 10, 11, 12, 103, -1, 15 };
struct elemento *alocar(int no, int armazenada[]) {
  struct elemento *novo;
  if (armazenada[no] != -1 && no < 16) {
    novo = (struct elemento *) malloc (sizeof(struct elemento));
    novo->valor = armazenada[no];
    novo->fesq = alocar(no*2, armazenada);
    novo->fdir = alocar(no*2+1, armazenada);
    return novo;
    }
  return NULL;
  }

///FUN��O QUE RECEBE UMA ARV�RE E O VALOR PARA UM N�VEL, E DIZ QUANTOS N�S EXISTEM NAQUELE N�VEL///

int n_element(struct elemento *arv, int nivel){
    int n = 0;

    if(!arv)
        return 0;

    n += n_element(arv->fesq, nivel-1);
    n += n_element(arv->fdir, nivel-1);

    if(nivel == 0)
        return 1;

    return n;
}

///FUN��O QUE ELIMINA A �RVORE, RETIRANDO OS FOLHAS INICIAMENTE, OBVIAMENTE///

void eliminar(struct elemento *arv) {
  if (!arv)
    return;
  eliminar(arv->fesq);
  eliminar(arv->fdir);
  free(arv);
  }

int main(){
    int armazenada[16] = { 0, 10, 2, 3, 47, 5, 6, 7, 58, 9, 10, 11, 12, 103, -1, 15 };
    struct elemento *aux, *raiz = NULL;
    int n;

    printf("\n\n");
    raiz = alocar(1, armazenada);

    prefixado(raiz);
    printf("\n\n");
    central(raiz);
    printf("\n\n");
    posfixado(raiz);
    printf("\n\n");


    puts("Digite um nivel para verificar quantos elementos tem naquele nivel:");
    scanf("%d", &n);

    printf("Numero de elementos no nivel %d e: %d", n, n_element(raiz,n));


return 0;
}
