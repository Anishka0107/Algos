
def evaluate (infix) :
    stack = []
    for x in infix :
        stack.append(0)
    ctr = -1
    for ch in range(len(infix)) :
        if (infix[ch] == '+') :
            stack[ctr-1] = stack[ctr] + stack[ctr-1]
            ctr -= 1
        elif (infix[ch] == '-') :
            stack[ctr-1] = - stack[ctr] + stack[ctr-1]
            ctr -= 1
        elif (infix[ch] == '*') :
            stack[ctr-1] = stack[ctr] * stack[ctr-1]
            ctr -= 1
        elif (infix[ch] == '/') :
            stack[ctr-1] = stack[ctr-1] / stack[ctr]
            ctr -= 1
        elif (infix[ch] == '^') :
            stack[ctr-1] = stack[ctr-1] ** stack[ctr]
            ctr -= 1
        elif (infix[ch] == ' ') : #nothing
            ch = ch
        else :
            ctr += 1 
            stack[ctr] = int(infix[ch])   
    return stack[ctr]


print ("Note the format for entering the postfix expression ---- \n\tSingle operator and operand allowed only... \n\tAfter you have finished entering the expression please press the Enter key... \n")
infix = input("Enter the infix expression : ")
postfix = evaluate (infix)
print ("The postfix expression is : %s" % (postfix))
