#include <stdio.h>
#include <string.h>

void convertor (char infix[50], char postfix[50]) {
    char stack[50];
    stack[0] = '(';
    int ctr = 0, x = 1, i;
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == ')') {
            while (stack[x-1] != '(') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            x--;
        }
        else if (infix[i] == '^') {
            while (stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == '/') {
            while (stack[x-1] == '/' || stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == '*') {
            while (stack[x-1] == '*' || stack[x-1] == '/' || stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == '+') {
            while (stack[x-1] == '+' || stack[x-1] == '*' || stack[x-1] == '/' || stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == '-') {
            while (stack[x-1] == '-' || stack[x-1] == '+' || stack[x-1] == '*' || stack[x-1] == '/' || stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == ' ') {
            //ignore
        }
        else {
            //assuming it is an operand...
            postfix[ctr] = infix[i];
            ctr++;
        }
    }
    postfix[ctr] = '\0';
}

int main() {
    char infixf[50], postfix[50], infix[50];
    printf ("Enter the infix expression : ");
    scanf ("%s", infix);
    infix[strlen(infix)] = ')';
    infix[strlen(infix)+1] = '\0';
    convertor (infix, postfix);
    printf ("The postfix expression is : %s\n", postfix);
    return 0;
}
