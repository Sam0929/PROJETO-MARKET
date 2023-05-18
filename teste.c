#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SENHA_CORRETA "1234"

int main(){
char senha [20], confirmar;
int t=0, i, vendas_efetuadas = 0, cont = 0;
char tent[2][5] = {"DUAS","UMA"};
float valor_venda, valor_total_venda = 0.0, aux = 200; 


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
  
  
  int N200 = 2, N100 = 4, N50 = 6, N10 = 10, N5 = 10, N1 = 20, N05 = 20;

    
    printf ("---------------------INSERCAO DOS ITENS VENDIDOS---------------------\n\n");

    do{
            do{
                
                printf("Digite o valor da venda %d (0 para encerrar): ", vendas_efetuadas + 1);                       // Inserção dos valores da venda.
                scanf("%f", &valor_venda);

                if (valor_venda != 0.0) {
                    if (valor_venda == -1.0) 
                    {
                        printf("Último valor incorreto. Será desconsiderado.\n");
                    } 
                    else 
                    {
                        valor_total_venda += valor_venda;
                        vendas_efetuadas++;
                    }
                }

              } while (valor_venda != 0.0);                                                                  
        
        printf ("Deseja realmente finalizar a venda? (S/N): ");                                  // Lógica para confirmar a finalização da venda.
        
        getchar();
        confirmar = getchar();
        confirmar = toupper(confirmar);                                                         //
      
      } while (confirmar != 'S');
       
        printf("\n\nVenda finalizada com %d itens\n", vendas_efetuadas);
        printf("\n\nValor total das vendas: R$ %.2f\n", valor_total_venda);
        
        
      int nat =  valor_total_venda/aux;
      
      do {

            nat =  valor_total_venda/aux;
            

            if ( nat == 1)
            {
              if (aux != 0.5) printf("\n%d Nota de R$ %.2f\n", nat, aux);
              else printf("\n%d Moeda de R$ %.2f\n", nat, aux);
              valor_total_venda = valor_total_venda - aux*nat;
            }
            
            else
            {
                if(nat>1)
                {
                    if (aux != 0.5) printf("\n%d Notas de R$ %.2f\n", nat, aux);
              	    else printf("\n%d Moedas de R$ %.2f\n", nat, aux);
                    valor_total_venda = valor_total_venda - aux*nat;
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
          
          } while (valor_total_venda != 0.0);

        


    


  return 0;


}
