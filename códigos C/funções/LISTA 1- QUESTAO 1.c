/*1. Escreva um programa que leia um n�mero inteiro e passe o n�mero para uma fun��o em
que � calculado o valor do seu fatorial. O resultado deve ser mostrado na fun��o main.*/

#include<stdio.h>
#include<locale.h>
                                                // 5 * 4 *3 *2* 1*
int func(int n){
    int i;
    i = n-1;
    for(i ; i > 0; i--){
        n = n * i;
    }
    return n;
}



main(){
setlocale(LC_ALL, "Portuguese");

    int n, res;

    printf("Digite um numero para descobrir seu fatorial: ");
    scanf("%d", &n);
    res = func(n);
    printf("Resultado do fatorial � %d", res);


}
