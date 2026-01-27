#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000;

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<int, MAX + 1> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int s, t, b;
        cin >> s >> t >> b;
        
        for (int j = s; j <= t; j++)
            cnt[j] += b;
    }

    int result = *max_element(cnt.begin(), cnt.end());
    cout << result << '\n';
}