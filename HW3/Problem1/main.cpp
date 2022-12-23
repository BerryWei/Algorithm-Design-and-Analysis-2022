#include <bits/stdc ++.h>

using namespace std;

vector <int > stk;
vector <long long > pre;

void PUT(int w) {
    stk.push_back(w);
    pre.push_back ((pre.empty () ? 0 : pre.back()) + w);
}

int TAKE() {
    int x = stk.back();
    stk.pop_back ();
    pre.pop_back ();
    return x;
}

long long MULTIPOP(int x, int k) {
    vector <pair <int ,int >> org;
    org.reserve(x);
    for (int i = 0; i < x; i++) {
        org.emplace_back(TAKE(), i);
    }

    const int sz = x - (x + k - 1) / k;
    assert (0 <= sz && sz <= x);
    vector <pair <int ,int >> tmp = org;
    nth_element(tmp.begin (), tmp.begin () + sz , tmp.end());
    // now , tmp[sz] is the $sz$ -th element and
    // tmp[0 ~ sz -1] is smaller , tmp[sz+1 ~ x-1] is bigger
    long long res = 0;
    for (int i = sz; i < x; i++) {
        res += tmp[i]. first;
    }

    if (sz == x) {
        for (int i = x - 1; i >= 0; i--)
            PUT(org[i]. first);
    } else {
        int kth = tmp[sz]. first;
        for (int i = x - 1; i >= 0; i--) {
            if (org[i]. first < kth) 
                PUT(org[i]. first);
        }
    }
    return res;
 }

 int main(){
    cin.tie(nullptr) -> sync_with_stdio(false);
    int M;
    cin >> M;

    while (M--) {
        string cmd;
        int x, k;
        cin >> cmd;
        if (cmd == "PUT") {
            cin >> x;
        PUT(x);
        } else if (cmd == "TAKE") {
            cout << TAKE() << '\n';
        } else if (cmd == "CC") {
            cin >> x >> k;
            cout << MULTIPOP(x, k) << '\n';
        } else if (cmd == "DD") {
            cin >> x;
            assert (1 <= x && x <= pre.size());
            cout << pre.back() - (x == pre.size() ? 0 : pre[pre.size() - 1 - x]) << '\n';
        }
    }
}