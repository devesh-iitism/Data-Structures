#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor) {
    if(image[r][c] == color) {
        image[r][c] = newColor;
        if (r >= 1) 
            dfs(image, r-1, c, color, newColor);
        if (c >= 1) 
            dfs(image, r, c-1, color, newColor);
        if (r+1 < image.size()) 
            dfs(image, r+1, c, color, newColor);
        if (c+1 < image[0].size()) 
            dfs(image, r, c+1, color, newColor);
    }    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int color = image[sr][sc];
    if(color!=newColor)
        dfs(image, sr, sc, color, newColor);
    return image;
}

int main()
{
    cout<<"Enter dimensions: ";
    int m, n, x;
    cin>>m>>n;
    
    vector<vector<int>> image;
    cout<<"Enter the image\n";
    for(int i=0;i<m;i++) {
        vector<int> temp;
        for(int j=0;j<n;j++) {
            cin>>x;
            temp.pb(x);
        }
        image.pb(temp);
    }
    
    int sr, sc;
    cout<<"Enter source points: ";
    cin>>sr>>sc;
    
    int newColor;
    cout<<"Enter new color: ";
    cin>>newColor;
    
    vector<vector<int>> newImage = floodFill(image, sr, sc, newColor);
    cout<<"New color\n";
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout<<newImage[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}