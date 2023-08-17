/* File Contain:    Lecture 24-11-2021   (Video File)

    - TEXT FILE
        - Let say a text file has 1000 integer data
        - Size ????? Can't be specified bcz we dont know every integer value to that 1000 integers.
        - SEQUENTIAL Access.
        - For Example if one want to do to int 450 he has to go through all from the start. using a loop

    - BINARY FILE
        - Let say a text file has 1000 integer data
        - Size => 1000 * 4  = 4000 bytes
        - RANDOM ACCESS
        - FIXED LENGHT RECORD
        - For Example if one want to do to int 450 he has to go through all from the start.
        - we simply Go to byte 449 * sizeof(int);

        - Binary file has special markers

            - put marker/pointer (output mode) - While writting in the file.

                - tellp()   tells the position of current pointer in the file.
                - seekp()   moves the put marker to the desired position in the file.


            - get marker/pointer (input mode) - While reading from the file.

                - tellg()   tells the position of current pointer in the file.
                - seekg()   moves the get marker to the desired position in the file.

    // WARNINGS
    // Binary filing will not work if you struct or class has string variable or pointer variale i.e.
    // string name;
    // int *p;
    // Becaus these are not FIXED LENGTH RECORDS when put and get markers only work with fixed length records.

    // REWINDING a File
        // Open a file for writting and then close it.
        // Open it again for readinfg and close it.
        // This concept is called as Rewinding a file.



*/

#include <iostream>
#include <fstream>
#include "Point.h"
#include "Point.cpp"
using namespace std;

struct Student
{
    int rollNo;    // 4 bytes
    char name[41]; // 41 bytes
    // Student Struct must have 45 bytes size but it has 48 bytes size due to 3 bytes padding.
    // This Concept is called as Structure Alignment or Data Structure Alignment.

    // WARNINGS
    // Binary filing will not work if you struct or class has string variable or pointer variale i.e.
    // string name;
    // int *p;
    // Becaus these are not FIXED LENGTH RECORDS when put and get markers only work with fixed length records.
};

int main()
{
    const int N = 5;
    Student arr[N] = {{123, "abc"}, {456, "def"}, {789, "mnp"}, {}, {}};
    // cout << sizeof(Student); // It will display 48 instead 45.

    // Binary file : can be open using fstream but specifying it is writting or reading data. i.e. ios::out for writtng.

    fstream fout("Students.dat", ios::out | ios::binary); // Bit-wise OR Operator.

    if (!fout)
    {
        cout << "ERROR File was not Created!!" << endl;
    }
    else
    {

        fout.write(reinterpret_cast<char *>(arr), sizeof(arr));
        fout.close();
    }

    // Reading from the file.

    fstream fin("Students.dat", ios::in | ios::out | ios::binary); // ios:: in Opening in reading/input mode.
    if (!fin)
    {
        cout << "ERROR File wasn't opened!" << endl;
    }
    else
    {
        // Student st[5];
        // fin.read(reinterpret_cast<char *>(st), sizeof(st));
        // fin.close();

        // for (int i = 0; i < 5; i++)
        // {
        //     cout << st[i].rollNo << " " << st[i].name << endl;
        // }

        //-Binary file has special markers
        //- put marker / pointer(output mode)
        //- get marker / pointer(input mode)

        // Let say you have to write data of third Student Object

        // cout << fin.tellg() << endl; // tellg() will tell the current position of get marker i.e. 0

        // Finding the file size and Number of records.

        fin.seekg(0, ios::end); // Move the get marker to the end of file.
        int fileSize = fin.tellg();
        int numOfRecords = fileSize / sizeof(Student);
        cout << "Size of the file is: " << fileSize << endl;
        cout << "Number of Records in file are: " << numOfRecords << endl;

        // Student temp;
        // int count = 0;
        // while (count < 2)
        // {
        //     fin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
        //     count++;
        // }
        // This is very similar to text file bcz we gave to move from previous student objects for going to 3rd object.
        // After this loop ends get Marker will be at 3rd Student Objects so we can get it easily

        // if we directly want to start reading from 96 we use seekg() function.
        int n;
        cout << "Enter the Student number you want to read/Edit: ";
        cin >> n;
        while (n <= 0 || n > numOfRecords)
        {
            cout << "ERROR Invalid Student Number!!" << endl;
            cout << "Re-Enter Student Number: ";
            cin >> n;
        }
        fin.seekg(sizeof(Student) * (n - 1), ios::beg); // move bytes from the begining acc. to n
        cout << fin.tellg() << " " << fin.tellp() << endl;

        Student s;
        fin.read(reinterpret_cast<char *>(&s), sizeof(Student));
        fin.close();
        // cout << fin.tellg() << endl; // 144

        cout << "From File: " << endl;
        cout << s.rollNo << " " << s.name << endl;

        // Modifying the Data which is readed from the file.

        cout << "Enter the new roll no: ";
        cin >> s.rollNo;
        cin.ignore();
        cout << "Enter the new Student Name: ";
        cin.getline(s.name, 41);

        fin.seekp(sizeof(Student) * (n - 1), ios::beg);
        fin.write(reinterpret_cast<char *>(&s), sizeof(Student));
    }

    return 0;
}