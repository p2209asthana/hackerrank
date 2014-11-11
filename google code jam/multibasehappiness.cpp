#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
/**https://code.google.com/codejam/contest/188266/dashboard*/
using namespace std;
int factor[11][4]={{-1,-1,-1,-1},{0,0,0,0},{1,0,0,0},{0,1,0,0},{2,0,0,0},{0,0,1,0},{1,1,0,0},{0,0,0,1},{3,0,0,0},{0,2,0,0},{1,0,1,0}};

int add(int i ,int j,int base)
{



}

int represent(int i,int base)
{
vector<int>v;
while(i!=0)
{
v.push_back(i%base);
i=i/base;
}
int sum=0;
for(int i=v.size()-1;i>=0;i--)
sum=sum*10+v[i];

return sum;
}
bool check(int i , int base,int *sieve)
{
if(base==2)sieve[i]=1;
if(base==3)sieve[i]=i%2;

vector<int> v;
int rep=represent(i,base);
v.push_back
}

int find_lcm(vector<int>&arr)
{
double max_2=0,max_3=0,max_5=0,max_7=0;
for(int i=0;i<arr.size();i++)
{
if(factor[arr[i]][0]>max_2)max_2=factor[arr[i]][0];
if(factor[arr[i]][1]>max_3)max_3=factor[arr[i]][1];
if(factor[arr[i]][2]>max_5)max_5=factor[arr[i]][2];
if(factor[arr[i]][3]>max_7)max_7=factor[arr[i]][3];
}
return (int)(pow(2,max_2)*pow(3,max_3)*pow(5,max_5)*pow(7,max_7));
}

int main()
{

for(int i=1;i<=1260;i++)
{
int pos;
int lcm;
vector<int> arr;
cout<<"Case #:"<<i<<" ";
getline(cin,s);
while((pos=s.find(" "))!=string::npos)
{
arr.push_back(atoi(s.substr(0,pos).c_str()));
s=s.substr(pos+1);
}
arr.push_back(atoi(s.c_str()));

lcm=find_lcm(arr);

int* sieve=new int[lcm+1];
for(int i=0;i<=lcm;i++)sieve[i]=-1;
/*
if(find(arr.begin(),arr.end(),2)!=arr.end())for(int i=0;i<=lcm;i++)sieve[i]=true;//every number can be happy
if(find(arr.begin(),arr.end(),3)!=arr.end())for(int i=0;i<=lcm;i+2)sieve[i]=false;//even numbers cant be happy
*/
for(int i=lcm;i>=0;i--)
{bool flag;
for(int j=0;j<arr.size();j++)
{
    bool flag= check(i,arr[j],sieve);
    if(!flag){sieve[i]=0;break;}
}

}


}
return 0;
}
