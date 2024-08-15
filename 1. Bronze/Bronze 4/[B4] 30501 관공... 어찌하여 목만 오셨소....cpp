#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Murderer(vector<string>& names)
{
    for (string& name : names)
    {
        for (char c : name)
        {
            if (c == 'S')
                return name;
        }
    }
    return "-1";
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; i++)
        cin >> names[i];

    string result = Murderer(names);
    cout << result << '\n';
}