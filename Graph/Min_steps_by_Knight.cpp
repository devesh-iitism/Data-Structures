#include<bits/stdc++.h>
using namespace std;

struct cell{
    int x;
    int y;
    int d;
    cell(){}
    cell(int x,int y,int d) : x(x),y(y),d(d){}
};
    
bool isSafe(int x,int y,int n)
{
    return (x>=1&&y>=1&&x<=n&&y<=n);
}

int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
{
    int visited[n+1][n+1];
    
    memset(visited,0,sizeof(visited));
    
    queue <cell> q;
    q.push(cell(KnightPos[0],KnightPos[1],0));
    
    cell t;
    int x,y;
    while(!q.empty())
    {
        int dx[] = {-2,-1,1,2,-2,-1,1,2};
        int dy[] = {-1,-2,-2,-1,1,2,2,1};
        
        t = q.front();
        q.pop();
        
        if(t.x==TargetPos[0]&&t.y==TargetPos[1])
            return t.d;
        
        for(int i=0;i<8;i++)
        {
            x = t.x + dx[i];
            y = t.y + dy[i];
            
            if(isSafe(x,y,n)&&(!visited[x][y]))
            {
                visited[x][y]=1;
                q.push(cell(x,y,t.d+1));
            }
        }
    }
    return 0;
}

int main()
{
    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};
    int n = 6;

    cout<<minStepToReachTarget(KnightPos, TargetPos, n)<<endl; 

    return 0;
}