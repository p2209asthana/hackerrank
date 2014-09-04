#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
/**https://www.hackerrank.com/contests/101aug14/challenges/pangrams*/
bool ispangram(map<char,bool> &m)
{
char ch1,ch2;
int t1,t2;
map<char,int>::iterator it1,it2;
for(int i=0;i<26;i++)
{
ch1=65+i;
ch2=97+i;
t1=m.count(ch1);
t2=m.count(ch2);
if((t1==0) && (t2==0))
    return false;
}


return true;
}
int main()
{
string s;
getline(cin,s);
map<char,bool> m;
for(int i=0;i<s.size();i++)m[s[i]]=true;

cout<<(ispangram(m)?"pangram":"not pangram");
return 0;
}
