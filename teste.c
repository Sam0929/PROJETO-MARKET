#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SENHA_CORRETA "1234"

int main(){
char senha [20], confirmar;
int t=0, i, vendas_efetuadas = 0, cont = 0;
char tent[2][5] = {"DUAS","UMA"};
float valor_venda,errado, valor_total_venda = 0.0, aux = 200, valor_pago, troco;


printf("---------------------------------------------------------------------\n\n");
printf("\n                           SEJA BEM-VINDO!\n");
printf("\n\n---------------------------------------------------------------------\n\n");

 do {                                                                                                           // Lógica para verificar a senha.
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

    printf("\nSenha correta \n\nCaixa Aberto!!!\n\n");

  float Cedulas [7] = {200, 100, 50, 10, 5, 1, 0.5};
  int Qcedulas [7] = {2, 4, 6, 10, 10, 20, 20};

    printf ("---------------------INSERCAO DOS ITENS VENDIDOS---------------------\n\n");

    do{
            do{
                if (valor_venda != -1.0)

                {
                  printf("Digite o valor da venda %d (0 para encerrar): ", vendas_efetuadas + 1);                       // Inserção dos valores da venda.
                  scanf("%f", &valor_venda);
                }

                if (valor_venda != 0.0) {

                    if (valor_venda == -1.0)
                    {
                        printf("Ultimo valor incorreto. Sera desconsiderado.\n");
                        valor_total_venda -= errado;
                        vendas_efetuadas--;
                        printf("Digite novamente o valor da venda %d (0 para encerrar): ", vendas_efetuadas + 1);
                        scanf("%f", &valor_venda);
                    }
                    else
                    {
                        valor_total_venda += valor_venda;
                        vendas_efetuadas++;
                        errado = valor_venda;
                    }
                }

              } while (valor_venda != 0.0);

        printf ("Deseja realmente finalizar a venda? (S/N): ");                                  // Lógica para confirmar a finalização da venda.

        getchar();
        confirmar = getchar();
        confirmar = toupper(confirmar);                                                         //

      } while (confirmar != 'S');

            if (vendas_efetuadas > 1)
            {
              printf("\n\nVenda finalizada com %d itens\n", vendas_efetuadas);
            }

            else
            {
              printf("\n\nVenda finalizada com %d item\n", vendas_efetuadas);
            }

        printf("\n\nVenda finalizada!!!\n");

        printf("\n\nValor Total: R$ %.2f\n", valor_total_venda);

        printf("\n\nValor Pago: R$ ");                                                                           // Inserção do valor pago pelo cliente.

        scanf ("%f", &valor_pago);

        troco = valor_pago - valor_total_venda;

        if ( troco != 0)

      {

          printf("\n\nTroco: R$ %.2f\n", troco);

          int nat =  troco/aux;

          do {
                nat =  troco/aux;
                if((Qcedulas [cont]) - (nat) < 0) nat = Qcedulas [cont];
                
                if ( nat == 1)
                {
                  if (aux > 1)
                  {
                    printf("\n%d Nota de R$ %.2f\n", nat, aux);
                    troco -= aux*nat;
                    Qcedulas [cont] -= nat;
                  } 
                  else
                  {
                    
                    printf("\n%d Moeda de R$ %.2f\n", nat, aux);
                    troco -= aux*nat;
                    Qcedulas [cont] -= nat;
                    
                  } 
                }
                else
                {
                 if(nat>1)
                    {
                        if (aux > 1)
                        { 
                          printf("\n%d Notas de R$ %.2f\n", nat, aux);
                          troco -= aux*nat;
                          Qcedulas [cont] -= nat;
                        }
                        else 
                        {
                            printf("\n%d Moedas de R$ %.2f\n", nat, aux);
                            troco -= aux*nat;
                            Qcedulas [cont] -= nat;
                        }
                    }
                }

               

                  if (cont<2)                                                                        // Lógica para alterar o aux, para que o programa possa calcular as notas de 100, 50, 10, 5, 1 e a moeda de 0.5.

                    {
                      aux = aux/2;
                      cont++;
                    }
                  else
                    {

                      if (cont%2 == 0)
                      {
                        aux = aux/5;
                      }

                      else
                      {
                        aux = aux/2;
                      }

                      cont++;
                    }

              }while (troco != 0.0);

      }

      else
        {
          printf("\n\nNAO HA TROCO\n");
        }


        for (i=0; i<7; i++)
        {
          printf ("\n%d", Qcedulas [i]);
        }
  return 0;


}
