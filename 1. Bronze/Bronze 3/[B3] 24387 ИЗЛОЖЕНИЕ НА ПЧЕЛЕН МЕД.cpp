#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<long long, 3> a;
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    array<long long, 3> b;
    for (int i = 0; i < 3; i++)
        cin >> b[i];
    sort(b.begin(), b.end());


    long long result = 0;
    for (int i = 0; i < 3; i++)
        result += a[i] * b[i];
    cout << result << '\n';
}