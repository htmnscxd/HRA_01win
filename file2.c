#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int x, y, a, b, n;

pair<int, int> F[N][N];

pair<int, int> newState(pair<int, int> s, int a, int v) {
    s.second += a;
    if (s.second >= v) {
        ++s.first;
        s.second = 0;
    }
    return s;
}

bool dp(int value) {
    for (int i = 0; i <= x; ++i) for (int j = 0; j <= y; ++j)
        F[i][j] = make_pair(0, 0);
    for (int i = 0; i <= x; ++i) for (int j = 0; j <= y; ++j) {
        if (F[i][j].first == n) return 1;
        if (i < x)
            F[i + 1][j] = max(F[i + 1][j], newState(F[i][j], a, value));
        if (j < y)
            F[i][j + 1] = max(F[i][j + 1], newState(F[i][j], b, value));
    }
    return 0;
}

int solve() {
    int l = 0, r = (a * x + b * y) / n;
    int ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (dp(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    cin >> x >> a >> y >> b >> n;
    cout << solve() << endl;
    
    return 0;
}

