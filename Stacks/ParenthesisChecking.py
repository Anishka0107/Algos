def checker (expr) :
    stack = []
    top = -1
    for x in range(len(expr)) :
        if expr[x] == '(' or expr[x] == '{' or expr[x] == '[' :
            stack.append(0)
    for x in range(len(expr)) :
        if expr[x] == '(' or expr[x] == '{' or expr[x] == '[' :
            top += 1
            stack[top] = expr[x]
        elif expr[x] == ')' or expr[x] == '}' or expr [x] == ']' :
            ele = stack [top]
            top -= 1
            if (not(ele == '(' and expr[x] == ')' or ele == '{' and expr[x] ==  '}' or ele == '[' and expr[x] == ']')) :
                print "Invalid Expression"
                quit()        
    if top != -1 :
        print "Invalid Expression"
        quit()
    
myex = raw_input ("Please enter the expression : ")
checker (myex)
print ("Congo!! Your expression in valid!!")