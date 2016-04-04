#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iomanip>
#include<sstream>
using namespace std;
int main()
{
    typedef map<string, int>::iterator it_type;
    ifstream f1;
    f1.open("../step2/stop_removed.txt");
    ofstream f2;
    f2.open("vocabulary.txt");
    string s1,s2;
    vector <string> s;
    map <string,int> vocab;
    int match,length=s.size();
    stringstream ss;
    while(getline(f1,s1,'\n'))
    {
        ss<<s1;
        while(getline(ss,s2,' '))
        {
            int s2len=s2.size();
            if(s2len>1)
                if(s2[s2len-1]=='s')
                    if(s2[s2len-2]!='s')
                        s2.resize(s2len-1);

            if(s2len==1)
            {
                if(s2=="u")
                {
                    s2.resize(3);
                    s2="you";
                }
                else
                    continue;
            }
            if(s2len>2)
            {
                if(s2[s2len-1]=='d' && s2[s2len-2]=='e')
                {
                    s2.resize(s2len-2);
                }
            }
            if(s2len>2)
            {
                if(s2[s2len-1]=='y' && s2[s2len-2]=='l')
                {
                    s2.resize(s2len-2);
                }
            }
            if(s2len>2)
            {
                if(s2[s2len-1]=='r' && s2[s2len-2]=='e')
                {
                    s2.resize(s2len-2);
                }
            }
            if(s2len>3)
            {
                if(s2[s2len-1]=='g' && s2[s2len-2]=='n' && s2[s2len-3]=='i')
                {
                    if(!(s2len>5 && s2[s2len-4]=='h' && s2[s2len-5]=='t'))
                    {
                        s2.resize(s2len-3);
                    }
                }
            }
            vocab[s2]++;
        }
        ss.clear();
    }
    for(it_type iterator = vocab.begin(); iterator != vocab.end(); iterator++)
    {
        if(iterator->second>1&&iterator->first!="n"&&iterator->first!="p"&&iterator->first!="")
            f2<<left<<setw(15)<<iterator->first<<"\t"<<iterator->second<<endl;
    }
    return 0;
}
