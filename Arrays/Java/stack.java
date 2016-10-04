class Stack
{
int top;
int st[]=new int[7];
Stack()
{
top=0;
}
void push(int n)
{
if(top==7)
System.out.println("Stack overflow...");
else
{
st[top]=n;
top++;
}
}
int pop()
{
if(top<0)
{
System.out.println("Stack underflow...");
return(0);
}
else 
{
int m;
m=st[top];
st[top]=0;
top--;
return(m);
}
}
}
class r
{
public static void main(String args[])
{
Stack obj1=new Stack();
for(int i=5;i<=12;i++)
{
obj1.push(i);
}
for(int i=0;i<8;i++)
{
System.out.println(obj1.pop());
}
}
}
