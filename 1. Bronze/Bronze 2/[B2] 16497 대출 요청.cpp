#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> cnt(32, 0);
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        for (int j = s; j < e; j++)
            cnt[j]++;
    }

    int k;
    cin >> k;

    bool result = (*max_element(cnt.begin(), cnt.end()) <= k);
    cout << result << '\n';
}