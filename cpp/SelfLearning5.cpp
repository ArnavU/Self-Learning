#include <iostream>
#include <string>
using namespace std;

int myStrlen(string str)
{
    int count = 0;

    while(str[count] != '\0')
    {
        count++;
    }

    return count;
}

void myStrcpy(string &destination, string source)
{
    destination = "";

    int i = 0;

    while(source[i] != '\0')
    {
        destination = destination + source[i];
        i++;
    }
}

int main()
{
    string str1;
    string str2;

    cout << "Enter string : ";
    cin >> str1;

    cout << "Length = " << myStrlen(str1) << endl;

    myStrcpy(str2, str1);

    cout << "Copied string = " << str2 << endl;

    return 0;
}