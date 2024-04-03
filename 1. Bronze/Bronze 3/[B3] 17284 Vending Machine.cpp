#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define COUNT 3

int main()
{
    FastIO;

    array<int, COUNT> cost = { 500,800,1'000 };
    int result = 5'000;
    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        result -= cost[n - 1];
    }

    cout << result << '\n';
}