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

        wordList = (char *) calloc (10, sizeof(char));

        if (wordList==NULL){
                printf("Erro de alocacao\n");
        } else{ 
                printf("Tudo certo\n");
        }

        //colocando conteudo para teste 
        
        scanf("%s", wordList);
        printf("%s\n", wordList);
        if(wordList[2]=='\0'){
                printf("agora sim sabemos como separam\n");
        }
        free(wordList);        
        return;
}
