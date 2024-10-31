#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const string CAMBRIDGE = "CAMBRIDGE";

int main()
{
    FastIO;

    string s;
    cin >> s;

    string result = "";
    for (char c : s)
    {
        if (CAMBRIDGE.find(c) == string::npos)
            result += c;
    }
    cout << result << '\n';
}