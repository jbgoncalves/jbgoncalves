/*Escreva uma fun��o para mesclar duas listas ordenadas de forma crescente recebidas como
par�metro, ou seja, transformar as duas em uma mantendo a ordena��o. A mescla deve ser feita
percorrendo as duas listas, e n�o concatenando uma no fim da outra e ent�o ordenando. Al�m disso,
nenhum novo elemento deve ser alocado.*/

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


    /*if(px->prox == NULL){
        px->prox= paux;
        paux->prox= NULL;
    }
    else{
        paux->prox= px->prox;
        px= paux;
    }

    return pini;
    */
}

struct item *juntarLISTAS(struct item *l1, struct item *l2){

    struct item *lp, *lf;

    if(!l1)
        return l2;

    else if(!l2)
        return l1;

    else{
        if(l1->id >= l2->id){
            lf= l2;
            lp= l2;
            l2= l2->prox;
        }
        else{
            lf= l1;
            lp= l1;
            l1= l1->prox;
        }

        while(l1 && l2){
            if(l1->id >= l2->id){
                lp->prox= l2;
                l2= l2->prox;
                lp= lp->prox;

            }
            else{
                lp->prox= l1;
                l1= l1->prox;
                lp= lp->prox;
            }
        }
        if(!lp->prox && !l1)
            lp->prox= l2;
        else
            lp->prox= l1;
        return lf;
    }
}

main(){

    struct item *p1, *p2;
    int n;

    p1 = NULL;

    puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n != -1){
       p1= insertORDEM(p1, n);
       fflush(stdin);
       puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
       scanf("%d", &n);
    }

    mostrar(p1);
    //----------------------------------------------------------------------------//
    //----------------------------------------------------------------------------//

    p2 = NULL;

    fflush(stdin);
    puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
    scanf("%d", &n);
    fflush(stdin);

    while(n != -1){
       p2= insertORDEM(p2, n);
       fflush(stdin);
       puts("Digite um n�mero referente ao id do item/user ou '-1' para sair: ");
       scanf("%d", &n);
    }
    mostrar(p2);

    //------------------------------------------------------------------------------//
    //------------------------------------------------------------------------------//
    p1 = juntarLISTAS(p1, p2);

    puts("Listas ordenadas:");
    mostrar(p1);

    killITEM(p1);



}
