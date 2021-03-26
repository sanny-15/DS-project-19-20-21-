#include<iostream>
#include<string.h>
#include<conio.h>
#include<fstream>
#include<stdio.h>

#define max 100
using namespace std;

//Class Customer
class Customer
{
public:
char name[100];
char address[100];
char phone[12];
char from_date[20];
char to_date[20];
float payment_advance;
int booking_id;
};


class Room
{
public:
char type;
char stype;
char ac;
int roomNumber;
int rent;
int status;

class Customer cust;
class Room addRoom(int);
void searchRoom(int);
void deleteRoom(int);
void displayRoom(Room);
};

//Global Declarations
class Room rooms[max];
int count=0;


Room Room::addRoom(int rno)
{
class Room room;
room.roomNumber=rno;
cout<<"\nType AC/Non-AC (A/N) : ";
cin>>room.ac;
cout<<"\nType Comfort (S/N) : ";
cin>>room.type;
cout<<"\nType Size (B/S) : ";
cin>>room.stype;
cout<<"\nDaily Rent : ";

cin>>room.rent;
room.status=0;
std::cout<<"\n";
std::cout<<"-----------------------------"<<endl;
std::cout<<"|  Room Added Successfully  |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
return room;
}


void Room::searchRoom(int rno)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
//cout<<"\t\t\t\t\tRoom Details\n";
std::cout<<"-----------------------------"<<endl;
std::cout<<"|      Room Details         |"<<endl;
//std::cout<<"-----------------------------"<<endl;
//cout<<"\nPress any key to go back..";
if(rooms[i].status==1)
{
//cout<<"\n\t\t\t\t\tRoom is Reserved";
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     Room is Reserved      |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
}
else
{
displayRoom(rooms[i]);
//cout<<"\n\t\t\t\t\tRoom is available";
//std::cout<<"-----------------------------"<<endl;
std::cout<<"|    Room is available      |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
}

}
else
{
//cout<<"\n\t\t\t\t\tRoom not found";
std::cout<<"-----------------------------"<<endl;
std::cout<<"|      Room not found       |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
std::cout<<"-----------------------------"<<endl;
std::cout<<"  Room Number : "<<tempRoom.roomNumber<<endl;
std::cout<<"  Type AC/Non-AC (A/N) : "<<tempRoom.ac<<endl;
std::cout<<"  Type Comfort (S/N) : "<<tempRoom.type<<endl;
std::cout<<"  Type Size (B/S) : "<<tempRoom.stype<<endl;
std::cout<<"  Rent : "<<tempRoom.rent<<endl;
std::cout<<"-----------------------------"<<endl;
//cout<<"Room Number: \t"<<tempRoom.roomNumber;
//cout<<"Type AC/Non-AC (A/N) "<<tempRoom.ac;
//cout<<"Type Comfort (S/N) "<<tempRoom.type;
//cout<<"Type Size (B/S) "<<tempRoom.stype;
//cout<<"Rent: "<<tempRoom.rent;
}

//hotel management class
class HotelMgnt:protected Room
{
public:
void checkIn();
void getAvailRoom();
void searchCustomer(char *);
void checkOut(int);
void guestSummaryReport();
};


void HotelMgnt::guestSummaryReport(){

if(count==0){
        system("cls");
	//cout<<"\n\t\t\t\t\t No Guest in Hotel !!";
	cout<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|   No Guest in Hotel !!    |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
}
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<" Customer First Name : "<<rooms[i].cust.name<<endl;
cout<<" Room Number : "<<rooms[i].roomNumber<<endl;
cout<<" Address (only city) : "<<rooms[i].cust.address<<endl;
cout<<" Phone : "<<rooms[i].cust.phone<<endl;
cout<<"---------------------------------------";
}

}

getch();
}

