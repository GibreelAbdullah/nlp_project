#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	ifstream f1;
	ofstream f2,f3;
	string s;
	char s1[12]="0/test0.txt",s2[13]="0/train0.txt";
	f1.open("stop_removed.txt");
	int i=-1;
	int countpos=0,countneg=0;
	while(++i<10)
	{
		int start=i*30;
		int end=(i+1)*30;
		countpos=0;
		countneg=0;
		system ("i=0; while [ $i -lt 10 ]; do mkdir -p $i; i=`expr $i + 1`; done;");
		s1[6]=i+'0';
		s2[7]=i+'0';
		s1[0]=i+'0';
		s2[0]=i+'0';
		f2.open(s1);
		f3.open(s2);
		while(getline(f1,s))
		{
			if(s[0]=='+')
			{
				countpos++;
				if(countpos>start && countpos<=end)
					f2<<s<<endl;
				else
					f3<<s<<endl;
			}
			else
			{
				countneg++;
				if(countneg>start && countneg<=end)
					f2<<s<<endl;
				else
					f3<<s<<endl;
			}
		}
		f1.clear();
		f1.seekg(0);
		f2.close();
		f3.close();
	}
}