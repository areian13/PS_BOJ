#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsCute(string& s)
{
    if (s.size() < 5)
        return false;
    return s.substr(s.size() - 5) == "driip";
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    bool result = IsCute(s);
    if (result == true)
        cout << "cute" << '\n';
    else
        cout << "not cute" << '\n';
}