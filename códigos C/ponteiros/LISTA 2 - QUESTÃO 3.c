/*Escreva um programa em C que leia dois vetores de 500 elementos inteiros cada um, al�m de dois
valores inteiros m e n. Os dois vetores, m e n devem ser passados para uma fun��o na qual cada elemento
de �ndice entre m e n deve ter seu valor trocado com o valor colocado na mesma posi��o do outro vetor. A
fun��o deve receber cada vetor atrav�s de um ponteiro para o seu primeiro elemento, e n�o devem ser
usados �ndices na manipula��o.*/

#include<stdio.h>
#include<locale.h>
#define NUM 6

void *trocavalores(int *vet1, int *vet2, int m, int n){
    int aux;
    //paux = vet1;
    for( ; m <= n; m++){                    //5/6/9/2/8/5/
         aux = *(vet1 +m);
        *(vet1 +m) = *(vet2 +m);
        *(vet2 +m) =  aux;
        /*  *(paux + m) = *vet1;
        *(vet1 + m) = *(vet2+m);
        *(vet2 + m) = *(paux+m);*/
    }
    //printf("\n%d", *(paux+1));
   // printf("\n%d", *(vet2+1));


}


main(){
setlocale(LC_ALL, "portuguese");
    int vet1[NUM], vet2[NUM];
    int m, n, i;

    printf("Digite os valores para o primeiro vetor: ");
    for(i = 0; i < NUM; i++){
        scanf("%d", &vet1[i]);
    }
    printf("Digite os valores para o segundo vetor: ");
    for(i = 0; i < NUM; i++){
        scanf("%d", &vet2[i]);
    }
    printf("Digite os valores de m e n, respectivamente: ");
    scanf("%d", &m);            // 2
    scanf("%d", &n);            // 5

    trocavalores(vet1,vet2, m, n);

    printf("Os valores do primeiro vetor s�o: ");
    for(i = 0; i < NUM; i++){
        printf("%d-", vet1[i]);
    }
    printf("\nOs valores do segundo vetor s�o: ");
    for(i = 0; i < NUM; i++){
        printf("%d-", vet2[i]);
    }







}
