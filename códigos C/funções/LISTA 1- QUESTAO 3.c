/*Escreva um programa no qual seja chamada uma fun��o que receba como par�metro um
ano e retorne 1 se o ano for bissexto, e 0 caso contr�rio. S�o bissextos todos os anos n�o
seculares divis�veis por 4, e os seculares divis�veis por 400.*/

#include<stdio.h>
#include<locale.h>

int func1(int n){
    if(n % 4 == 0 && n % 100 != 0 || n % 100 == 0 && n % 400 == 0)
        return 1;
    else
        return 0;

}

main(){
setlocale(LC_ALL, "portuguese");
    int n;

    printf("Digite um ano para verificar se ele � bissexto: ");
    scanf("%d", &n);
    n = func1(n);
    printf("%d", n);

}
