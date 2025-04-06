#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int a;
    string s;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<vector<Node>, 201> peoples;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;

        peoples[a].push_back({ a,s });
    }

    for (auto& people : peoples)
    {
        for (auto& person : people)
            cout << person.a << ' ' << person.s << '\n';
    }
}