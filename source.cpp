/* File Contain:  Lecture 22-11-2021 (Video File)
                  Gaddid Book Chapter 12
    - Text Filing
        - Data is Stored in the form of ASCII in text filing.
        - for example:  int num = 12345;
        - Text file containing above int variable will occupy 5 bytes in the memory bcz digits are 5 and vice versa.
        - Each byte contain ASCII of respective digit.
        - Extention used for text files is ".txt"


    - Binary Filing
        - Data will be stored according to datatype used.
        - for example: int num = 0; or int num = 12345656;
        - in above examples binary file will occupy 4 bytes in the memory.
        - Binary file is just like storing the data in the disk.
        - Extention used for binary files is ".dat"  can be ".txt" and ".bin" also.

        - Whenever multi-byte data is written in a binary file it will write the least significant byte first in the file

        Representation in file:
            Little Endian System:

            01000110        Least Significant byte first
            00000000
            00000000
            00000000        Most Significant byte at the end.


            Big Endian System: (Data will be stored as it is)

            00000000        Most Significant byte at the start.
            00000000
            00000000
            01000110        Least Significant byte at the end.
*/

/*#include <iostream>
#include <fstream>
#include "Point.h"
#include "Point.cpp"
using namespace std;

int main()*/
//{
// Writting in a Binary File
// ofstream fout("output.dat", ios::binary); // syntax for binary file , second parameter to specify it as binary file.
// if (!fout)
// {
//     cout << "ERROR Creating the File!!" << endl;
// }
// else
// {
// Stream insertion and extraction operator will not be used with binary files but we use some special functions

/*// char ch = 'd';
// fout.put(ch); //[.put() function to write in a binary file]

char arr[5] = {'A', 'B', 'C', 'D', 'E'};

// for (int i = 0; i < 5; i++)
// {
//     fout.put(arr[i]);
// }

// Writtng an Array in a binary file can be done by write() function without using loop as,
// Write and Read Functions recieves only char pointers in first argument.
fout.write(arr, sizeof(arr)); // Two arguments 1st is array name and 2nd is array size.

fout.close();*/

// Writting Integer Data.

// int val = 70;
// fout.write(reinterpret_cast<char *>(&val), sizeof(val));
// reinterpret_cast will change the first byte address of int to char* (i.e Variable to Pointer Conversion)
// Because Write and Read Functions recieves only char pointers in first argument.
//- Whenever multi-byte data is written in a binary file it will write the least significant byte first in the file/
// Actually in memory of int    00000000 00000000 00000000 01000110
/*
 Representation in file:
    Little Endian System:

    01000110        Least Significant byte first
    00000000
    00000000
    00000000        Most Significant byte at the end.


    Big Endian System: (Data will be stored as it is)

    00000000        Most Significant byte at the start.
    00000000
    00000000
    01000110        Least Significant byte at the end.


*/

// Writting an Integer array

// int marks[3] = {97, 65, 90};
// fout.write(reinterpret_cast<char *>(marks), sizeof(marks));

// fout.close();

// Writting an Array of Points From Point Class.

// Point pts[5] = {{97, 98}, {99, 100}, {101, 102}, {103, 104}, {105, 106}};
// fout.write(reinterpret_cast<char *>(pts), sizeof(pts)); // Each Point has size 8 so 8 * 5 = 40 Byte File.
// fout.close();

// Writting a Part of Array into file.

// int arr[100] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106};
// int currSize = 5;
// fout.write(reinterpret_cast<char *>(arr), currSize * sizeof(int));

// From Index # 2 to 5
// fout.write(reinterpret_cast<char *>(&arr[2]), 4 * sizeof(int));

// fout.close();

// Writting a Dynmically Allocated Array

// const int N = 5;
// int *arr = new int[N];
// // cout << sizeof(arr); // arr is a pointer which is always of size 4
// fout.write(reinterpret_cast<char *>(arr), 4 * sizeof(int) * N);
// fout.close();
//}

// Reading from a Binary File.

// ifstream fin;
// fin.open("output.dat", ios::binary);
// if (!fin)
// {
//     cout << "ERROR Opening the file!!" << endl;
// }
// else
// {
/*// char temp;
// fin.get(temp); // [.get() function to read from a binary file]
char chrs[5];
// for (int i = 0; i < 5; i++)
// {
//     fin.get(chrs[i]);
// }
// Similarly Reading an Array in a binary file can be done by Read() function without using loop as,
fin.read(chrs, sizeof(chrs));
fin.close();
cout << "DATA frrom the file: ";
// cout << temp;
for (int i = 0; i < 5; i++)
{
    cout << chrs[i] << " ";
}*/

// Reading Integer Data

// int num;
// fin.read(reinterpret_cast<char *>(&num), sizeof(num));
// reinterpret_cast will change the first byte address of int to char*  (i.e Variable to Pointer Conversion)
// Because Write and Read Functions recieves only char pointers in first argument.
// fin.close();
// cout << "Number Readed from the file is: " << num << endl;

// Reading an Array of Integer

// int temp[3];
// fin.read(reinterpret_cast<char *>(temp), sizeof(temp));
// fin.close();

// for (int i = 0; i < 3; i++)
// {
//     cout << temp[i] << " ";
// }

// Reading an Array of Points From Point Class.

// Point points[5];
// fin.read(reinterpret_cast<char *>(points), sizeof(points));
// fin.close();
// for (int i = 0; i < 5; i++)
// {
//     points[i].displayPoint();
// }

// Reading a part of Array from a file

//         int temp[4];
//         fin.read(reinterpret_cast<char *>(temp), sizeof(temp));
//         fin.close();

//         for (int i = 0; i < 4; i++)
//         {
//             cout << temp[i] << " ";
//         }
//     }
//     return 0;
// }