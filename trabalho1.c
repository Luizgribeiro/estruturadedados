/* TRABALHO 1 DE ESTRUTURAS DE DADOS
 * aluno: Luiz Guilherme Ribeiro
 * DRE:114150509
 * data:23/10/2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sortstring(char*string_array, int wordsize, int qttd){
        int i, arraypos=0, retorno, j, controle, k, l;
        char *originalword, *testedword, *aux;

        //alocando espaco e copiando a palavra a ser testada
        testedword= (char*) calloc(wordsize, sizeof(char));
        originalword=(char*) calloc(wordsize, sizeof(char));
        if((originalword==NULL) || (testedword==NULL)){
                printf("Erro de alocação!!!\n\n");
                        return;
        }     
        //printf("Tamanho da palavra: %d, quantidade %d\n", wordsize, qttd);
        
        //bubble sort para todos os elementos do array
        for(i=0;i<qttd;i++){
               //carregando a palavra base
               for(j=0;j<wordsize;j++){
                        originalword[j]=string_array[j+i*wordsize];
               }
                //carregar as outras palavras, comparalas e dependendo do retorno trocar de lugar
                for(k=0;k<qttd;k++){
                        for(l=0;l<wordsize;l++){
                                testedword[l]=string_array[l+k*wordsize];
                        }
                        retorno=strncmp(originalword,testedword, wordsize);
                        //printf("palavras a serem comparardas: %s & %s-------->%d\n", originalword, testedword, retorno);
                        if(retorno<0){
                                //colocar aquilo que estiver em tested na posicao de original
                               for(j=0;j<wordsize;j++){
                                        
                                        string_array[k*wordsize+j]=originalword[j];
                                        string_array[i*wordsize+j]=testedword[j];
                               }
                               //troando as referencias caso tenha trocado
                               aux=testedword;
                               testedword=originalword;
                               originalword=aux;
                        }
                }
        }
               free(originalword);
               free(testedword);


}

//checagem letra por letra do anagrama
int checkbyletter (char * original, char * tested, char * allocplace, int wordsize){
        //dicionario de dados
        int i,j, count=0;
        char * testedword, *originalword;
               
        //alocando espaco e copiando a palavra a ser testada
        testedword= (char*) calloc(wordsize, sizeof(char));
        originalword=(char*) calloc(wordsize, sizeof(char));
        if((originalword==NULL) || (testedword==NULL)){
                printf("Erro de alocação!!!\n\n");
                        return;
        }      
        //copiando para nao perder data
        strcpy(testedword, tested);
        strcpy(originalword, original);

        //verifica se cada letra presente na palavra original existe na palavra comparada
        for (i=0; i<wordsize; i++){
                for(j=0; j<wordsize; j++){
                                if(originalword[i]==testedword[j]){
                                count++;
                                //para que letras repetidas não sejam contadas duas vezes
                                originalword[i]='\0';
                                testedword[j]='\n';
                                }
                }
        }

        //jogando os anagramas em um buffer 
        if (wordsize==count){
                strcat(allocplace, tested);
                return 1;

        }
        //desalocando espaco
        free(testedword);
        free(originalword);
        return 0;
}

void anagramtest(char * c, int size){
        //dicionario de dados
        char space=' ', breakline='\n', *comparable, *word, *anagrams;
        int currentpos=0, stringsize=0,newstringsize=0, keepwrdinit=0, vector2pos=0, i, numofwrd=0, j;


        while(currentpos<size){
                //alocando espaco e checando para a palavra a ser comparada
                 word=(char*)calloc(size,sizeof(char));
                 if((word==NULL)){
                                printf("Erro de Alocação!!\n\n");
                                return;
                 }else {  

                        //pegando o inicio da palavra comparada
                        keepwrdinit=currentpos;
                        stringsize=0;   
                        //pegando a palavra comparada
                        while ((c[currentpos]!= space) && (c[currentpos]!=breakline)) {
                                word[stringsize]=c[currentpos];
                                stringsize++;
                                currentpos++;
                        }       
                        printf("%s", word);

                        //alocando espaço para os anagramas&comparable e checando
                                anagrams=(char*)calloc(size,sizeof(char));
                                comparable=(char*)calloc(size,sizeof(char));
                                if((comparable==NULL) || (anagrams==NULL)){
                                        printf("Erro de alocacao de memoria!\n");
                                        return;
                                }
                   
                        //varrendo o vetor em busca de palavras
                        while(vector2pos!=keepwrdinit){
                                 
                                newstringsize=0; 
                                //carregando a palavra anterior
                                while((c[vector2pos]!= space) && (c[vector2pos]!=breakline)){
                                        comparable[newstringsize]=c[vector2pos];
                                        newstringsize++;
                                        vector2pos++;
                                }
                                //colocando na primeira letra da prox palavra
                                vector2pos++;

                                //verificando se eh anagrama e contando quantos anagrama ela tem
                                if(stringsize==newstringsize){
                                        if(checkbyletter(word, comparable, anagrams, newstringsize)){
                                                numofwrd++;
                                        }
                                }

                                //zerando o vetor
                                for(i=0;i<newstringsize;i++){
                                        comparable[i]=0;
                                }
                        }
                        if(numofwrd>1){
                                sortstring(anagrams,stringsize, numofwrd);
                        }

                        //imprimindo o resto das palavras ordenadas
                        for(i=0;i<numofwrd;i++){
                                printf(" ");
                                for(j=0;j<stringsize;j++){
                                        printf("%c",anagrams[i*stringsize+j]);
                                }
                        }
                        printf("\n");
                        //liberando espaço allocado pelos anagramas
                        free(anagrams);
                        free(comparable);
                        vector2pos=0;
                        currentpos++;
                        numofwrd=0;
                }
                free(word);
        }
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
                       // printf("%c", *(wordList+letterCount));
                        letterCount++;
                //parando no EOF
                }else{
                        break;
                }
        }

        anagramtest(wordList, letterCount);
        printf("\n");
        free(wordList);        
        return;
}



