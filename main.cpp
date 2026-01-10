#include <iostream>
#include <string>
#include <chrono>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;
using namespace chrono;

template <typename Func, typename... Args>
auto PrintFuncTimeImpl(const char* name, Func&& func, Args&&... args)
-> decltype(func(std::forward<Args>(args)...))
{
    auto start = chrono::steady_clock::now();

    func(std::forward<Args>(args)...);

    auto end = chrono::steady_clock::now();
    auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "[" << name << "] "
        << duration.count() << " us\n";
}

#define PrintFuncTime(func, ...) \
    PrintFuncTimeImpl(#func, func, __VA_ARGS__)

void IF(vector<int>& arr) {
    int cnt = 0;
    for (int v : arr) {
        if (v >= 0)
            v++;
    }
    cout << cnt << '\n';
}
void Comp(vector<int>& arr) {
    int cnt = 0;
    for (int v : arr)
        cnt += (v >= 0);
    cout << cnt << '\n';
}
void Bit(vector<int>& arr) {
    int cnt = 0;
    for (int v : arr)
        cnt += ((unsigned)v >> 31) ^ 1;
    cout << cnt << '\n';
}

void Just(vector<int>& arr) {
    vector<int> holsu;
    for (int v : arr) {
        if (v & 1)
            holsu.push_back(v);
    }
}
void Reserve(vector<int>& arr) {
    vector<int> holsu;
    holsu.reserve(arr.size() / 2 + 10);
    for (int v : arr) {
        if (v & 1)
            holsu.push_back(v);
    }
    holsu.shrink_to_fit();
}

int main() {
    srand((unsigned)time(NULL));
    int n = 100'000'000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % n) * (rand() % 2 ? +1 : -1);

    PrintFuncTime(Just, arr);
    PrintFuncTime(Reserve, arr);
}
