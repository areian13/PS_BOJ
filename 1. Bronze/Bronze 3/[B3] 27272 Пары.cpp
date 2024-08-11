#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> num;
    for (int i = 0; i < 4; i++)
        cin >> num[i];
    sort(num.begin(), num.end());

    int result = num[0] * num[1] + num[2] * num[3];
    cout << result << '\n';
}