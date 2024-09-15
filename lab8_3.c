// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode{
    char data;
    struct treenode *left;
    struct treenode *right;
}treenode;

treenode *root;
treenode *stack[50];
int top = -1;

treenode* createNode(char data) {
    treenode *newnode = (treenode*)malloc(sizeof(treenode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

treenode* setNode(char operatorr, treenode *left, treenode *right) {
    treenode *newnode = createNode(operatorr);
    newnode->left = left;
    newnode->right = right;
    
    return newnode;
}

void push(treenode* node) {
    if(top==50) {
        printf("Stack is full");
    }else {
        top++;
        stack[top] = node;
    }
}

treenode* pop() {
    treenode *data = NULL;
    if( top==-1) {
        printf("Stack is empty");
    }else {
        data = stack[top];
        top--;
    }
    
    return data;
}

void stackDisplay() {
    int i;
    for(i=0; i<=top; i++) {
        printf("%c ", (stack[i])->data);
    }
    printf("\n");
}

void printTree(treenode* r, int space) {
    if(r==NULL) return;
    
    space += 5;
    
    printTree(r->right, space);
    
    printf("\n");
    int i;
    for(i=5; i<space; i++)
        printf(" ");
    printf("%c\n", r->data);
    
    printTree(r->left, space);
}

void infix(treenode* r) {
    if(r==NULL) return;
    if(r->left != NULL)
        printf("(");
    infix(r->left);
    
    printf("%c", r->data);
    
    infix(r->right);
    if(r->left != NULL)
        printf(") ");
}

float calculate(treenode* r) {
    if(r->data >= '0' && r->data <= '9') return (r->data) - '0';
   
    char op = r->data;
    float result;
    int operand1 = calculate(r->left);
    int operand2 = calculate(r->right);
    
    switch(op) {
        case '+':  
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
    }
    return result;
}

int main() {
    char input[51];
    scanf("%50s", input);
    
    int i;
    for(i=strlen(input)-1; i>=0; i--) {
        
        if(input[i]>='0' && input[i]<='9') {
            push(createNode(input[i]));
            //push( node ( data ) );            
        }else{
            treenode *left = pop();
            treenode *right = pop();
            push(setNode(input[i], left, right));
        }
        stackDisplay();
    }
    
    root = pop();
    //printf("\n");
    infix(root);
    printf("=%.0f", calculate(root));
    //printf("\n\n\n\n");
    //printTree(root, 0);
    
    return 0;
}
