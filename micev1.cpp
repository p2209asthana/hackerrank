#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main() {
    int t;cin>>t;
    while(t--)
        {
        ll n,m;cin>>n>>m;
        vector<ll> mice(n);
        vector<ll> holes(m);
        for(int i=0;i<n;i++){
            cin>>mice[i];
        }
        for(int i=0;i<m;i++){
            cin>>holes[i];
        }
        sort(mice.begin(),mice.end());
        sort(holes.begin(),holes.end());

        ull diff=m-n;

        ll ans=0;
        ll k;
        if(n&1) k=n/2;
        else k =n/2-1;
        for(ll i=0;i<=k;i++){
            ans = max(max(abs(holes[i]-mice[i]),abs(holes[n-i-1]-mice[n-i-1])),ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
