/*Escrever um programa que l� dois valores, x e y, e chama uma fun��o para calcular x elevado na y (assuma x e y inteiros n�o
negativos). A fun��o deve retornar o valor resultante para a fun��o main, para ent�o ser exibido. N�o utilize a fun��o
pronta pow!*/


#include<stdio.h>
#include<locale.h>

int funcpotencia(int x, int y){
    if(y == 0)
        return 1;
    int i, aux;
    aux = x;
    for(i = 1; i < y; i++){
        x = x * aux;

    }
    return x;

}

main(){
setlocale(LC_ALL, "portuguese");
    int x,y;

    printf("Digite um n�mero e a pot�ncia para que ele seja elevado: ");
    scanf("%d", &x);
    scanf("%d", &y);

    x =funcpotencia(x,y);
    printf("O resultado � %d", x);



}
