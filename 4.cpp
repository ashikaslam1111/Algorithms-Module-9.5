#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertex;
    int edge;
    cin>>vertex>>edge;
    int admat[vertex][vertex];
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            admat[i][j]=0;
        }
    }
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        admat[u][v]=1;
    }
    for(int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            if( admat[i][j]!= admat[j][i])
            {
                cout<<-1;
                return 0;
            }

        }

    }
    cout<<1;
    return 0;
}
