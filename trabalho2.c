/*
 *Segundo trabalho de Estrutura de dados
 *Aluno: Luiz Guilherme Ribeiro
 *DRE: 114150509
 */


#include <stdio.h>
#include <stdlib.h>

//estrutura de celula da lista
typedef struct cel{
        struct cel *next;
        int content;
}celula;

//inicializando lista--> o ponteiro para a primeira celula é criado
celula* init (void){
        return NULL;
}

//insere uma celula na lista--> será inserida no começo
celula* insert (celula* prox, int valor){
        
        //aloca espaco--> novo eh ponteiro para um espaco que contem celula
        celula* novo = (celula*) calloc(1, sizeof(celula));
        novo->content=valor;
        novo->next=prox;
        return novo;
}

void quicksort(celula* begin, int tamanho){
        int i, j, nv;
        celula *atual=begin, *proximo=begin;

        //ordenando
        for(i=0;i<tamanho;i++){
                for(j=0;j<tamanho-1;j++){
                        if((atual->content)<(proximo->content)){
                               nv=atual->content;
                               atual->content=proximo->content;
                               proximo->content=nv;
                        }
                        proximo=proximo->next;
                }
                proximo=begin;
                atual=atual->next;
        }
}


void radixsort(celula *begin, int tamanho){

    int i, *b, maior=begin->content, exp=1, *array;
    celula *aux=begin;

    if(!( b = (int *)calloc(tamanho, sizeof(int))) || !( array = (int *)calloc(tamanho, sizeof(int)))){
	exit(1);
    }
    // pegando o maior numeo da lista
    for (i = 0; i < tamanho; i++) {
        if (aux->content > maior)
    	    maior = aux->content;
        array[i]=aux->content;
        aux=aux->next;
    }
    aux=begin;

    

    //comparando de acordo com o algarismo da casa decimal
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        //guardando o numero de casos para cada numero
    	for (i = 0; i < tamanho; i++){
    	    bucket[(array[i] / exp) % 10]++;
        } 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(array[i] / exp) % 10]] = array[i];
    	for (i = 0; i < tamanho; i++)
    	    array[i]= b[i];
    	exp *= 10;
    }
    for(i=0;i<tamanho;i++){
        aux->content=array[i];
        aux=aux->next;
    }
    aux=begin;    
    free(b);
}


void main (){

        //dicionario de dados
        int i, aux, size=0;

        //inicializando lista
        celula* start=init();

        //recebendo dados do arquivo
        while(scanf("%d", &aux)!=EOF){
                start=insert(start, aux);
                size++;
                
        }
        
        radixsort(start, size);
        //testando entrada
        celula* currentcel=start;
        for(i=0;i<size;i++){
                printf("%d\n", currentcel->content);
                currentcel=currentcel->next;
        }


}

