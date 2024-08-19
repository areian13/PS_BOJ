#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Clause
{
    int l, r;
};

bool result = false;

bool DFS(int k, vector<Clause>& clauses, vector<bool>& state)
{
    int n = state.size() - 1;

    if (k == n + 1)
    {
        bool can = true;
        for (Clause& clause : clauses)
        {
            bool l = (clause.l > 0) ? state[clause.l] : !state[-clause.l];
            bool r = (clause.r > 0) ? state[clause.r] : !state[-clause.r];

            if (!l && !r)
                return false;
        }
        return true;
    }

    for (int i = 0; i < 2; i++)
    {
        state[k] = !i;
        if (DFS(k + 1, clauses, state))
            return true;
    }
    return false;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Clause> clause(m);
    for (int i = 0; i < m; i++)
        cin >> clause[i].l >> clause[i].r;

    vector<bool> state(n + 1, true);
    bool result = DFS(1, clause, state);
    cout << result << '\n';
}