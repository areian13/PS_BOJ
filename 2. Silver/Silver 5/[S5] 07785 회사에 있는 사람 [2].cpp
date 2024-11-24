#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, bool> isExisted;
    for (int i = 0; i < n; i++)
    {
        string name, state;
        cin >> name >> state;

        isExisted[name] = (state == "enter");
    }

    vector<string> result;
    for (pair<const string, bool>& elem : isExisted)
    {
        if (elem.second == true)
            result.push_back(elem.first);
    }

    sort(result.begin(), result.end(), greater<string>());
    for (string& name : result)
        cout << name << '\n';
}