//hotel management reservation of room
void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|         Check-IN          |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"Enter Room number : ";
cin>>rno;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
found=1;
break;
}
}
if(found==1)
{
if(rooms[i].status==1)
{
std::cout<<"-----------------------------"<<endl;
std::cout<<"|  Room is already Booked   |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"Room is already Booked";
getch();
return;
}

cout<<"\n Enter booking id : ";
cin>>rooms[i].cust.booking_id;

cout<<"\n Enter Customer Name (First Name) : ";
cin>>rooms[i].cust.name;

cout<<"\n Enter Address (only city) : ";
cin>>rooms[i].cust.address;

cout<<"\n Enter Phone : ";
cin>>rooms[i].cust.phone;

cout<<"\n Enter From Date : ";
cin>>rooms[i].cust.from_date;

cout<<"\n Enter to  Date : ";
cin>>rooms[i].cust.to_date;


cout<<"\n Enter Advance Payment : ";
cin>>rooms[i].cust.payment_advance;

rooms[i].status=1;

//cout<<"\n Customer Checked-in Successfully..";
cout<<"\n";
std::cout<<"------------------------------------"<<endl;
std::cout<<"| Customer Checked-in Successfully |"<<endl;
std::cout<<"------------------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
}
}


//hotel management shows available rooms
void HotelMgnt::getAvailRoom()
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==0)
{
displayRoom(rooms[i]);
//cout<<"Press enter for next room";
found=1;
getch();
}
}
if(found==0)
{
//cout<<"\nAll rooms are reserved";
//getch();
}
}


//hotel management shows all persons that have booked room
void HotelMgnt::searchCustomer(char *pname)
{
int i,found=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && stricmp(rooms[i].cust.name,pname)==0)
{
    system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"| Customer Name: "<<rooms[i].cust.name<<endl;
std::cout<<"| Room Number: "<<rooms[i].roomNumber<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"Customer Name: "<<rooms[i].cust.name;
//cout<<"Room Number: "<<rooms[i].roomNumber;

//cout<<"Press enter for next record";
found=1;
getch();
}
}
if(found==0)
{
system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|        Person not found       |"<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"\n\t\t\t\t\tPerson not found.";
getch();
}
}


//hotel managemt generates the bill of the expenses
void HotelMgnt::checkOut(int roomNum)
{
int i,found=0,days,rno;
float billAmount=0;
for(i=0;i<count;i++)
{
if(rooms[i].status==1 && rooms[i].roomNumber==roomNum)
{
//rno = rooms[i].roomNumber;
found=1;
//getch();
break;
}
}
if(found==1)
{
cout<<endl;
cout<<" Enter Number of Days : ";
cin>>days;
billAmount=days * rooms[i].rent;
cout<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     CheckOut Details      |"<<endl;
std::cout<<"-----------------------------"<<endl;
//cout<<" CheckOut Details \n";
cout<<" Customer Name : "<<rooms[i].cust.name<<endl;
cout<<" Room Number : "<<rooms[i].roomNumber<<endl;
cout<<" Address : "<<rooms[i].cust.address<<endl;
cout<<" Phone : "<<rooms[i].cust.phone<<endl;
cout<<" Total Amount Due : "<<billAmount<<endl;
cout<<" Advance Paid: "<<rooms[i].cust.payment_advance<<endl;
cout<<" Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only"<<endl;

rooms[i].status=0;
}
getch();
}


