
#include<bits/stdc++.h>
using namespace std;

class crim_rec
{
char name[20], standard[5], fathr_name[20], addrs[25], course[20], section[5], dob[9];
int  admin;
void disp();
public:
void get();
void wtf();
void rff();
void search();
void del();
void mod();
}c;
void crim_rec::get()
{
puts("\nEnter name of student");
cin>>name;
puts("\nEnter  class:");
cin>>standard;
puts("\nEnter  section:");
cin>>section;
puts("\nEnter admission number of student:");
cin>>admin;
puts("\nEnter date of birth:");
cin>>dob;
puts("\nEnter father's name:");
cin>>fathr_name;
puts("\nEnter address:");
cin>>addrs;
puts("\nEnter the course:");
cin>>course;

}
void crim_rec::disp()
{
cout<<"The record of student:\n";
cout<<"\nName of student: "<<name;
cout<<"\nClass: "<<standard;
cout<<"\nSection: "<<section;
cout<<"\nAdmission number: "<<admin;
cout<<"\nDOB: "<<dob;
cout<<"\nFather's name: "<<fathr_name;
cout<<"\nAddress: "<<addrs;
cout<<"\nCourse: "<<course;


}
void crim_rec::wtf()
{
ofstream ofile;
ofile.open("CBI", ios::app);
get();
ofile.write((char*)&c, sizeof(c));
ofile.close();
}
void crim_rec::rff()
{
ifstream ifile;
ifile.open("CBI");
ifile.seekg(0, ios::beg);
ifile.read((char*)&c, sizeof(c));
while(ifile)
{
disp();
ifile.read ((char*)&c, sizeof(c));
}
ifile.close();
}
void crim_rec::search()
{
char m[20];
ifstream ifile("CBI");
puts("Enter name of student which has to be searched");
gets(m);
ifile.seekg (0, ios::beg);
ifile.read((char*)&c, sizeof(c));
while(ifile)
{
if (strcmpi(m, name)==0)
disp();
ifile.read((char*)&c, sizeof(c));
}
ifile.close();
}
void crim_rec::del()
{
char b[20];
ifstream ifile;
ifile.open("CBI", ios::app);
ofstream ofile;
ofile.open("new", ios::app);
puts("Enter the name of the student whose records you want to delete");
gets(b);
ifile.seekg (0, ios::beg);
ifile.read((char*)&c, sizeof(c));
while(ifile)
{
if (strcmpi(b, name))
ofile.write((char*)&c, sizeof(c));
ifile.read((char*)&c, sizeof(c));
}
ifile.close();
ofile.close();
remove ("CBI");
rename("new", "CBI");
}
void crim_rec::mod()
{
char d[20];
int p;
puts("\nEnter name of student whose record you want to modify\n");
gets(d);
fstream f;
f.open("CBI", ios::in|ios::out);
f.seekg(0, ios::beg);
f.read((char*)&c, sizeof(c));
int a=f.tellg();
while(! f.eof())
{
if (!strcmpi(d, name))
{
puts("\nPress 1 to change name\nPress 2 to change class\nPress 3 to change section\nPress 4 to change admission numbern\n Press 5 to change DOB\nPress 6 to change father's name\nPress 7 to change address\nPress 8 to change course\n");
cin>>p;
switch(p)
{
case 1:
gets(name);
break;
case 2:
cin>>standard;
break;
case 3:
gets(section);
break;
case 4:
cin>>admin;
break;
case 5:
gets(dob);
break;
case 6:
gets(fathr_name);
break;
case 7:
gets(addrs);

break;
case 8:
cin>>course;
break;
}
f.seekg(a-sizeof(c), ios::beg);
f.write((char*)&c, sizeof(c));
}
f.read((char*)&c, sizeof(c));
a=f.tellg();
}
f.close();
}
int main ()
{
int ch;
char choice;
do
{
cout<<"\tVBPS STUDENT INFORMATION SYSTEM";
cout<<"\n ********************************************";
cout<<"\n\n *  1. View student details";
cout<<"\n\n *  2. Add new student details";
cout<<"\n\n *  3. Search a student record";
cout<<"\n\n *  4. Delete a student record";
cout<<"\n\n *  5. Modify a student record";
cout<<"\n ********************************************";
cout<<"\n\n Enter your choice:";
cin>>ch;
switch(ch)
{
case 1:

c.rff();
break;
case 2:
c.wtf();
break;
case 3:
c.search();
break;
case 4:
c.del();
break;
case 5:
c.mod();
break;
default:
{
cout<<"\nerror!";
}
break;
}
cout<<"\ncontinue? (y/n)\n";
cin>>choice;
}while(choice=='y');
cout<<"\nGood bye";
return 0;
}

