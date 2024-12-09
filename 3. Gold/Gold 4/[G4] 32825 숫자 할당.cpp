#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsValid(int k, vector<int>& a, vector<int>& table)
{
    if (k == 0)
        return true;
    if (k == 1)
        return (table[0] > a[0] && table[4] > a[0]);
    if (k == 2)
        return (table[1] > a[1] && table[4] > a[0] + a[1]);
    if (k == 3)
        return (table[2] > a[2] && table[4] > a[0] + a[1] + a[2]);
    if (k == 4)
        return (table[3] > a[3] && table[4] == a[0] + a[1] + a[2] + a[3]);
    if (k == 5)
        return (table[0] > a[0] + a[4] && table[5] > a[4]);
    if (k == 6)
        return (table[1] > a[1] + a[5] && table[5] > a[4] + a[5]);
    if (k == 7)
        return (table[2] > a[2] + a[6] && table[5] > a[4] + a[5] + a[6]);
    if (k == 8)
        return (table[3] == a[3] + a[7] && table[5] == a[4] + a[5] + a[6] + a[7]);
    if (k == 9)
        return (table[0] > a[0] + a[4] + a[8] && table[6] > a[8]);
    if (k == 10)
        return (table[1] > a[1] + a[5] + a[9] && table[6] > a[8] + a[9]);
    if (k == 11)
        return (table[2] == a[2] + a[6] + a[10] && table[6] == a[8] + a[9] + a[10]);
    if (k == 12)
        return (table[0] == a[0] + a[4] + a[8] + a[11] && table[7] > a[11]);
    if (k == 13)
        return (table[1] == a[1] + a[5] + a[9] + a[12] && table[7] == a[11] + a[12]);
    return true;
}

int BT(int k, vector<int>& a, vector<bool>& isUsed, vector<int>& table)
{
    if (!IsValid(k, a, table))
        return 0;
    if (k == 13)
        return 1;

    int result = 0;
    for (int i = 0; i < 13; i++)
    {
        if (isUsed[i])
            continue;

        isUsed[i] = true;
        a[k] = i + 1;
        result += BT(k + 1, a, isUsed, table);
        a[k] = 0;
        isUsed[i] = false;
    }
    return result;
}

int main()
{
    FastIO;

    vector<int> table(8);
    for (int i = 0; i < 8; i++)
        cin >> table[i];

    vector<int> a(13, 0);
    vector<bool> isUsed(13, false);
    int result = BT(0, a, isUsed, table);
    cout << result << '\n';
}