//managing rooms (adding and searching available rooms)
void manageRooms()
{
class Room room;
int opt,rno,i,flag=0;
char ch;
do
{
system("cls");
cout<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     Hotel Management      |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|       1. Add Room         |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     2. Search Room        |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|   3. Back to Main Menu    |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"Choose option : ";
cin>>opt;
//cout<<"\n\t\t\t\t\t### Manage Rooms ###";
//cout<<"\n\t\t\t\t\t1. Add Room";
//cout<<"\n\t\t\t\t\t2. Search Room";
//cout<<"\n\t\t\t\t\t3. Back to Main Menu";
//cout<<"\n\n\t\t\t\t\tEnter Option: ";
//cin>>opt;


//switch statement
switch(opt)
{
case 1:
    system("cls");
    cout<<"\n\tRoom Details"<<endl;
cout<<"\nEnter Room Number : ";
cin>>rno;
i=0;
for(i=0;i<count;i++)
{
if(rooms[i].roomNumber==rno)
{
flag=1;
}
}
if(flag==1)
{
//cout<<"\nRoom Number is Present.";
//std::cout<<"-----------------------------"<<endl;
std::cout<<"|  Room Number is Present   |"<<endl;
std::cout<<"-----------------------------"<<endl;
cout<<"\nPress any key to go back..";
flag=0;
getch();
}
else
{
rooms[count]=room.addRoom(rno);
count++;
}
break;
case 2:
    system("cls");
cout<<"\n Enter room number : ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
    system("cls");
system("COLOR 4F");
std::cout<<endl;
std::cout<<"-----------------------------------------"<<endl;
std::cout<<"|  Please, Enter option between 1 to 3  |"<<endl;
std::cout<<"-----------------------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
//cout<<"\n Please Enter correct option";
break;
}
}while(opt!=3);
}
using namespace std;
int main()
{

   system("COLOR 3F");
   system("mode 0,100");
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];
//textbackground(BLACK);
//textcolor(WHITE);
system("cls");

do
{
system("cls");
system("COLOR 3F");
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     Hotel Management      |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     1. Manage Rooms       |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     2. Check-In Room      |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|    3. Available Room      |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     4. Search Customer    |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|     5. Check-Out Room     |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|   6. Guest Summary Report |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|          7. Exit          |"<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"Choose option : ";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|  Rooms data is not available  |"<<endl;
std::cout<<"|  Please add the rooms first   |"<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"Rooms data is not available Please add the rooms first.";
getch();
}
else
    system("cls");
hm.checkIn();
break;
case 3:
if(count==0)
{
system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|  Rooms data is not available  |"<<endl;
std::cout<<"|  Please add the rooms first   |"<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"\n\t\t\t\t\tRooms data is not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else{
system("cls");
std::cout<<endl;
std::cout<<"-----------------------------"<<endl;
std::cout<<"|      Room Details         |"<<endl;
hm.getAvailRoom();
cout<<"\nPress any key to go back..";
getch();}
break;
case 4:
if(count==0)
{
system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|  Rooms data is not available  |"<<endl;
std::cout<<"|  Please add the rooms first   |"<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"\n\t\t\t\t\tRooms are not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
{
system("cls");
std::cout<<endl;
cout<<" Enter Customer Name : ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|  Rooms data is not available  |"<<endl;
std::cout<<"|  Please add the rooms first   |"<<endl;
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
//cout<<"\n\t\t\t\t\tRooms are not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
{
       system("cls");
std::cout<<endl;
cout<<" Enter Room Number : ";
cin>>rno;
hm.checkOut(rno);
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
}
break;
case 6:
    system("cls");
std::cout<<endl;
std::cout<<"---------------------------------"<<endl;
std::cout<<"|      Guest Summary Report     |"<<endl;
std::cout<<"---------------------------------"<<endl;
hm.guestSummaryReport();
std::cout<<"---------------------------------"<<endl;
cout<<"\nPress any key to go back..";
break;
case 7:
system("cls");
std::cout<<endl;
std::cout<<"-----------------------------------"<<endl;
std::cout<<"|  THANK YOU! FOR USING SOFTWARE  |"<<endl;
std::cout<<"-----------------------------------"<<endl;
//cout<<"\nPress any key to go back..";
//cout<<"\n\t\t\t\t\tTHANK YOU! FOR USING SOFTWARE";
break;
default:
system("cls");
system("COLOR 4F");
std::cout<<endl;
std::cout<<"-----------------------------------------"<<endl;
std::cout<<"|  Please, Enter option between 1 to 7  |"<<endl;
std::cout<<"-----------------------------------------"<<endl;
cout<<"\nPress any key to go back..";
getch();
break;
}
}while(opt!=7);
getch();
}
