#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SENHA_CORRETA "212223"



float valor_caixa (float *Cedulas, int *Qcedulas) // Função para calcular o valor total do caixa.) 

{

  float valor = 0.0;

  int i;

  for (i = 0; i < 7; i++)

    {

      valor += Cedulas [i] * Qcedulas [i];

    }

  return valor;

}

float calcula_aux (float aux, int cont)
{
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
    return aux;
}

int main()
{
  char senha [20], confirmar;
  int t=0, i, itens_vendidos = 0, vendas_efetuadas = 0, cont = 0;
  char tent[2][5] = {"DUAS","UMA"};
  float valor_venda, errado, valor_total_venda = 0.0, aux = 200, valor_pago, troco, valor_total_das_vendas = 0;


  printf("---------------------------------------------------------------------\n\n");
  printf("\n                           SEJA BEM-VINDO!\n");
  printf("\n\n---------------------------------------------------------------------\n\n");

 do {                                                                                                           // Lógica para verificar a senha.
      printf("\n\nDigite sua senha: ");
      scanf("%s", senha);

      t++;

      if (strcmp(senha, SENHA_CORRETA) != 0 && t < 3)

      {
        printf("\nSENHA INCORRETA!");

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
  int Qcedulas [7] = {2, 4, 6, 10, 10, 20, 20}, Qcedulas_Save [7];
  do{
      printf ("---------------------INSERCAO DOS ITENS VENDIDOS---------------------\n\n");

      for (i = 0; i < 7; i++)
      {
        Qcedulas_Save [i] = Qcedulas [i];
      }

      do{
          aux=200;
          cont = 0;
          if (vendas_efetuadas>0) system("cls");
          
              do{
                  if (valor_venda != -1.0)

                  {
                    printf("\nDigite o valor do item %d (0 para encerrar): ", itens_vendidos + 1);                       // Inserção dos valores da venda.
                    scanf("%f", &valor_venda);
                  }

                  if (valor_venda != 0.0) 
                  
                  {

                      if (valor_venda == -1.0)
                      {
                          printf("Ultimo valor incorreto. Sera desconsiderado.\n");
                          valor_total_venda -= errado;
                          itens_vendidos--;
                          printf("Digite novamente o valor do item %d (0 para encerrar): ", itens_vendidos + 1);
                          scanf("%f", &valor_venda);
                          
                      }
                  
                  valor_total_venda += valor_venda;
                  itens_vendidos++;
                  errado = valor_venda;
              
                  }

                } while (valor_venda != 0.0);

          printf ("\nDeseja realmente finalizar a venda? (S/N): ");                                  // Lógica para confirmar a finalização da venda.

          getchar();
          confirmar = getchar();
          confirmar = toupper(confirmar);                                                         //

        } while (confirmar != 'S');

              if (itens_vendidos > 1)
              {
                printf("\n\nVenda finalizada com %d itens\n", itens_vendidos);
              }

              else
              {
                printf("\n\nVenda finalizada com %d item\n", itens_vendidos);
              }
          
          itens_vendidos = 0;

          valor_total_das_vendas += valor_total_venda;

          printf("\n\nVenda finalizada!!!\n");

          printf("\n\nValor Total: R$ %.2f\n", valor_total_venda);

          if (valor_total_venda != 0)
          {
            printf("\n\nValor Pago: R$ ");                                                                           // Inserção do valor pago pelo cliente.
            scanf ("%f", &valor_pago);
            vendas_efetuadas++;
            troco = valor_pago - valor_total_venda;
            valor_total_venda = 0;
          }
          else
          {
            printf("\n\nNao houve compra");  
            valor_pago = 0;
          }

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
                      printf("\n     %d Nota de R$ %.2f\n", nat, aux);
                      troco -= aux*nat;
                      Qcedulas [cont] -= nat;
                    } 
                    else
                    {
                      
                      printf("\n     %d Moeda de R$ %.2f\n", nat, aux);
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
                            printf("\n     %d Notas de R$ %.2f\n", nat, aux);
                            troco -= aux*nat;
                            Qcedulas [cont] -= nat;
                          }
                          else 
                          {
                              printf("\n     %d Moedas de R$ %.2f\n", nat, aux);
                              troco -= aux*nat;
                              Qcedulas [cont] -= nat;
                          }
                      }
                  }

                  aux = calcula_aux (aux, cont);
                  cont++;

                      if (Qcedulas [6] == 0)
                      {
                        system ("cls");
                        printf("\n\nNAO HA NOTAS O SUFICIENTE PARA O TROCO\n");
                        for (int i = 0; i < 7; i++)
                        {
                          Qcedulas [i] = Qcedulas_Save [i];
                        }
                        break;
                      }

                }while (troco != 0.0);

        }

        else
          {
            printf("\n\nNAO HA TROCO\n");
          }

      printf("\n\nFechar o caixa? (S = Sim / N = Nao): ");                                  // Lógica para confirmar a finalização da venda.
      getchar();
      confirmar = getchar();
      confirmar = toupper(confirmar);

    }while (confirmar != 'S');

  system("cls");

  printf("\nFechamento do Caixa!!!\n");
  printf("\n\nNumero de clientes atendidos: %d\n", vendas_efetuadas);
  printf("\n\nValor total das vendas: R$ %.2f\n", valor_total_das_vendas);

  float valor = valor_caixa (Cedulas, Qcedulas);
  

  printf("\n\nValor total em caixa: R$ %.2f\n", valor);

  printf("\n\nQuantidade total de cedulas no caixa:\n");
  
  for (i=0; i<7; i++)
          
          {
            if (i<4)
            printf ("\n%d Notas de %.2f", Qcedulas [i], Cedulas [i]);
            else
            printf ("\n%d Moedas de %.2f", Qcedulas [i], Cedulas [i]);
          }

  printf (" \n\nAte Breve!!!\n\n");
    
    return 0;


}
