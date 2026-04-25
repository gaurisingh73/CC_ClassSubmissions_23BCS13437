#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }
    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);   
        }
    }
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= (i & -i); 
        }
        return s;
    }
    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    FenwickTree ft(n);

    vector<int> arr(n + 1);

    cout << "Enter array elements (1-based indexing): ";
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ft.update(i, arr[i]);   // build tree
    }

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int type;
        cout << "\n1: Update, 2: Range Sum Query\nEnter type: ";
        cin >> type;

        if (type == 1) {
            int index, val;
            cout << "Enter index and value to add: ";
            cin >> index >> val;
            ft.update(index, val);
        } 
        else if (type == 2) {
            int l, r;
            cout << "Enter range (l r): ";
            cin >> l >> r;
            cout << "Sum = " << ft.rangeSum(l, r) << endl;
        }
    }

    return 0;
}
    
    
