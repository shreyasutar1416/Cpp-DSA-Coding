#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;
    list<int>* l;
    bool isUndir;
public:
    Graph(int v, bool isUndir = true){
        this->v = v;
        l = new list<int> [v];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndir){
            l[v].push_back(u);
        }
    }

    //cycle detection--> directed graph (DFS)
    bool dirCycleHelper(int src, vector<bool> &vis, vector<bool> &recPath){
        vis[src] = true;
        recPath[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors){
            if(!vis[v]){
                if(dirCycleHelper(v,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    bool isCycleDir(){
        vector<bool> vis(v,false);
        vector<bool> recPath(v,false);

        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dirCycleHelper(i,vis,recPath);
                return true;
            }
        }
    }
    return false;
};

//disconnected components
    //DFS
    void dfsHelper(int u, vector<bool> &vis){
        cout<<u<<" ";
        vis[u] = true;
        list<int> neighbors = l[u];

        for(int v : neighbors){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(v,false);
        for(int i = 0; i<v; i++){
            if(!vis([i])){
                dfsHelper(i,vis);  //starting point = i
                cout<<endl;
            }
        }
        cout<<endl;
    }

    //BFS
    void bfsHelper(int st, vector<bool> &vis){
        queue<int> q;
        q.push(st);
        vis[st] = true;

        while(q.size() > 0){
            int curr = q.front();
            q.pop();

            cout<<curr<<" ";

            list<int> neighbors = l[curr];
            for(int neigh : neighbors){
                //to ensure that one nodes is added only once to queue
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout<<endl;
    }

    void bfs(){
        vector<boo> vis(v,false);
        for(int i = 0; i<v; i++){
            if(!vis[i]){
                bfsHelper(i, vis);
                cout<<endl;
            }
        }
    }

//cycle detection--> undirected graph (DFS)
bool undirCycleHelper(int src, int par, vector<boo> &vis){
    vis[src] = true;
    list<int> neighbors = l[src];

    for(int v : neighbors){
        if(!vis[v]){
            if(undirCycleHelper(v,src,vis)){
                return true;
            }
        }else{
            if(v != par){       //cycle condition
                return true;
            }
        }
    }
    return false;
}

bool isCycleUndir(){
    vector<bool> vis(v,false);
    return undirCycleHelper(0,-1,vis);
}

//Bipartitie BFS Approach:

bool isBipartite(){
    queue<int> q;
    vector<boo> vis(v,false);
    vector<int> color(v,-1);
    q.push(0);
    color[0] = 0;
    while(q.size() > 0){
        int curr = q.front();
        q.pop();
        list<int> neighbors = l[curr];

        for(int v : neighbors){
            if(!vis[v]){
                vis[v] = true;
                color[v] =! color[curr];
                q.push(v);
            }else{
                if(color[v] == color[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}

//All Paths Problem--> Print all paths from src to dest for a directed graph

void pathHelper(int src, int dest, vector<bool> &vis, string &path){
    if(src == dest){
        cout<<path<<dest<<endl;
        return;
    }
    vis[src] = true;
    path += to_string(src);
    list<int> neighbors = l[src];

    for(int v : neighbors){
        if(!vis[v]){
            pathHelper(v,dest,vis,path);
        }
    }

    path = path.substr(0,path.size()-1);
    vis[src] = false;

}
void printAllPaths(int src, int dest){
    vector<bool> vis(v,false);
    string path = " ";
    pathHelper(src,dest,vis,path);
}

//Topological sorting
void topoHelper(int src, vector<bool> &vis, vector<int> &s){
    vis[src] = true;

    list<int> neighbors = l[src];
    for(int v : neighbors){
        if(!vis[v]){
            topoHelper(v,vis,s);
        }
    }
    s.push(src);
}

void topoSort(){
    vector<bool> vis(v,false);
    stack<int> s;

    for(int i = 0; i<v; i++){
        if(!vis[i]){
            topoHelper(i,vis,s);
        }
    }//print topological order
    while(s.size() > 0){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

//Topological sort using BFS (Kahn's Algorithm)
void topoSort2(){
    vector<int> indeg(v,0);
    calIndegree(indeg);
    queue<int> q;
    //0 indeg node--> starting point
    for(int i = 0; i<v; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(q.size() > 0){
        int curr = q.front();
        q.pop(); cout<<curr<<" ";
        list<int> neighbors = l[curr];

        for(int v : neighbors){
            indeg[v]--;
            if(indeg[v] == 0){   //no pending dependencies
                q.push(v);
            }
        }
    }
    cout<<endl;
}

int main(){
    //topological sorting
    Graph graph(6,false);
    
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);
    
    graph.topoSort();
    graph.topoSort2();
    return 0;
}

// int main(){
//     //All paths Problem
//     Graph graph(6,false);
    
//     graph.addEdge(0,3);
//     graph.addEdge(2,3);
//     graph.addEdge(3,1);
//     graph.addEdge(4,0);
//     graph.addEdge(4,1);
//     graph.addEdge(5,0);
//     graph.addEdge(5,2);
    
//     printAllPaths(5,1);
//     return 0;
// }

// int main(){
//     //undirected bipartite graph
//     Graph graph(4);
    
//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,3);

//     cout<<graph.isBipartite()<<endl;
//     return 0;
// }

// int main(){
//     //cycle detection using directed graph
//     Graph graph(4,false);
    
//     graph.addEdge(1,0);
//     graph.addEdge(0,2);
//     graph.addEdge(2,3);
//     graph.addEdge(3,0);

//     cout<<graph.isCycleDir()<<endl;
//     return 0;
// }

// int main(){
//     //cycle detection using undirected graph
//     int v = 5;
//     Graph graph();
    
//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,2);
//     graph.addEdge(0,3);
//     graph.addEdge(3,4);

//     cout<<graph.isCycleUndir()<<endl;
//     return 0;
// }

// int main(){
//     //topological sorting
//     Graph graph(7);
    
//     graph.addEdge(0,1);
//     graph.addEdge(0,2);
//     graph.addEdge(1,3);
//     graph.addEdge(2,4);
//     graph.addEdge(3,4);
//     graph.addEdge(3,5);
//     graph.addEdge(4,5);
//     graph.addEdge(5,6);

//     graph.print();
//     graph.bfs();

//     graph.dfs(0, vis);
//     return 0;
// }


