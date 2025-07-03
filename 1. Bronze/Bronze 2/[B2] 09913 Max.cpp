#include <iostream>
#include <unordered_map>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cnt[a]++;
    }

    int result = 0;
    for (auto& it : cnt)
        result = max(result, it.second);
    cout << result << '\n';
}