#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<array<int, 2>, 11> score =
    {
        array<int, 2>
        { 12,1600 },
        { 11,894 },
        { 11,1327 },
        { 10,1311 },
        { 9,1004 },
        { 9,1178 },
        { 9,1357 },
        { 8,837 },
        { 7,1055 },
        { 6,556 },
        { 6,773 },
    };

    int n;
    cin >> n;

    array<int, 2> result = score[n - 1];
    cout << result[0] << ' ' << result[1] << '\n';
}