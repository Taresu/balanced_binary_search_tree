#ifndef _AVL_H
#define _AVL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_char {
   char chave;
   int altura;
   struct node_char* esq;
   struct node_char* dir;
} No_char, Arvore_char;

typedef struct node_int {
   int chave;
   int altura;
   struct node_int* esq;
   struct node_int* dir;
} No_int, Arvore_int;

int maior (int esq, int dir);

int altura_char (Arvore_char *a);
int altura_int (Arvore_int *a);

int atualizar_altura_char (Arvore_char *a);
int atualizar_altura_int (Arvore_int *a);

int balanceamento_char (Arvore_char *a);
int balanceamento_int (Arvore_int *a);

Arvore_char* rotacao_simples_esq_char (Arvore_char* a);
Arvore_int* rotacao_simples_esq_int (Arvore_int* a);

Arvore_char* rotacao_simples_dir_char (Arvore_char* a);
Arvore_int* rotacao_simples_dir_int (Arvore_int* a);

Arvore_char* rotacao_dupla_esq_char (Arvore_char* a);
Arvore_int* rotacao_dupla_esq_int (Arvore_int* a);

Arvore_char* rotacao_dupla_dir_char (Arvore_char* a);
Arvore_int* rotacao_dupla_dir_int (Arvore_int* a);

Arvore_char* atualizar_fb_dir_char (Arvore_char *a);
Arvore_int* atualizar_fb_dir_int (Arvore_int *a);

Arvore_char* atualizar_fb_esq_char (Arvore_char *a);
Arvore_int* atualizar_fb_esq_int (Arvore_int *a);

Arvore_char* inserir_char (Arvore_char *a, char chave);
Arvore_int* inserir_int (Arvore_int *a, int chave);

Arvore_char* remover_char (Arvore_char *a, char chave);
Arvore_int* remover_int (Arvore_int *a, int chave);

void inverte_nos_int (Arvore_int *a, Arvore_int *tmp, int v);
void inverte_nos_char (Arvore_char *a, Arvore_char *tmp, int v);

void arvore_char_libera (Arvore_char* a);
void arvore_int_libera (Arvore_int* a);

void imprimir_in_order_char (Arvore_char* a, int nivel);
void imprimir_in_order_int (Arvore_int* a, int nivel);

#endif
