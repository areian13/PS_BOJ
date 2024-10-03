#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> cnt(n);
    int curr = 0;
    int result = 0;
    while (true)
    {
        int next = (cnt[curr] % 2 == 1 ? curr + l : curr - l + n) % n;
        cnt[next]++;

        if (cnt[next] == m)
            break;

        curr = next;
        result++;
    }

    cout << result << '\n';
}