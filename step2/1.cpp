#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f1;
    f1.open("../data.txt");
    char ch;
    ofstream f2;
    f2.open("lower.txt");
    while(!f1.eof())
    {
        f1.get(ch);
        if(ch>='A'&&ch<='Z')
            ch=ch-'A'+'a';
        if(!(ch==' '||ch=='\n'||(ch>='a'&&ch<='z')))
                continue;
        f2<<ch;
    }
    return 0;
}
