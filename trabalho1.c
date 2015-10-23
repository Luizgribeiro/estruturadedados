/* TRABALHO 1 DE ESTRUTURAS DE DADOS
 * aluno: Luiz Guilherme Ribeiro
 * DRE:114150509
 * data:23/10/2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (){

        //dicionario de dados
        char *wordList;
        int letterCount, pointerLen;


        //alocando espaço na memoria
        wordList = (char *) calloc(20, sizeof(char));
        pointerLen=20*sizeof(char);

        if (wordList==NULL){
                printf("Erro de alocacao\n");
        } else{ 
                printf("Tudo certo\n");
        }
       
        
       scanf("%s %s", wordList, wordList+4);
       letterCount=strlen(wordList);
       printf("%d", pointerLen );
       //REALOCANDO ESPAÇO
        
        
        //testando realloc
        wordList=(char *) realloc(wordList, 40*sizeof(char));
        
        
        free(wordList);        
        return;
}



