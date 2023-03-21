#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
bool visited[N];
int level[N];
vector<int>node;
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
    bfs(3);
    for(int i=0; i<node.size(); i++)cout<<node[i]<<" -> "<<level[node[i]]<<"\n";
    return 0;
}
void bfs(int src)
{
    queue<int>q;
    node.push_back(src);
    visited[src]=true;
    q.push(src);
    level[src]=0;
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
                level[child]=level[head]+1;
                node.push_back(child);
            }
        }
    }
}
