#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsBoil(int t, vector<array<int, 2>>& record)
{
    int k = record.size();
    for (int i = 0; i < k; i++)
    {
        if (!(record[i][0] <= t && t <= record[i][1]))
            return false;
    }
    return true;
}
int main()
{
    FastIO;

    int n;
    cin>> n;

    vector<array<int, 2>> record(n);
    for (int i = 0; i < n; i++)
        cin>>record[i][0] >> record[i][1];

    bool isPossible = false;
    for (int t = 0; t <= 1'000; t++)
        isPossible = isPossible || IsBoil(t, record);

    string result = (isPossible ? "gunilla has a point" : "edward is right");
    cout << result << '\n';
}