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
        int i, letterCount=0, pointerLen, j=0;


        //alocando espaço na memoria
        wordList = (char *) calloc(20, sizeof(char));
        pointerLen=20*sizeof(char);

        if (wordList==NULL){
                printf("Erro de alocacao\n");
        } else{ 
                printf("Tudo certo\n");
        }
       
        //teste de retorno do scanf
        //--> pegar palavras digitadas 
        //--> contar quantas letras
        //-->realocar espaço
        

       // for (i=0; i>=0, i++){
                while(1){ 
                        scanf("%c", wordList+letterCount);
                        printf("%c", wordList[letterCount]);
                        letterCount++;
                        j++;
                }
                //adicionado por conta do \0 no final das palavras
                letterCount++;
                if(letterCount>=(pointerLen/2)){
                          wordList=(char *) realloc(wordList,pointerLen*2);
                          printf("Entrou aqui\n");
                }
        printf("%d\n\n", letterCount);
        
       scanf("%s %s", wordList, wordList+4);
       letterCount=strlen(wordList);
       printf("%d", pointerLen );
       //REALOCANDO ESPAÇO
        
        
        //testando realloc
        wordList=(char *) realloc(wordList, 40*sizeof(char));
        
        
        free(wordList);        
        return;
}



