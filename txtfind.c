#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define MAXLINES 250
#define OPTION1 'a'
#define OPTION2 'b'

char Line[LINE] = "";
char Word[WORD] = "";
char str[WORD] = "";
char option;

int get_line();

int getword(char word[]);

int substring(char * str1, char * str2);

int similar(char *s, char *t, int n);

void print_lines();

void print_similar_words();

int run_options();

int main() {
    
    getword(str);
    scanf(" %c\n", &option);
    if (!run_options()){
        printf ("%c is not an option!",option);
    }
    return 0;
}

int get_line(){
    int i = 0;
    for(i=0;i<LINE;i++){
        if(scanf("%c" , (Line+i))== EOF){
            *(Line+i) = '\0';
            break;
        }
        if(*(Line+i) == '\n'){
            *(Line+(++i)) = '\0';
            break;
        }
    }
    return i;
}

int getword(char word[]) {
    int i = 0;
    while (i < WORD){
        if (scanf("%c", &word[i]) == EOF || word[i] == ' ' || word[i] == '\t' || word[i] == '\n'){
            word[i] = '\0';
            break;
        }
        i++;
    }
    if (i == WORD)
        word[i - 1] = '\0';
    return i;
}

int substring(char *str1, char *str2){
    int flag = 0;
    int tempSize = 0;
    int size_str1 = strlen(str1);
    int size_str2 = strlen(str2);
    if(size_str1 < size_str2){
        return flag;
    }
    for(int i=0;i<size_str1;i++){
        for(int j=0;j<size_str2;j++) {
            if (*(str1 + i + j) == *(str2 + j)) {
                tempSize++;
            }
            else{
                tempSize =0;
                break;
            }
        }
        if(tempSize == size_str2){
            flag = 1;
            break;
        }
    }
    return flag;
}
int similar(char *s, char *t, int n) {
    int lens = strlen(s), lent = strlen(t), lenres = 0, i = 0;
    if (lens != lent + n) {
        return 0;
    }
    while (i < lens && lenres < lent){
        if (*(s + i) == *(t + lenres))
            lenres++;
        i++;
    }
    return (lent == lenres);
}


void print_lines(){
    while(get_line()){
        if(substring(Line,str)){
            printf("%s",Line);
        }
    }
}


void print_similar_words() {
    while (getword(Word)) {
        if (similar(Word, str, 0) || similar(Word, str, 1))
            printf("%s\n", Word);
    }
}

int run_options() {
    switch (option) {
        case OPTION1:
            print_lines(str);
            return 1;
        case OPTION2:
            print_similar_words(str);
            return 1;
    }
    return 0;
}
