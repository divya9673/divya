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
