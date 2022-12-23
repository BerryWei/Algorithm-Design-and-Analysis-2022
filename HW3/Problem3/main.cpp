#include <iostream >
#include <vector >
#include <algorithm >
using namespace std;
vector <int > G[3005];
int dp [3005][3005] , pa[3005] , dft;
int m, c[3005] , d[3005] , w[3005];

// We embed the process of performing dynamic programming in the process of dfs
void dfs(int u) {
    int in = dft ++;
    w[u] = c[u];
    // Normal 0-1 Knapsack transition
    for (int i = 0; i <= m; ++i)
        dp[dft][i] = dp[dft - 1][i];
    for (int i = c[u]; i <= m; ++i)
        dp[dft][i] = max(dp[dft][i], dp[dft - 1][i - c[u]] + c[u]);
    for (int i : G[u])
        dfs(i), w[u] += w[i];
    // Special 0-1 Knapsack transition , thanks for the dfs order
    for (int i = d[u]; i <= m; ++i)
        dp[dft][i] = max(dp[dft][i], dp[in][i - d[u]] + w[u]);
}

int main() {
    ios:: sync_with_stdio (0), cin.tie (0);
    int n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> pa[i];
        if (pa[i] != -1)
            G[pa[i]]. push_back(i);
        }
    for (int i = 0; i < n; ++i)
        cin >> c[i] >> d[i];
    for (int i = 0; i < n; ++i)
        if (pa[i] == -1)
            dfs(i);
    cout << *max_element(dp[n], dp[n] + m + 1) << "\n";
}