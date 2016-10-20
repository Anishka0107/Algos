#include<iostream.h>
#include<conio.h>
class Node{
public:
int info;
Node *next;
Node(){
next=NULL;
}
};
class Stack{
Node *top;
public:
Stack(){
top=NULL;
}
void display();
void peek();
void push(int);
void pop();
};
void Stack::push(int ele){
Node *n=new Node;
n->info=ele;
n->next=top;
top=n;
cout<<"Element "<<top->info<<" inserted!!";
}
void Stack::pop(){
if(top==NULL){
cout<<"Stack underflow!! Pop operation cannot be performed...";
return;
}
Node *kill=top;
top=top->next;
cout<<kill->info<<" deleted!!";
delete kill;
}
void Stack::display(){
Node *current=top;
while(current!=NULL){
cout<<current->info<<"->";
current=current->next;
}
}
void Stack::peek(){
cout<<top->info;    
}
void main()
{
clrscr();
int ch;
char con;
Stack s;
do{
cout<<"MENU:\n";
cout<<"\t1.PUSH\n"<<"\t2.POP\n"<<"\t3.DISPLAY\n"<<"\t4.PEEK"<<"Enter your choice : ";
cin>>ch;
switch(ch){
case 1:
int e;
cout<<"Enter the element you want to push : ";
cin>>e;
s.push(e);
break;
case 2:
s.pop();
break;
case 3:
cout<<"The stack is : ";
s.display();
break;
case 4:
cout<<"The top element is : ";    
s.peek();    
break;    
default:
cout<<"Wrong choice entered!!";
}
cout<<"\nDo you want to continue? ('Y' for yes)";
cin>>con;
}while(con=='y' || con=='Y');
}
