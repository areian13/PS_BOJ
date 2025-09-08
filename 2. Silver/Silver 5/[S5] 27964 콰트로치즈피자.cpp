#include <iostream>
#include <string>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_set<string> cheeses;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        if (s.size() >= 6 && s.substr(s.size() - 6) == "Cheese")
            cheeses.insert(s);
    }

    bool result = cheeses.size() >= 4;
    if (result)
        cout << "yummy" << '\n';
    else
        cout << "sad" << '\n';
}