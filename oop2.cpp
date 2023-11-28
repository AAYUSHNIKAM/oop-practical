/*
Experiment Number 2 : Develop a program in C++ to create a database of
student’s information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no. and other. Construct
the database with
suitable member functions. Make use of constructor, default constructor,
copy constructor,
destructor, static member functions, friend class, this pointer, inline
code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/



#include<iostream>
#include<string.h>
using namespace std;

class StudData;

class Student{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;jspm@jspm-Vostro-3470:~$ c++ oops2.cpp
jspm@jspm-Vostro-3470:~$ ./a.out
Enter Student Name : 	AAYUSH      
Enter Roll Number : 37
Enter Class : SE
Enter Division : A
Enter Date of Birth : 19/02/2005
Enter Blood Group : B positive
Enter Contact Address : Enter Telephone Number : 12345
Enter Driving License Number : 1234
Do you want to add another student (y/n) : n
---------------------------------------------------------------
Student Name : 	AAYUSH
Roll Number : 37
Class : SE
Division : A
Date of Birth : 19/02/2005
Blood Group : B
Contact Address : positive
Telephone Number : 12345
Driving License Number : 1234
---------------------------------------------------------------
Total Students : 1
---------------------------------------------------------------
jspm@jspm-Vostro-3470:~$ 


    static int count;

    public:

    Student()          // Default Constructor
    {
        name="";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/mm/yyyy";
        bloodgroup=new char[4];
    }

    ~Student()
    {
        delete division;
        delete[] bloodgroup;
    }

    static int getCount()
    {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData{
    string caddress;
    long int* telno;
    long int* dlno;
    friend class Student;

    public:

    StudData()
    {
        caddress="";
        telno=new long;
        dlno=new long;
    }
    
    ~StudData()
    {
        delete telno;
        delete dlno;
    }

    void getStudData()
    {
        cout<<"Enter Contact Address : ";
        cin.get();
        getline(cin,caddress);
        cout<<"Enter Telephone Number : ";
        cin>>*telno;
        cout<<"Enter Driving License Number : ";
        cin>>*dlno;
    }

    void dispStudData()
    {
        cout<<"Contact Address : "<<caddress<<endl;
        cout<<"Telephone Number : "<<*telno<<endl;
        cout<<"Driving License Number : "<<*dlno<<endl;
    }
};

inline void Student::getData(StudData* st)
{
    cout<<"Enter Student Name : ";
    getline(cin,name);
    cout<<"Enter Roll Number : ";
    cin>>roll_no;
    cout<<"Enter Class : ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter Division : ";
    cin>>division;
    cout<<"Enter Date of Birth : ";
    cin.get();
    getline(cin,dob);
    cout<<"Enter Blood Group : ";
    cin>>bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1)
{
    cout<<"Student Name : "<<name<<endl;
    cout<<"Roll Number : "<<roll_no<<endl;
    cout<<"Class : "<<cls<<endl;
    cout<<"Division : "<<division<<endl;
    cout<<"Date of Birth : "<<dob<<endl;
    cout<<"Blood Group : "<<bloodgroup<<endl;
    st1->dispStudData();
}jspm@jspm-Vostro-3470:~$ c++ oops2.cpp
jspm@jspm-Vostro-3470:~$ ./a.out
Enter Student Name : 	AAYUSH      
Enter Roll Number : 37
Enter Class : SE
Enter Division : A
Enter Date of Birth : 19/02/2005
Enter Blood Group : B positive
Enter Contact Address : Enter Telephone Number : 12345
Enter Driving License Number : 1234
Do you want to add another student (y/n) : n
---------------------------------------------------------------
Student Name : 	AAYUSH
Roll Number : 37
Class : SE
Division : A
Date of Birth : 19/02/2005
Blood Group : B
Contact Address : positive
Telephone Number : 12345
Driving License Number : 1234
---------------------------------------------------------------
Total Students : 1
---------------------------------------------------------------
jspm@jspm-Vostro-3470:~$ 



int Student::count;

int main()
{
    Student* stud1[100];
    StudData* stud2[100];
    int n=0;
    char ch;

    do
    {
        stud1[n]=new Student;
        stud2[n]=new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout<<"Do you want to add another student (y/n) : ";
        cin>>ch;
        cin.get();
    } while (ch=='y' || ch=='Y');

    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------------------------"<<endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Total Students : "<<Student::getCount();
    cout<<endl<<"---------------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
    

    return 0;
}

OUTPUT:
jspm@jspm-Vostro-3470:~$ c++ oops2.cpp
jspm@jspm-Vostro-3470:~$ ./a.out
Enter Student Name : 	AAYUSH NIKAM
Enter Roll Number : 37
Enter Class : SE
Enter Division : A
Enter Date of Birth : 19/02/2005
Enter Blood Group : B positive
Enter Contact Address : Enter Telephone Number : 12345
Enter Driving License Number : 1234
Do you want to add another student (y/n) : n
---------------------------------------------------------------
Student Name : 	AAYUSH
Roll Number : 37
Class : SE
Division : A
Date of Birth : 19/02/2005
Blood Group : B
Contact Address : positive
Telephone Number : 12345
Driving License Number : 1234
---------------------------------------------------------------
Total Students : 1
---------------------------------------------------------------
jspm@jspm-Vostro-3470:~$ 

