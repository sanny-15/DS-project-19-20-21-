#include<iostream>
#include<string.h>
#include<conio.h>

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
cout<<"\n\t\t\t\t\tType AC/Non-AC (A/N) : ";
cin>>room.ac;
cout<<"\n\t\t\t\t\tType Comfort (S/N) : ";
cin>>room.type;
cout<<"\n\t\t\t\t\tType Size (B/S) : ";
cin>>room.stype;
cout<<"\n\t\t\t\t\tDaily Rent : ";
cin>>room.rent;
room.status=0;

cout<<"\n\t\t\t\t\t Room Added Successfully!";
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
cout<<"\t\t\t\t\tRoom Details\n";
if(rooms[i].status==1)
{
cout<<"\n\t\t\t\t\tRoom is Reserved";
}
else
{
cout<<"\n\t\t\t\t\tRoom is available";
}
displayRoom(rooms[i]);
getch();
}
else
{
cout<<"\n\t\t\t\t\tRoom not found";
getch();
}
}

void Room::displayRoom(Room tempRoom)
{
cout<<"\n\t\t\t\t\tRoom Number: \t"<<tempRoom.roomNumber;
cout<<"\n\t\t\t\t\tType AC/Non-AC (A/N) "<<tempRoom.ac;
cout<<"\n\t\t\t\t\tType Comfort (S/N) "<<tempRoom.type;
cout<<"\n\t\t\t\t\tType Size (B/S) "<<tempRoom.stype;
cout<<"\n\t\t\t\t\tRent: "<<tempRoom.rent;
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
	cout<<"\n\t\t\t\t\t No Guest in Hotel !!";
}	
for(int i=0;i<count;i++)
{
if(rooms[i].status==1)
{
cout<<"\n\t\t\t\t\t Customer First Name : "<<rooms[i].cust.name;
cout<<"\n\t\t\t\t\t Room Number : "<<rooms[i].roomNumber;
cout<<"\n\t\t\t\t\t Address (only city) : "<<rooms[i].cust.address;
cout<<"\n\t\t\t\t\t Phone : "<<rooms[i].cust.phone;
cout<<"\n\t\t\t\t\t---------------------------------------";	
}
	
}

getch();
}

//hotel management reservation of room
void HotelMgnt::checkIn()
{
int i,found=0,rno;

class Room room;
cout<<"\n\t\t\t\t\tEnter Room number : ";
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
cout<<"\n\t\t\t\t\tRoom is already Booked";
getch();
return;
}

cout<<"\nEnter booking id: ";
cin>>rooms[i].cust.booking_id;

cout<<"\n\t\t\t\t\tEnter Customer Name (First Name): ";
cin>>rooms[i].cust.name;

cout<<"\n\t\t\t\t\tEnter Address (only city): ";
cin>>rooms[i].cust.address;

cout<<"\n\t\t\t\t\tEnter Phone: ";
cin>>rooms[i].cust.phone;

cout<<"\n\t\t\t\t\tEnter From Date: ";
cin>>rooms[i].cust.from_date;

cout<<"\nEnter to  Date: ";
cin>>rooms[i].cust.to_date;


cout<<"\n\t\t\t\t\tEnter Advance Payment: ";
cin>>rooms[i].cust.payment_advance;

rooms[i].status=1;

cout<<"\n\t\t\t\t\t Customer Checked-in Successfully..";
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
cout<<"\n\n\t\t\t\t\tPress enter for next room";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\n\t\t\t\t\tAll rooms are reserved";
getch();
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
cout<<"\n\t\t\t\t\tCustomer Name: "<<rooms[i].cust.name;
cout<<"\n\t\t\t\t\tRoom Number: "<<rooms[i].roomNumber;

