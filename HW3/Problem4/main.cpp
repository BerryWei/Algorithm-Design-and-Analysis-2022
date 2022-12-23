// Kruskal
#include <bits/stdc ++.h>
#define int long long
#define pb push_back
using namespace std;
#define kN 1000006
struct edge{
    int u, v, l, c;
    edge(){}
    edge(int u, int v, int l, int c):u(u), v(v), l(l), c(c){}
    void init(){cin >>u>>v>>l>>c;}
}e[kN];

struct Edge{
    int v, d;
    Edge(){}
    Edge(int v, int d):v(v), d(d){}
    bool operator <( const Edge r)const{return d>r.d;}
};

int n, m, p[kN], sz[kN];
vector <Edge > G[kN];
vector <int > used;
bool vis[kN ]={0};

int Find(int x){return p[x]==x?x:p[x]=Find(p[x]);}
void Union(int x, int y){int u=Find(x), v=Find(y); if(u!=v)p[u]=v, sz[v]+=sz[u], sz[u]=0;}

signed main(){
    ios:: sync_with_stdio (0), cin.tie (0);
    cin >>n>>m;
    for(int i=0; i<n; ++i)p[i]=i, sz[i]=1;
    for(int i=0; i<m; ++i)e[i].init();
    sort(e, e+m, []( edge x, edge y){return x.l<y.l;});
    edge *l=e, *r=e;
    int ans =0;
    for(; r<=e+m; ++r)if(r==e+m||l->l!=r->l){
        for(edge *i=l; i<r; ++i){
            int u=Find(i->u), v=Find(i->v);
            if(u!=v)G[u].pb(Edge(v, i->c)), G[v].pb(Edge(u, i->c)), used.pb(u), used.pb(v);
    }
        priority_queue <Edge > pq;
        int root=Find (0);
        used.pb(root);
        pq.push(Edge(root , 0));
        while (!pq.empty ()){
            Edge e=pq.top(); pq.pop();
            if(vis[e.v]) continue;
            vis[e.v]=1, ans+=e.d*sz[e.v];
            for(auto i:G[e.v])if(!vis[i.v])pq.push(Edge(i.v, e.d+i.d));
        }
        for(auto i:used)vis[i]=0, G[i]. clear ();
        used.clear ();
        for(edge *i=l; i<r; ++i)Union(i->u, i->v);
        l=r;
    }
    cout <<ans <<endl;
}