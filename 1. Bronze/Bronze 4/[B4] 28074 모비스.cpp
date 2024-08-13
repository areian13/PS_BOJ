#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMobis(string& mobis)
{
    array<bool, 26> isMobis = { false, };
    for (char c : mobis)
        isMobis[c - 'A'] = true;

    string MOBIS = "MOBIS";
    for (char c : MOBIS)
    {
        if (!isMobis[c - 'A'])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    string mobis;
    cin >> mobis;

    string result = (IsMobis(mobis) ? "YES" : "NO");
    cout << result << '\n';
}