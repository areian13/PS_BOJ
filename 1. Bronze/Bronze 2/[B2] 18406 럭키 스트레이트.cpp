#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Sum(const string& s)
{
    int result = 0;
    for (char c : s)
        result += c - '0';
    return result;
}
bool IsLucky(string& s)
{
    int n = s.size();
    return Sum(s.substr(0, n / 2)) == Sum(s.substr(n / 2));
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    bool result = IsLucky(s);
    cout << (result ? "LUCKY" : "READY") << '\n';
}