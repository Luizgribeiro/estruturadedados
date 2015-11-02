/*
 *Autor: Luiz Guilherme Ribeiro
 *Biblioteca das funcoes utilizadas durante o curso
 */




void getchar(char *wordlist, int * lettercount){
	
	int pointerLen=20;
	char letter;
	while(1){
                //realocando espaço
                if(letterCount>=(pointerLen/2)){
                       pointerLen*=2;
                       wordList=(char *) realloc(wordList, pointerLen);
                       
                //pegando entrada do usuario
                }else if(scanf("%c", &letter)!=EOF){
                        
                        wordList[letterCount]=letter;
                        letterCount++;
                //parando no EOF
                }else{
                        break;
                }
        }

	return;
}
