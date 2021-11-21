#include "avl.h"
#include "avl.c"

int main () {

   Arvore *AVL = NULL;

   printf("\n|Arvore Binaria de Busca Balanceada - Caracteres |\n\n");

   /*Inserção de nós, com dados do tipo char*/
   AVL = inserir (AVL, 'Q'); 
   AVL = inserir (AVL, 'Z');
   AVL = inserir (AVL, 'B');
   AVL = inserir (AVL, 'Y');
   AVL = inserir (AVL, 'T');
   AVL = inserir (AVL, 'M');
   AVL = inserir (AVL, 'E');
   AVL = inserir (AVL, 'W');
   AVL = inserir (AVL, 'X');
   AVL = inserir (AVL, 'S');
   AVL = inserir (AVL, 'F');
   AVL = inserir (AVL, 'G');
   AVL = inserir (AVL, 'A');
   AVL = inserir (AVL, 'H');
   AVL = inserir (AVL, 'N');
   AVL = inserir (AVL, 'O');
   AVL = inserir (AVL, 'P');
   AVL = inserir (AVL, 'R');

   imprimir_in_order(AVL, 0);

   printf("\nOs elementos da arvore serao removidos!\n\n");

   /*Remoção dos nós anteriormente formados*/
   AVL = remover (AVL, 'Q');
   AVL = remover (AVL, 'Z');
   AVL = remover (AVL, 'B');
   AVL = remover (AVL, 'Y');
   AVL = remover (AVL, 'T');
   AVL = remover (AVL, 'M');
   AVL = remover (AVL, 'E');
   AVL = remover (AVL, 'W');
   AVL = remover (AVL, 'X');
   AVL = remover (AVL, 'S');
   AVL = remover (AVL, 'F');
   AVL = remover (AVL, 'G');
   AVL = remover (AVL, 'A');
   AVL = remover (AVL, 'H');
   AVL = remover (AVL, 'N');
   AVL = remover (AVL, 'O');
   AVL = remover (AVL, 'P');
   AVL = remover (AVL, 'R');

   if (AVL == NULL) {printf("Arvore Vazia!!!");}
   printf("\n\n");

   arvore_libera(AVL);

   /*Inserção de nós, com dados do tipo int*/
   /*
   for(int i=0;i<=40;i++) {
      if (i>0) {
         if ( (i != 9) && (i != 17) && !(i>22 && i<28) )
         AVL = inserir (AVL, i);
      }
   }
   /*Remoção do Nó / Elemento 1*/
   //AVL = remover (AVL, 1);

   //AVL = remover (AVL, 'A');
   //AVL = remover (AVL, 'H');
   //AVL = remover (AVL, 'E');
   //AVL = remover (AVL, 'W');
   //AVL = remover (AVL, 'G');
   //AVL = remover (AVL, 'N');
   //AVL = remover (AVL, 'P');
   //AVL = remover (AVL, 'O');

   //imprimir_in_order_int (AVL, 0);

   return 0;
}
