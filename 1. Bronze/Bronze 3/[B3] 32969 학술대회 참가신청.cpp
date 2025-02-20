#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsIn(string& s, vector<string>& words)
{
    for (string& word : words)
    {
        if (s.find(word) != string::npos)
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    vector<string> dh = { "social","history","language","literacy" };
    vector<string> pb = { "bigdata","public","society" };

    string result = "";
    while (result == "")
    {
        string s;
        cin >> s;

        if (cin.eof())
            break;

        if (IsIn(s, dh))
            result = "digital humanities";
        if (IsIn(s, pb))
            result = "public bigdata";
    }
    cout << result << '\n';
}