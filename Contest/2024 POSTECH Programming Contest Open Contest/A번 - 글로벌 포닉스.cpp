#include <iostream>
#include <array>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 3

bool IsGlobal(array<string, SIZE>& s)
{
    unordered_map<char, bool> lkp;
    for (int i = 0; i < SIZE; i++)
        lkp[s[i][0]] = true;

    return lkp['l'] && lkp['k'] && lkp['p'];
}

int main()
{
    FastIO;

    array<string, SIZE> s;
    for (int i = 0; i < SIZE; i++)
        cin >> s[i];

    string result = (IsGlobal(s) ? "GLOBAL" : "PONIX");
    cout << result << '\n';
}