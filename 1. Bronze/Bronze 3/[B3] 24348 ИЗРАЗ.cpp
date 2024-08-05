#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<long long, 3> num;
    for (int i = 0; i < 3; i++)
        cin >> num[i];
    sort(num.begin(), num.end());

    long long result = max(num[2] * num[1] + num[0], num[2]);
    cout << result << '\n';
}