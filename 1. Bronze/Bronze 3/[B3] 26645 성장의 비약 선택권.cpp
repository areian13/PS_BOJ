#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int BestPotion(int n)
{
    static const array<int, 4> up = { 8,4,2,1 };
    static const array<int, 4> maxLevel = { 209,219,229,239 };

    int idx = 0;
    for (int i = 0; i < 4; i++)
    {
        if (min(maxLevel[i], n + up[i]) > min(maxLevel[idx], n + up[idx]))
            idx = i;
    }
    return idx + 1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = BestPotion(n);
    cout << result << '\n';
}