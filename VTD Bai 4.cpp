#include<bits/stdc++.h>
#define maxn 5005

using namespace std;

int a[maxn][maxn], n, k, d1[maxn][maxn], d2[maxn][maxn];
int res, ok;

struct data
{
    int x, y, d;
};

queue<data> q1, q2;

int check(int x,int y)
{
    return (x>=1 && x<=n && y>=1 && y<=n);
}
void push1(int x, int y, int d)
{
    data tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.d = d;
    q1.push(tmp);
    d1[x][y] = d;
    if (d2[x][y] == d)
    {
        res = d;
        ok = 1;
    }
}
void push2(int x, int y, int d)
{
    data tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.d = d;
    d2[x][y] = d;
    q2.push(tmp);
}
void bfs2(int now)
{
    while(!q2.empty())
    {
        data u = q2.front();
        if (u.d > now) return;
        q2.pop();
        if (check(u.x, u.y-1) && a[u.x][u.y-1]==0 && d2[u.x][u.y-1]!=now+1)
            push2(u.x, u.y-1, u.d+1);
        if (check(u.x+1, u.y-1) && a[u.x+1][u.y-1]==0 && d2[u.x+1][u.y-1]!=now+1)
            push2(u.x+1, u.y-1, u.d+1);
        if (check(u.x+1, u.y) && a[u.x+1][u.y]==0 && d2[u.x+1][u.y]!=now+1)
            push2(u.x+1, u.y, u.d+1);
    }
}
void bfs1()
{
    while(!q1.empty())
        q1.pop();
    while(!q2.empty())
        q2.pop();

    push1(1, 1, 0);
    push2(1, n, 0);

    int now = 0;
    while(!q1.empty())
    {
        data u = q1.front();
        q1.pop();
        if (u.d == now)
        {
            bfs2(now);
            now++;
        }
        if (check(u.x, u.y+1) && a[u.x][u.y+1]==0 && d1[u.x][u.y+1]!=now)
            push1(u.x, u.y+1, now);
        if (check(u.x+1, u.y+1) && a[u.x+1][u.y+1]==0 && d1[u.x+1][u.y+1]!=now)
            push1(u.x+1, u.y+1, now);
        if (check(u.x+1, u.y) && a[u.x+1][u.y]==0 && d1[u.x+1][u.y]!=now)
            push1(u.x+1, u.y, now);
        if (ok) return;
    }
}
int main()
{
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cin >> n >> k;
            if (n == 1)
            {
                cout << 0;
                return 0;
            }
            for (int i=1; i<=k; ++i)
            {
                int x, y;
                cin >> x >> y;
                a[x][y]=1;
            }
            memset(d1, -1, sizeof(d1));
            memset(d2, -1, sizeof(d2));
            bfs1();
            cout << res;
            return 0;
}
