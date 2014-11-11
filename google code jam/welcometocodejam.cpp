#include<iostream>
/**https://code.google.com/codejam/contest/90101/dashboard#s=p2*/
using namespace std;

int rec=0;
int find(string &needle, string &haystack)
{
//cout<<"needle="<<needle<<" haystack="<<haystack<<endl;
int val=0;
if((needle.size()>haystack.size())or (haystack.size()==0)or (needle.size()==0) ){val=0;}
else
{
    int i=haystack.find(needle[0]);
    if(i==string::npos)val=0;
    else
    {
        //cout<<"i="<<i<<endl;
        if(needle.size()==1)val=1;
        else
        {
            string haystack1=haystack.substr(i+1);
            val=find(needle,haystack1);
            string needle1=needle.substr(1);
            val+=find(needle1,haystack1);
        }
    }
}
val=val%10000;
//cout<<"return= "<<val<<endl;
return val;
}





int main()
{
int n;
cin>>n;
cin.ignore();
string s;
string p="welcome to code jam";
while(n--)
{
getline(cin,s);
int t=find(p,s);
cout<<t;
}


}
