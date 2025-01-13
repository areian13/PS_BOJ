#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    getline(cin, s);

    string main = "", sub = "";
    bool isSub = false;
    for (char c : s)
    {
        if (c == '(')
        {
            main.pop_back();
            isSub = true;
            continue;
        }

        if (!isSub)
            main += c;
        else
            sub += c;
    }

    if (sub != "")
        sub.pop_back();

    cout << main << '\n';
    if (sub == "")
        cout << '-' << '\n';
    else
        cout << sub << '\n';
}