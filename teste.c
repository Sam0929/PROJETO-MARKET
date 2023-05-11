#include <stdio.h>
#include <stdlib.h>

int main(){
int senha;
int t=0;
char tent[2][5] = {"DUAS"
                    ,"UMA"};


printf("---------------------\n\n");
printf("\n   Seja bem-vindo!\n");
printf("\n\n---------------------\n\n");

 do{
      printf("\nDigite sua senha: ");
      scanf("%d", &senha);

    if(senha == 1233123214)
      {
        printf("\nSenha correta");
        break;
      }
      else
        printf("\nSenha incorreta");
        if(t<2)
        {
            printf("\nVoce tem mais %s tentativas", tent [t]);
        }
        t++;
} while (t<3);






  return 0;
}
