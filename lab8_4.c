#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treenode{
    char op;
    int value;
    struct treenode *left;
    struct treenode *right;
}node;

node *root;
node *stack[100];
int top = -1;

int power(int x, int deg) {
    int i;
    int result = 1;
    for(i=0;i<deg;i++)
        result *= x;
        
    return result;
}

int strToInt(char s[]) {
    int i,j=0;
    int result=0;
    for(i=strlen(s)-1; i>=0; i--, j++) {
        //printf("%d * %d\n", s[i]-'0', power(10, j));
        result += ((s[i] - '0') * power(10, j));
        //printf("result = %d\n", result);
    }
    
    return result;
}

node* createNode(int data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->value = data;
    newnode->op = '\0';
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

node* setNode(char op, node* left, node* right) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->op = op;
    newnode->left = left;
    newnode->right = right;
    
    return newnode;
}

void push(node* r) {
    if(top==100) {
        printf("stack is full");
    }else {
        stack[++top] = r;
    }
}

node* pop() {
    node* data=NULL;
    if(top==-1) {
        printf("stack is empty");
    }else {
        data = stack[top--];
    }
}

void infix(node *r) {
    if(r==NULL) return;
    if(r->left!=NULL)
        printf("(");
    infix(r->left);
    if(r->op == '\0') {
        printf("%d", r->value);
    }else {
        printf("%c", r->op);
    }
    infix(r->right);
    if(r->right!=NULL)
        printf(") ");
}

int calculate(node *r) {
    if(r->op == '\0') return r->value;
    
    int operand1 = calculate(r->left);
    //printf("\n%d   mmmmmmmmmmmmmm\n",r->right->value);
    int operand2 = calculate(r->right);
    char op = r->op;
    //printf("%d %c %d",operand1, op, operand2);
    int result;
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
    //printf(" => %d\n", result);
    return result;
}

void printTree(node *r, int space) {
    if(r==NULL) return;
    space += 5;
    
    printTree(r->right, space);
    
    int i;
    printf("\n");
    for(i=5; i<space; i++)
        printf(" ");
    if(r->op == '\0') {
        printf("%d\n", r->value);
    }else {
        printf("%c\n", r->op);
    }
    
    printTree(r->left, space);
}

int main() {
    char input[101];
    scanf("%[^\n]s", input);
    //strcpy(input, "1 2 3 4");
    char s[2] = " ";
    char *token = strtok(input, s);
    
    while(token!=NULL) {
        
        if(strcmp(token,"+")==0 || strcmp(token,"-")==0 || strcmp(token,"*")==0 || strcmp(token,"/")==0) {
            node *right = pop();
            node *left = pop();
            push(setNode(*token, left, right));
        }else {
            push(createNode(strToInt(token)));
        }
        token = strtok(NULL, s);
    }
    
    root = pop();
    infix(root);
    printf("=%d", calculate(root));
    //printTree(root, 0);
    
    return 0;
}
