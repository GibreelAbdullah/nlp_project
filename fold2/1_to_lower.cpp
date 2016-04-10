#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f1;
    f1.open("../data.txt");
    char ch;
    ofstream f2;
    f2.open("lower.txt");
    int flag=0;
    f1.get(ch);
    f2<<ch;
    while(!f1.eof())
    {
        f1.get(ch);
        if(ch>='A'&&ch<='Z')
            ch=ch-'A'+'a';
        if(ch=='n')
        {
            flag=1;
            continue;
        }
        if(flag==1)
        {
            if(ch=='\'')
            {
                flag=2;
                continue;
            }
            else
            {
                f2<<'n';
                flag=0;
            }
        }
        if(flag==2 && ch=='t')
        {
            f2<<" not";
            flag=0;
            continue;
        }
        if(!(ch==' '||ch=='\n'||(ch>='a'&&ch<='z')))
                continue;
        if(ch=='\n')
        {
            f2<<ch;
            f1.get(ch);
            f2<<ch;
            continue;
        }
        f2<<ch;
    }
    return 0;
}
