#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsNum(string& num)
{
    for (char& c : num)
    {
        if (!('0' <= c && c <= '9'))
            return false;
    }
    return true;
}

string Sub(string& a, string& b)
{
    return to_string(stoi(a) - stoi(b));
}

int main()
{
    FastIO;

    string x, y;
    cin>> x >> y;

    string result = (IsNum(x) && IsNum(y) ? Sub(x, y) : "NaN");
    cout << result << '\n';
}