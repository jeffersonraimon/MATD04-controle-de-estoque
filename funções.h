#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int heap_tamanho = 0;
const int INF = 100000;

void menu_usuario(){
printf("\nSelecione uma operacao\n");
printf("1 - Listar produtos\n");
printf("2 - Adicionar produto\n");
printf("3 - Remover produto\n");
printf("4 - Visualizar o produto mais proximo do vencimento\n");
printf("5 - Sair\n");
}

typedef struct{
    char produto[30];
    int codigo;
    int validade;
}estoque;
estoque func[30];

void troca(estoque *a, estoque *b){
    estoque aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int get_right(estoque func[], int indice){
    if((((2 * indice) + 1) < MAX) && (indice >= 1))
        return (2 * indice) + 1;
    return -1;
}

int get_left(estoque func[], int indice){
    if(((2 * indice) < MAX) && (indice >= 1))
        return 2 * indice;
    return -1;
}

int get_parent(estoque func[], int indice){
  if ((indice > 1) && (indice < MAX)){
    return indice/2;
  }
  return -1;
}

void min_heapify(estoque func[], int indice){
    int indice_esquerda= get_left(func, indice);
    int indice_direita= get_right(func, indice);
    int menor = indice;
    if ((indice_esquerda <= heap_tamanho) && (indice_esquerda > 0)){
        if(func[indice_esquerda].validade < func[menor].validade){
            menor = indice_esquerda;
        }
    }

    if ((indice_direita <= heap_tamanho) && (indice_direita > 0)){
        if(func[indice_direita].validade < func[menor].validade){
            menor = indice_direita;
        }
    }

    if (menor != indice){
        troca(&func[indice], &func[menor]);
        min_heapify(func, menor);
    }
}

void criar_min_heap(estoque func[]){
    for(int i = heap_tamanho / 2; i >= 1; i--){
        min_heapify(func, i);
    }
}

int minimo(estoque func[]){
    printf("\n======================================================\n");
    printf("\nO produto mais proximo do vencimento e o(a):\n");
    printf("\nNome: %s", func[1].produto);
    printf("\nCodigo: %i", func[1].codigo);
    if (func[1].validade == 1){
        printf("\nValidade: %i mes\n", func[1].validade);
    }else{
        printf("\nValidade: %i meses\n", func[1].validade);
    }
    printf("\n======================================================\n");
}

int remover_minimo(estoque func[]){
    printf("\n======================================================\n");
    printf("\nO produto removido foi o(a):\n");
    printf("\nNome: %s", func[1].produto);
    printf("\nCodigo: %i", func[1].codigo);
    if (func[1].validade == 1){
        printf("\nValidade: %i mes\n", func[1].validade);
    }else{
        printf("\nValidade: %i meses\n", func[1].validade);
    }
    printf("\n======================================================\n");
    troca(&func[1], &func[heap_tamanho]);
    heap_tamanho--;
    min_heapify(func, 1);
}

void inserir_posicao(estoque func[], int indice){
    printf("\nDigite o nome do produto: ");
    scanf("%s%*c", &func[indice].produto);
    printf("Digite o codigo do produto: ");
    scanf("%d%*c", &func[indice].codigo);
    printf("Digite em quantos meses e o vencimento do produto: ");
    scanf("%d%*c", &func[indice].validade);

    while((indice > 1) && (func[get_parent(func, indice)].validade > func[indice].validade)){
            troca(&func[indice], &func[get_parent(func, indice)]);
            indice = get_parent(func, indice);
    }
}

void inserir(estoque func[]){
    heap_tamanho++;
    func[heap_tamanho].validade = INF;
    inserir_posicao(func, heap_tamanho);
}

void print_head(estoque func[]){
    printf("\n======================================================\n");
    printf("\nLista de produtos:\n");
    for(int i = 1; i <= heap_tamanho; i++){
        printf("\nProduto: %s", func[i].produto);
        printf("\nCodigo: %i", func[i].codigo);
        if (func[i].validade == 1){
            printf("\nValidade: %i mes\n", func[i].validade);
        }else{
            printf("\nValidade: %i meses\n", func[i].validade);
        }
    }
    printf("\n======================================================\n");
    printf("\n");
}
