#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int GetFood(string& s)
{
    int n = s.size();

    array<int, 2> sum = { 0,0 };
    for (int i = 0; i < n; i++)
        sum[s[i] == 'O']++;

    array<int, 2> cnt = { 0,0 };
    for (int i = 0; i < n - 1; i++)
    {
        cnt[s[i] == 'O']++;

        if (cnt[0] * 2 != sum[0] && cnt[1] * 2 != sum[1])
            return i + 1;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    int result = GetFood(s);
    cout << result << '\n';
}