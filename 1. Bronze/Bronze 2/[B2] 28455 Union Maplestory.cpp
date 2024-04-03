#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int UpLevel(int level)
{
    array<int, 6> upLevel = { 60,100,140,200,250,301 };

    int result = 0;
    while (level >= upLevel[result])
        result++;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> level(n);
    for (int i = 0; i < n; i++)
        cin >> level[i];
    sort(level.begin(), level.end(), greater<int>());

    array<int, 2> result = { 0,0 };
    int k = min(n, 42);
    for (int i = 0; i < k; i++)
    {
        result[0] += level[i];
        result[1] += UpLevel(level[i]);
    }
    cout << result[0] << ' ' << result[1] << '\n';
}
