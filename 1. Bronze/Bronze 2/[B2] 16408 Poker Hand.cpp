#include <iostream>
#include <string>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    map<char, int> cnt;
    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        cnt[s[0]]++;
    }

    int result = 0;
    for (auto& [c, v] : cnt)
        result = max(result, v);
    cout << result << '\n';
}