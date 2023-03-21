#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool visited[N];
vector<int>ad_lis[N];
void bfs(int src);
void dfs(int src);
int main()
{
    int vertex;
    int edge;
    cin>>vertex>>edge;
    for(int i=0; i<edge; i++)
    {
        int v,u;
        cin>>v>>u;
        ad_lis[v].push_back(u);
        ad_lis[u].push_back(v);
    }
    int call=0;
    for(int i=1; i<=vertex; i++)
    {
        if(visited[i]==false)
        {
            call++;
            dfs(i);
        }
    }
    cout<<call;
    return 0;
}
void bfs(int src)
{
    queue<int>q;
    visited[src]=true;
    q.push(src);
    while(!q.empty())
    {
        int head=q.front();
        q.pop();
        for(int child:ad_lis[head])
        {
            if(visited[child]==false)
            {
                q.push(child);
                visited[child]=true;

            }
        }
    }
}
void dfs(int src)
{
    visited[src]=true;
    for(int child:ad_lis[src])
    {
        if(visited[child]==false)
        {
            dfs(child);
        }
    }
}
