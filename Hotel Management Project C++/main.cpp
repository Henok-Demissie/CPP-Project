#include<iostream>
#include<fstream>
using namespace std;

//creating structure for store coustomer information

struct person
{
	char name[20];
	char phone[20];
	int room_no;
	long room_price;
}info;

//function for booking room

void book_room()
{
	int room;
	string ty;

    cout<<"**********************************************\n";
	cout<<"\t\tROOM MENU\n";
	cout<<"**********************************************\n";
    cout<<"*********************************************\n";
	cout<<"\t\tTOTAL NUMBER OF ROOMS 50 \n";
	cout<<"\t\t1-15 VIP\n\t\t16-30 NORMAL\n\t\t31-50 FAMILY\n";
	cout<<"**********************************************\n";
	beg:
	cin>>room;

	if(!room||room>50||room<1)
	{
		cout<<"\t\t\tERORR PLEASE ENTER CORRECT NUMBER AGAIN\n";
		cin.clear();
		cin.ignore();
		goto beg;
	}
	ofstream fp;        //To write input data to txt file
    fp.open("info.txt",ios::out|ios::app);

   fstream rfile("info.txt",ios::in);
   if(!rfile)
   {
   	cout<<"\t\t\tFILE DOESNT EXIST\n";
   	return;
   }
   while(rfile.read(reinterpret_cast<char*>(&info),sizeof(person)))
{

if(room==info.room_no)
{
	cout<<"\t\t\tROOM TAKEN ENTER ANOTHER";
    cin.clear();
	cin.ignore();
    goto beg;
}
}
rfile.close();
 fstream wfile("info.txt",ios::out|ios::app);
 if(!wfile)
  {
   	cout<<"\t\t\tFILE DOESNT EXIST\n";
   	return;
   }
    cout<<"------------------------------------------------------------\n";
	cout<<"\t\t\tENTER YOUR NAME\n";
    cin.ignore();
    cin.getline(info.name,20);
    cout<<"\t\t\tENTER YOUR PHONE NO : 251";
    cin>>info.phone;
    info.room_no=room;
    if(room>=1&&room<=15)
    {
    	info.room_price=2000;
	}
	else if(room>=16&&room<=30)
    {
    	info.room_price=1000;
	}
	else if(room>=31&&room<=50)
    {
    	info.room_price=1500;
	}
 wfile.write(reinterpret_cast<char*>(&info),sizeof(person));
wfile.close();

}

//function to list all customer record with detail

void adminlist_room()
{
	system("cls");
	 cout<<"*********************************************\n";
	cout<<"\t\tLIST OF TAKEN ROOMS\n";
	cout<<"*********************************************\n";
	fstream rfile("info.txt",ios::in);
	if(!rfile)
	{
		cout<<"\t\t\tERORR FILE DOESNT EXIST";
		return;
	}
while(rfile.read(reinterpret_cast<char*>(&info),sizeof(person)))
	{
	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: "<<info.name<<"\nCUSTOMER PHONE NO: 251"<<info.phone<<endl;
cout<<"-----------------------------------------------\n";

	}
	rfile.close();

}

//function to list taken rooms record

void list_room()
{
	system("cls");
	 cout<<"*********************************************\n";
	cout<<"\t\tLIST OF TAKEN ROOMS\n";
	cout<<"*********************************************\n";
	fstream rfile("info.txt",ios::in);
	if(!rfile)
	{
		cout<<"\t\t\tERORR FILE DOESNT EXIST";
		return;
	}
while(rfile.read(reinterpret_cast<char*>(&info),sizeof(person)))
	{
	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: *********"<<"\nCUSTOMER PHONE NO: 251**********"<<endl;
	cout<<"-----------------------------------------------\n";
	}
	rfile.close();

}

//function to search specific room details with room numbers

