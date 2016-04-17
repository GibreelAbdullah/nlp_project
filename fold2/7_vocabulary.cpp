#include<bits/stdc++.h>
using namespace std;
int main()
{
    typedef map<string, int>::iterator it_type;
    ifstream f2;
    ifstream f3;
    ofstream f4;
    ofstream f5;
    char c2[30]="0/pos_vocabulary0_unigram.txt";
    char c3[30]="0/pos_vocabulary0_bigram.txt";
    char c4[30]="0/uni_pos_vocabulary0.txt";
    char c5[30]="0/bi_pos_vocabulary0.txt";
    int i=-1;
    map <string,int> vocab;
    while(++i<10)
    {
        c2[0]=i+'0';
        c2[16]=i+'0';
        c3[0]=i+'0';
        c3[16]=i+'0';
        c4[0]=i+'0';
        c4[20]=i+'0';
        c5[0]=i+'0';
        c5[19]=i+'0';
        f2.open(c2);
        f3.open(c3);
        f4.open(c4);
        f5.open(c5);        
        stringstream ss;
        string s1,s2,s3;
        while(getline(f2,s1))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s3,'\n');
            while(s3==" " || s3=="\0" || s3=="\n")
                getline(ss,s3,' ');
            vocab[s2]=atoi(s3.c_str());
            ss.clear();
        }
        char ch;
        string s4;
        while(getline(f3,s1))
        {
            ss<<s1;
            getline(ss,s2,',');
            getline(ss,s3,' ');
            getline(ss,s4,'\n');
            while(s4==" " || s4=="\0" || s4=="\n")
                getline(ss,s4,' ');
            vocab[s2]-=atoi(s4.c_str());
            vocab[s2+","+s3]=atoi(s4.c_str());
            ss.clear();
        }
        for(it_type iterator = vocab.begin(); iterator != vocab.end(); iterator++)
        {
            if(iterator->first!="-"&&iterator->first!="+"&&iterator->first!=""&&iterator->first!="*"&&iterator->second>1)
                if(iterator->first.find(",")!= std::string::npos)
                    f5<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
                else
                    f4<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f2.close();
        f3.close();
        f4.close();
        f5.close();
    }

    strcpy(c2,"0/neg_vocabulary0_unigram.txt");
    strcpy(c3,"0/neg_vocabulary0_bigram.txt");
    strcpy(c4,"0/uni_neg_vocabulary0.txt");
    strcpy(c5,"0/bi_neg_vocabulary0.txt");
    i=-1;
    map <string,int> vocab1;
    while(++i<10)
    {
        c2[0]=i+'0';
        c2[16]=i+'0';
        c3[0]=i+'0';
        c3[16]=i+'0';
        c4[0]=i+'0';
        c4[20]=i+'0';
        c5[0]=i+'0';
        c5[19]=i+'0';
        f2.open(c2);
        f3.open(c3);
        f4.open(c4);
        f5.open(c5);        
        stringstream ss;
        string s1,s2,s3;
        while(getline(f2,s1))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s3,'\n');
            while(s3==" " || s3=="\0" || s3=="\n")
                getline(ss,s3,' ');
            vocab1[s2]=atoi(s3.c_str());
            ss.clear();
        }
        char ch;
        string s4;
        while(getline(f3,s1))
        {
            ss<<s1;
            getline(ss,s2,',');
            getline(ss,s3,' ');
            getline(ss,s4,'\n');
            while(s4==" " || s4=="\0" || s4=="\n")
                getline(ss,s4,' ');
            vocab1[s2]-=atoi(s4.c_str());
            vocab1[s2+","+s3]=atoi(s4.c_str());
            ss.clear();
        }
        for(it_type iterator = vocab1.begin(); iterator != vocab1.end(); iterator++)
        {
            if(iterator->first!="-"&&iterator->first!="+"&&iterator->first!=""&&iterator->first!="*"&&iterator->second>1)
                if(iterator->first.find(",")!= std::string::npos)
                    f5<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
                else
                    f4<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f2.close();
        f3.close();
        f4.close();
        f5.close();
    }
    strcpy(c2,"0/vocabulary0_unigram.txt");
    strcpy(c3,"0/vocabulary0_bigram.txt");
    strcpy(c4,"0/uni_vocabulary0.txt");
    strcpy(c5,"0/bi_vocabulary0.txt");
    i=-1;
    map <string,int> vocab2;
    while(++i<10)
    {
        c2[0]=i+'0';
        c2[12]=i+'0';
        c3[0]=i+'0';
        c3[12]=i+'0';
        c4[0]=i+'0';
        c4[16]=i+'0';
        c5[0]=i+'0';
        c5[15]=i+'0';
        f2.open(c2);
        f3.open(c3);
        f4.open(c4);
        f5.open(c5);        
        stringstream ss;
        string s1,s2,s3;
        while(getline(f2,s1))
        {
            ss<<s1;
            getline(ss,s2,' ');
            getline(ss,s3,'\n');
            while(s3==" " || s3=="\0" || s3=="\n")
                getline(ss,s3,' ');
            vocab2[s2]=atoi(s3.c_str());
            ss.clear();
        }
        char ch;
        string s4;
        while(getline(f3,s1))
        {
            ss<<s1;
            getline(ss,s2,',');
            getline(ss,s3,' ');
            getline(ss,s4,'\n');
            while(s4==" " || s4=="\0" || s4=="\n")
                getline(ss,s4,' ');
            vocab2[s2]-=atoi(s4.c_str());
            vocab2[s2+","+s3]=atoi(s4.c_str());
            ss.clear();
        }
        for(it_type iterator = vocab2.begin(); iterator != vocab2.end(); iterator++)
        {
            if(iterator->first!="-"&&iterator->first!="+"&&iterator->first!=""&&iterator->first!="*"&&iterator->second>1)
                if(iterator->first.find(",")!= std::string::npos)
                    f5<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
                else
                    f4<<left<<setw(31)<<iterator->first<<" "<<iterator->second<<endl;
        }
        f2.close();
        f3.close();
        f4.close();
        f5.close();
    }
    
    return 0;
}
