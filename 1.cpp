//PROGRAM TO SEPERATE NEGATIVE AND POSITIVE REVIEWS
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f1;
    f1.open("data.txt");
    ofstream f2;
    f2.open("pos.txt");
    ofstream f3;
    f3.open("neg.txt");
    string s;
    while(getline(f1,s))
    {
        if(s[0]=='p')
            f2<<s<<endl;
        else
            f3<<s<<endl;
    }
    return 0;
}
