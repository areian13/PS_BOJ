#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, r;
    cin >> n >> r;

    vector<bool> isAlive(n, false);
    for (int i = 0; i < r; i++)
    {
        int d;
        cin >> d;

        isAlive[d - 1] = true;
    }

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (!isAlive[i])
            result.push_back(i);
    }

    if (result.empty())
        cout << '*' << '\n';
    else
    {
        for (auto d : result)
            cout << d + 1 << ' ';
    }
}