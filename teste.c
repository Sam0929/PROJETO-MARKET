#include <stdio.h>
#include <stdlib.h>

int main(){

int senha = 1234, t=3;


printf("---------------------\n\n");
printf("\n   Seja bem-vindo!\n");
printf("\n\n---------------------\n\n");

 do{
      printf("\nDigite sua senha: ");
      scanf("%d", &senha);

    if(senha == 1234)
      {
        printf("\nSenha correta");
        break;
      }
      else{
        printf("\nSenha incorreta");
        printf("\nVoce tem mais %d tentativas", t-1);
        }
        t--;


} while (t>0);






  return 0;
}
