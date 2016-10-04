#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class Node{
public:
int info;
Node *prev;
Node *next;
Node(){
prev=NULL;
next=NULL;
}
};
class List{
Node *start;
Node *last;
public:
List(){
start=NULL;
last=NULL;
}
void traverse();
void insert();
void remove();
void search();
void rtraverse();
};
void List::traverse(){
if(start==NULL){
return;
}
Node *current;
current=start;
while(current!=NULL){
cout<<current->info<<endl;
current=current->next;
}
}
void List::rtraverse(){
if(start==NULL){
return;
}
Node *current;
current=last;
while(current!=NULL){
cout<<current->info<<endl;
current=current->prev;
}
}
void List::insert(){
int ele;
cout<<"Enter the element to be inserted : ";
cin>>ele;
Node *x=new Node;
x->info=ele;
if(start==NULL){
start=x;
last=x;
return;
}
Node *current;
current=start;
if(start->next==NULL && start->info>=ele){
x->next=start;
start->prev=x;
last=start;
start=x;
return;
}
if(start->info>=ele){
x->next=start;
start->prev=x;
start=x;
return;
}
while(current->next->info<ele && current->next!=NULL){
current=current->next;
}
if(current->next!=NULL){
x->next=current->next;
current->next=x;
x->next->prev=x;
x->prev=current;
return;
}
if(current->next==NULL){
current->next=x;
x->prev=current;
last=x;
}
}
void List::remove(){
if(start==NULL){
cout<<"Linked List empty!! Delete operation cannot be performed...\n";
return;
}
int ele;
cout<<"Enter the element to be deleted : ";
cin>>ele;
Node *current;
current=start;
if(start->info==ele && start->next==NULL){
start=NULL;
last=start;
cout<<"Deleted "<<ele<<" from linked list!!\n";
return;
}
if(start->info==ele){
start=start->next;
start->next->prev=NULL;
cout<<"Deleted "<<ele<<" from linked list!!\n";
return;
}
while(current->next!=NULL){
if(current->info==ele){
current->prev->next=current->next;
current->next->prev=current->prev;
delete current;
cout<<"Deleted "<<ele<<" from linked list!!\n";
return;
}
current=current->next;
}
if(current->info==ele){
current->prev->next=NULL;
delete current;
cout<<"Deleted "<<ele<<" from linked list!!\n";
return;
}
cout<<"Sorry!! Element "<<ele<<" not found in linked list...\n";
}
void List::search(){
if(start==NULL){
cout<<"Linked List empty!! No element exists...\n";
return;
}
int ele,ctr=1;
cout<<"Enter the element to be searched for : ";
cin>>ele;
Node *current;
current=start;
while(current!=NULL){
if(current->info==ele){
cout<<"Element "<<ele<<" found at index : "<<ctr<<" !!\n";
return;
}
current=current->next;
ctr++;
}
cout<<"Sorry!! Element "<<ele<<" not found in linked list...\n";
}
void main()
{
clrscr();
int a;
char ch;
List l;
do{
cout<<"MENU : "<<endl;
cout<<"\t1. Traverse"<<endl<<"\t2. Insert"<<endl<<"\t3. Delete"<<endl<<"\t4. Search"<<endl<<"\t5. Reverse Traverse"<<endl<<"\t6. Exit";
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
case 5:l.rtraverse();
       break;
case 6:exit(0);
       break;
default:cout<<"Wrong choice entered!!";
}
cout<<"Do you want to perform more operations?";
cin>>ch;
}while(ch=='y' || ch=='Y');
}
