#include<iostream>
#include<vector>
#include<string>
using namespace std;
/**https://www.hackerrank.com/contests/w9/challenges/sansa-and-xor*/
typedef unsigned int uint;
int main()
{int t,n;
cin>>t;
int *arr;
int *count_arr;
while(t--)
{
cin>>n;
arr=new int[n];
for(int i=0;i<n;i++)
cin>>arr[i];
int global_xor=0;
if(!(n%2))cout<<0<<endl;
else
{
for(int i=0;i<n;i+=2)
global_xor^=arr[i];

cout<<global_xor<<endl;
}}
return 0;
}
