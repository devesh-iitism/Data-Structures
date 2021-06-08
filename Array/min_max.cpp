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

    int minimum = arr[0];
    int maximum = arr[0];

    for(int i=1;i<n;i++) {
        if(arr[i]>maximum)
            maximum = arr[i];
        else if(arr[i]<minimum)
            minimum = arr[i];
    }

    cout<<"Minimum: "<<minimum
        <<"\nMaximum: "<<maximum<<"\n";

    return 0;
}