/*2. Escreva uma fun��o que receba como par�metro um ponteiro para o primeiro elemento de
uma lista encadeada e troque de posi��o entre si o primeiro e o �ltimo elementos.*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    int id;
    struct item *prox;
};

///FUN��O PARA INSERIR NO IN�CIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, int n){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //aloca��o de mem�ria para a nova struct

    paux->id= n;
    paux->prox= pini;
    return paux;
}

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

///FUN��O PARA TROCAR ENTRE SI OS DOIS PRIMEIROS E ULTIMOS ELEMENTOS///
struct item *trocarP_U(struct item *p){
    struct item *paux, *pini;
    int cont;
    cont= 0;

    if(!p || !p->prox){     // Eu garanto que pelo menos tem dois elementos de lista //
        return p;
    }
    else{
        paux= p->prox;
        p->prox= paux->prox;
        paux->prox= p;
        pini= paux;

        for(p = paux; p->prox->prox; p= p->prox){
            cont= 1;
            paux= p;
        }

        if(cont == 0){
            p= p->prox;
            p->prox= paux;
            p->prox->prox= NULL;
            return p;
        }
        else{
            paux->prox= p->prox;
            p->prox->prox= p;
            p->prox= NULL;
            return pini;
        }
    }
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

    p1= trocarP_U(p1);

    mostrar(p1);


    killITEM(p1);
}
