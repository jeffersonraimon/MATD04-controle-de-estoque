#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funções.h"

int main(){
  estoque *func = (struct estoque*)malloc(MAX * sizeof(estoque));
  if (func == NULL){
    printf("Memoria insuficiente.\n");
    exit(0);
}
  for (int i=0; i<MAX; ++i){
    strcpy(func[i].produto, "NULL");
    func[i].codigo = 0;
    func[i].validade= 0;
}

  int operacao, leave=0;

  printf("Bem vindo ao sistema de controle de estoque\n");
  while(leave==0){
    menu_usuario();
    scanf("%d", &operacao);
    switch(operacao){
      case 1:
        if(heap_tamanho==0){
            printf("\nA lista de produtos esta vazia!\n");
            break;
        }
        print_head(func);
        break;
      case 2:
        if(heap_tamanho==MAX){
            printf("\nA lista de produtos esta cheia!\n");
            break;
        }
        inserir(func);
        break;
      case 3:
        if(heap_tamanho==0){
            printf("\nA lista de produtos esta vazia!\n");
            break;
        }
        remover_minimo(func);
        break;
      case 4:
        if(heap_tamanho==0){
            printf("\nA lista de produtos esta vazia!\n");
            break;
        }
        minimo(func);
        break;
      case 5:
        leave = 1;
        free(func);
        break;
      default:
        printf("\nOperacao invalida!\n");
    }
  }
  return 0;
}
