#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura (Arvore* a) {
   return (a == NULL ? -1 : a->altura);
}

/*----------------------*/
int atualizar_altura (Arvore *a) {
   return (maior(altura(a->esq), altura(a->dir))+1);
}

/*----------------------*/
int balanceamento (Arvore *a) {
   return (altura(a->dir) - altura(a->esq));
}

/*----------------------*/
Arvore* rotacao_simples_esq (Arvore* a) {
   No *tmp = a->dir;
   a->dir = tmp->esq;
   tmp->esq=a;
   a->altura = atualizar_altura(a);
   tmp->altura = atualizar_altura(tmp);
   return tmp;
}

/*----------------------*/
Arvore* rotacao_simples_dir (Arvore* a) {
   No *tmp = a->esq;
   a->esq = tmp->dir;
   tmp->dir=a;
   a->altura = atualizar_altura(a);
   tmp->altura = atualizar_altura(tmp);
   return tmp;
}

/*----------------------*/
Arvore* rotacao_dupla_esq (Arvore* a) {
   a->dir = rotacao_simples_dir(a->dir);
   return rotacao_simples_esq(a);
}

/*----------------------*/
Arvore* rotacao_dupla_dir (Arvore* a) {
   a->esq = rotacao_simples_esq(a->esq);
   return rotacao_simples_dir(a);
}

/*----------------------*/
Arvore* atualizar_fb_dir (Arvore *a) {
   a->altura = atualizar_altura(a);
   if(balanceamento(a)==2) {
      //Sinais do fb do nó pai e nó filho são iguais
      if (balanceamento(a->dir) >= 0) {a = rotacao_simples_esq(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else{a = rotacao_dupla_esq(a);}
   }
   return a;
}

/*----------------------*/
Arvore* atualizar_fb_esq (Arvore *a) {
   a->altura = atualizar_altura(a);
   if (balanceamento(a)==-2) {
      //Sinais do fb do nó pai e nó filho são iguais 
      if(balanceamento(a->esq) <= 0) {a = rotacao_simples_dir(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else {a = rotacao_dupla_dir(a);}
   }
   return a;
}

/*----------------------*/
Arvore* inserir (Arvore *a, char chave) {
   if (a == NULL) {
      a = (No*) malloc (sizeof(No));
      a->chave = chave;
      a->altura = 0;
      a->esq = a->dir = NULL;
   }
   else if(chave < a->chave) {
      a->esq = inserir (a->esq, chave);
      a = atualizar_fb_esq(a);
   }
   else {
      a->dir = inserir (a->dir, chave);
      a = atualizar_fb_dir(a);
   }
   return a;
}

//Função para inverter o valor de dois nós
void inverte_nos (Arvore *a, Arvore *tmp, int v) {
   a->chave = tmp->chave;
   tmp->chave = v;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}
/*Função para remover um nó de uma árvore binária de busca balanceada!*/
Arvore* remover (Arvore *a, char chave) {
   if (a == NULL) {return NULL;}
   else {
      if (chave < a->chave) {
         a->esq = remover (a->esq, chave);
         a = atualizar_fb_dir (a);
      }
      else if (chave > a->chave) {
         a->dir = remover (a->dir, chave);
         a = atualizar_fb_esq (a);
      }
      //Encontramos o elemento a ser removido
      else {
         //Grau 0: Folha (não tem filhos)
         if ((a->esq == NULL) && (a->dir == NULL)) {
            free (a);
            a = NULL;
         }
         //Grau 1 (DIR): Um Filho / Nó p/ direita
         else if (a->esq == NULL) {
            No *tmp = a; //ponteiro "tmp" aponta p/ nó atual
            a = a->dir; //ponteiro "a" se liga com o nó / filho da dir
            free (tmp); //liberamos "tmp"
         }
         //Grau 1 (ESQ): Filho / Nó p/ esquerda
         else if (a->dir == NULL) {
            No *tmp = a;
            a = a->esq; 
            free (tmp); 
         }
         //Grau 2 (ESQ & DIR): Dois filhos / Nó p/ esquerda e p/ direita
         else {
            //Promoção à raiz: 
            //1) Maior nó da subárvore da esquerda (escolhido) 
            //2) Menor nó da subárvore da direita 
            //OBS: A árvore será reestruturada!
            No *tmp = a->esq;
            while (tmp->dir != NULL) {tmp = tmp->dir;}
            //Função para inverter o valor da raiz com o da folha
            inverte_nos(a, tmp, chave);
            a->esq = remover (a->esq, chave); 
            a = atualizar_fb_dir (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      if (balanceamento(a) < 0) {printf("Chave: %c (altura: %d, fb: %-d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      else if (balanceamento(a) > 0) {printf("Chave: %c (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      else {printf("Chave: %c (altura: %d, fb: %d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}


/*Função para imprimir os nós de uma árvore binária de acordo com um percurso in-ordem!*/
/*
void imprimir_in_order_int (Arvore* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      if (balanceamento(a) < 0) {printf("Chave: %d (altura: %d, fb: %-d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      else if (balanceamento(a) > 0) {printf("Chave: %d (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      else {printf("Chave: %d (altura: %d, fb: %d) no nivel: %d\n", a->chave, a->altura, balanceamento(a), nivel);}
      imprimir_in_order (a->esq, nivel + 1);
      imprimir_in_order (a->dir, nivel + 1);
   }
}
*/


