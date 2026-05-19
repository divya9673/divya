# include <bits/stdc++.h>
using namespace std;
struct Edge{
    int u;
    int v;
    int weight;

};
bool compareEdges(Edge a,Edge b){
    return a.weight <b.weight;

}
int findParent(int parent[],int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}
void unionset(int parent[],int x,int y){
    int xset=findParent(parent,x);
    int yset=findParent(parent, y);
}
int main(){
    int V,E;
    cout<<"enter number of villages (vertices):";
    cin>>V;
    cout<<"enter number of possible pipes(edges):";
    cin>>E;
    Edge edges[E];
    cout<<"enter source destination cost:\n";
    for(int i=0;i<E;i++){
        cin>> edges[i].u >>edges[i].v >>edges[i].weight;
    }
    sort(edges,edges+E,compareEdges);
    int parent[V];
    for(int i=0;i<V;i++){
        parent[i]=i;}
    int edgeCount=0;
    int mincost=0;
    cout<<"\nEdges in minimum spanning tree:\n";

    
    for(int i=0;i<E && edgeCount<V-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int setU=findParent(parent,u);
        int setV=findParent(parent,v);
        if(setU !=setV){
            cout<<u<<" "<<v<<" : "<<edges[i].weight<<endl;
            mincost+=edges[i].weight;
            unionset(parent,setU,setV);
            edgeCount++;
        }
    }
    cout<<"Minimum Cost="<<mincost<<endl;
    return 0;
}

/*
enter number of villages (vertices): 5
enter number of possible pipes(edges): 7
enter source destination cost:

0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Edges in minimum spanning tree:

0 1 : 2
1 2 : 3
1 4 : 5
0 3 : 6

Minimum Cost=16


ALGORITHM:
Steps involved in Kruskal’s Algorithm to generate a minimum spanning tree:
Step 1: Sort all edges in increasing order of their edge weights.
Step 2: Pick the smallest edge.
Step 3: Check if the new edge creates a cycle or loop in a spanning tree.
Step 4: If it doesn’t form the cycle, then include that edge in MST. Otherwise, discard it.
Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.

*/