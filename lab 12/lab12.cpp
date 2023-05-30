#include <iostream>
#include<limits>
#include <limits.h>
using namespace std;

// Number of vertices in the graph
#define V 6

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	cout << "city \t\t Distance from Source city" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src, float avg_list[])
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

    float avg = 0;
    for(int i=0;i<6;i++) avg = avg + dist[i]/6.0;
    avg_list[src]=avg;


	// print the constructed distance array
    cout << "----------------------------------------------------" << endl;
    cout << "source city is city " << src << endl;
	printSolution(dist);
    cout << "____________________________________________________" << endl;
    cout << "average time taken form source city to a city =" << avg << endl;
    cout << "----------------------------------------------------" << endl;
}

// driver's code
int main()
{

	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 10, 0, 0, 15, 5},
						{ 10, 0, 10, 30, 0, 0},
						{ 0, 10, 0, 12, 5, 0},
						{ 0, 30, 12, 0, 0, 20},
						{ 15, 0, 5, 0, 0, 0},
						{ 5, 0, 0, 20, 0, 0}};

	// Function call
    //dijkstra(graph, 5);
    float min_avg = 10000000;
    float avg_list[6];
    for(int i=0; i<6; i++) dijkstra(graph, i, avg_list);
    for(int i=0; i<6; i++) if(min_avg>avg_list[i]) min_avg = avg_list[i];

    cout << "overall minimum average time taken = " << min_avg << endl;
    cout << "best city/cities to build hospital :" << endl;
    for(int i=0; i<6; i++) if(avg_list[i]==min_avg) cout << "city " << i << endl;
	

	return 0;
}

