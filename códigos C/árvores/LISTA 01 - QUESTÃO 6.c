/*6. Escreva uma fun��o que receba como par�metros um ponteiro apontando para a raiz de uma �rvore bin�ria de
pesquisa e um valor num�rico, e retorne o valor da soma de todos os n�s do caminho entre a raiz e o n� que
armazena o valor passado (inclusive). Se o valor n�o existir na �rvore, deve ser retornado 0.*/

#include<stdio.h>
#include<stdlib.h>

struct elemento{
    int valor;
    struct elemento *fesq;
    struct elemento *fdir;
};

///MOSTRO OS VALORES COM IDENTA��O PARA A DIREITA///

void mostrar1(int nivel, struct elemento *arv) {
  int i;
  for(i = 0; i < nivel; i++)
    printf("   ");
  if (arv) {
    printf("%d\n", arv->valor);
    mostrar1(nivel+1, arv->fesq);
    mostrar1(nivel+1, arv->fdir);
    }
  else
    printf("-\n");
}

///FUN��O PARA INSERIR ELEMENTOS NA ABP, RECURSIVAMENTE, VOU INDO PARA O ESPA�O DO MENOR OU MAIOR VALOR, AT� CHEGAR NO NULL E ALOCAR O ELEMENTO///

struct elemento *inserirRec (int valor, struct elemento *arv) {
  if (!arv) {
    arv = (struct elemento *) malloc (sizeof(struct elemento));
    arv->valor = valor;
    arv->fdir = arv->fesq = NULL;
    return arv;
    }
  //else
  if (valor < arv->valor) {
    arv->fesq = inserirRec(valor, arv->fesq);
    }
  else {
    arv->fdir = inserirRec(valor, arv->fdir);
    }
  return arv;
}

///FUN��O PARA INSERIR ELEMENTOS NA ABP, UTILIZANDO LA�O DE REPETI��O, SE CHEGAR NO NULL, ALOCAR E AVAN�AR, SAI DO LA�O E ENDERE�O IGUAIS SAI FORA///

struct elemento *inserir (int valor, struct elemento *arv) {
  struct elemento *novo, *ini;
  novo = (struct elemento *) malloc (sizeof(struct elemento));
  novo->valor = valor;
  novo->fdir = novo->fesq = NULL;
  if (!arv)
    return novo;
  ini = arv;
  while(arv != novo) {
    if (valor < arv->valor) {
      if (!arv->fesq)
        arv->fesq = novo;
      arv = arv->fesq;
      }
    else {
      if (!arv->fdir)
        arv->fdir = novo;
      arv = arv->fdir;
      }
    }
  return ini;
}

///FUN��O PARA LOCALIZAR VALOR NA ARV�RE, RETORNA UM PONTEIRO PARA O ELEMENTO COM O VALOR PEDIDO, SE RETORNAR NULL � Q N�O TEM O VALOR///

struct elemento *localizar (int valor, struct elemento *arv) {
  if (!arv)
    return NULL;
  while(arv && arv->valor != valor) {
    if (valor < arv->valor) {
      arv = arv->fesq;
      }
    else {
      arv = arv->fdir;
      }
    }
  return arv;
}

///FUN��O QUE RECEBE UM PONTEIRO PARA ABP E UM VALOR NUMERICO, FA�O O CAMINHO SOMANDO POR QUEM PASSAR AT� CHEGAR NO NUMERO, INCLUINDO ELE///
///CASO N�O EXISTA ELE, RETORNE 0///

int soma_chegar(struct elemento *arv, int valor){
    int s = 0, f = 1;

    if(!arv)
        return 0;

    while(arv){
        if(valor == arv->valor)
            f = 0;
        if(valor < arv->valor){
            s += arv->valor;
            arv = arv->fesq;
        }
        else{
            s += arv->valor;
            arv = arv->fdir;
        }
    }

    if(f == 1)
        return 0;
    else
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
    struct elemento *aux, *raiz = NULL;

    raiz = inserir(60, raiz);
    raiz = inserir(40, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(3, raiz);
    raiz = inserirRec(15, raiz);
    raiz = inserirRec(51, raiz);
    raiz = inserirRec(70, raiz);
    raiz = inserir(80, raiz);
    raiz = inserir(71, raiz);
    raiz = inserir(72, raiz);
    raiz = inserir(111, raiz);
    raiz = inserir(121, raiz);
    raiz = inserir(-3, raiz);

    mostrar1(0, raiz);
    printf("\n\n\n\n");

    printf("O valor da soma do caminho ate o valor e: %d", soma_chegar(raiz, 72));
    eliminar(raiz);
    return 0;
}
