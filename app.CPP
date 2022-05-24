#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class book
{
    char book_number[30];
    char book_name[50];
    char author_name[20];
    public:
    void create_book()
    {
        system("cls");
        cout<<"\nEnter The Book Number: ";
        cin>>book_number;
        cout<<"\nEnter The Name of The Book: ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nEnter The Author's Name: ";
        cin.getline(author_name,50);
        cout<<"\t\n\nBook Created Successfully...";

    }
    void show_book()
    {
        system("cls");
        cout<<"\nBook Number: "<<book_number;
        cout<<"\nBook Name: "<<book_name;
        cout<<"\nAuthor's Name: "<<author_name;
    }
    void modify_book()
    {
        system("cls");
        cout<<"\nBook number : "<<book_number;
        cout<<"\nModify Book Name : ";
        cin.ignore();
        cin.getline(book_name,50);
        cout<<"\nModify Author's Name: ";
        cin.getline(author_name,50);
    }
    char* getbooknumber()
    {
        return book_number;
    }
    void report()
    {  
        cout<<book_number<<setw(30)<<book_name<<setw(30)<<author_name<<endl;
	}
};
class student
{
	  char ID_number[20];
	  char Student_name[20];
	  char stbno[6];
	  int token;
	   
	  public:
	  void create_student()
	  {
		    cout<<"\nEnter The ID Number ";
		    cin>>ID_number;
		    cout<<"\nEnter The Name of The Student: ";
		    cin>>Student_name;
		    token=0;
		    stbno[0]='\0';
		    cout<<"\t\n\nStudent Record Created Successfully...";
	  }

	  void show_student()
	  {
		    cout<<"\nID Number: "<<ID_number;
		    cout<<"\nStudent Name: ";
		    puts(Student_name);
		    cout<<"\nNo of Book issued: "<<token;
		    if(token==1)
			cout<<"\nBook No "<<stbno;
	  }
	  void modify_student()
	  {
		    cout<<"\nID Number: "<<ID_number;
		    cout<<"\nModify Student Name: ";
	         cin.getline(Student_name,50);
	  }
	  char* get_ID_number()
	  {
		    return ID_number;
	  }
	  char* retstbno()
	  {
		    return stbno;
	  }
	  int rettoken()
	  {
		    return token;
	  }
	  void addtoken()
	  {token=1;}
	  void resettoken()
	  {token=0;}
	  void getstbno(char t[])
	  {
		    strcpy(stbno,t);
	  }
	  void report()
	  {cout<<"\t"<<ID_number<<setw(20)<<Student_name<<setw(10)<<token<<endl;}
};

fstream fp,fp1;
book bk;
student st;

void write_book()
{
	  system("cls");
	  int more_or_main;
	  fp.open("book.dat",ios::out|ios::app);
	  do
	  {
		    bk.create_book();
		    fp.write((char*)&bk,sizeof(book));
		    cout<<"\nPress 1 to add more books.";
		    cout<<"\nPress 2 to return to main menu.\n";
		    cout<<"\nEnter: ";
		    cin>>more_or_main;
	  }while(more_or_main == 1);
	  fp.close();
}

void write_student()
{
	  system("cls");
	  int more_or_main;
	  fp.open("student.dat",ios::out|ios::app);
	  do
	  {
		    st.create_student();
		    fp.write((char*)&st,sizeof(student));
		    cout<<"\nPress 1 to add more students.";
		    cout<<"\nPress 2 to return to main menu.\n";
		    cout<<"\nEnter: ";
		    cin>>more_or_main;
	  }while(more_or_main == 1);
	  fp.close();
}

void display_a_book(char n[])
{
	  system("cls");
	  cout<<"\n\nBOOK DETAILS\n";
	  int check=0;
	  fp.open("book.dat",ios::in);
	  while(fp.read((char*)&bk,sizeof(book)))
	  {
		    if(strcmpi(bk.getbooknumber(),n)==0)
		    {
			       bk.show_book();
			      check=1;
		    }
	  }
	  fp.close();
	  if(check==0)
		    cout<<"\nBook does not exist";
	  getch();
}
void display_a_student(char n[])
{
	  system("cls");
	  cout<<"\n\nSTUDENT DETAILS\n";
	  int check=0;
	  fp.open("student.dat",ios::in);
	  while(fp.read((char*)&st,sizeof(student)))
	  {
		    if((strcmpi(st.get_ID_number(),n)==0))
		    {
			       st.show_student();
			       check=1;
		    }
	  }
	  fp.close();
	  if(check==0)
		    cout<<"\n\nStudent does not exist";
	  getch();
}

