/**
Author: Prakhar Asthana
prakharast@gmail.com
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#define pb push_back
#define PRIME 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define endl "\n"
#define fi(i,a,b) for(int i=a;i<b;i++)
#define feq(i,a,b) for(int i=a;i<=b;i++)
#define debug(v) if(v.size()>0){for(int DontUseThisVaraibleInOuterLoop=0;DontUseThisVaraibleInOuterLoop<v.size();DontUseThisVaraibleInOuterLoop++)cout<<v[DontUseThisVaraibleInOuterLoop]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;

int check(vector<string>&arr)
{
vector<vector<vector<int> > >grand0;grand0.resize(arr.size());
vector<vector<vector<int> > >grand1;grand1.resize(arr.size());

fi(i,0,grand0.size())grand0[i].resize(26);
fi(i,0,grand0.size())grand1[i].resize(26);
int g_count;
{
int count=0;
int length=1;
char old_c=arr[0][0];
grand0[0][old_c-'a'].pb(0);
fi(i,1,arr[0].size())
{
if(arr[0][i]!=old_c)
    {
        grand1[0][old_c-'a'].pb(length);
        length=1;
        old_c=arr[0][i];count++;
        grand0[0][old_c-'a'].pb(count);
    }
else length++;
}
grand1[0][old_c-'a'].pb(length);
g_count=count;
//cout<<"gcount="<<g_count<<endl;
}
fi(j,1,arr.size())
{
  //  cout<<arr[j]<<endl;
    int count=0;
    int length=1;
    char old_c=arr[j][0];
    grand0[j][old_c-'a'].pb(0);
    fi(i,1,arr[j].size())
    {
    if(arr[j][i]!=old_c)
        {
            grand1[j][old_c-'a'].pb(length);
            length=1;
            old_c=arr[j][i];count++;
            grand0[j][old_c-'a'].pb(count);
        }
    else length++;
    }
    grand1[j][old_c-'a'].pb(length);
    fi(i,0,26)
    {
        if(grand0[j-1][i].size()!=grand0[j][i].size())return -1;
        fi(k,0,grand0[j-1][i].size())
        {
            if(grand0[j-1][i][k]!=grand0[j][i][k])return -1;
        }
    }
}
//fi(i,0,grand1.size())fi(j,0,grand1[i].size())debug(grand1[i][j]);
//fi(i,0,grand1.size())fi(j,0,grand1[i].size())debug(grand0[i][j]);
int total=0;
vector<vector<int> >count_arr;count_arr.resize(g_count+1);
fi(i,0,grand0.size())
{
    fi(j,0,grand0[i].size())
    {
        fi(k,0,grand0[i][j].size())
        {
            count_arr[grand0[i][j][k]].pb(grand1[i][j][k]);
        }

    }
}
//fi(i,0,count_arr.size())debug(count_arr[i]);
vector<int>median_arr;median_arr.resize(count_arr.size());
fi(i,0,count_arr.size())
{
    sort(count_arr[i].begin(),count_arr[i].end());
    median_arr[i]=count_arr[i][count_arr[i].size()/2];
}

fi(i,0,count_arr.size())
        fi(j,0,count_arr[i].size())
            count_arr[i][j]-=median_arr[i];

int sum=0;
fi(i,0,count_arr.size())
    fi(j,0,count_arr[i].size())
        sum+=abs(count_arr[i][j]);

return sum;
}

int main()
{
//ios_base::sync_with_stdio(false);
int T;
cin>>T;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n;cin>>n;
vector<string>arr;arr.resize(n);
fi(i,0,n)cin>>arr[i];

int ok=check(arr);
if(ok==-1)cout<<"Fegla Won"<<endl;
else cout<<ok<<endl;
}

return 0;
}
