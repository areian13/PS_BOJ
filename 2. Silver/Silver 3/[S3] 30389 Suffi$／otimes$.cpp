#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, int> cnt;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        int m = s.size();
        for (int j = 0; j < m; j++)
            cnt[s.substr(j, m - j)]++;
    }

    int result = 0;
    for (auto& iter : cnt)
        result += (iter.second % 2);
    cout << result << '\n';
}