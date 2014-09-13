#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
int n,k;
vector<bool> s;
cin>>n>>k;

char ch;
while(ch=getchar()){if(ch=='0' or ch=='1' )break;}
for(int i=0;i<n+k-1;i++)
{s.push_back(ch-'0');ch=getchar();}

vector<bool> z;
bool temp=0;
for(int i=0;i<=k-1;i++)
{z.push_back(temp^s[i]);  temp=s[i];}

for(int i=k;i<n;i++)
{temp^=z[i-k];z.push_back(temp^s[i]);temp=s[i];}


for(int i=0;i<z.size();i++)cout<<z[i];
return 0;
}
