/*. Escreva uma fun��o que receba como par�metro duas listas encadeadas, e retorne o n�mero de
elementos presentes na primeira que t�m elementos com mesmo valor na segunda.*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    int id;
    struct item *prox;

};

///FUN��O PARA MOSTRAR LISTA ENCADEADA NA TELA///
void mostrar(struct item *pini){
    while(pini){                 //Enquanto "p" for v�lido, mostra os nomes,
        printf("%d ", pini->id);//pois se fosse "p->prox" n�o mostraria o �ltimo, pois testaria no final e n entraria no la�o dnv
        pini = pini->prox;
    }
    printf("\n");
}

///FUN��O PARA MATAR LISTA ENCADEADA///
void killITEM(struct item *pini){
    struct item *paux;

    while(pini){                //Crio uma vari�vel aux para ponteiro inicial, assim eu aponto para o msm lugar q o ponteiro inicial e
    paux = pini;                //avan�o com o ponteiro inicial para o pr�ximo da lista, depois do free no ponteiro auxiliar q contem o end anterior
    pini = pini->prox;
    free(paux);
    }
}

///FUN��O PARA INSERIR ELEMENTOS DE ACORDO COM O ID///
struct item *insertORDEM(struct item *pini, int n){

    struct item *paux, *px;
    px = pini;
    paux = (struct item *) malloc (sizeof(struct item));
    paux->id= n;

    if(!pini || paux->id < pini->id){
        paux->prox= pini;
        return paux;
    }

    while(px->prox != NULL && paux->id > px->prox->id)
        px = px->prox;

    paux->prox= px->prox;
    px->prox= paux;

    return pini;

}

///FUN��O PARA INSERIR NO IN�CIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, int n){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //aloca��o de mem�ria para a nova struct

    paux->id= n;
    paux->prox= pini;
    return paux;
}

///FUN��O PARA FALAR O N�MERO DE ELEMENTOS QUE TEM NA PRIMEIRA LISTA E TEM IGUAL NA SEGUNDA LISTA
int numELEREP(struct item *p1, struct item *p2){
    struct item *aux, *px;
    int cont= 0;

    aux= p2;     //Guardo inicio da segunda lista
    for( ; p1; p1= p1->prox){ //Travo no primeiro elemento
        for(p2= aux; p2;p2= p2->prox){ //entro no la�o comparando com todos elementos da segunda lista
            if(p1->id == p2->id){ //Se o elemento for igual, eu add no contador e quebro o la�o, para ir para o proximo elemento da primeira lista
                cont++;
                break;
            }
        }
    }
    return cont;            //Retorno o n�mero de repeti��es
}

main(){

    struct item *p1, *p2;
    int n;

    p1 = NULL;

    puts("Digite um numero referente ao id do item/user ou '-1' para sair: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n != -1){
       p1= insertINI(p1, n);
       fflush(stdin);
       puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
       scanf("%d", &n);
    }

    mostrar(p1);
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//

    p2 = NULL;

    fflush(stdin);
    puts("Digite um numero referente ao id do item/user ou '-1' para sair: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n != -1){
       p2= insertINI(p2, n);
       fflush(stdin);
       puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
       scanf("%d", &n);
    }
    mostrar(p2);

    n= numELEREP(p1, p2);
    printf("\n");
    printf("O numero de elementos que tem na primeira lista, e tem igual na segunda lista e %d", n);


    killITEM(p1);
    killITEM(p2);
}
