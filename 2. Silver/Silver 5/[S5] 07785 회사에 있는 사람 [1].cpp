#include <iostream>
#include <map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    map<string, bool, greater<string>> isExisted;
    for (int i = 0; i < n; i++)
    {
        string name, state;
        cin >> name >> state;

        isExisted[name] = (state == "enter");
    }

    for (pair<const string, bool>& elem : isExisted)
    {
        if (elem.second == true)
            cout << elem.first << '\n';
    }
}