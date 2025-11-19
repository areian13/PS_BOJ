#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000;
const int INF = INT_MAX;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    vector<int> dist(MAX + 1, INF);
    dist[0] = 0;
    for (int i = 1; i <= MAX; i++)
    {
        for (int j : a)
        {
            if (i < j) continue;
            if (dist[i - j] == k) continue;
            dist[i] = min(dist[i], dist[i - j] + 1);
        }
    }

    int result = 0;
    while (result < MAX && dist[result] != INF)
        result++;

    printf("%s win at %d\n", (result & 1 ? "jjaksoon" : "holsoon"), result);
}