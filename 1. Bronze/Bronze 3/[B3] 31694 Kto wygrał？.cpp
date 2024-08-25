#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Winner(array<int, 18>& a, array<int, 18>& b)
{
    array<int, 10 + 1> aCnt = { 0, }, bCnt = { 0, };
    int aSum = 0, bSum = 0;
    for (int i = 0; i < 18; i++)
    {
        aSum += a[i];
        aCnt[a[i]]++;

        bSum += b[i];
        bCnt[b[i]]++;
    }

    array<string, 2> result = { "Algosia","Bajtek" };
    if (aSum != bSum)
        return result[aSum < bSum];

    for (int i = 10; i >= 0; i--)
    {
        if (aCnt[i] != bCnt[i])
            return result[aCnt[i] < bCnt[i]];
    }
    return "remis";
}

int main()
{
    FastIO;

    array<int, 18> a;
    for (int i = 0; i < 18; i++)
        cin >> a[i];

    array<int, 18> b;
    for (int i = 0; i < 18; i++)
        cin >> b[i];

    string result = Winner(a, b);
    cout << result << '\n';
}