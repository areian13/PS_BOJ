#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000;
vector<int> tri(MAX + 1, 0);

bool IsEureka(int n)
{
    for (int i = 1; i <= MAX; i++)
    {
        if (tri[i] >= n) break;
        for (int j = i; j <= MAX; j++)
        {
            if (tri[i] + tri[j] >= n) break;
            for (int k = j; k <= MAX; k++)
            {
                if (tri[i] + tri[j] + tri[k] == n)
                    return true;
                if (tri[i] + tri[j] + tri[k] > n)
                    break;
            }
        }
    }
    return false;
}

int main()
{
    FastIO;

    for (int i = 1; i <= MAX; i++)
        tri[i] = tri[i - 1] + i;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        bool result = IsEureka(n);
        cout << result << '\n';
    }
}