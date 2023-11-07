#include <stdlib.h>
#include <stdio.h>

//Enzo Casagrande - 32209606
//Rafael Russo - 32220294
//Marcos Junior - 32234120

struct reg{
	int conteudo;
	struct reg *prox;
};

typedef struct reg celula;

typedef struct lista{
	celula *head;
	celula *tail;
	int tam;
} lista;


lista *criaLista();
void insertList(lista *list, int valor);


void imprime(celula *cel);
void tamanhoCelula ();

celula *buscaCelula(celula *head, int buscado);

void removeCelula(celula *head, int removido);
void calculaTamanhoMax();

int main()
{
	lista *linkedList = criaLista();
	for(int i = 0; i<3; i++){
		insertList(linkedList,i);
	}
	printf("Imprimindo lista\n");
	imprime(linkedList->head);
	printf("Removendo item 2 da lista\n");
	removeCelula(linkedList->head, 2);
	printf("Mostrando nova lista...\n");
	imprime(linkedList->head);
	tamanhoCelula();
	calculaTamanhoMax();

	return 0;
};

void imprime(celula *cel)
{
	if(cel != NULL){
		printf("Valor da celula: %d\n",cel->conteudo);
		imprime(cel->prox);
	}
}

void tamanhoCelula(){
	printf ("Tamanho de uma instancia Celula: = %ld\n", sizeof(celula));
}

lista *criaLista(){
	printf("Criando lista...\n");
	lista *l = (lista*) malloc(sizeof(lista));
	if(l==NULL){
		printf("Erro ao alocar memória\n");
		exit(1);
	}
	l->head = NULL;
	l->tail = NULL;
	l->tam =0;
	return l;
}

void insertList(lista *list, int valor){
	celula *novo = (celula*)malloc(sizeof(celula));
	printf("inserindo item %d...\n",valor);
	if(novo == NULL){
		printf("Erro ao alocar memoria\n");
		exit(1);
	}
	novo->conteudo = valor;
	if(list->tail != NULL)
	list->tail->prox = novo;

	list->tail = novo;
	if(list->head == NULL){
		list->head = novo;
	}
	list->tam++;
}

celula *busca(celula *head, int buscado){
	if(head == NULL) return NULL;
	if(head->conteudo == buscado) return head;
	return busca(head->prox, buscado);
}

void removeCelula(celula *head, int removido){
	celula *p, *q;
	p = head;
	q = head->prox;
	while(q != NULL && q->conteudo != removido){
		p = q;
		q = q->prox;
	}
	if(q != NULL){
		p->prox = q->prox;
		free(q);
	}
}

void calculaTamanhoMax(){
	printf("baseado em um computador com 8gb de memoria principal\n");
	int tamanhoMax = 8589934592/sizeof(celula);
	printf("O tamanho maximo que a lista pode assumir é de aproximadamente: %d\n", tamanhoMax);
}
