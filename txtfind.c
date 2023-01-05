#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define MAXLINES 250
#define OPTION1 'a'
#define OPTION2 'b'

int main(){

    int checkWord(char *word, char*str){
        int count = 0;
        char* tmp = str;
        char result[WORD]="";
        if(strlen(str) != strlen(word) && strlen(str)+1 != strlen(word) ){
            return 0;
        }
        while(*word!= '\t' && *word!= '\n' && *word!= '\0' && *tmp!= '\t' && *tmp!= '\n' && *tmp!= '\0'){
            if(*word==*tmp){
                *(result+count)=*word;
                tmp++;
                count++;
            }
            word++;
        }
        return(strcmp(result,str)==0);
    }

    int applyLine(char*sentence, char*str, char c){
        int ans=0;
        char ptr[strlen(sentence)+1];
        for(int i=0; i<strlen(sentence)+1; i++){
            ptr[i] = *(sentence+i);
        }
        ptr[strlen(sentence)]=' ';
        char *start, *end;
        start = ptr;
        end = ptr+'\0';
        while (*end != '\0') {
            if (*end == ' ') {
                *end = '\0';
                if(checkWord(start,str)){
                    ans=1;
                    if( c== OPTION2){
                        printf("%s\n", start);
                    }
                }
                start = end + 1;
                end = start;
            }
            else {
                end++;
            }
        }
        if(ans && c == OPTION1){
            printf("%s\n",sentence);
        }
        return ans;
    }

    char ch,option;
    char str [WORD];
    int i=0;
    scanf("%c",&ch);
    while(ch != ' ')
    {
        str[i]=ch;
        i++;
        scanf("%c",&ch);
    }
    scanf("%c",&option);
    while( scanf("%c",&ch)) {
        if (ch =='\n'){
            break;
        }
    }
    int lines=0;
    while( lines<MAXLINES && scanf("%c",&ch) && ch != EOF){
        i=0;
        char line [LINE]="";
        while(ch != '\n')
        {
            line[i]=ch;
            i++;
            scanf("%c",&ch);
        }
        if(*line=='\n'){
            break;
        }
        applyLine(line,str,option);
        if(++lines>MAXLINES){
            break;
        }
    }
    return 0;


}
