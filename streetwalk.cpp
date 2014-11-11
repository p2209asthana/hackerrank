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
#define PRIME 1000000007
using namespace std;
typedef unsigned long long int ull;
typedef  long long int sll;

int calculate(vector<string>&arr,int **num_arr,int x,int y)
{
if(num_arr[x][y]==-1)
{
if(arr[x][y]=='x'){num_arr[x][y]=0;}
else
{
    int n1=0,n2=0;
    if((x+1)!=arr.size())
        n1=calculate(arr,num_arr,x+1,y);
    if((y+1)!=arr.size())
        n2=calculate(arr,num_arr,x,y+1);
    ull n3=n1+n2;
    n3%=PRIME;
    num_arr[x][y]=n3;
}


}
//cout<<num_arr[x][y]<<endl;
return num_arr[x][y];
}
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
vector<string>arr;
while(n--)
{
string temp;
cin>>temp;
arr.push_back(temp);
}
int ways=0;


int **num_arr=new int*[arr.size()];
for(int i=0;i<arr.size();i++)
num_arr[i]=new int[arr.size()];

for(int i=0;i<arr.size();i++)
for(int j=0;j<arr.size();j++)
num_arr[i][j]=-1;

num_arr[arr.size()-1][arr.size()-1]=1;

ways=calculate(arr,num_arr,0,0);
if(ways>0)cout<<ways<<endl;
else cout<<-1<<endl;
}
return 0;
}
