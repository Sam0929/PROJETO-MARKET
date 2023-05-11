#include <stdio.h>
#include <stdlib.h>

int main(){

int senha = 1234, t=0;


printf("---------------------\n\n");
printf("\n   Seja bem-vindo!\n");
printf("\n\n---------------------\n\n");

 do{
      printf("\nDigite sua senha: ");
      scanf("%d", &senha);

    if(senha == 1234)
      {
        printf("\nSenha correta");
      }
      else
        printf("\nSenha incorreta");
        t++;

} while (t<3);






  return 0;
}
