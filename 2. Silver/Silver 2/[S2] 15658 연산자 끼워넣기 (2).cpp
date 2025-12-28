#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int Operate(vector<int>& a, vector<int>& op)
{
    int n = a.size();
    int result = a[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (op[i] == 0)
            result += a[i + 1];
        else if (op[i] == 1)
            result -= a[i + 1];
        else if (op[i] == 2)
            result *= a[i + 1];
        else if (op[i] == 3)
            result /= a[i + 1];
    }
    return result;
}

pair<int, int> InsertOp(int d, vector<int>& op, vector<int>& cnt, vector<int>& a)
{
    int n = a.size();
    if (d == n - 1)
    {
        int result = Operate(a, op);
        return { result,result };
    }

    pair<int, int> result = { -INF,INF };
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] == 0) continue;

        cnt[i]--;
        op[d] = i;
        auto temp = InsertOp(d + 1, op, cnt, a);
        result.first = max(result.first, temp.first);
        result.second = min(result.second, temp.second);
        cnt[i]++;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> cnt(4);
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];

    vector<int> op(n - 1);
    auto [M, m] = InsertOp(0, op, cnt, a);
    cout << M << '\n' << m << '\n';
}