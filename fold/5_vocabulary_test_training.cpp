#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef map<string, int>::iterator it_type;
    ifstream f1;
    char s1[17]="0/pos_train0.txt";
    char s2[22]="0/pos_vocabulary0.txt";
    int i=-1;
    while(++i<10)
    {
        s1[0]=i+'0';
        s1[11]=i+'0';
        s2[0]=i+'0';
        s2[16]=i+'0';
        f1.open(s1);
        ofstream f2;
        f2.open(s2);
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
                if(s2len>1 && s2[s2len-1]=='s')
                {
                    if(s2[s2len-2]!='s')
                        s2.resize(s2len-1);
                }
                else if(s2len==1)
                {
                    if(s2=="u")
                    {
                        s2.resize(3);
                        s2="you";
                    }
                    else
                        continue;
                }
                else if(s2len>2 && s2[s2len-1]=='d' && s2[s2len-2]=='e')
                {
                        s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='y' && s2[s2len-2]=='l')
                {
                    s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='r' && s2[s2len-2]=='e')
                {
                    s2.resize(s2len-2);
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
            if(iterator->second>1 && iterator->first!="-"&&iterator->first!="+"&&iterator->first!="")
                f2<<left<<setw(15)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f1.close();
        f2.close();

    }

    strcpy(s1,"0/neg_train0.txt");
    strcpy(s2,"0/neg_vocabulary0.txt");
    i=-1;
    while(++i<10)
    {
        s1[0]=i+'0';
        s1[11]=i+'0';
        s2[0]=i+'0';
        s2[16]=i+'0';
        f1.open(s1);
        ofstream f2;
        f2.open(s2);
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
                if(s2len>1 && s2[s2len-1]=='s')
                {
                    if(s2[s2len-2]!='s')
                        s2.resize(s2len-1);
                }
                else if(s2len==1)
                {
                    if(s2=="u")
                    {
                        s2.resize(3);
                        s2="you";
                    }
                    else
                        continue;
                }
                else if(s2len>2 && s2[s2len-1]=='d' && s2[s2len-2]=='e')
                {
                        s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='y' && s2[s2len-2]=='l')
                {
                    s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='r' && s2[s2len-2]=='e')
                {
                    s2.resize(s2len-2);
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
            if(iterator->second>1 && iterator->first!="-"&&iterator->first!="+"&&iterator->first!="")
                f2<<left<<setw(15)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f1.close();
        f2.close();

    }
    strcpy(s1,"0/train0.txt");
    strcpy(s2,"0/vocabulary0.txt");
    i=-1;
    while(++i<10)
    {
        s1[0]=i+'0';
        s1[7]=i+'0';
        s2[0]=i+'0';
        s2[12]=i+'0';
        f1.open(s1);
        ofstream f2;
        f2.open(s2);
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
                if(s2len>1 && s2[s2len-1]=='s')
                {
                    if(s2[s2len-2]!='s')
                        s2.resize(s2len-1);
                }
                else if(s2len==1)
                {
                    if(s2=="u")
                    {
                        s2.resize(3);
                        s2="you";
                    }
                    else
                        continue;
                }
                else if(s2len>2 && s2[s2len-1]=='d' && s2[s2len-2]=='e')
                {
                        s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='y' && s2[s2len-2]=='l')
                {
                    s2.resize(s2len-2);
                }
                else if(s2len>2 && s2[s2len-1]=='r' && s2[s2len-2]=='e')
                {
                    s2.resize(s2len-2);
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
            if(iterator->second>1 && iterator->first!="-"&&iterator->first!="+"&&iterator->first!="")
                f2<<left<<setw(15)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f1.close();
        f2.close();

    }
    return 0;
}
