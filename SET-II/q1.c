#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    char *a;
    int top;
}ST;

void init(ST*s){
    s -> a = (char*)malloc(sizeof(char));
    s -> top = -1;
}

void push(ST*s, int x){
    s->a[++s->top] = x;
}

char pop(ST*s){
    return s->a[s->top--];
}

int match(char a, char b){
    return (a == '(' && b == ')' ||
            a == '{' && b == '}' ||
            a == '[' && b == ']');
} 

int isBalanced(char exp[]){
    ST s;
    init(&s);

    for(int i = 0; exp[i]; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(&s, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(s.top == -1 || !match(pop(&s), exp[i])){
                return 0;
            }
        }
    }
    return s.top==-1;
}

int main(){
    char exp[100];

    printf("Enter expression:");
    scanf("%s", exp);

    if(isBalanced(exp)){
        printf("Balanced");
    }else{
        printf("Not balanced");
    }
    return 0;
}
