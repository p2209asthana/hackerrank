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
#include<string>
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;

int main()
{

int t;
cin>>t;
int n;
for(int k=0;k<t;k++)
{
string w;
cin>>w;
int pos=w.size()-1;
for(int i=w.size()-2;i>=0;i--)
{
    if(w[i]<w[pos])break;
    else pos--;
}
if(pos>0)
{
    int pos1;
    for(pos1=w.size()-1;pos1>=pos;pos1--)
    if(w[pos1]>w[pos-1])break;

    w[pos1]^=w[pos-1]^=w[pos1]^=w[pos-1];


    for(int i=0;i<pos;i++)cout<<w[i];
    for(int i=w.size()-1;i>=pos;i--)cout<<w[i];
    cout<<endl;
}
else
cout<<"no answer"<<endl;
}


return 0;
}
