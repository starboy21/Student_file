/*  C++ Program to Read Write Student Details using File Handling  */

#include<iostream>
#include<fstream>
using namespace std;

// define a class to store student data
class student
{
   int roll;
   char name[30];
   float marks1, m2,m3,m4,m5;
public:
   student() { }
   void getData(); // get student data from user
   void displayData(); // display data
};

void student :: getData() {
   cout << "\nEnter Roll No. :: ";
   cin >> roll;
   cin.ignore(); // ignore the newline char inserted when you press enter
   cout << "\nEnter Name :: ";
   cin.getline(name, 30);
   cout << "\nEnter Marks in each subject:: ";
   cin >>marks1>>m2>>m3>>m4>>m5;
}

void student :: displayData() {
   cout << "\nRoll No. :: " << roll << endl;
   cout << "\nName :: " << name << endl;
   cout << "\nMarks :: " << "\n"<<marks1<<"\n"<<m2<<"\n"<<m3<<"\n"<<m4<<"\n"<<m5<< endl;
  float grade=(marks1+ m2+ m3+ m4+ m5)/5;
cout << "\ngrade :: " <<grade;



}

int main()
{
   student s[3]; // array of 3 student objects
   fstream file;
   int i;

   file.open("C:\\Users\\Documents\\file4.txt", ios :: out); // open file for writing
    cout << "\nWriting Student information to the file :- " << endl;
    cout << "\nEnter 3 students Details to the File :- " << endl;

   for (i = 0; i < 3; i++)
    {
      s[i].getData();
      // write the object to a file
      file.write((char *)&s[i], sizeof(s[i]));
    }

   file.close(); // close the file

   file.open("C:\\Users\\Documents\\file4.txt", ios :: in); // open file for reading
   cout << "\nReading Student information to the file :- " << endl;

   for (i = 0; i < 3; i++)
    {
      // read an object from a file
      file.read((char *)&s[i], sizeof(s[i]));
      s[i].displayData();
    }

   file.close(); // close the file

   return 0;
  }