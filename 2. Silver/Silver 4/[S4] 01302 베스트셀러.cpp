#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<string> books(n);
    for (int i = 0; i < n; i++)
        cin >> books[i];
    sort(books.begin(), books.end());

    vector<int> salesRate(n, 1);
    int maxSalesRate = 1;
    string result = books[0];
    for (int i = 1; i < n; i++)
    {
        if (books[i - 1] == books[i])
            salesRate[i] = salesRate[i - 1] + 1;
        if (maxSalesRate < salesRate[i])
        {
            maxSalesRate = salesRate[i];
            result = books[i];
        }
    }
    cout << result << '\n';
}