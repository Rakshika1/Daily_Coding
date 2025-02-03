#include <iostream>
#include <vector>
using namespace std;

class QuickUnion {
    vector<int> root;  
public:
    QuickUnion(int n) {
        root.resize(n);
        for (int i = 0; i < n; i++) root[i] = i;  // Each node is its own parent
    }

    int find(int x) {  
        while (x != root[x]) x = root[x];  // Traverse up until root is found
        return x;
    }

    void unionSet(int x, int y) {  
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) root[rootX] = rootY;  // Attach one root to another
    }

    void print() {
        for (int i = 0; i < root.size(); i++) cout << root[i] << " ";
        cout << endl;
    }
};

int main() {
    QuickUnion qu(5);
    qu.unionSet(0, 1);
    qu.unionSet(2, 3);
    qu.unionSet(1, 2);
    
    qu.print();
}
