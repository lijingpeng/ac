#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int lowbit = x & -x;
        cout << (x - lowbit + 1) << ' ' << (x + lowbit - 1) << '\n';
    }
    return 0;
}
