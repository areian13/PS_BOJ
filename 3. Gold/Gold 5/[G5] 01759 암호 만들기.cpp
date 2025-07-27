#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsMo(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void PrintPWD(int k, string& pwd, int mo, int ja, int l, vector<char>& code)
{
    int c = code.size();

    if (pwd.size() == l)
    {
        if (mo >= 1 && ja >= 2)
            cout << pwd << '\n';
        return;
    }

    for (int i = k; i < c; i++)
    {
        pwd += code[i];
        PrintPWD(i + 1, pwd, mo + IsMo(code[i]), ja + !IsMo(code[i]), l, code);
        pwd.pop_back();
    }
}

int main()
{
    FastIO;

    int l, c;
    cin >> l >> c;

    vector<char> code(c);
    for (int i = 0; i < c; i++)
        cin >> code[i];
    sort(code.begin(), code.end());

    string pwd;
    PrintPWD(0, pwd, 0, 0, l, code);
}