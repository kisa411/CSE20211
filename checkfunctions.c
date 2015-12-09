#include <stdio.h>

typedef struct {

    char word[15];
    int rowStart;
    int colStart;
    char orientation[6];
    char clue[15];
} Crossword;

int inputWords(Crossword words[20]);

int main() {
    inputWords():
}

int inputWords(Crossword words[20]) {

    int j, k, i;

    for(i=0; i<20; i++) {
        scanf("%s", words[i].word);
        if(words[i].word[0]=='.') {
            break;
        }
        i++;
    }
    for(j=0; j<i; j++) {
        for(k=0; k<strlen(words[j].word); k++) {
            words[j].word[k] = toupper(words[j].word[k]);
        }
    }
    return i;
}