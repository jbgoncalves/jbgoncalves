/*1. Escreva um programa em cuja fun��o main sejam lidos valores para duas vari�veis inteiras.
 A seguir, deve ser chamada uma fun��o, passando as vari�veis lidas como par�metros, onde � calculada a m�dia aritm�tica dos valores lidos e,
se a m�dia for um valor inteiro, ela � atribu�da �s vari�veis. Se a m�dia n�o for um valor inteiro,
uma das vari�veis deve receber o maior valor inteiro menor que a m�dia e a outra vari�vel deve receber o menor valor inteiro maior que a m�dia,
ou seja, os dois valores inteiros entre os quais est� a m�dia (por exemplo, lidos os valores 4 e 7, a m�dia � 5.5,
e as vari�veis devem assumir os valores 5 e 6). Ao final do programa, a fun��o main deve mostrar os valores resultantes das vari�veis na tela.
 N�o use vari�veis globais!*/

 #include<stdio.h>
 #include<locale.h>

 void *func1(int *a, int *b){
        int n;

        n = *a + *b;

        if(n % 2 == 0){
            *a = n / 2;
            *b = n /2;
        }
        else{
            *a = n/2;
            *b = n/2+1;
        }
 }

 main(){
setlocale(LC_ALL, "portuguese");
     int a,b;

     printf("Digite dois valores: ");
     scanf("%d", &a);
     scanf("%d", &b);
     func1(&a,&b);
     printf("Os valores s�o %d e %d", a, b);















 }
