#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
    ifstream f1,f2;
    f1.open("stopwords.txt");
    string stop,s1;
    vector <string> s;
    while(getline(f1,stop))
        s.push_back(stop);
    f2.open("lower.txt");
    ofstream f3;
    f3.open("stop_removed.txt");
    int match,length=s.size();
    while(getline(f2,stop,' '))
    {
        match=0;
        for(int i=0;i<length;i++)
        {
            if(stop==s[i])
            {
                match=1;
                break;
            }
        }
        if(match==0 && stop!="\n")
            f3<<stop<<" ";
    }

    return 0;
}