void modify_book()
{
	  system("cls");
	  char n[20];
	  int found=0;
	  cout<<"\n\n\tMODIFY BOOK";
	  cout<<"\n\n\tEnter The book number: ";
	  cin>>n;
	  fp.open("book.dat",ios::in|ios::out);
	  while(fp.read((char*)&bk,sizeof(book)) && found==0)
	  {
		    if(strcmpi(bk.getbooknumber(),n)==0)
		    {
			       bk.show_book();
			       cout<<"\n\nEnter The New Details of book"<<endl;
			       bk.create_book();
			       int pos=-1*sizeof(bk);
			      fp.seekp(pos,ios::cur);
			      fp.write((char*)&bk,sizeof(book));
			      cout<<"\n\n\t Record Updated Successfully...";
			      found=1;
		    }
	  }
	  fp.close();
	  if(found==0)
		    cout<<"\n\n Record Not Found ";
	  getch();

}
void modify_student()
{
	  system("cls");
	  char n[20];
	  int found=0;
	  cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	  cout<<"\n\n\tEnter Student's ID number: ";
	  cin>>n;
	  fp.open("student.dat",ios::in|ios::out);
	  while(fp.read((char*)&st,sizeof(student)) && found==0)
	  {
		    if(strcmpi(st.get_ID_number(),n)==0)
		    {
			       st.show_student();
			       cout<<"\n\nEnter The New Details of student"<<endl;
			       st.create_student();
			       int pos=-1*sizeof(st);
			       fp.seekp(pos,ios::cur);
			       fp.write((char*)&st,sizeof(student));
			       cout<<"\n\n\t Record Updated Successfully...";
			       found=1;
		    }
	  }
	  fp.close();
	  if(found==0)
		    cout<<"\n\n Record Not Found ";
	  getch();
}
void delete_student()
{
	  system("cls");
	  char n[20];
	  int flag=0;
	  cout<<"\n\tDELETE STUDENT";
	  cout<<"\n\nEnter The ID number of the Student You Want To Delete: ";
	  cin>>n;
	  fp.open("student.dat",ios::in|ios::out);
	  fstream fp2;
	  fp2.open("Temp.dat",ios::out);
	  fp.seekg(0,ios::beg);
	  while(fp.read((char*)&st,sizeof(student)))
	  {
		    if(strcmpi(st.get_ID_number(),n)!=0)
			      fp2.write((char*)&st,sizeof(student));
		    else
			      flag=1;
	  }

	  fp2.close();
	  fp.close();
	  remove("student.dat");
	  rename("Temp.dat","student.dat");
	  if(flag==1)
		    cout<<"n\tRecord Deleted ..";
	  else
		    cout<<"\nRecord not found";
	  getch();
}

void delete_book()
{
	  system("cls");
	  char n[20];
	  int flag=0;
	  cout<<"\n\tDELETE BOOK";
	  cout<<"\nEnter The Book's number You Want To Delete: ";
	  cin>>n;
	  fp.open("book.dat",ios::in|ios::out);
	  fstream fp2;
	  fp2.open("Temp.dat",ios::out);
	  fp.seekg(0,ios::beg);
	  while(fp.read((char*)&bk,sizeof(book)))
	  {
		    if(strcmpi(bk.getbooknumber(),n)!=0)
		    {
			       fp2.write((char*)&bk,sizeof(book));
		    }
		    else
			      flag=1;
	  }
	  fp2.close();
	  fp.close();
	  remove("book.dat");
	  rename("Temp.dat","book.dat");
	  if(flag==1)
		    cout<<"\n\tRecord Deleted ..";
	  else
		    cout<<"\nRecord not found";
	  getch();
}

void display_all_students()
{
	      system("cls");
	  fp.open("student.dat",ios::in);
	  if(!fp)
	  {
		    cout<<"\nERROR!!! FILE COULD NOT BE OPEN ";
		    getch();
		    return;
	  }
	  cout<<"\n\n\t\tSTUDENT LIST\n\n";
	  cout<<"==================================================================\n";
	  cout<<"\tID Number."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
	  cout<<"==================================================================\n";
	  while(fp.read((char*)&st,sizeof(student)))
	  {
		    st.report();
	  }
	  fp.close();
	  getch();
}

void display_allb()
{
	  system("cls");
	  fp.open("book.dat",ios::in);
	  if(!fp)
	  {
		    cout<<"\nERROR!!! FILE COULD NOT BE OPEN ";
		    getch();
		    return;
	  }
	  cout<<"\n\n\t\tBook LIST\n\n";
	 cout<<"=========================================================================\n";
	  cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
	  cout<<"=========================================================================\n";
	  while(fp.read((char*)&bk,sizeof(book)))
	  {
		    bk.report();
	  }
	  fp.close();
	  getch();
}

void issue_book()
{
	  system("cls");
	  char sn[20],bn[20];
	  int found=0,flag=0;
      cout<<"\t\t\nBOOK ISSUE";
	  cout<<"\n\n\tEnter student's ID number: ";
	  cin>>sn;
	  fp.open("student.dat",ios::in|ios::out);
	  fp1.open("book.dat",ios::in|ios::out);
	  while(fp.read((char*)&st,sizeof(student)) && found==0)
	  {
		    if(strcmpi(st.get_ID_number(),sn)==0)
		    {
			       found=1;
			       if(st.rettoken()==0)
			       {
					cout<<"\n\n\tEnter book number: ";
					 cin>>bn;
					 while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
					 {
						   if(strcmpi(bk.getbooknumber(),bn)==0)
						   {
							     bk.show_book();
							     flag=1;
							     st.addtoken();
							     st.getstbno(bk.getbooknumber());
							     int pos=-1*sizeof(st);
							     fp.seekp(pos,ios::cur);
							     fp.write((char*)&st,sizeof(student));
							     cout<<"\n\n\t Book issued successfully...";
						   }
					}
					if(flag==0)

						   cout<<"\nBook number does not exist";

			       }
			      else
					cout<<"You have not returned the last book ";
		    }
	  }
	  if(found==0)
		    cout<<"\nStudent record not exist...";
	  getch();
	  system("cls");
	  fp.close();
	  fp1.close();

}



