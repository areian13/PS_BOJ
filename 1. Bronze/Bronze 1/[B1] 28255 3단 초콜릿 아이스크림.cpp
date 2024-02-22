#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Third(string& icecream)
{
    return icecream.substr(0, (icecream.size() + 2) / 3);
}
string Rev(string icecream)
{
    reverse(icecream.begin(), icecream.end());
    return icecream;
}
string Tail(string& icecream)
{
    return icecream.substr(1, icecream.size() - 1);
}
bool IsTripleIceCream(string& icecream)
{
    string third = Third(icecream);
    string revThird = Rev(third);
    string tailRevThird = Tail(revThird);
    string tailThird = Tail(third);

    return icecream == third + revThird + third
        || icecream == third + tailRevThird + third
        || icecream == third + revThird + tailThird
        || icecream == third + tailRevThird + tailThird;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        string icecream;
        cin >> icecream;

        bool result = IsTripleIceCream(icecream);
        cout << result << '\n';
    }
}