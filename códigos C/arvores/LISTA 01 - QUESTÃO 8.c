/*8. Escreva uma fun��o que receba como par�metro um ponteiro para a raiz de uma �rvore bin�ria de pesquisa e
retorne um ponteiro para o n� FOLHA de menor valor.*/

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

///FUN��O QUE RECEBE UM PONTEIRO PARA ABP E RETORNA O NO FOLHA DE MENOR VALOR///

struct elemento *folhamenor(struct elemento *arv){

    if(!arv)
        return NULL;

    while(arv->fesq || arv->fdir){
        if(arv->fesq)
            arv = arv->fesq;
        else
            arv = arv->fdir;
    }
    return arv;
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
    raiz = inserir(4, raiz);

    mostrar1(0, raiz);
    printf("\n\n\n\n");

    printf("O menor valor que e no folha e: %d", folhamenor(raiz)->valor);
    eliminar(raiz);
    return 0;
}
