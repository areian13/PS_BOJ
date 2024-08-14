#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    array<int, 4> stats;
    for (int i = 0; i < 4; i++)
        cin >> stats[i];
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < 4; i++)
        result += n - stats[i];
    result = max(result, 0);

    cout << result << '\n';
}