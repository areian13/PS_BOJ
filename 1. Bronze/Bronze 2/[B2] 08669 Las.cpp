#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<bool, MAX + 1> hasG = { false, };
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int g, r;
        cin >> g >> r;

        result += !hasG[r];
        hasG[r] = true;
    }
    cout << result << '\n';
}