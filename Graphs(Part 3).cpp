//Dijkstra's Algorithm: (Greedy algorithm) --> shortest path from src to all vertices for weighted

#include<iostream>
#include<vector>
#include<queue>
#include <climits>
#include <functional>
using namespace std;

class Edge{
public:
   int v;
   int wt;

   Edge(int v, int wt){
    this->v = v;
    this->wt = wt;
   }
};

void dijkstra(int src, vector<vector<Edge>> &graph, int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    //min heap
    
    //pair(dist[v], v)
    vector<int> dist(v, INT_MAX);
    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(pq.size() > 0){
        int u = pq.top().second;
        pq.pop();

        vector<Edge> edges = graph[u];
        for(Edge e : edges){
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }
    for(int d : dist){
        cout<<d<<" ";
    }
    cout<<endl;
}

int main(){
    int v = 6;
    vector<vector<Edge>> graph(v);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[2].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));
    dijkstra(0,graph, v);
    return 0;
}

//Bellmanford ALgorithm: (DP alogrithm)--> shortest path from src to all vertices for weighted graph with negative wt

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<vector<Edge>> &graph, int v, int src) {

    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++) {

        for (int u = 0; u < v; u++) {

            for (Edge e : graph[u]) {

                if (dist[u] != INT_MAX &&
                    dist[e.v] > dist[u] + e.wt) {

                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    for (int d : dist)
        cout << d << " ";

    cout << endl;
}

int main() {

    int v = 5;
    vector<vector<Edge>> graph(v);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,-4));
    graph[2].push_back(Edge(3,2));
    graph[3].push_back(Edge(4,4));
    graph[4].push_back(Edge(1,-1));

    bellmanFord(graph, v, 0);

    return 0;
}

//Minimum spanning tree (MST):

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
using namespace std;

class Graph {
    int v;
    list<pair<int,int>> *l;

public:

    Graph(int v) {
        this->v = v;
        l = new list<pair<int,int>>[v];
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back({v, wt});
        l[v].push_back({u, wt});
    }

    void primsAlgo(int src) {

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<bool> mst(v, false);

        pq.push({0, src});

        int ans = 0;

        while (!pq.empty()) {

            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (mst[u])
                continue;

            mst[u] = true;
            ans += wt;

            for (auto n : l[u]) {

                int vertex = n.first;
                int currwt = n.second;

                if (!mst[vertex])
                    pq.push({currwt, vertex});
            }
        }

        cout << "Final cost of MST = " << ans << endl;
    }
};

int main() {

    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);
    graph.addEdge(1,3,40);
    graph.addEdge(2,3,50);

    graph.primsAlgo(0);

    return 0;
}

//Min cost to connect all points:

class solution{
public:
    int minCostConnectPoints(vector<vector<int>> &points){
        int v = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //(wt, u)
        int src = 0;
        vector<bool> mst(v,false);
        pq.push(make_pair(0,src));
        int minCost = 0;

        while(pq.size() > 0){
            int u = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            if(!mst[u]){
                mst[u] = true;
                minCost += cost;

                for(int v = 0; v<V; v++){
                    if(u != v){
                        int wt = abs(points[u][0] - points[v][0] + abs[points[u][1] - points[v][1]]);
                        pq.push(make_pair(wt, v));
                    }
                }
            }
            return minCost;
        }
    }
}

//Cheapest flights within k stops:

class solution{
public:
    class Info{
    public: 
        int u;
        int cost;
        int stops;   //src to u
         
        Info(int u, int cost, int stops){
            this->u = u;
            this->cost = cost;
        }
    }
};

int findCheapestPrice(int v, vector<vector<int>> &flights, int src, int dst, int k){
    queue<Info> q;
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    q.push(Info(src, 0, -1));

    while(q.size() > 0){
        Info curr = q.front();
        q.pop();

        for(int i = 0; i<flights.size(); i++){
            if(flights[i][0] == curr.u){
                int v = flights[i][1];
                int wt = flights[i][2];

                if(dist[v] > curr.cost + wt && curr.stops + 1 <= k){
                    dist[v] = curr.cost + wt;
                    q.push(Info(v,dist[v], curr.stops + 1));
                }
            }
        }
    }
}

//Disjoint set Ds: a,b are part of the same set or diff sets

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <functional>
using namespace std;

class DisjointSet{
public:
   int n;
   vector<int>par;
   vector<int>rank;

   DisjointSet(int n){
        this->n = n;

        for(int i = 0; i<n; i++){
            par.push_back(i);
            rank.push_back(0);
        }
   }

   int find(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);  //path compression optimization
   }

   int unionByRank(int a, int b){
    int parA = find(a);
    int parB = find(b);

    if(rank[parA] == rank[parB]){
        par[parB] = parA;
        rank[parA]++;
    }else if(rank[parA] > rank[parB]){
        par[parB] = parB;
    }else{
        par[parA] = parB;
    }
   }

   void getInfo(){
    for(int i = 0; i<n; i++){
        cout<<i<<":"<<par[i]<<","<<rank[i]<<endl;
    }
   }
};

int main(){
    DisjointSet dj(6);

    dj.unionByRank(0,2);
    cout<<dj.find(2)<<endl;

    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.unionByRank(0,3);
    cout<<dj.find(2)<<endl;

    dj.unionByRank(0,4);
    dj.getInfo();
    return 0;
}

//Kruskal's algorithm:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, wt;

    Edge(int src, int dest, int wt) {
        this->src = src;
        this->dest = dest;
        this->wt = wt;
    }
};

// Sort edges by weight
bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]); // Path Compression
    }

    void Union(int x, int y) {
        int parX = find(x);
        int parY = find(y);

        if (parX == parY)
            return;

        // Union by Rank
        if (rank[parX] < rank[parY]) {
            parent[parX] = parY;
        }
        else if (rank[parX] > rank[parY]) {
            parent[parY] = parX;
        }
        else {
            parent[parY] = parX;
            rank[parX]++;
        }
    }
};

void kruskal(vector<Edge> &edges, int V) {

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int mstCost = 0;

    cout << "Edges in MST:\n";

    for (Edge e : edges) {

        if (dsu.find(e.src) != dsu.find(e.dest)) {

            dsu.Union(e.src, e.dest);

            cout << e.src << " - " << e.dest
                 << " : " << e.wt << endl;

            mstCost += e.wt;
        }
    }

    cout << "Total Cost = " << mstCost << endl;
}

int main() {

    int V = 4;

    vector<Edge> edges;

    edges.push_back(Edge(0,1,10));
    edges.push_back(Edge(0,2,15));
    edges.push_back(Edge(0,3,30));
    edges.push_back(Edge(1,3,40));
    edges.push_back(Edge(2,3,50));

    kruskal(edges, V);

    return 0;
}

//Flood fill algorithm:

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &image, int r, int c,
         int oldColor, int newColor) {

    int rows = image.size();
    int cols = image[0].size();

    // Boundary check
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    // Different color
    if (image[r][c] != oldColor)
        return;

    // Fill color
    image[r][c] = newColor;

    // 4 directions
    dfs(image, r + 1, c, oldColor, newColor);
    dfs(image, r - 1, c, oldColor, newColor);
    dfs(image, r, c + 1, oldColor, newColor);
    dfs(image, r, c - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image,
                              int sr, int sc,
                              int newColor) {

    int oldColor = image[sr][sc];

    if (oldColor == newColor)
        return image;

    dfs(image, sr, sc, oldColor, newColor);

    return image;
}

int main() {

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    floodFill(image, 1, 1, 2);

    for (auto row : image) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
