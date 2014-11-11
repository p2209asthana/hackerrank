#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin>>t;
    while(t--){
        string b,w;
        vector<int> brok(256,0);
        vector<int> isc(256,0);
        cin>>b>>w;

        for(int i=0;i<b.length();i++){
            brok[b[i]]++;
        }
        int count=0;
        for(int i=0;i<w.length();i++){
            if(brok[w[i]]&&isc[w[i]]==0){
                count++;
                isc[w[i]]++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
