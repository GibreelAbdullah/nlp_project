#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<iomanip>
#include<sstream>
using namespace std;
int main()
{
    typedef std::map<std::string, int>::iterator it_type;

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
            vocab[s2]++;
        ss.clear();
    }
    for(it_type iterator = vocab.begin(); iterator != vocab.end(); iterator++)
    {
        if(iterator->second>1&&iterator->first!="n"&&iterator->first!="p"&&iterator->first!="")
            f2<<left<<setw(15)<<iterator->first<<"\t"<<iterator->second<<endl;
    }
    return 0;
}
