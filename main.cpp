#include <vector>
#include <iostream>
#include <queue>
#include <limits>

using namespace std;

struct CompareFirst {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Min-heap: smallest distance has the highest priority
    }
};

// int main() {
//     int inf = numeric_limits<int>::max();

//     // Graph represented as an adjacency list with weights
//     vector<vector<pair<int, int>>> graph = {
//         {{1, 1}, {2, 3}},    // Neighbors for node 0
//         {{0, 1}, {4, 0}},    // Neighbors for node 1
//         {{0, 3},{3,4},{4,1}},            // Neighbors for node 2
//         {{2, 4}},            // Neighbors for node 3
//         {{1,0},{2,1}}                   // Neighbors for node 4
//     };

//     vector<int> distances(5, inf);
//     distances[0] = 0;
//     int source = 0;
//     priority_queue<vector<int>, vector<vector<int>>, CompareFirst> pq;
//     pq.push({0, 0});
    

//     while (!pq.empty()) {
//         int dist = pq.top()[1];
//         int node = pq.top()[0];
//         pq.pop();

       

//         for (auto& edge : graph[node]) {
//             int neighbor = edge.first;
//             int weight = edge.second;
//             if (distances[node] + weight < distances[neighbor]) {
//                 distances[neighbor] = distances[node] + weight;
//                 pq.push({neighbor,distances[neighbor]});
//             }
//         }
//     }

//     for (int i = 0; i < distances.size(); ++i) {
//         cout << "The distance to node " << i << " is: " << distances[i] << endl;
//     }

//     return 0;
// }
struct customComparator{
    bool operator()(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
};

int main(){
    // represent a graph with adjency list
    int inf = numeric_limits<int>::max();
    int V;
    cout << "please enter the number of vertices in your graph: "<< endl;
    cin >> V;
    vector<vector<vector<int>>> graph(V);
    for (int i = 0;i<V;i++){
        cout << "please enter the number of neighbors of "<< i <<endl;
        int n ; 
        cin >> n;
        while (n--){
            cout << "enter the "<<(n+1)<<"th neighbor then space then the weight "<< endl;
            int neighbor;
            int w;
            cin >> neighbor>>w;

            graph[i].push_back({neighbor,w});
        }
    }
    priority_queue<vector<int>,vector<vector<int>>,customComparator> pq;
    vector<int> distances(V,inf);
    int start;
    cout << "enter the source node label : "<<endl;
    cin >> start;
    distances[start] = 0;
    pq.push({start,0});
    while (!pq.empty()){
        int node = pq.top()[0];
        int weight = pq.top()[1];
        pq.pop();
        for (auto &edge : graph[node]){
            int neighbor = edge[0];
            int dist = edge[1];
            if (distances[neighbor]>distances[node]+dist){
                distances[neighbor]=distances[node]+dist;
                pq.push({neighbor,distances[neighbor]});
            }

        }
    }
    int i =0;
    for (auto &d : distances){
        cout << "the distance from "<<start<<" to "<<i<<" is "<<d<<endl;
    }







    return 0;
}