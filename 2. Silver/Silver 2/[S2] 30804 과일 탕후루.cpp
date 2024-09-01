#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int KindFruits(array<int, 9>& cnt)
{
    int result = 0;
    for (int i = 0; i < 9; i++)
        result += (cnt[i] != 0);
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> tanghulu(n);
    for (int i = 0; i < n; i++)
        cin >> tanghulu[i];

    int result = 0;
    int left = 0;
    int right = 0;
    array<int, 9> cnt = { 0, };
    while (right < n)
    {
        cnt[tanghulu[right] - 1]++;
        right++;

        while (KindFruits(cnt) > 2)
        {
            cnt[tanghulu[left] - 1]--;
            left++;
        }
        result = max(result, right - left);
    }
    cout << result << '\n';
}