int search_room(int x)
{
	system("cls");
		cout<<"-----------------------------------------------\n";
		cout<<"\t\t\tSEARCHING ROOM\n";
		cout<<"-----------------------------------------------\n";

        fstream rfile("info.txt",ios::in);
	if(!rfile)
	{
		cout<<"\t\t\tERORR FILE DOESNT EXIST";
		goto end;
	}
while(rfile.read(reinterpret_cast<char*>(&info),sizeof(person)))
	{
		if(info.room_no==x)
		{
	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: "<<info.name<<"\nCUSTOMER PHONE NO: 251"<<info.phone<<endl<<endl;
	cout<<"-----------------------------------------------\n";
	  goto end;  }
    }
   rfile.close();
   end:
if(info.room_no!=x)
		{
		cout<<"-----------------------------------------------\n";
	    cout<<"\t\t\tCUSTOMER DOESNT EXIST\n";
	   	cout<<"-----------------------------------------------\n";
		}}

//function to delete room record

int delete_room(int n)
{

int ch;
	fstream rfile;
	fstream wfile;
	rfile.open("info.txt",ios::in);
	if(!rfile)
	{
		cout<<"\t\t\tFILE DOESNT EXIST\n";
		return 0;
	}
	wfile.open("info1.txt",ios::out);
	rfile.seekg(0,ios::beg);
	while (rfile.read(reinterpret_cast<char*>(&info),sizeof(person)))
	{
	if(info.room_no==n)
	{
	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: "<<info.name<<"\nCUSTOMER PHONE NO: 251"<<info.phone<<endl<<endl;
	cout<<"-----------------------------------------------\n";
	cout<<"\n\t\t\tIF YOU WANT TO DELETE THIS RECORED PRESS 1 ELSE ANY number\n";
     v:
    cin>>ch;
	if(!ch)
	{
	cout<<"\t\t\tERORR ENTER CORRECT NUMBER";
	cin.clear();
	cin.ignore();
	goto v;
	}
	if(ch==1)
	{

goto del;
	}
else cout<<"\t\t\tRECORD SAVED \n";
return 0;
}else
{
 cout<<"\n\t\t\tROOM DOESNT EXIST";
return 0;
}

del:
		if(info.room_no!=n)
	{
		wfile.write(reinterpret_cast<char*>(&info),sizeof(person));

	}rfile.close();
	wfile.close();
	remove("info.txt");
	rename("info1.txt","info.txt");
		cout<<"\t\t\tRECORD DELETED\n";}

}

//function to modify room record

int modify_room(int x)
{
	long pos,test=0;
	fstream file("info.txt",ios::in|ios::out);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read(reinterpret_cast<char*>(&info),sizeof(person));
		if(info.room_no==x)
		{	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: "<<info.name<<"\nCUSTOMER PHONE NO: 251"<<info.phone<<endl<<endl;
	cout<<"-----------------------------------------------\n";


			cout<<"------------------------------------------------------------\n";
		cout<<"\t\t\tENTER NEW DETAILS\n";
	cout<<"\t\t\tENTER  THE NEW NAME\n";
    cin.ignore();
    cin.getline(info.name,20);
    cout<<"\t\t\tENTER THE NEW PHONE NO : 251";
    cin>>info.phone;
			file.seekg(pos);
			file.write(reinterpret_cast<char*>(&info),sizeof(person));
			test=1;
			break;

		cout<<"\t\t\tROOM MODIFIED SUCCESSFULLY ";
	}}
	if(test==0)
	{
		cout<<"\t\t\t SORRY ROOM DOESN'T EXIST\n";
	}
}






int modify_Rprice(int x)
{
	long pos,test=0;
	fstream file("info.txt",ios::in|ios::out);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read(reinterpret_cast<char*>(&info),sizeof(person));
		if(info.room_no==x)
		{	cout<<"-----------------------------------------------\n";
cout<<"\nCUSTOMER ROOM NO: "<<info.room_no<<"\nCUSTOMER ROOM PRICE: "<<info.room_price<<" BIRR\nCUSTOMER NAME: "<<info.name<<"\nCUSTOMER PHONE NO: 251"<<info.phone<<endl<<endl;
	cout<<"-----------------------------------------------\n";


			cout<<"------------------------------------------------------------\n";
		cout<<"\t\t\tENTER NEW DETAILS\n";
    cout<<"\t\t\tENTER ROOM BILL";
    cin>>info.room_price;
			file.seekg(pos);
			file.write(reinterpret_cast<char*>(&info),sizeof(person));
			test=1;
			break;

		cout<<"\t\t\tROOM MODIFIED SUCCESSFULLY ";
	}
	if(test==0)
	{
		cout<<"\t\t\t SORRY ROOM DOESN'T EXIST\n";
	}}
	return 0;
}


