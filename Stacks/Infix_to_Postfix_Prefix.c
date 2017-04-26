#include <stdio.h>
#include <string.h>

void convertor_postfix (char infix[50], char postfix[50]) {
    char stack[50];
    stack[0] = '(';
    infix[strlen(infix)] = ')';
    infix[strlen(infix)+1] = '\0';
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
        else if (infix[i] == '*' || infix[i] == '/') {
            while (stack[x-1] == '*' || stack[x-1] == '/' || stack[x-1] == '^') {
                postfix[ctr] = stack[x-1];
                ctr++;
                x--;
            }
            stack[x] = infix[i];
            x++;
        }
        else if (infix[i] == '-' || infix[i] == '+') {
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

void reverse_string (char* str) {
    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void convertor_prefix (char infix[50], char prefix[50]) {
    infix[strlen(infix)-1] = '\0';
    reverse_string (infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    convertor_postfix (infix, prefix);
    reverse_string (prefix);
}

int main() {
    char prefix[50], postfix[50], infix[50];
    printf ("Enter the infix expression : ");
    scanf ("%s", infix);
    convertor_postfix (infix, postfix);
    printf ("The postfix expression is : %s\n", postfix);
    convertor_prefix (infix, prefix);
    printf ("The prefix expression is : %s\n", prefix);
    return 0;
}