void book_return()

{
	system("cls");
    char sn[20],bn[20];
    int found=0, flag=0, day, fine;
   cout<<"\t\tRETURN BOOKS\n";
    cout<<"\n\n\tEnter The students ID Number: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
		   if(strcmpi(st.get_ID_number(),sn)==0)
	      {
			found=1;
			if(st.rettoken()==1)
			{
			       while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			       {
					 if(strcmpi(bk.getbooknumber(),st.retstbno())==0)
			       {
					 bk.show_book();
					 flag=1;
					 cout<<"\n\nBook returned in no. of days:";
					 cin>>day;
					 if(day>15)
					 {
					    fine=(day-15)*1;
					    cout<<"\n\nLate submission!!! You have to pay a fine of Rs "<<fine;
					 }
						   st.resettoken();
						   int pos=-1*sizeof(st);
						   fp.seekp(pos,ios::cur);
						   fp.write((char*)&st,sizeof(student));
						  cout<<"\n\n\t Book returned successfully...";
			       }
			}
		      if(flag==0)
			cout<<"Book number does not exist";
			  }
		     else
			       cout<<"No book is issued..please check!!";
		    }
	     }

      if(found==0)
	  cout<<"Student record not exist...";
	  getch();
	  system("cls");
  fp.close();
  fp1.close();
  }
void intro()
{
    system("cls");
    cout<<"\n\n\t\t\t***-----NIRMA UNIVERSITY- LIBRARY MANAGEMENT SYSTEM-----***";
}

void book_menu()
{
    int option;
    cout<<"\t\t\n\n\n";
    cout<<"\n\t\tPress 1 to CREATE BOOKS";
    cout<<"\n\t\tPress 2 to DISPLAY ALL BOOKS";
    cout<<"\n\t\tPress 3 to DISPLAY SPECIFIC BOOK";
    cout<<"\n\t\tPress 4 to MODIFY BOOKS";
    cout<<"\n\t\tPress 5 to DELETE BOOKS";
    cout<<"\n\t\tPress 6 to GO BACK TO MAIN MENU";
    cout<<"\n\t\t\n";
    cout<<"\n\t\tOption: ";
    cin>>option;
    switch(option)
    {
        case 1:  system("cls");
                write_book();
                break;
        case 2: display_allb();
                break;
		case 3:
				char num[20];
				system("cls");
				cout<<"\n\n\tPlease Enter The book No. ";
				cin>>num;
				display_a_book(num);
				break;

		    case 4: modify_book();break;

		    case 5: delete_book();break;

		    case 6: system("cls");
			       break;
	  }
}

void student_menu()
{
	    int option;
	    cout<<"\n";
		cout<<"\n\tPress 1 to CREATE STUDENT RECORD";
		cout<<"\n\tPress 2 to DISPLAY ALL STUDENTS RECORD";
		cout<<"\n\tPress 3 to DISPLAY SPECIFIC STUDENT RECORD";
		cout<<"\n\tPress 4 to MODIFY STUDENT RECORD";
		cout<<"\n\tPress 5 to DELETE STUDENT RECORD";
		cout<<"\n\tPress 6 to GO BACK TO MAIN MENU";
 cout<<"\t\n";
 cout<<"\n\tOption: ";
 cin>>option;
 switch(option)
	  {
		    case 1:  system("cls");
					 write_student();
						   break;
		    case 2: system("cls");
					 display_all_students();
					     break;
		    case 3:
					char num[20];
					system("cls");
					cout<<"\n\n\tPlease Enter The ID Number: ";
					cin>>num;
					display_a_student(num);
					break;
		    case 4:system("cls");
					 modify_student();break;
		    case 5: system("cls");
					 delete_student();break;
		    case 6: break; 
	  }
}

int main()
{
	  int option = 0;
	  while(1)
	  {
		intro();
		cout<<"\nPress 1 to ISSUE BOOKS";
		cout<<"\nPress 2 to RETURN BOOKS";
		cout<<"\nPress 3 to UPDATE STUDENT RECORDS";
		cout<<"\nPress 4 to UPDATE BOOK RECORDS";
		cout<<"\nPress 5 to TO EXIT";
		cout<<"\n\t\t\n";
		cout<<"\nOption: ";
		cin>>option;

   		switch(option)
		{
			case 1:system("cls");
				issue_book();
				break;
			case 2:system("cls");
				book_return();
				break;
			case 3:system("cls");
				student_menu();
				break;
			case 4:system("cls");
				book_menu();
				break;
			case 5:exit(0);
				break;
		}
	}
	return 0;
}



