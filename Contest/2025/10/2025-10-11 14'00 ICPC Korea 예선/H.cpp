#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> p;
int n;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({ x, y });
    }

    sort(p.begin(), p.end());
}

int arr[500'001];
int xarr[500'001];

bool check(int x1, int x2, int y1, int y2) {
    int x = abs(x2 - x1);
    int y = abs(y2 - y1);

    if (x == 0 || y == 0) {
        return true;
    }

    double res = y / x;
    if (res < 1) return true;
    else return false;
}

void solve() {
    int idx = 0;

    // lis
    for (int i = 0; i < n; i++) {
        int cur = p[i].second;
        int xcur = p[i].first;

        if (i == 0) {
            arr[idx++] = cur;
            xarr[idx++] = xcur;
            continue;
        }

        if (arr[idx - 1] > cur) {
            arr[idx - 1] = cur;
        }
        else if (arr[idx - 1] <= cur && check(xarr[idx - 1], xcur, arr[idx - 1], cur)) 
        {
            arr[idx++] = cur;
        }
    }

    int start = idx;
    for (int i = start; i < n; i++) {
        int cur = p[i].second;
        int xcur = p[i].first;

        if (i == start) {
            arr[idx++] = cur;
            xarr[idx++] = xcur;
            continue;
        }

        if (arr[idx - 1] < cur) {
            arr[idx - 1] = cur;
        }
        else if (arr[idx - 1] >= cur && check(xarr[idx - 1], xcur, arr[idx - 1], cur)) {
            arr[idx++] = cur;
        }
    }

    cout << idx - 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    input();
    solve();
}