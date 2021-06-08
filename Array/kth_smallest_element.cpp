#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    int n, k; cin>>n>>k;
    int x;

    map<int, int> m;
    for(int i=0;i<n;i++) {
        cin>>x;
        m[x]++;
    }

    int ans;

    for(auto it: m) {
        if(it.second>=k) {
            ans = it.first;
            break;
        }
        else {
            k-=it.second;
        }
    }

    cout<<ans<<"\n";

    return 0;
}