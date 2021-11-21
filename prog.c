#include "avl.h"
#include "avl.c"

typedef int bool;
enum { false, true };

void continua_char(Arvore_char *a, char c, bool insercao) {
   if(a != NULL) {
      if (insercao) {printf("\t|Insercao do caractere %c|\n\n", c);}
      else {printf("\t|Remocao do caractere %c|\n\n", c);}
   }
   imprimir_in_order_char(a, 0);
   printf("\nAperte qualquer tecla para continuar... ");
   getchar(); //recebe um caractere de entrada p/ continuar a execução
   system("cls||clear"); //limpa a tela (windows ou linux) 
} 

void continua_int(Arvore_int *a, int i, bool insercao) {
   if(a != NULL) {
      if (insercao) {printf("\t|Insercao do inteiro %d|\n\n", i);}
      else {printf("\t|Remocao do inteiro %d|\n\n", i);}
   }
   imprimir_in_order_int(a, 0);
   printf("\nAperte qualquer tecla para continuar... ");
   getchar();
   system("cls||clear");  
}

int main () {

   Arvore_char *AVL = NULL;
   
   arvore_int_libera(AVL);

   printf("\n|Arvore Binaria de Busca Balanceada - Caracteres |\n\n");

   printf("Aperte qualquer tecla para comecar a insercao... ");
   getchar();
   system("cls||clear"); 

   char str[17] = {'Q', 'Z', 'B', 'Y', 'T', 'M', 'E', 'W', 'X', 'F', 'G', 'A', 'H', 'N', 'O', 'P', 'R'};
   bool insercao = true; //Será uma inserção

   /*Inserção de nós, com dados do tipo char*/
   for (int e = 0;e<17;e++) {
      char letra;
      letra = str[e];
      AVL = inserir_char (AVL, letra); 
      continua_char(AVL, letra, insercao);
   }

   printf("\nOs elementos da arvore serao removidos (ordem invertida da insercao)!\n\n");

   printf("Aperte qualquer tecla para comecar a remocao... ");
   getchar();
   system("cls||clear"); 

   /*Remoção dos nós anteriormente formados*/
   for (int e = 16;e>-1;e--) {
      char letra;
      letra = str[e];
      AVL = remover_char (AVL, letra); 
      continua_char(AVL, letra, false);
   }
   
   if (AVL == NULL) {printf("\t| Arvore Vazia |\a\n\n");}

   arvore_char_libera(AVL);

   //Exercício 1 (inserção e remoção dos nós propostos)

   /*Inserção de nós, com dados do tipo char*/
   for (int e = 0;e<17;e++) {
      char letra;
      letra = str[e];
      AVL = inserir_char (AVL, letra); 
   }

   printf("A arvore foi novamente preenchida com os elementos iniciais...");
   
   printf("\nAgora, os caracteres A, H, E, W, G, N, P, O serao removidos!\n\n");

   printf("Aperte qualquer tecla para comecar a remocao... ");
   getchar(); 
   system("cls||clear"); 

   AVL = remover_char (AVL, 'A'); continua_char(AVL, 'A', false);
   AVL = remover_char (AVL, 'H'); continua_char(AVL, 'H', false);
   AVL = remover_char (AVL, 'E'); continua_char(AVL, 'E', false);
   AVL = remover_char (AVL, 'W'); continua_char(AVL, 'W', false);
   AVL = remover_char (AVL, 'G'); continua_char(AVL, 'G', false);
   AVL = remover_char (AVL, 'N'); continua_char(AVL, 'N', false);
   AVL = remover_char (AVL, 'P'); continua_char(AVL, 'P', false);
   AVL = remover_char (AVL, 'O'); continua_char(AVL, 'O', false);

   arvore_char_libera(AVL);

   Arvore_int *AVL2 = NULL;

   printf("|Arvore Binaria de Busca Balanceada - Inteiros |\n\n");

   printf("Aperte qualquer tecla para comecar a insercao... ");
   getchar();
   system("cls||clear"); 

   /*Inserção de nós, com dados do tipo int*/
   for(int i=1;i<=40;i++) {
      if ( (i != 9) && (i != 17) && !(i>22 && i<28) ) {
         AVL2 = inserir_int (AVL2, i);   
         continua_int(AVL2, i, true);
      }
   }

   /*Remoção do Nó / Elemento 1*/
   printf("Aperte qualquer tecla para remover o inteiro 1... ");
   getchar();
   system("cls||clear");
   AVL2 = remover_char (AVL2, 1);
   printf("\t|Remocao do inteiro 1|\n\n");
   imprimir_in_order_int(AVL2, 0);

   arvore_int_libera(AVL2);

   printf("\n");

   return 0;
}
