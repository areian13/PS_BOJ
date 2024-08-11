#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> a;
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int result = a[0] * a[2];
    cout << result << '\n';
}