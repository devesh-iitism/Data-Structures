#include<bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> arr(n, 0);

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Before: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    int l = 0, r = n-1;

    while(l<r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }

    cout<<"After: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}