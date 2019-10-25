#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[]){
  int ch,helper,prev_ch;
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
        continue;
    else if(ch=='/'){
        ch=getchar();
        if(isalpha(ch)){
            helper=getchar();
            if((helper=='>')&&(helper!=EOF)){
                if(isEmpty() == 1){//cant pop empty stack
                    fprintf(stderr,"Empty stack, Invalid pop\n");
                    exit(0);
                }
                else if((prev_ch=pop())==ch)//compare ch with top of stack
                    continue;
                else{//can pop an empty stack
                    fprintf(stderr, "Pop and top of stack does not match, Invalid\n");
                    exit(1);
                }
            }
            else{
                fprintf(stderr, "No closing identifier\n");
                exit(1);
            }
        }
    }
    else if(ch=='<'){
        ch=getchar();
        if(isalpha(ch)){
            helper=getchar();
            if((helper!=EOF)&&(helper=='>'))//pushing only if tag is complete
                push(ch);
            else{
                printf("Cannot find full tag, terminating");
                exit(1);
            }
        }
    }
    else
        exit(0);
  }
  if(isEmpty() == 1){
    printf("Valid\n");
    exit(0);
  }
  else{
    printf("NOT valid\n");
    exit(1);
  }
}
