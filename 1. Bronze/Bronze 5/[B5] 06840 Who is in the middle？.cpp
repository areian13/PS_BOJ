#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 3> bowl;
    for (int i = 0; i < 3; i++)
        cin >> bowl[i];
    sort(bowl.begin(), bowl.end());

    int result = bowl[1];
    cout << result << '\n';
}