cout<<"\n\n\t\t\t\t\tPress enter for next record";
found=1;
getch();
}
}
if(found==0)
{
cout<<"\n\t\t\t\t\tPerson not found.";
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
cout<<"\n\t\t\t\t\tEnter Number of Days:\t";
cin>>days;
billAmount=days * rooms[i].rent;

cout<<"\n\t\t\t\t\t\t######## CheckOut Details ########\n";
cout<<"\n\t\t\t\t\tCustomer Name : "<<rooms[i].cust.name;
cout<<"\n\t\t\t\t\tRoom Number : "<<rooms[i].roomNumber;
cout<<"\n\t\t\t\t\tAddress : "<<rooms[i].cust.address;
cout<<"\n\t\t\t\t\tPhone : "<<rooms[i].cust.phone;
cout<<"\n\t\t\t\t\tTotal Amount Due : "<<billAmount<<" /";
cout<<"\n\t\t\t\t\tAdvance Paid: "<<rooms[i].cust.payment_advance<<" /";
cout<<"\n\t\t\t\t\t*** Total Payable: "<<billAmount-rooms[i].cust.payment_advance<<"/ only";

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
cout<<"\n\t\t\t\t\t### Manage Rooms ###";
cout<<"\n\t\t\t\t\t1. Add Room";
cout<<"\n\t\t\t\t\t2. Search Room";
cout<<"\n\t\t\t\t\t3. Back to Main Menu";
cout<<"\n\n\t\t\t\t\tEnter Option: ";
cin>>opt;


//switch statement
switch(opt)
{
case 1:
cout<<"\n\t\t\t\t\tEnter Room Number: ";
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
cout<<"\n\t\t\t\t\tRoom Number is Present.\n\t\t\t\t\tPlease enter unique Number";
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
cout<<"\n\t\t\t\t\tEnter room number: ";
cin>>rno;
room.searchRoom(rno);
break;
case 3:
//nothing to do
break;
default:
cout<<"\n\t\t\t\t\tPlease Enter correct option";
break;
}
}while(opt!=3);
}
using namespace std;
int main()
{
class HotelMgnt hm;
int i,j,opt,rno;
char ch;
char pname[100];

system("cls");

do
{
system("cls");
cout<<"\t\t\t\t\t######## Hotel Management #########\n";
cout<<"\n\t\t\t\t\t1. Manage Rooms";
cout<<"\n\t\t\t\t\t2. Check-In Room";
cout<<"\n\t\t\t\t\t3. Available Rooms";
cout<<"\n\t\t\t\t\t4. Search Customer";
cout<<"\n\t\t\t\t\t5. Check-Out Room";
cout<<"\n\t\t\t\t\t6. Guest Summary Report";
cout<<"\n\t\t\t\t\t7. Exit";
cout<<"\n\n\t\t\t\t\tEnter Option: ";
cin>>opt;
switch(opt)
{
case 1:
manageRooms();
break;
case 2:
if(count==0)
{
cout<<"\n\t\t\t\t\tRooms data is not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
hm.checkIn();
break;
case 3:
if(count==0)
{
cout<<"\n\t\t\t\t\tRooms data is not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
hm.getAvailRoom();
break;
case 4:
if(count==0)
{
cout<<"\n\t\t\t\t\tRooms are not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
{
cout<<"\t\t\t\t\tEnter Customer Name: ";
cin>>pname;
hm.searchCustomer(pname);
}
break;
case 5:
if(count==0)
{
cout<<"\n\t\t\t\t\tRooms are not available.\n\t\t\t\t\tPlease add the rooms first.";
getch();
}
else
{
cout<<"\t\t\t\t\tEnter Room Number : ";
cin>>rno;
hm.checkOut(rno);
}
break;
case 6:
hm.guestSummaryReport();	
break;
case 7:
cout<<"\n\t\t\t\t\tTHANK YOU! FOR USING SOFTWARE";
break;
default:
cout<<"\n\t\t\t\t\tPlease Enter correct option";
break;
}
}while(opt!=7);

getch();
}
