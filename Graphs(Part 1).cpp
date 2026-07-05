//Create a graph:

#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int>* l;
public:
    Graph(int v){
        this->v = v;
        l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int u = 0; u < v; u++){
            list<int>neighbors = l[u];
            cout<<u<<" ";
            for(int v : neighbors){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    //BFS (Breadth first search):

    void bfs(){
        queue<int> q;
        vector<bool> vis(v, false);

        q.push(0);
        vis[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";

            list<int> neighbors = l[u];
            for(int v : neighbors){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    //DFS (Depth first search):

    void dfs(int u, vector<bool> &vis){
        vis[u] = true;
        cout<<u<<" ";

        list<int> neighbors = l[u];
        for(int v : neighbors){
            if(!vis[v]){
                dfs(v,vis);
            }
        }
    }

    //HasPath problem:

    bool pathHelper(int src, int dest, vector<bool> &vis){
        if(src == dest){
            return true;
        }
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(pathHelper(v, dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPath(int src, int dest){
        vector<bool> vis(v, false);
        return pathHelper(src, dest, vis);
    }
};

int main(){
    Graph graph(7);
    
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    graph.print();
    graph.bfs();

    vector<bool> vis(7,false);
    graph.dfs(0, vis);
    return 0;
}


