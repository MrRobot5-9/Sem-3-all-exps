#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct {
 char data[MAX_SIZE];
 int top;
} Stack;
void push(Stack* stack, char item) {
 if (stack->top == MAX_SIZE - 1) {
 printf("Error: Stack overflow\n");
 return;
 }
 stack->data[++stack->top] = item;
}
char pop(Stack* stack) {
 if (stack->top == -1) {
 printf("Error: Stack underflow\n");
 exit(1);
  }
 return stack->data[stack->top--];
}
bool isBalanced(char* str) {
 Stack stack;
 stack.top = -1;
 for (int i = 0; str[i] != '\0'; i++) {
 if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
 push(&stack, str[i]);
 } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
 if (stack.top == -1) {
 return false;
 }
 char item = pop(&stack);
 if (str[i] == ')' && item != '(') {
 return false;
 } else if (str[i] == '}' && item != '{') {
 return false;
 } else if (str[i] == ']' && item != '[') {
 return false;
 }
 }
 }
 return stack.top == -1;
}
int main() {
 char str[MAX_SIZE];
 printf("Enter a string of parentheses: ");
 scanf("%s", str);
 if (isBalanced(str)) {
 printf("The parentheses are balanced.\n");
 } else {
 printf("The parentheses are not balanced.\n");
 }
 return 0;
}
 
