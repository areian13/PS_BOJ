#include <iostream>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> first(n);
    for (int i = 0; i < n; i++)
        cin >> first[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int second;
        cin >> second;

        for (int j = 0; j < n; j++)
        {
            if (second > first[j])
                sum++;
            else if (second < first[j])
                sum--;
        }
    }

    string result = (sum == 0 ? "tie" : (sum < 0 ? "first" : "second"));
    cout << result << '\n';
}