#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENHA_CORRETA "1234"

int main(){
char senha [20];
int t=0;
char tent[2][5] = {"DUAS"
                    ,"UMA"};


printf("---------------------\n\n");
printf("\n   Seja bem-vindo!\n");
printf("\n\n---------------------\n\n");

 do {
      printf("\n\nDigite sua senha: ");
      scanf("%s", senha);

      t++;

      if (strcmp(senha, SENHA_CORRETA) != 0 && t < 3)
    
      {
        printf("\nSenha incorreta");
        
        printf("\n\nVoce tem mais %s tentativas...", tent [t-1]);
      }

    if (t == 3 && strcmp(senha, SENHA_CORRETA) != 0) 
      {
        printf("\nNumero maximo de tentativas atingido! O caixa sera reinicializado.\n");
        return 1;
      }
        
    } while (strcmp(senha, SENHA_CORRETA) != 0);

    printf("\nSenha correta \n\nCaixa Aberto!!!");


  return 0;


}
