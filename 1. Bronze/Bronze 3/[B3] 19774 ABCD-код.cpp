#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsCode(string& code)
{
    string l = code.substr(0, 2);
    string r = code.substr(2, 2);
    return ((int)(pow(stoi(l), 2) + pow(stoi(r), 2)) % 7 == 1);
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string code;
        cin >> code;

        string result = (IsCode(code) ? "YES" : "NO");
        cout << result << '\n';
    }
}