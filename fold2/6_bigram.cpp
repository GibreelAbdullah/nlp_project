#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef map<string, int>::iterator it_type;
    ifstream f1;
    char s1[24]="0/pos_train0.txt";
    char s2[29]="0/pos_vocabulary0_bigram.txt";
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
        string s1,s2,s3,s4;
        vector <string> s;
        map <string,int> vocab;
        int match,length=s.size();
        stringstream ss;
        while(getline(f1,s1,'\n'))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s2,' ');
            do
            {
                getline(ss,s3,' ');
                if(s3==" " || s3=="\0")
                    continue;
                int s3len=s3.size();
                s4=s2+","+s3;
                s2=s3;
                vocab[s4]++;
            }while(s3!="</stop>");
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
    strcpy(s2,"0/neg_vocabulary0_bigram.txt");
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
        string s1,s2,s3,s4;
        vector <string> s;
        map <string,int> vocab;
        int match,length=s.size();
        stringstream ss;
        while(getline(f1,s1,'\n'))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s2,' ');
            do
            {
                getline(ss,s3,' ');
                if(s3==" " || s3=="\0")
                    continue;
                int s3len=s3.size();
                s4=s2+","+s3;
                s2=s3;
                vocab[s4]++;
            }while(s3!="</stop>");
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
    strcpy(s2,"0/vocabulary0_bigram.txt");
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
        string s1,s2,s3,s4;
        vector <string> s;
        map <string,int> vocab;
        int match,length=s.size();
        stringstream ss;
        while(getline(f1,s1,'\n'))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s2,' ');
            do
            {
                getline(ss,s3,' ');
                if(s3==" " || s3=="\0")
                    continue;
                s4=s2+","+s3;
                s2=s3;
                vocab[s4]++;
            }while(s3!="</stop>");
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
