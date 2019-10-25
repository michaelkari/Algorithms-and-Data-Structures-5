#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char * pop();
extern void push(char *);

extern void add(char *);
extern void check_in();
extern int getCount();

typedef enum { FALSE, TRUE } boolean; //boolean definition

void attach(char * out, char in){
    out = realloc(out, strlen(out)+1);
    out[strlen(out)] = in;
}

int main(int argc, char * argv[])
{
    int ch;
    char * stringIn=malloc(sizeof(char *));
    boolean swtch=FALSE;
    check_in();
    //check for ch
    while ((ch=getchar())!='\n') {
        if(ch=='<')
            swtch=FALSE;
        else if(ch=='/') {
            swtch=TRUE;
            stringIn=malloc(sizeof(char*));
        }
        else if(ch=='>'){
            if(swtch==TRUE && strcmp(pop(),stringIn)!=0) {
                printf("NOT valid");
                exit(1);
            }
            else if(swtch==FALSE) {
                push(stringIn);
                add(stringIn);
            }
            stringIn=malloc(sizeof(char*));
        }
        else if(isalpha(ch))
            attach(stringIn, ch);
    }
    getCount();
    exit(0);
}
