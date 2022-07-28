#include <bits/stdc++.h> 

using namespace std;

struct DSU
{
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.assign(n, 0);
        rank.assign(n, 1);

        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int get(int x){
        if(parent[x] == x)
            return x;
        parent[x] = get(parent[x]);
        return parent[x];
    }

    void merge(int x, int y){
        x = get(x);
        y = get(y);

        if(x == y) return;
        if(rank[x] < rank[y])
            swap(x, y);

        parent[y] = x;
        if(rank[x] != rank[y])
            rank[x]++;
    }
};


int main(){
    DSU dsu(5);

    cout << dsu.get(1) << ' ' << dsu.get(2) << '\n';

    dsu.merge(1, 2);
    cout << dsu.get(1) << ' ' << dsu.get(2) << '\n';
    return 0;
}