//starting of main program

int main()
{ bmenu:
int ch,ch1;
string pass="1234";
system("cls");
cout<<"-------------------------------------------------------------------\n";
cout<<"\t\t\tHOTEL MANAGEMENT\n\t\t\t***MAIN MENU***\n";
cout<<"-------------------------------------------------------------------\n";
cout<<"\t\t\t1)BOOK A ROOM\n";
cout<<"\t\t\t2)LIST OF TAKEN ROOM\n";
cout<<"\t\t\t3)ADMIN\n";
cout<<"\t\t\t4)EXIT\n";
bg:
cin>>ch;
if(!ch||ch>4||ch<1)
{
	cout<<"\t\t\tENTER CORRECT CHOICE AGAIN\n";
	cin.clear();
	cin.ignore();
	goto bg;
}
switch(ch)
{
	case 1:
		system("cls");
		book_room();
		break;
	case 2:
		system("cls");
		list_room();
		break;
	case 3:
		{ system("cls");
			cout<<"\t\t\tWELLCOME TO ADMIN MENU \n\t\t\tENTER PASSWORD:";
			cin>>pass;
		if(pass!="1234")
		{
	for(int z=1;z<3;z++)
	{cout<<"\t\t\tINCORRECT PASSWORD TRY AGAIN\n\t\t\tATTEMPT:"<<1+z<<" OF 3";
	cin>>pass;
	if(pass=="1234")
	{goto next;
	}
	}
	cout<<"\n\t\t\tINCORRECT PASSWORD";
		return 0;
	}
		next:
				{
					system("cls");
cout<<"-------------------------------------------------------------------\n";
cout<<"\t\t\tHOTEL MANAGEMENT\n\t\t\t***ADMIN MENU***\n";
cout<<"-------------------------------------------------------------------\n";
cout<<"\t\t\t1)DELETE ROOM\n";
cout<<"\t\t\t2)MODIFY ROOM\n";
cout<<"\t\t\t3)SEARCH ROOM\n";
cout<<"\t\t\t4)LIST ROOM\n";
cout<<"\t\t\t5)MODIFY ROOM PRICE\n";
cout<<"\n   \t\t\t6) BACK\t\t 7)EXIT\n";
				}
bac:
cin>>ch1;
if(!ch1||ch1>7||ch1<1)
{cout<<"\t\t\tENTER CORRECT CHOICE";
cin.clear();
cin.ignore();
goto bac;
}
switch(ch1)
{

case 1:
	int n;
	system("cls");
	cout<<"\t\t\tENTER ROOM NUMBER:";
	cin>>n;
	delete_room(n);
	break;
	case 2:
			int n1;
	system("cls");
	cout<<"\t\t\tENTER ROOM NUMBER:";
	cin>>n1;
	modify_room(n1);
	break;
	case 3:
			int n2;
	system("cls");
	cout<<"\t\t\tENTER ROOM NUMBER:";
	cin>>n2;
	search_room(n2);
	break;
	case 4:
		adminlist_room();
    break;
    case 5:
    			int n3;
	system("cls");
	cout<<"\t\t\tENTER ROOM NUMBER:";
	cin>>n3;
	modify_Rprice(n3);
    	break;
    case 6:
    goto bmenu;
    break;
    case 7:
    return 0;
}
		string cont;
cout<<"\n\t\tTO CONTINUE PREES 0 ELSE ANY NUMBER";
cin>>cont;
if(cont!="0")
return 0;
else goto next;
}
case 4:
return 0;

}
string cont;
cout<<"\n\t\tTO CONTINUE PREES 0 ELSE ANY NUMBER";
cin>>cont;
if(cont!="0")
return 0;
else goto bmenu;
}
