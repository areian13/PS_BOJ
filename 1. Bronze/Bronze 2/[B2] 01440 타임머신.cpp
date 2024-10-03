#include <iostream>
#include <cstdio>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isReadable(array<int, 3>& d, array<array<int, 3>, 3>& limits)
{
    for (int i = 0; i < 3; i++)
    {
        if (!(limits[i][1] <= d[i] && d[i] <= limits[i][2]))
            return false;
    }
    return true;
}

int CountReadable(array<int, 3>& d)
{
    static array<array<int, 3>, 3> limits =
    {
        array<int, 3>
        { 0,1,12 },
        { 1,0,59 },
        { 2,0,59 },
    };

    int result = 0;
    do
    {
        result += isReadable(d, limits);
    } while (next_permutation(limits.begin(), limits.end()));
    return result;
}

int main()
{
    FastIO;

    array<int, 3> d;
    scanf("%02d:%02d:%02d", &d[0], &d[1], &d[2]);

    int result = CountReadable(d);
    cout << result << '\n';
}