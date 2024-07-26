#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void BT(int k, vector<bool>& isSelected, vector<int>& result)
{
    int n = isSelected.size();
    int m = result.size();

    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSelected[i])
            continue;

        isSelected[i] = true;
        result[k] = i + 1;
        BT(k + 1, isSelected, result);
        isSelected[i] = false;
    }
}

void PrintNM(int n, int m)
{
    vector<int> result(m);
    vector<bool> isSelected(n, false);
    BT(0, isSelected, result);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    PrintNM(n, m);
}