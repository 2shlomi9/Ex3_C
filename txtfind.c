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

    int checkWord(char *word, char*str,int strl) {
        int count = 0, wordl = 0;
        char *tmp = str;
        char result[WORD] = "";
        if (!word) {
            word = "";
        } else {
            wordl = strlen(word);
        }
        if (!str) {
            str = "";
            strl=0;
        }


//        if(word && str){
//            //printf("word:%s, str:%s\n",word,str);
//            strl =strlen(str);
//            wordl = strlen(word);
//        }
//        else{
//            return 0;
//        }

        if (strl != wordl && strl + 1 != wordl) {
            return 0;
        }
        while (*result && *word && *tmp  && *word != '\0' && *tmp != '\0') {
            if (*word == *tmp) {
                *(result + count) = *word;
                tmp++;
                count++;
            }
            word++;
        }
        if (result != NULL && *result!= '\0') {
            int n = strlen(result);
            if(n == strl)
            return 1;
        }
        return 0;
    }

    int applyLine(char*sentence, char*str, char c, int strl){
        int ans=0;
//        char ptr[strlen(sentence)+1];
//        for(int i=0; i<strlen(sentence)+1; i++){
//            ptr[i] = *(sentence+i);
//        }
//        ptr[strlen(sentence)]=' ';
        char *start= sentence, *end = sentence;
//        start = ptr;
//        end =  ptr;
        //printf("end:%s, start:%s",end,start);
        while (start && end!= NULL && *end != '\0') {
            int sl= 0;
            if (*end == ' ') {
                *end = '\0';
                if(start){
                    sl = strlen(start);
                }
                if(sl>0 && checkWord(start,str, strl)){
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
    int i=0, strl=0;
    scanf("%c",&ch);
    while(ch != ' ')
    {
        str[i]=ch;
        i++;
        scanf("%c",&ch);
    }
    strl = i;
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
            if(i==LINE-2){
                break;
            }
        }
        line[i]=' ';
        if(*line=='\n'){
            break;
        }
        applyLine(line,str,option, strl);
        if(++lines>MAXLINES){
            break;
        }
    }
    return 0;


}