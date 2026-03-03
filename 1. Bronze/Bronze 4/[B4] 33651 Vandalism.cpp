#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = "";
    for (char c : (string)"UAPC")
    {
        if (s.find(c) == -1)
            result += c;
    }
    cout << result << '\n';
}