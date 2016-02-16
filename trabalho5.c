/*
Quinto trabalho de estrutura de dados
Aluno: Luiz Guilherme Ribeiro
DRE:114150509
Objetivo: implementar dois hashes diferentes (encadeamento interno e externo) para uma mesma funçao
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _cel{
    int data;
    cel *next;
}celula;

void main (int argc,char *argv[]){

    if(argc != 2){
        printf("favor entrar com \"./nome_do_arquivo -i/-e\"\n");
        exit(1);
    }else{
        if (*argv[1]=="-i"){
            //criar hash com encademento interno
        }else if (*argv[1]="-e"){
            //criar hash com encadeamento externo
        }


}
