/*2. Fa�a um programa que passe um vetor de 50 elementos inteiros para uma
fun��o na qual ele � preenchido com 50 valores inteiros informados pelo usu�rio.
A posi��o no vetor que cada elemento ocupar� ser� definida aleatoriamente.
Quando o vetor j� estiver com a maioria de suas posi��es ocupadas, � prov�vel
que a fun��o de gera��o de n�meros pseudo-aleat�rios indique posi��es j�
ocupadas. Uma forma de lidar com este problema seria continuar gerando �ndices
poss�veis at� encontrar uma posi��o desocupada. Procure fazer um programa
que, garantidamente, precise de apenas 50 chamadas � fun��o de gera��o de
n�meros para definir as 50 posi��es.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
#define TAM 10


void func1(int vet[]){              //fun��o void pois alterei os endere��es. E assim utilizei uma passagem por refer�ncia "discreta".
    int i, j, n;                    // Vari�veis = n= valor que usu�rio quer por no vetor aleat�riamente. i = indice de qts posi��es ja
    for(i = 0; i < TAM; i++)        // foi preenchida. j= posi��o sorteada pelo rand.
        vet[i] = -10;
        printf("%d", &vet);
    for(i = 0; i < TAM; ){          // la�o que faz o i avan�ar a cada vez que uma posi��o for preenchida aleat�riamente.
        j = rand() % 10;            // j = gera a posi��o aleat�ria.
        if(vet[j] == -10){          // verifico se � valida.
            printf("Informe um valor usu�rio: \n");
            scanf("%d", &n);        // user digita o numero.
            vet[j] = n;
            i++;
        }
    }

}



main(){
setlocale(LC_ALL, "portuguese");

    int vet[TAM],i;

    srand((unsigned)time(NULL));        //inicializar semente.
    func1(vet);                         // passar vet pra fun��o.
    printf("Valores dentro do vetor:");
    for(i = 0; i < TAM; i++){
        printf("%d -- ", vet[i]);       // resultado do vetor ap�s a passagem dos valores para posi��es pseudoaleat�rias.
    }
}
