#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>


using namespace std;

const char FILE_PATH[] = "D:\\iofile";

class  Student
{
	public:
 char names [ 16 ];
 	int roll_no;
 string remarks;
 
 int marks;
 float perc;
};

fstream MyFile ( FILE_PATH , ios :: binary | ios :: in | ios :: out );

void createFile();
void mainMenu();
void funcSwitch();
void addRecord();
int displayRecord();
void updateRecord();
void deleteRecord();
void printRecords();
int searchRecord();


int main ( int argc, char* argv [] )
{
 createFile();

 mainMenu();
}

void mainMenu()
{
cout << "Welcome to main menu\n\n" 
<< "enter  option: " << endl
 << "1. Add record" << endl
 << "2. Display record" << endl
 << "3. Update record" << endl
 << "4. Delete record" << endl
 << "5. Show all Students details" << endl
 << "6  Exit " << endl << endl
 << "Select: ";

 funcSwitch();
}

void funcSwitch()
{
 char choice;

 choice = getch();
 
 while ( choice != 54 )
 {
switch ( choice )
 {
  case '1' :
 addRecord();
 getch();
 
 
 break;

 case '2' :
displayRecord();
 getch();
 break;

 case '3' :
 updateRecord();
 getch();
 break;

case '4' :
 deleteRecord();
 getch();
 break;

 case '5' :
 printRecords();
 getch();
 break;

 case '6' :
 break;
 default :
 cout << choice << " Invaild choice" << endl << endl
 << "Press any key to choose again... ";
 getch();
 

 }
 mainMenu();
 choice = getch();

 }
}

void addRecord()
{
 Student temp;
 float a;
 
 cout << "Add new Student!" << endl
 << "All we need is a few details, let's begin: " << endl;
   
 cout << endl << " enter  name of student : ";
  cin >> temp.names;
  cout<< endl << "enter roll no : ";
  cin>>temp.roll_no;



cout << endl << " enter marks out of 500: ";
cin >> temp.marks;

 a=(float)temp.marks/500*100;
 cout<< "Percentage : "<< a;

cout<< endl<< "Enter remarks of the student : ";
cin>>temp.remarks;


 MyFile.open ( FILE_PATH , ios :: binary | ios :: app | ios :: out );
 MyFile.clear();
 MyFile.write ( ( const char* ) &temp, sizeof ( Student ) );
 MyFile.clear();
 MyFile.close();
}

int displayRecord()
{
Student temp;
int Roll_No;
 int position;
 int a;
 cout << "Enter roll no of person : ";
 cin >> Roll_No;
 



MyFile.open ( FILE_PATH , ios :: binary | ios :: in );
 MyFile.clear();
 MyFile.seekp ( position * sizeof ( Student ), ios :: beg );
 MyFile.read ( ( char* ) &temp, sizeof ( Student ) );

 if ( Roll_No != temp.roll_no )
 {
cout << endl << "No record found. Press any key to continue...";
 }
 else
  {
 cout << "We found your record: " << endl << endl
 << "Name: " << temp.names << endl <<"Roll No : "<<temp.roll_no
 << "marks:* " << temp.marks << endl;
 
 a=(float)temp.marks/500*100;
 cout<<"percentage : "<<a;
 cout<<"\nremarks:* "<<temp.remarks;
 }

cout << endl << "Press any key to continue..." << endl;
getch();

mainMenu();
MyFile.close();
return 0;

}
//------------------------------------------------------------------------------
void updateRecord()
{
 Student temp;
time_t t;
 char choice;
int position; 
float a;

position = displayRecord ();

MyFile.open( FILE_PATH, ios :: binary | ios :: out );
 MyFile.clear();

 if( position != -1 )
 {
 cout << endl << "Do you want to Update this Record( y or n )";
 choice = getch();
 }

 if( choice == 'y' )
 {
 cout << endl << "Enter name : ";
 cin >> temp.names;
  cout << endl << "Enter roll no : ";
 cin >> temp.roll_no;
 

 cout << endl << " Enter marks : ";
 cin >> temp.marks;
  
 a=(float)temp.marks/500*100;
 cout<<"percentage : "<<a;
 cout<< endl<<"Enter remarks : ";
 cin >>temp.remarks;




 MyFile.open( FILE_PATH, ios :: binary | ios :: out );
 MyFile.clear();
 MyFile.seekp( position * sizeof( Student ), ios :: beg );
 MyFile.clear();
MyFile.write( ( const char* ) &temp, sizeof( Student ) );
 MyFile.close();
 }
}


//------------------------------------------------------------------------------
void deleteRecord()
{

Student temp;
 char choice;
 int position;

 MyFile.open( FILE_PATH, ios :: binary | ios :: in | ios :: out );
 MyFile.clear();
 MyFile.seekp( position * sizeof( Student ), ios :: beg );
 MyFile.read( ( char* )&temp, sizeof( Student ) );

 cout << endl << endl;
 cout << "Would you like to delete this record? Yes (y) or No (n): ";
 cin >> choice;

choice = getch();

 MyFile.seekp( position * sizeof( Student ), ios :: beg );
 MyFile.write( ( const char* )&temp, sizeof( Student ) );

 getch();
 
mainMenu();
MyFile.close();
}

//-----------------------------------------------------------------------------

void printRecords()
{
Student temp;
float a;

 MyFile.open ( FILE_PATH , ios :: binary | ios :: in );
MyFile.clear();
MyFile.read ( ( char* ) &temp, sizeof ( Student ) );

while ( ! MyFile.eof() )
 {
cout << "Name: " << temp.names << endl <<"Roll No : "<<temp.roll_no <<endl
 << "marks:* " << temp.marks <<endl;
 
 a=(float)temp.marks/500*100;
 cout<<"percentage : "<<a;
  cout<<"\nRemarks:* "<< temp.remarks << endl;


 MyFile.read ( ( char* ) &temp, sizeof ( Student ) );
 }

 cout << endl << "Press any key to go back to main menu" << endl;
 getch();
 
 mainMenu();

MyFile.close();
}
//------------------------------------------------------------------------------
void createFile()
{
 if( ! MyFile )
 {
MyFile.close();
 MyFile.open(FILE_PATH, ios::binary | ios::in | ios::out);
 }

 if ( ! MyFile )
 {
cout << "File Error: File does not exist. Creating new file..."
 << endl << "Click to go  to main menu...";
getch();
 
 }
}
