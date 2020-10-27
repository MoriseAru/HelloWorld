#include <iostream>
#include <cstring>
using namespace std;
#define N 300030
int n, m, k;
int fa[N], cnte[N], cntv[N];
bool vis[N];
int x, y;
int Find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = Find(fa[x]);
}

void unio(int x, int y)
{
    int fx = Find(x);
    int fy = Find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        cntv[fy] += cntv[fx] + 1;
        cnte[fy] += cnte[fx];
    }
    else
        cntv[fy]++;
    return;
}
int T;
int main()
{
    int t;
    scanf("%d",&T);
    int cas = 1;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<=n;i++)
        {
            fa[i] = i,cnte[i] = 1,cntv[i] = 0;
            vis[i] = false;
        }
        int ans = 0;
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            unio(x, y);
        }
        for (int i=1;i<=n;i++)
        {
            if (!vis[fa[i]])
            {
                if (cntv[fa[i]] - cnte[fa[i]] > 0)
                    ans += (cntv[fa[i]] - cnte[fa[i]]);
                vis[fa[i]] = true;
            }
        }
        printf("Case #%d: %d\n", cas++, ans);
    }
    return 0;
}
