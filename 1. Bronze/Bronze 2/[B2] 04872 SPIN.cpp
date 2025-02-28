#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    int n = s.size();
    while (true)
    {
        string d;
        cin >> d;

        if (cin.eof())
            break;

        for (int i = 0; i < n; i++)
            s[i] = ((s[i] - '0') + (d[i] - '0')) % 10 + '0';
    }
    cout << s << '\n';
}