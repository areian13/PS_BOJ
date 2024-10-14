#include <iostream>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int l = 0;
    int r = 0;
    for (int i = 0; i < n; i++)
    {
        int stone;
        cin >> stone;

        if (l == r)
            l += stone;
        else
            (l < r ? l : r) += stone;
    }

    array<int, 7> weights = { 100,50,20,10,5,2,1 };

    int gap = abs(l - r);
    int result = 0;
    for (int weight : weights)
    {
        result += gap / weight;
        gap %= weight;
    }
    cout << result << '\n';
}