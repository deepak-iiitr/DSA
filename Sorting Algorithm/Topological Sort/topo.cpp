#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>> &graph){
    int V=graph.size();
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto it: graph[i]){
            inDegree[it]++;
        }
    }
    vector<int> sortedArr;
    queue<int> q;
    for(int i=0;i<V;i++){
        if(inDegree[i]==0){
            q.push(i);
            sortedArr.push_back(i);
            // cout<<"deepak"<<endl;
        }
    }

    while(!q.empty()){
        int currNode=q.front();
        q.pop();

        for(auto it: graph[currNode]){

            if((--inDegree[it])==0){
                q.push(it);
                sortedArr.push_back(it);
            }
        }

    }
    return sortedArr;

}
int main(){

    vector<vector<int>> graph(3);
    graph[0].push_back(1);
    graph[1].push_back(2);
    vector<int> sortedArr=topoSort(graph);
    for(auto it: sortedArr){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}