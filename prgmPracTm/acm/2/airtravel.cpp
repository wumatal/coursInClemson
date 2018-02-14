#include <climits>
#include <iostream>
#include <fstream>
using namespace std;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[], int V)
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

int dijkstra_cost(int **graph, int V, int src, int dest) {
	int dist[V];     // The output array.  dist[i] will hold the shortest
                     // distance from src to i
  
	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
					// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V-1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet, V);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
								   && dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}

	return dist[dest];
}

int main() {
	int n, m, f, s, t;
	int min_cost;
	
	cin >> n >> m >> f >> s >> t;
	
	int e = m + f;
	int i, j;
	int **cost;
	cost = new int *[e];
	for(i = 0; i <e; i++)
		cost[i] = new int[e];
	//init
	for ( i=0; i<e; i++ )
		for ( j=0; j<e; j++)
			cost[i][j] = INT_MAX;
			
	int v_1, v_2, fee;
	// put roads in
	for ( i=0; i<m; i++) {
		cin >> v_1 >> v_2 >> fee;
		cost[v_1][v_2] = fee;
	}
	// put flights in
	for ( i=m; i<e; i++) {
		cin >> v_1 >> v_2;
		cost[v_1][v_2] = 0;
	}

	min_cost = dijkstra_cost(cost, e, s, t);
	cout << min_cost;
}
