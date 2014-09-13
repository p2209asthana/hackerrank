#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
int main() {
int t;
string str;
cin>>t;
while(t--)
{
cin>>str;
char curr=str[0];
unsigned long long int count=0;
for(int i=1;i<str.size();i++)
{
if(str[i]==curr)count++;
else curr=str[i];
}

cout<<count<<endl;
}
    


return 0;
}

