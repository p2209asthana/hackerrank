#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> a(n);
    vector<int> cnt(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int j=0;
        while(j<32){
            cnt[i] += (a[i]&(1<<j))>>j;
            j++;
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        res= res^cnt[i];
    }

    if(res){
        cout<<"Shaka :)"<<endl;
    }
    else{
        cout<<"The other player :("<<endl;
    }

    return 0;
}
