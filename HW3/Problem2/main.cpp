#include <bits/stdc ++.h>
#define int long long
#define pb emplace_back
#define pii pair <int ,int >
#define ff first
#define ss second
using namespace std;

const int MAXN = 2000;
const int MAXM = 4000;
const int INF = 1e9;
int N, M;
vector <pii > G[MAXN +1];
int d[MAXN +1];

int solve(int id) {
    priority_queue <pii , vector <pii >, greater <pii >> pq;
    for (int i = 2; i <= N; i++) d[i] = INF;
    d[id] = 0;
    pq.push(pii(0, 1)), pq.push(pii(0, id));
    while (!pq.empty ()) {
        auto [_, cur] = pq.top(); pq.pop();
        for (auto [to , v] : G[cur]) {
            if (d[cur] + v < d[to]) {
                d[to] = d[cur] + v;
                pq.push(pii(d[to], to));
            }
        }
    }
    for (int i = 1; i <= N; i++) assert(d[i] != INF);
    int sum = 0;
    for (int i = 1; i <= N; i++) sum += d[i];
    return sum;
}

signed main(){
    ios_base :: sync_with_stdio (0), cin.tie (0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        G[a].pb(b, c);
    }
    int ans = solve (1);
    for (int i = 2; i <= N; i++) {
        ans = min(ans , solve(i));
    }
    cout << ans << '\n';
}