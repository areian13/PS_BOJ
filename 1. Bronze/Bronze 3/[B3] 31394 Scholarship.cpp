#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Scholarship(vector<int>& m)
{
    int n = m.size();

    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i] == 3)
            return "None";

        avg += m[i];
    }
    avg /= n;

    if (avg == 5.0)
        return "Named";
    if (avg >= 4.5)
        return "High";
    return "Common";
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> m(n);
    for (int i = 0; i < n; i++)
        cin >> m[i];

    string result = Scholarship(m);
    cout << result << '\n';
}