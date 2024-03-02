#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000

int MaxCount(vector<int>& x)
{
    array<int, MAX + 1> cnt = { 0, };
    
    int maxValue = 0;
    for (int value : x)
    {
        cnt[value]++;
        maxValue = max(maxValue, cnt[value]);
    }

    for (int i = 1; i <= MAX; i++)
    {
        if (cnt[i] == maxValue)
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int result = MaxCount(x);
    cout << result << '\n';
}