#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    cin.ignore();
    while (tc--)
    {
        string str;
        getline(cin, str);

        if (str.back() != '.')
            str += '.';

        cout << str << '\n';
    }
}