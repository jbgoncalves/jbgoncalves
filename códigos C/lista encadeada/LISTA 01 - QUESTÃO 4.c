/*4. A atribui��o Segunda = Primeira; pode ser considerada uma c�pia de uma lista? N�o, pois
embora haja dois ponteiros (Segunda e Primeira), a lista � uma s�, ou seja, os dois ponteiros apontam
para a mesma lista, e modifica��es em uma se refletir�o na outra. Escreva uma fun��o que receba como
par�metro um ponteiro para o primeiro elemento de uma lista e retorne um ponteiro para o primeiro
elemento de outra lista que � uma c�pia da recebida como par�metro. (duplique a lista).*/

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

///FUN��O PARA INSERIR NO IN�CIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, int n){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //aloca��o de mem�ria para a nova struct

    paux->id= n;
    paux->prox= pini;
    return paux;
}

///FUN��O PARA DUPLICAR LISTA ENCADEADA///
struct item *duplicarLIST(struct item *p1){
    struct item *p2, *aux, *lf;
    aux = p2 = NULL;

    if(p1){                 //fa�o este if para garantir q o aux n�o entre NULL no la�o, ai n tento acessar ponteiro nulo de struct aux->prox
        aux=p2;
        p2= (struct item *) malloc (sizeof(struct item));
        lf= p2;             //Guardo a posi��o inicial do novo ponteiro
        p2->id= p1->id;     //O primeiro id da segunda lista original vai para a nova lista
        p1= p1->prox;       //Lista original vai para o segundo elemento
    }

    while(p1){
        aux=p2;             //Garanti q o aux n�o ser� NULL dentro do la�o
        p2= (struct item *) malloc(sizeof(struct item));
        p2->id= p1->id;     //O respectivo elemento da lista original vai para a nova lista
        aux->prox= p2;      //Aux est� no anterior p2, ou seja, aux->prox = p2;
        p1= p1->prox;       //lista original avan�a
    }
    p2->prox= NULL;         //Tenho que garantir que no final da lista c�pia ter� um fim, portanto p2->prox= NULL
    return lf;              //Retorno ponteiro inicial
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

    p2 = duplicarLIST(p1);

    mostrar(p2);

    killITEM(p1);
    killITEM(p2);

}
