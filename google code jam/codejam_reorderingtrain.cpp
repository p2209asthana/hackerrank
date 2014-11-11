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
#define vr vector
#define pb push_back
#define PRIME 1000000007
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define endl "\n"
#define fi(i,a,b) for(int i=a;i<b;i++)
#define feq(i,a,b) for(int i=a;i<=b;i++)
#define debug(v){for(int DNUTVIOL=0;DNUTVIOL<v.size();DNUTVIOL++)cout<<v[DNUTVIOL]<<" ";cout<<endl;}
using namespace std;
typedef unsigned long long int ull;
typedef long long int sll;

struct node
{
string s;
node*next;

};

bool check(vr<string>&arr)
{

    int EMPTY=0;
    int LEFT=1;
    int RIGHT=2;
    int MIDDLE=3;
    int BOTH_LR=4;
    vr<vr<int> >matrix;matrix.resize(26);
    fi(i,0,26)matrix[i].assign(arr.size(),EMPTY);
    fi(i,0,arr.size())
    {
        if(arr[i].size()==1){matrix[arr[i][0]-'a'][i]=BOTH_LR;}
        else
        {
            matrix[arr[i][0]-'a'][i]=LEFT;
            fi(j,1,arr[i].size())
            {
                char c=arr[i][j];
                if(matrix[c-'a'][i]!=EMPTY)return false;
                matrix[c-'a'][i]=MIDDLE;
            }
            matrix[arr[i][arr[i].size()-1]-'a'][i]=RIGHT;
        }

    //fi(g,0,4)debug(matrix[g]);cout<<endl;
    }
    //fi(g,0,4)debug(matrix[g]);cout<<endl;
    fi(i,0,26)
    {
        int mid_count=0;
        bool left_flag=false;
        bool right_flag=false;
        bool both_lr_flag=false;
        fi(j,0,arr.size())
        {
            if(matrix[i][j]==MIDDLE)mid_count++;
            else if(matrix[i][j]==LEFT){if(left_flag)return false;left_flag=true;}
            else if(matrix[i][j]==RIGHT){if(right_flag)return false;right_flag=true;}
            else if(matrix[i][j]==BOTH_LR)both_lr_flag=true;
            //cout<<"mid_count="<<mid_count<<" left_flag="<<left_flag<<" right_flag="<<right_flag<<" both_lr_flag="<<both_lr_flag<<endl;
            if((mid_count==2)or(left_flag and mid_count>0)or(right_flag and mid_count>0)or(both_lr_flag and mid_count>0))return false;

        }
    }

return true;
}
vr<vr<string> >transform(vr<string>&arr)
{
vr<string> arr1,arr2;
fi(i,0,arr.size())
{
    if(arr[i].size()>1)
    {
        string s;
        s.pb(arr[i][0]);
        s.pb(arr[i][arr[i].size()-1]);
        arr1.pb(s);
    }
    else
    {
        string s;s.pb(arr[i][0]);
        arr2.pb(s);
    }
}
vr<vr<string> > g;
g.pb(arr1);g.pb(arr2);
return g;
}
vr<string>trim(vr<string>&arr)
{
vr<string>arr1;arr1.resize(arr.size());
fi(i,0,arr.size())
{
arr1[i].pb(arr[i][0]);
fi(j,1,arr[i].size())
{
    if(arr[i][j]!=arr1[i][arr1[i].size()-1])
    {
        arr1[i].pb(arr[i][j]);
    }
}
}

return arr1;
}
int main()
{
//ios_base::sync_with_stdio(false);

vr<int>fact;fact.resize(101);fact[0]=1;
feq(i,1,100){ull temp=(ull)i*(ull)fact[i-1];temp%=PRIME;fact[i]=temp;}

int T;cin>>T;;
feq(t,1,T)
{
cout<<"Case #"<<t<<": ";
int n;cin>>n;
vr<string>arr;
fi(i,0,n){string temp;cin>>temp;arr.pb(temp);}
arr=trim(arr);
//debug(arr);
if(!check(arr)){cout<<0<<endl;continue;}
vr< vr<string> >arr1=transform(arr);

vr<string> &non_single=arr1[0];
vr<string> &single=arr1[1];

sort(single.begin(),single.end());
//debug(arr);
vr<int>taken;taken.assign(non_single.size(),-1);
vr<int>start;start.assign(26,-1);
vr<int>end;end.assign(26,-1);

fi(i,0,arr1[0].size())
{
start[non_single[i][0]-'a']=i;
end[non_single[i][1]-'a']=i;
}
bool good_data=false;
fi(i,0,26)
{
if(start[i]!=-1 and end[i]==-1){good_data=true;break;}
}

if(!good_data and non_single.size()>0){cout<<0<<endl;continue;}
//debug(start);
//debug(end);

vr<vr<string> >set;
while(1)
{
    int index=-1;
    fi(i,0,26)if(start[i]!=-1 and end[i]==-1 and taken[start[i]]==-1){index=start[i];taken[index]=set.size();break;}
    if(index==-1)break;
   // cout<<"index="<<index<<endl;
    vr<string> temp;temp.pb(non_single[index]);
    char c=non_single[index][non_single[index].size()-1];
    index=start[c-'a'];
    while(start[c-'a']!=-1 and taken[index]==-1)
    {
     //   cout<<"index="<<index<<endl;
        taken[index]=set.size();
        temp.pb(arr1[0][index]);
        c=non_single[index][non_single[index].size()-1];
        index=start[c-'a'];
    }
    set.pb(temp);
    //cout<<endl;
}
vr<int>single_count;single_count.assign(26,0);
fi(i,0,single.size())
{
single_count[single[i][0]-'a']++;
}

vr<vr<int> >set_factorial;
fi(i,0,set.size())
{
vr<int>temp;
set_factorial.pb(temp);
}


fi(i,0,single_count.size())
{
if(single_count[i]!=0)
{
    int set_no;
    if(start[i]==-1 and end[i]==-1){vr<int>temp;temp.pb(single_count[i]);set_factorial.pb(temp);continue;}
    else if(start[i]!=-1){set_no=taken[start[i]];}
    else set_no=taken[end[i]];

    set_factorial[set_no].pb(single_count[i]);
}
}
ull prod=1;

fi(i,0,set_factorial.size())
{
fi(j,0,set_factorial[i].size())
{
prod*=(ull)fact[set_factorial[i][j]];
prod%=PRIME;
}
}
prod*=(ull)fact[set_factorial.size()];
prod%=PRIME;
cout<<prod<<endl;
}

return 0;
}
