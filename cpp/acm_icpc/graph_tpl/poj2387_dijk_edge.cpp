#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<memory.h>
#include<cmath>
#include<algorithm>
#include<queue>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Abs(a) ((a)>0?(a):-(a))
#define llong long long int
#define CLEAN(x) (memset(x, 0, sizeof(x)))
using namespace std;
const int inf = 0x7fffffff;
const int N=1005, M=40005;

int s, t;
int dis[N];
bool visit[N];
int n, m;


struct Edge
{
    int v, w, next;
}edge[M];
int edgehead[N];
int edgen;
void addedge(int u, int v, int w)
{
    edge[edgen].v = v;
    edge[edgen].w = w;
    edge[edgen].next = edgehead[u];
    edgehead[u] = edgen;
    edgen++;
}


int dijkstra()
{
    for(int i = 0; i <= n; i++)
    {
        dis[i] = inf;
    }
    CLEAN(visit);
    int now = s;
    dis[now] = 0;
    visit[now] = true;
    while(!visit[t])
    {
        int mn = inf;
        int min_v = 0;
        for(int j = edgehead[now]; j; j = edge[j].next)
        {
            int v = edge[j].v;
            int w = edge[j].w;
            if(!visit[v])
            {
                if(dis[v] > dis[now] + w)
                {
                    dis[v] = dis[now] + w;
                }
                if(dis[v] < mn)
                {
                    mn = dis[v];
                    min_v = v;
                }
            }
        }
        now = min_v;
        visit[now] = true;
    }
    return dis[t];
}

void solve()
{
    printf("%d\n", dijkstra());
}

int main()
{
#ifdef WYY_DEBUG
    freopen("data/poj2387.in", "r", stdin);
#endif
    scanf("%d%d",&m,&n);
    edgen = 1;
    int u, v, w;
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    s = 1;
    t = n;
    solve();
    return 0;
}

