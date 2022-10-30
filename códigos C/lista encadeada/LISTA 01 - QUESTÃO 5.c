/*5. Escreva uma fun��o que receba como par�metros dois ponteiros, um para o primeiro elemento da
primeira lista, outro para o primeiro elemento da segunda lista, e retorne 1 indicando que as listas s�o
iguais ou 0 indicando que n�o s�o iguais (iguais significa listas com mesmo tamanho, com mesmos
valores na mesma ordem).*/

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

///FUN��O PARA COMPARAR DUAS LISTAS ENCADEADAS E DIZER SE S�O IGUAIS///
int mosIGUAL(struct item *p1,  struct item *p2){

    for( ;p1 && p2 && p1->id == p2->id; p1= p1->prox, p2= p2->prox); //Para os dois serem iguais, os dois tem que sair do la�o valendo NULL

    if(p1 || p2 )    //Se alguma lista ainda n�o chegou no NULL, j� sabemos que n�o s�o iguais
        return 0;
    else
        return 1;
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

    n= mosIGUAL(p1, p2);

    if(n == 1)
        puts("Listas iguais");
    else
        puts("Listas diferentes");


    killITEM(p1);
    killITEM(p2);

}
