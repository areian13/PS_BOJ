#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, int> names;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        names[name]++;
    }

    unordered_map<string, int> finish;
    for (int i = 0; i < n - 1; i++)
    {
        string name;
        cin >> name;
        finish[name]++;
    }

    for (auto& [name, cnt] : names)
    {
        for (int i = 0; i < cnt - finish[name]; i++)
            cout << name << '\n';
    }
}