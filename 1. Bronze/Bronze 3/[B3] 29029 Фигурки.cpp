#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Index(char c)
{
    if (c == 'N')
        return 0;
    if (c == 'S')
        return 1;
    if (c == 'E')
        return 2;
    return 3;
}

int main()
{
    FastIO;

    int n;
    string x;
    cin >> n >> x;

    array<int, 4> cnt = { 0, };
    for (int i = 0; i < n; i++)
        cnt[Index(x[i])]++;

    int result = n - *max_element(cnt.begin(), cnt.end());
    cout << result << '\n';
}