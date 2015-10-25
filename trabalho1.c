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
        char *wordList, letter;
        int letterCount=0, pointerLen;


        //alocando espaço na memoria
        wordList = (char *) calloc(20, sizeof(char));
        pointerLen=20*sizeof(char);

        if (wordList==NULL){
                printf("Erro de alocacao\n");
        }

        while(1){
                //realocando espaço
                if(letterCount>=(pointerLen/2)){
                       pointerLen*=2;
                       wordList=(char *) realloc(wordList,(pointerLen*2));
                       pointerLen*=2;
                //pegando entrada do usuario
                }else if(scanf("%c", &letter)!=EOF){
                        
                        wordList[letterCount]=letter;
                        printf("%c", *(wordList+letterCount));
                        letterCount++;
                //parando no EOF
                }else{
                        break;
                }

        }

        free(wordList);        
        return;
}



