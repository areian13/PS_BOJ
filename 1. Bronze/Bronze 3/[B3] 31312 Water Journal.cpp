#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    vector<bool> isChecked(b + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int w;
        cin >> w;

        isChecked[w] = true;
    }

    vector<int> result;
    if (!isChecked[a] && !isChecked[b])
        result.push_back(-1);
    else if (!isChecked[a])
        result.push_back(a);
    else if (!isChecked[b])
        result.push_back(b);
    else
    {
        for (int i = a; i <= b; i++)
            result.push_back(i);
    }

    for (int water : result)
        cout << water << '\n';
}