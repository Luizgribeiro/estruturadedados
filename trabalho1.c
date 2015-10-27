/* TRABALHO 1 DE ESTRUTURAS DE DADOS
 * aluno: Luiz Guilherme Ribeiro
 * DRE:114150509
 * data:23/10/2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void anagramtest(char * c, int size){
        char space=' ', breakline='\n', *comparable, *word;
        int currentpos=0, stringsize=0,newstringsize=0;
        
        comparable=(char*)calloc(size,sizeof(char));
        word=(char*)calloc(size,sizeof(char));

        //pegando a primeira palavra
        while ((c[currentpos]!= space) && (c[currentpos]!=breakline)) {
                word[stringsize]=c[currentpos];
                stringsize++;
                currentpos++;
        }

        //pegando a proxima palavra
        currentpos++;
        while((c[currentpos]!= space) && (c[currentpos]!=breakline)){
                comparable[newstringsize]=c[currentpos];
                newstringsize++;
                currentpos++;
        }

        if(stringsize==newstringsize){
                printf("temos o mesmo tamanho\n\n");
        }else
        //pegar a segunda
        printf("Ele está parado aqui %s!!!!!\n\n\n",word);
        //comparar o tamanho delas
        //ir para a proxima se o tamanho nao for o mesmo
        //se for o mesmo, comparar letra a letra
}

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

        anagramtest(wordList, pointerLen);

        free(wordList);        
        return;
}



