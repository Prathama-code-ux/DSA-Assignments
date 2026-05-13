#include <stdio.h>
#include <string.h>

void reverse (char str[]){
    int start = 0;
    int end = strlen(str) - 1;

    while(start < end){
        char temp = str[start];
        str[start] = str [end];
        str[end] = temp; 

        start++;
        end--;
    }
}

int main(){
    char original[100];
    char num[100];

    printf("Enter number:\n");
    scanf("%s", original);

    strcpy(num, original);

    reverse(num);
    printf("After first reverse:%s\n",num);

    reverse(num);
    printf("After second reverse:%s\n",num);

    if(strcmp(num, original) == 0){
        printf("same\n");
    }else{
        printf("not same\n");
    }
    return 0;
}