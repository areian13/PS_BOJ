#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAllNum(vector<array<int, 49>>& lottos)
{
    int n = lottos.size();
    if (n <= 8)
        return false;

    array<int, 49> isExisted = { false, };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
            isExisted[lottos[i][j] - 1] = true;
    }

    for (int i = 0; i < 49; i++)
    {
        if (!isExisted[i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<array<int, 49>> lottos(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 6; j++)
                cin >> lottos[i][j];
        }

        string result = (IsAllNum(lottos) ? "Yes" : "No");
        cout << result << '\n';
    }
}