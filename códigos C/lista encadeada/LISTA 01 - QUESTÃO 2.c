/*2. Escreva uma fun��o que receba como par�metro uma lista encadeada e elimine todos os elementos
que estejam repetidos, mantendo apenas a primeira ocorr�ncia de cada, ou seja, de todos os elementos
que possu�rem o mesmo conte�do, deve ficar apenas o primeiro.*/

#include<stdio.h>
#include<stdlib.h>

struct item {
    char nome;
    struct item *prox;
};

///FUN��O PARA INSERIR NO IN�CIO DA LISTA ENCADEADA, ALOCANDO DINAMICAMENTE///
struct item *insertINI(struct item *pini, char l){
    struct item *paux;      //ponteiro aux, o novo elemento a ser colocado na ordem pedida
    paux = (struct item *) malloc (sizeof(struct item));    //aloca��o de mem�ria para a nova struct

    paux->nome= l;
    paux->prox= pini;
    return paux;
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

///FUN��O PARA MOSTRAR LISTA ENCADEADA NA TELA///
void mostrar(struct item *pini){
    while(pini){                 //Enquanto "p" for v�lido, mostra os nomes,
        printf("%c", pini->nome);//pois se fosse "p->prox" n�o mostraria o �ltimo, pois testaria no final e n entraria no la�o dnv
        pini = pini->prox;
    }
    printf("\n");
}

///FUN��O PARA MATAR IDS/NOMES IGUAIS, DEIXANDO SOMENTO O PRIMEIRO///
void killREP(struct item *px){
    struct item *aux, *pp, *ant;


    while(px){ // LA�O DUPLO, UM PRA FIXAR EM UMA LETRA E O OUTRO PARA VARRER//
        ant= px;    // O endere�o do valor anterior v�lido do auxiliar
        for(aux= px->prox; aux;  ){ // inicializo o segundo la�o no pr�ximo valor do encadeamento l�gico
            if(px->nome == aux->nome){  //se for igual as letras do la�o inicial e do segundario eu fa�o o free da letra a ser morta e avan�o                                                                      // A A C A
                pp= aux;
                aux= aux->prox;
                free(pp);
                ant->prox= aux;
            }
            else{                       //caso as letras n�o sejam iguais, eu avan�o minha anterior para a proxima letra v�lida e avan�o a letra do segundo
                ant= aux;               //la�o para a pr�xima passada
                aux= aux->prox;
            }
        }
        px= px->prox;                   //avan�o o ponteiro do la�o inicial para o pr�ximo elemento l�gico
    }
}

main(){
    char letra;
    struct item *p2;
    p2 = NULL;

    puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair: ");
    fflush(stdin);
    scanf("%c", &letra);

    while(letra != '@'){
        p2 = insertINI(p2, letra); //Passo letra que o usu�rio digitou mais o ponteiro com endere�o inicial
        fflush(stdin);
        puts("Digite uma letra referente ao nome que deseja inserir na lista ou '@' para sair: ");
        scanf("%c", &letra);
    }

    mostrar(p2);

    killREP(p2);

    mostrar(p2);

    killITEM(p2);
}
