#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    int elec = 0;
    int vote = 0;
    for (int i = 0; i < n; i++)
    {
        int e, v1, v2;
        cin >> e >> v1 >> v2;

        vote += v1 - v2;
        if (v1 > v2)
            elec += e;
        else if (v1 < v2)
            elec -= e;
    }

    int result = 0;
    if (elec > 0 && vote > 0)
        result = 1;
    else if (elec < 0 && vote < 0)
        result = 2;
    cout << result << '\n';
}