#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp == NULL)
        return;
    temp->data = x;
    temp->next = top;
    top = temp;
}
int pop(){
    struct Node *temp;
    if(top == NULL)
        return -1;
    temp = top;
    top = top->next;
    free(temp);
    return 0;
}
bool isBalanced(char *expression){
    for(int i=0;expression[i]!='\0';i++){
            if(expression[i] == '('){
               push(expression[i]);
            }else if(expression[i] == ')'){
                if(top == NULL)
                    return false;
                pop();
            }
    }
    if(top == NULL)
        return true;
    return false;
}


int main()
{
    char *exp = "((a+ib)-(c+id))";

    if(isBalanced(exp)){
        printf("Balanced Expression :)");
    }
    else
        printf("Not Balanced Expression :(");

    return 0;
}
