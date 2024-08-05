#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int r;
    cin >> r;

    array<int, 2> result = { 1,r };
    cout << result[0] << ' ' << result[1] << '\n';
}