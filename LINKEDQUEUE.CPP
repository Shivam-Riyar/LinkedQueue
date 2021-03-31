/*Write an interactive menu driven program in C++ to implement Linked Queue which contains book information   (represented with the help of an array of structure BOOK) Book accession number as integer and title of the
  book as string.
  struct Book
  {
	   long accno;
	   char title[20];
  };*/

#include<iostream>
#include<conio.h>
#include<process.h>
#include<stdio.h>
using namespace std;
struct Book
{
	 long accno ;
	 char title[30];
	 Book *next;
}*front,*newptr,*save,*ptr,*rear;
Book *Create_new_node();
void Insert(Book*);
void Delq();
void Display(Book*);
int main()
{
front =rear=NULL;
int inf;
char ch;
int choice;

do
{
	getch();
	
	cout<<"1. Enter information.";
	cout<<"\n2. Display";
	cout<<"\n3. Delete ";
	cout<<"\n4. Exit";
	cout<<"\nEnter your choice:\t";
	cin>>choice;
	switch(choice)
	{
	case 1:
		newptr=Create_new_node();
		if(newptr==NULL)
		{
		cout<<"\nCannot create new node!!!Aborting";
		getch();
		exit(0);
		}
		Insert(newptr);
		break;
	case 2:
		Display(front);
		break;
	case 3:
		Delq();
		break;
	case 4:
		exit(0);
	default:
		cout<<"\nWrong choice";
	}
	cout<<"\nWant to repeat(y/n):\t";
	cin>>ch;
}while(ch=='y'||ch=='Y');
getch();
}
Book *Create_new_node()
{
 ptr =new Book;
 cout<<"Enter book information:\n";
 cout<<"Account no:\t";
 cin>>ptr->accno;
 cout<<"Enter title name:\t";
 cin>>(ptr->title);
 ptr->next=NULL;
 return ptr;
}
void Insert(Book *np)
{
if(front ==NULL)
front =rear =np;
else
{
rear->next=np;
rear=np;
}
}
void Delq()
{
if(front ==NULL)
cout<<"UNDERFLOW!!!\n";
else
{
ptr=front;
front =front->next;
delete ptr;
}
}
void Display(Book *np)
{
 cout<<"\nAccount No\tBook Title\n";
 while(np!=NULL)
 {
  cout<<np->accno<<"\t\t"<<np->title<<endl;
  np=np->next;
 }
 }


