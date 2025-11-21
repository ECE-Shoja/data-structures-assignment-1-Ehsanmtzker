#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    if (v == parent[v])
        return v;
    parent[v] = findSet(parent[v]);
    return parent[v];
}

void unionSet(int a, int b) {
    int parentA = parent[a];
    int parentB = parent[b];
    for (int i = 0; i < parent.size(); i++)
    {
        if (parent[i] == parentA)
        {
            parent[i] = parentB;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
