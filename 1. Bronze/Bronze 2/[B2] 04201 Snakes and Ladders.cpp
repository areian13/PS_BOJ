#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    unordered_map<int, int> l;
    for (int i = 0; i < b; i++)
    {
        int x, y;
        cin >> x >> y;

        l[x] = y;
    }

    vector<int> result(a, 1);
    for (int i = 0; i < c; i++)
    {
        int k;
        cin >> k;

        result[i % a] += k;
        if (l.count(result[i % a]))
            result[i % a] = l[result[i % a]];

        if (result[i % a] >= 100)
        {
            result[i % a] = 100;
            break;
        }
    }

    for (int i = 0; i < a; i++)
        printf("Position of player %d is %d.\n", i + 1, result[i]);
}