#include <iostream>
#include <vector>
using namespace std;

class QuickFind {
    vector<int> root;  
public:
    QuickFind(int n) {
        root.resize(n);  
        for (int i = 0; i < n; i++) root[i] = i;  // Har node apne aap ka root hai
    }

    int find(int x) const {  
        return root[x];  
    }

    void unionSet(int x, int y) {  
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {  
            for (int i = 0; i < root.size(); i++) {
                if (root[i] == rootX) root[i] = rootY;  
            }
        }
    }

    void print() {
        cout << "Root Array: ";
        for (int i = 0; i < root.size(); i++) cout << root[i] << " ";
        cout << endl;
    }
};

int main() {
    QuickFind qf(5); 
    qf.unionSet(0, 1);
    qf.unionSet(2, 3);
    qf.unionSet(1, 2);
    
    qf.print();  
}
