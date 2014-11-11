#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int t;cin>>t;
    while(t--){
        ll x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        ll ans = min(min(abs(x-x1),abs(y-y1)),min(abs(x-x2),abs(y-y2)));
        cout<<ans<<endl;
    }
    return 0;
}
