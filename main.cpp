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


struct Node {
    int a;
};


int main() {

}