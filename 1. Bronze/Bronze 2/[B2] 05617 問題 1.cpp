#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int TriagleType(array<int, 3>& triangle)
{
    sort(triangle.begin(), triangle.end());

    if (triangle[0] + triangle[1] <= triangle[2])
        return -1;

    int p = triangle[0] * triangle[0] + triangle[1] * triangle[1];
    int q = triangle[2] * triangle[2];

    return (p == q ? 1 : (p > q ? 2 : 3));
}

int main()
{
    FastIO;

    array<int, 4> result = { 0, };
    while (true)
    {
        array<int, 3> triangle;
        for (int i = 0; i < 3; i++)
            cin >> triangle[i];

        int type = TriagleType(triangle);

        if (type == -1)
            break;

        result[0]++;
        result[type]++;
    }

    for (int i = 0; i < 4; i++)
        cout << result[i] << ' ';
}