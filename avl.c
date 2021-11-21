#include "avl.h"

/*Função que devolve o maior entre dois números inteiros!*/
int maior (int esq, int dir) {
   return (esq > dir ? esq : dir);
}

/*----------------------*/
int altura_char (Arvore_char* a) {
   return (a == NULL ? -1 : a->altura);
}

int altura_int (Arvore_int* a) {
   return (a == NULL ? -1 : a->altura);
}

/*----------------------*/
int atualizar_altura_char (Arvore_char *a) {
   return (maior(altura_char(a->esq), altura_char(a->dir))+1);
}

int atualizar_altura_int (Arvore_int *a) {
   return (maior(altura_int(a->esq), altura_int(a->dir))+1);
}

/*----------------------*/
int balanceamento_char (Arvore_char *a) {
   return (altura_char(a->dir) - altura_char(a->esq));
}

int balanceamento_int (Arvore_int *a) {
   return (altura_int(a->dir) - altura_int(a->esq));
}

/*----------------------*/
Arvore_char* rotacao_simples_esq_char (Arvore_char* a) {
   No_char *tmp = a->dir;
   a->dir = tmp->esq;
   tmp->esq=a;
   a->altura = atualizar_altura_char(a);
   tmp->altura = atualizar_altura_char(tmp);
   return tmp;
}

Arvore_int* rotacao_simples_esq_int (Arvore_int* a) {
   No_int *tmp = a->dir;
   a->dir = tmp->esq;
   tmp->esq=a;
   a->altura = atualizar_altura_int(a);
   tmp->altura = atualizar_altura_int(tmp);
   return tmp;
}

/*----------------------*/
Arvore_char* rotacao_simples_dir_char (Arvore_char* a) {
   No_char *tmp = a->esq;
   a->esq = tmp->dir;
   tmp->dir=a;
   a->altura = atualizar_altura_char(a);
   tmp->altura = atualizar_altura_char(tmp);
   return tmp;
}

Arvore_int* rotacao_simples_dir_int (Arvore_int* a) {
   No_int *tmp = a->esq;
   a->esq = tmp->dir;
   tmp->dir=a;
   a->altura = atualizar_altura_int(a);
   tmp->altura = atualizar_altura_int(tmp);
   return tmp;
}

/*----------------------*/
Arvore_char* rotacao_dupla_esq_char (Arvore_char* a) {
   a->dir = rotacao_simples_dir_char(a->dir);
   return rotacao_simples_esq_char(a);
}

Arvore_int* rotacao_dupla_esq_int (Arvore_int* a) {
   a->dir = rotacao_simples_dir_int(a->dir);
   return rotacao_simples_esq_int(a);
}

/*----------------------*/
Arvore_char* rotacao_dupla_dir_char (Arvore_char* a) {
   a->esq = rotacao_simples_esq_char(a->esq);
   return rotacao_simples_dir_char(a);
}

Arvore_int* rotacao_dupla_dir_int (Arvore_int* a) {
   a->esq = rotacao_simples_esq_int(a->esq);
   return rotacao_simples_dir_int(a);
}

