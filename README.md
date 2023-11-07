# Sistemas-Operacionais-Memoria

##1.Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista); 
```C
  lista *linkedList = criaLista();
  for(int i = 0; i<3; i++){
    insertList(linkedList,i);
  }
```
##2.Construa uma função que imprima todos os valores da lista; 
```C
void imprime(celula *cel)
{
	if(cel != NULL){
		printf("Valor da celula: %d\n",cel->conteudo);
		imprime(cel->prox);
	}
}
```

##3.Calcule a quantidade de memória gasta por cada instância da célula
```C
void tamanhoCelula(){
	printf ("Tamanho de uma instancia Celula: = %ld\n", sizeof(celula));
}
```
Resposta: 16 Bytes

##4.Construa uma função que remove os elementos da lista;
```C
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
```
##5.Incremente sua função liberando a memória quando um elemento é liberado;
Função acima já faz isso linha 41 'free(q)'

##6.Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.
```C
void calculaTamanhoMax(){
	printf("baseado em um computador com 8gb de memoria principal\n");
	int tamanhoMax = 8589934592/sizeof(celula);
	printf("O tamanho maximo que a lista pode assumir é de aproximadamente: %d\n", tamanhoMax);
}
```
Resposta esperada: 536870912 
