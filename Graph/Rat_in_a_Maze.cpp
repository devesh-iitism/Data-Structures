#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void getPath(int i, int j, vector<vector<int>> &maze, int n, string s, vector<string> &ans)
{
    if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0)
        return;
    else if(i==n-1 && j==n-1) {
        ans.pb(s);
    }
    else {
        maze[i][j] = 0;
        getPath(i+1, j, maze, n, s+'D', ans);
        getPath(i-1, j, maze, n, s+'U', ans);
        getPath(i, j+1, maze, n, s+'R', ans);
        getPath(i, j-1, maze, n, s+'L', ans);
        maze[i][j] = 1;
    }
}

vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    getPath(0, 0, maze, n, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<int>> maze;
    vector<int> temp;
    int n, x;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Enter the maze\n";
    for(int i=0;i<n;i++) {
        temp.clear();
        for(int j=0;j<n;j++) {
            cin>>x;
            temp.pb(x);
        }
        maze.pb(temp);
    }

    vector<string> ans = findPath(maze, n);
    if(ans.size()==0)
        cout<<-1<<endl;
    else {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}