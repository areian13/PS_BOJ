#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Get3LetterName(vector<string>& names)
{
    string result = "ZZZZZ";
    for (string& name : names)
    {
        if (name.size() == 3)
            result = min(result, name);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
        cin >> names[i];

    string result = Get3LetterName(names);
    cout << result << '\n';
}