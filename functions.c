/*
 *Autor: Luiz Guilherme Ribeiro
 *Biblioteca das funcoes utilizadas durante o curso
 */


#include <stdio.h>
#include <stdlib.h>

//recebe char de forma dinamica
void getword(char *wordList, int * letterCount){
	
	int pointerLen=20;
	char letter;
	while(1){
                //realocando espaço
                if(*letterCount>=(pointerLen/2)){
                       pointerLen*=2;
                       wordList=(char *) realloc(wordList, pointerLen);
                       
                //pegando entrada do usuario
                }else if(scanf("%c", &letter)!=EOF){
                        
                        wordList[*letterCount]=letter;
                        letterCount++;
                //parando no EOF
                }else{
                        break;
                }
        }

	return;
}




//busca em lista sequencial  --> substituir pelos tipos desejados
int buscaSequencial(int * lista, int tamanho, int valor){
        int i;
        for(i=0;i<tamanho;i++){
                if(*(lista+i)==valor){
                        return i;
                }
        }
}
