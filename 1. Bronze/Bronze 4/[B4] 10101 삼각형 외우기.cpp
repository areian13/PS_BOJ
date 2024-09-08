#include <iostream>
#include <array>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string TriType(array<int, 3>& angles)
{
    if (angles[0] + angles[1] + angles[2] != 180)
        return "Error";

    sort(angles.begin(), angles.end());
    if (angles[0] == angles[1] && angles[1] == angles[2])
        return "Equilateral";
    if (angles[0] == angles[1] || angles[1] == angles[2])
        return "Isosceles";
    return "Scalene";
}

int main()
{
    FastIO;

    array<int, 3> angles;
    for (int i = 0; i < 3; i++)
        cin >> angles[i];

    string result = TriType(angles);
    cout << result << '\n';
}