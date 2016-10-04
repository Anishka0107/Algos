#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class Node{
public:
int info;
Node *next;
};
class List{
Node *last;
public:
List(){
last=NULL;
}
void traverse();
void insert();
void remove();
void search();
};
void List::traverse(){
if(last!=NULL){
Node *current;
current=last->next;
do{
cout<<current->info<<endl;
current=current->next;
}while(current!=last->next);
}
}
void List::insert(){
int ele;
cout<<"Enter the value of the element : ";
cin>>ele;
Node *x=new Node;
x->info=ele;
x->next=NULL;
if(last==NULL){
last=x;
last->next=last;
return;
}
Node *current;
current=last->next;
if(current->info>ele){
x->next=last->next;
last->next=x;
return;
}
while(current!=last){
if(current->next->info<ele)
current=current->next;
else break;
}
if(current==last){
x->next=last->next;
last->next=x;
last=x;
return;
}
x->next=current->next;
current->next=x;
}
void List::remove(){
if(last==NULL){
cout<<"List is empty!! Delete operation cannot be performed...\n";
return;
}
int ele;
cout<<"Enter the element to be deleted : ";
cin>>ele;
Node *current;
current=last;
if(last->next==last && last->info==ele){
last=NULL;
delete current;
cout<<"Element "<<ele<<" deleted!!\n";
return;
}
if(last->info==ele){
while(current->next!=last)
current=current->next;
Node *kill=current->next;
current->next=last->next;
last=current;
delete kill;
cout<<"Element "<<ele<<" deleted!!\n";
return;
}
do{
if(current->next->info==ele){
Node *kill=current->next;
current->next=current->next->next;
delete kill;
cout<<"Element "<<ele<<" deleted!!\n";
return;
}
else
current=current->next;
}while(current!=last);
if(current==last->next)
cout<<"Element "<<ele<<" not found in linked list!!\n";
}
void List::search(){
if(last==NULL){
cout<<"Linked list is empty!! Cannot find element...\n";
return;
}
int ele;
cout<<"Enter the element to be searched : ";
cin>>ele;
Node *current;
current=last;
if(last->info==ele){
cout<<"Element "<<ele<<" found in linked list!!\n";
return;
}
while(current!=last){
if(current->info==ele){
cout<<"Element "<<ele<<" found in linked list!!\n";
break;
}
else{
current=current->next;
}
}
if(current==last)
cout<<"Element "<<ele<<" not found in linked list!!\n";
}
void main()
{
clrscr();
int a;
char ch;
List l;
do{
cout<<"MENU : "<<endl;
cout<<"\t1. Traverse"<<endl<<"\t2. Insert"<<endl<<"\t3. Delete"<<endl<<"\t4. Search"<<endl<<"\t5. Exit";
cout<<"\nEnter your choice : ";
cin>>a;
switch(a){
case 1:l.traverse();
       break;
case 2:l.insert();
       break;
case 3:l.remove();
       break;
case 4:l.search();
       break;
case 5:exit(0);
       break;
default:cout<<"Wrong choice entered!!";
}
cout<<"Do you want to perform more operations?";
cin>>ch;
}while(ch=='y' || ch=='Y');
}





