/*2. Escreva uma fun��o que receba como par�metro um ponteiro para a raiz de uma �rvore bin�ria
e um valor inteiro g (cujos valores poss�veis s�o 0, 1 ou 2), e retorne o n�mero de n�s da �rvore que t�m grau igual a g.*/

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

///FUN��O QUE RECEBE UM PONTEIRO PARA UMA ARVORE BINARIA E UM VALOR X (0, 1 E 2), E RETORNA O NUMERO DE ELEMENTOS COM AQUELE GRAU///

int conta_graus(struct elemento *arv, int grau){
    int s = 0;

    if(!arv)
        return 0;

    s += conta_graus(arv->fesq, grau);
    s += conta_graus(arv->fdir, grau);

    if(!arv->fesq && !arv->fdir && grau == 0)
        return s+1;
    if((arv->fesq && !arv->fdir) || (!arv->fesq && arv->fdir) && grau == 1)
        return s+1;
    if(arv->fesq && arv->fdir && grau == 2)
        return s+1;

    return s;
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
    int armazenada[16] = { 0, 10, 2, 3, -47, 5, 6, 7, 58, -9, 10, -11, 12, -103, -1, -15 };
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

    puts("Digite um grau (0,1,2)");
    scanf("%d", &n);
    printf("O numero de nos com o grau %d e: %d\n", n, conta_graus(raiz,n));
    eliminar(raiz);

return 0;
}
