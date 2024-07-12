#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin>> n;

    unordered_map<string, bool> log;
    vector<string> name(n);
    for (int i = 0; i < n; i++)
    {
        string state;
        cin>> name[i] >> state;

        log[name[i]] = (state == "enter");
    }

    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        if (log[name[i]])
        {
            result.push_back(name[i]);
            log[name[i]] = false;
        }
    }
    sort(result.begin(), result.end(), greater<string>());

    for (string& enteredMan : result)
        cout << enteredMan << '\n';
}