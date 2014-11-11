/**
Author: Prakhar Asthana
prakharast@gmail.com
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;


int main()
{
string s;
cin>>s;
string s1(s.length(),'a');
if(s==s1){s=s+"a";cout<<s<<endl;return 0;}
for(int i=1;i<s.size();i++)
{
string temp(i,'a');
if(s.find(temp)==string::npos){cout<<temp<<endl;return 0;}
}




return 0;
}
