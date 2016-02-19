/*
Quinto trabalho de estrutura de dados
Aluno: Luiz Guilherme Ribeiro
DRE:114150509
Objetivo: implementar dois hashes diferentes (encadeamento interno e externo) para uma mesma funçao
*/

#include <stdio.h>
#include <stdlib.h>

//celula usada no encadeamento externo
typedef struct _cel{
    int data;
    int usedflag;
    struct _cel *next;
}celula;

int hashfunction (int hashSize, int chave){
    chave = chave % hashSize;
    return chave;
}


void cria_externo (int nChaves, int hashSize){

    int i=0, aux;
	celula *hashtable;
	//criando tabela
	hashtable = (celula*) calloc(hashSize, sizeof(celula));
	
	//lendo até o fim
    while (i < nChaves){
        scanf("%d", &aux);
        //guardando na tabela hash
        if(!(hashtable[hashfunction(hashSize, aux)].usedflag)){
            hashtable[hashfunction(hashSize, aux)].data=aux;
            hashtable[hashfunction(hashSize, aux)].usedflag=1;
        } else {
            //percorrer a lista até achar um ponteiro null e fazer ele apontar para a célula
            celula *helppointer = hashtable[hashfunction(hashSize, aux)].next;
            
            while (1){
                //LOGICAAA
                if(hashtable[hashfunction(hashSize, aux)].next==NULL








        i++;
    }
	free (hashtable);
	}
}

void main (int argc,char *argv[]){

    if(argc != 4){
        printf("favor entrar com \"./nome_do_arquivo -i/-e -n (número de chaves) -m (tamanho da hash table)\"\n");
        exit(1);
    }else{
        if (argv[1]=="-i"){
            //criar hash com encademento interno
        }else if (argv[1]="-e"){
            //criar hash com encadeamento externo
        }


    }
}
