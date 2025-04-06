#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int i, a;
    string s;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Node> people(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> a >> s;

        people[i] = { i,a,s };
    }

    sort(people.begin(), people.end(),
        [](const Node& a, const Node& b)
        {
            if (a.a != b.a)
                return a.a < b.a;
            return a.i < b.i;
        }
    );

    for (Node& person : people)
        cout << person.a << ' ' << person.s << '\n';
}