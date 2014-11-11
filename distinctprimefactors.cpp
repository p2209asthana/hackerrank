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

struct node
{
int n;
bool prime;
int count;
};

vector<node>sieve;


void get_sieve()
{
    for(int i=0;i<sieve.size();i++)
    {
        if(sieve[i].prime)
        {
            int num=sieve[i].n;
            sieve[i].count++;
            for(int j= i+num;j<sieve.size();j+=num)
            {
                sieve[j].prime=false;sieve[j].count++;
            }
        }
    }
}
int main()
{
for(int i=2;i<=1000000;i++){node temp;temp.n=i;temp.prime=true;temp.count=0;sieve.push_back(temp);}
get_sieve();
int t;
cin>>t;
while(t--)
{
    int num;
    cin>>num;
    cout<<sieve[num-2].count<<endl;


}

return 0;
}
