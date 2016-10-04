#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
//Turbo
class Node{
public:
int info;
Node *next;
};
class List{
Node *start;
public:
List(){
start=NULL;
}
void traverse();
void insert();
void remove();
void search();
};
void List::traverse(){
if(start!=NULL){
Node *current;
current=start;
while(current!=NULL){
cout<<current->info<<endl;
current=current->next;
}
}
}
void List::insert(){
int ele;
cout<<"Enter the value of the element : ";
cin>>ele;
Node *x=new Node;
x->info=ele;
x->next=NULL;
if(start==NULL){
start=x;
return;
}
Node *prev;
prev=start;
if(start->info>=ele){
x->next=start;
start=x;
}
else{
while(prev->next->info<ele && prev->next!=NULL){
prev=prev->next;
}
if(prev->next!=NULL){
x->next=prev->next;
prev->next=x;
}
else{
prev->next=x;
}
}
}
void List::remove(){
if(start==NULL){
cout<<"List is empty!! Delete operation cannot be performed...\n";
return;
}
int ele;
cout<<"Enter the element to be deleted : ";
cin>>ele;
Node *current;
current=start;
if(start->info==ele){
start=current->next;
delete current;
cout<<"Element "<<ele<<" deleted!!\n";
return;
}
while(current!=NULL){
if(current->next->info==ele){
Node *kill=current->next;
current->next=current->next->next;
delete kill;
cout<<"Element "<<ele<<" deleted!!\n";
break;
}
else
current=current->next;
}
if(current==NULL)
cout<<"Element "<<ele<<" not found in linked list!!\n";
}
void List::search(){
if(start==NULL){
cout<<"Linked list is empty!! Cannot find element...\n";
return;
}
int ele;
cout<<"Enter the element to be searched : ";
cin>>ele;
Node *current;
current=start;
int ctr=1;
if(start->info==ele){
cout<<"Element "<<ele<<" found at position : "<<ctr<<" !!\n";
return;
}
while(current!=NULL){
if(current->info==ele){
cout<<"Element "<<ele<<" found at position : "<<ctr<<" !!\n";
break;
}
else{
ctr++;
current=current->next;
}
}
if(current==NULL)
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
