#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    string s;
    cin >> n >> s;

    string result = "";
    for (char c : s)
    {
        if (c != 'J' && c != 'A' && c != 'V')
            result += c;
    }

    if (result.empty())
        cout << "nojava" << '\n';
    else
        cout << result << '\n';
}