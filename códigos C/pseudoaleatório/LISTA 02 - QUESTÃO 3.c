/*Escreva um programa que leia tr�s valores inteiros, A, B e N ( assuma que | A �
B | > 3N ). O programa deve gerar dois valores aleat�rios x e y, ambos entre A e B
e com diferen�a entre eles maior que N ( ou seja, | x � y | > N ). Uma forma de
garantir a diferen�a m�nima entre os valores da gera��o aleat�ria � gerar primeiro
x e depois gerar tantos valores para y quantos necess�rios at� que tal restri��o
seja obedecida. Mas � desej�vel que voc�s codifiquem uma solu��o que garanta
que o primeiro valor de y j� ser� satisfat�rio, ou seja, uma solu��o em que a
fun��o de gera��o de n�meros aleat�rios seja chamada apenas duas vezes.*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>


main(){
setlocale(LC_ALL, "portuguese");


    int a,b,n,x,y;
    printf("Digite tr�s valores inteiros");         // ex: a = 20 b = 10 n = 10 //
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &n);
    x = rand() % (a-b) + b;     // x = 12
        if(x )
        y = rand() %(a-b) + b;  // y = 14











}
