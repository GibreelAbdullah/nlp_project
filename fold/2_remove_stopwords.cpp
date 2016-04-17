#include <iostream>
#include <fstream>
#include <vector>
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
        if(match==0)
        {
                int stoplen=stop.size();
                if(stoplen>1 && stop[stoplen-1]=='s')
                {
                    if(stop[stoplen-2]!='s')
                        stop.resize(stoplen-1);
                }
                else if(stoplen==1 && !(stop=="*" || stop=="+" || stop=="-"))
                {
                    if(stop=="u")
                    {
                        stop.resize(3);
                        stop="you";
                    }
                    else
                        continue;
                }
                else if(stoplen>2 && stop[stoplen-1]=='d' && stop[stoplen-2]=='e')
                {
                        stop.resize(stoplen-2);
                }
                else if(stoplen>2 && stop[stoplen-1]=='y' && stop[stoplen-2]=='l')
                {
                    stop.resize(stoplen-2);
                }
                else if(stoplen>2 && stop[stoplen-1]=='r' && stop[stoplen-2]=='e')
                {
                    stop.resize(stoplen-2);
                }
                if(stoplen>3)
                {
                    if(stop[stoplen-1]=='g' && stop[stoplen-2]=='n' && stop[stoplen-3]=='i')
                    {
                        if(!(stoplen>5 && stop[stoplen-4]=='h' && stop[stoplen-5]=='t'))
                        {
                            stop.resize(stoplen-3);
                        }
                    }
                }
            f3<<stop<<" ";
        }

    }
    return 0;
}

