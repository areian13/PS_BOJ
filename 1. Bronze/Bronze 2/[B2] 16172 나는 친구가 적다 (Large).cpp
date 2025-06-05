#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    string t = "";
    for (char c : a)
    {
        if ('0' <= c && c <= '9')
            continue;
        t += c;
    }

    bool result = t.find(b) != string::npos;
    cout << result << '\n';
}