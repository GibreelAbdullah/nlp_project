//PROGRAM TO SEPERATE NEGATIVE AND POSITIVE REVIEWS
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream f1;
    int i=-1;
    char s1[13]="0/train0.txt";
    char s2[17]="0/pos_train0.txt";
    char s3[17]="0/neg_train0.txt";
    while(++i<10)
    {
        s1[0]=i+'0';
        s1[7]=i+'0';
        s2[0]=i+'0';
        s2[11]=i+'0';
        s3[0]=i+'0';
        s3[11]=i+'0';
        cout<<s1<<"\t"<<s2<<"\t"<<s3<<"\n";
        f1.open(s1);
        ofstream f2;
        f2.open(s2);
        ofstream f3;
        f3.open(s3);
        string s;
        while(getline(f1,s))
        {
            if(s[0]=='+')
                f2<<s<<endl;
            else
                f3<<s<<endl;
        }
        f1.close();
        f2.close();
        f3.close();
    }
    return 0;

}
