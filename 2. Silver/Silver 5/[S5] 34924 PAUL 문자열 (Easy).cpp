#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPaul(string& s)
{
    array<int, 4> idx;
    for (int i = 0; i < 4; i++)
        idx[i] = s.find("PAUL"[i]);
    for (int i = 0; i < 3; i++)
    {
        if (idx[i + 1] < idx[i] || (idx[i + 1] - idx[i]) % 2 == 0)
            return false;
    }
    return idx[0] % 2 == 0 && (s.size() - idx[3]) % 2 == 1;
}

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    bool result = IsPaul(s);
    cout << (result ? "YES" : "NO") << '\n';
}