/*----------------------*/
Arvore_char* atualizar_fb_dir_char (Arvore_char *a) {
   a->altura = atualizar_altura_char(a);
   if(balanceamento_char(a)==2) {
      //Sinais do fb do nó pai e nó filho são iguais
      if (balanceamento_char(a->dir) >= 0) {a = rotacao_simples_esq_char(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else{a = rotacao_dupla_esq_char(a);}
   }
   return a;
}

Arvore_int* atualizar_fb_dir_int (Arvore_int *a) {
   a->altura = atualizar_altura_int(a);
   if(balanceamento_int(a)==2) {
      //Sinais do fb do nó pai e nó filho são iguais
      if (balanceamento_int(a->dir) >= 0) {a = rotacao_simples_esq_int(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else{a = rotacao_dupla_esq_int(a);}
   }
   return a;
}

/*----------------------*/
Arvore_char* atualizar_fb_esq_char (Arvore_char *a) {
   a->altura = atualizar_altura_char(a);
   if (balanceamento_char(a)==-2) {
      //Sinais do fb do nó pai e nó filho são iguais 
      if(balanceamento_char(a->esq) <= 0) {a = rotacao_simples_dir_char(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else {a = rotacao_dupla_dir_char(a);}
   }
   return a;
}

Arvore_int* atualizar_fb_esq_int (Arvore_int *a) {
   a->altura = atualizar_altura_int(a);
   if (balanceamento_int(a)==-2) {
      //Sinais do fb do nó pai e nó filho são iguais 
      if(balanceamento_int(a->esq) <= 0) {a = rotacao_simples_dir_int(a);}
      //Sinais do fb do nó pai e nó filho são diferentes
      else {a = rotacao_dupla_dir_int(a);}
   }
   return a;
}

/*----------------------*/
Arvore_char* inserir_char (Arvore_char *a, char chave) {
   if (a == NULL) {
      a = (No_char*) malloc (sizeof(No_char));
      a->chave = chave;
      a->altura = 0;
      a->esq = a->dir = NULL;
   }
   else if(chave < a->chave) {
      a->esq = inserir_char (a->esq, chave);
      a = atualizar_fb_esq_char(a);
   }
   else {
      a->dir = inserir_char (a->dir, chave);
      a = atualizar_fb_dir_char(a);
   }
   return a;
}

Arvore_int* inserir_int (Arvore_int *a, int chave) {
   if (a == NULL) {
      a = (No_int*) malloc (sizeof(No_int));
      a->chave = chave;
      a->altura = 0;
      a->esq = a->dir = NULL;
   }
   else if(chave < a->chave) {
      a->esq = inserir_int (a->esq, chave);
      a = atualizar_fb_esq_int(a);
   }
   else {
      a->dir = inserir_int (a->dir, chave);
      a = atualizar_fb_dir_int(a);
   }
   return a;
}

//Função para inverter o valor de dois nós (char)
void inverte_nos_char (Arvore_char *a, Arvore_char *tmp, int v) {
   a->chave = tmp->chave;
   tmp->chave = v;
}

//Função para inverter o valor de dois nós (int)
void inverte_nos_int (Arvore_int *a, Arvore_int *tmp, int v) {
   a->chave = tmp->chave;
   tmp->chave = v;
}

void arvore_char_libera (Arvore_char* a) {
   if (a != NULL) {
      arvore_char_libera (a->esq);
      arvore_char_libera (a->dir);
      free(a);
   }
}

void arvore_int_libera (Arvore_int* a) {
   if (a != NULL) {
      arvore_int_libera (a->esq);
      arvore_int_libera (a->dir);
      free(a);
   }
}

/*Função para remover um nó (int) de uma árvore binária de busca balanceada!*/
Arvore_int* remover_int (Arvore_int *a, int chave) {
   if (a == NULL) {return NULL;}
   else {
      if (chave < a->chave) {
         a->esq = remover_int (a->esq, chave);
         a = atualizar_fb_dir_int (a);
      }
      else if (chave > a->chave) {
         a->dir = remover_int (a->dir, chave);
         a = atualizar_fb_esq_int (a);
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
            No_int *tmp = a; //ponteiro "tmp" aponta p/ nó atual
            a = a->dir; //ponteiro "a" se liga com o nó / filho da dir
            free (tmp); //liberamos "tmp"
         }
         //Grau 1 (ESQ): Filho / Nó p/ esquerda
         else if (a->dir == NULL) {
            No_int *tmp = a;
            a = a->esq; 
            free (tmp); 
         }
         //Grau 2 (ESQ & DIR): Dois filhos / Nó p/ esquerda e p/ direita
         else {
            //Promoção à raiz: 
            //1) Maior nó da subárvore da esquerda (escolhido) 
            //2) Menor nó da subárvore da direita 
            //OBS: A árvore será reestruturada!
            No_int *tmp = a->esq;
            while (tmp->dir != NULL) {tmp = tmp->dir;}
            //Função para inverter o valor da raiz com o da folha
            inverte_nos_int(a, tmp, chave);
            a->esq = remover_int (a->esq, chave); 
            a = atualizar_fb_dir_int (a);
         }
      }
      return a; 
   }   
}

/*Função para remover um nó (char) de uma árvore binária de busca balanceada!*/
Arvore_char* remover_char (Arvore_char *a, char chave) {
   if (a == NULL) {return NULL;}
   else {
      if (chave < a->chave) {
         a->esq = remover_char (a->esq, chave);
         a = atualizar_fb_dir_char (a);
      }
      else if (chave > a->chave) {
         a->dir = remover_char (a->dir, chave);
         a = atualizar_fb_esq_char (a);
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
            No_char *tmp = a; //ponteiro "tmp" aponta p/ nó atual
            a = a->dir; //ponteiro "a" se liga com o nó / filho da dir
            free (tmp); //liberamos "tmp"
         }
         //Grau 1 (ESQ): Filho / Nó p/ esquerda
         else if (a->dir == NULL) {
            No_char *tmp = a;
            a = a->esq; 
            free (tmp); 
         }
         //Grau 2 (ESQ & DIR): Dois filhos / Nó p/ esquerda e p/ direita
         else {
            //Promoção à raiz: 
            //1) Maior nó da subárvore da esquerda (escolhido) 
            //2) MeNo_charr nó da subárvore da direita 
            //OBS: A árvore será reestruturada!
            No_char *tmp = a->esq;
            while (tmp->dir != NULL) {tmp = tmp->dir;}
            //Função para inverter o valor da raiz com o da folha
            inverte_nos_char(a, tmp, chave);
            a->esq = remover_char (a->esq, chave); 
            a = atualizar_fb_dir_char (a);
         }
      }
      return a; 
   }   
}

/*Função para imprimir os nós (char) de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order_char (Arvore_char* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      if (balanceamento_char(a) < 0) {printf("Chave: %c (altura: %d, fb: %-d) no nivel: %d\n", a->chave, a->altura, balanceamento_char(a), nivel);}
      else if (balanceamento_char(a) > 0) {printf("Chave: %c (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento_char(a), nivel);}
      else {printf("Chave: %c (altura: %d, fb: %d) no nivel: %d\n", a->chave, a->altura, balanceamento_char(a), nivel);}
      imprimir_in_order_char (a->esq, nivel + 1);
      imprimir_in_order_char (a->dir, nivel + 1);
   }
}

/*Função para imprimir os nós (int) de uma árvore binária de acordo com um percurso in-ordem!*/
void imprimir_in_order_int (Arvore_int* a, int nivel) {
   if (a != NULL) {
      int i;
      for (i = 0; i < nivel; i++) {
         printf("      ");
      }
      if (balanceamento_int(a) < 0) {printf("Chave: %d (altura: %d, fb: %-d) no nivel: %d\n", a->chave, a->altura, balanceamento_int(a), nivel);}
      else if (balanceamento_int(a) > 0) {printf("Chave: %d (altura: %d, fb: %+d) no nivel: %d\n", a->chave, a->altura, balanceamento_int(a), nivel);}
      else {printf("Chave: %d (altura: %d, fb: %d) no nivel: %d\n", a->chave, a->altura, balanceamento_int(a), nivel);}
      imprimir_in_order_int (a->esq, nivel + 1);
      imprimir_in_order_int (a->dir, nivel + 1);
   }
}


