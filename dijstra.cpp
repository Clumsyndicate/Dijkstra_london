#include <iostream>
#include <stdio.h>

using namespace std;
#define INF 9999
#define max 5

void dijkstra(int G[max][max], int n, int startnode);

int main() {
	int G[max][max]={{0,1,0,3,10},{1,0,5,0,0},{0,5,0,2,1},{3,0,2,0,6},{10,0,1,6,0}};
	int n=5;
	int u=0;
	dijkstra(G,n,u);
}


void dijkstra(int G[max][max], int n, int startnode) {
	int cost[max][max], distance[max], pred[max];
	int visited[max], count, mindistance, nextnode, i, j;
	for (i=0; i<n; i++) 
		for (j=0; j<n; j++)
			if (G[i][j]==0) 
				cost[i][j] = INF;
			else 
				cost[i][j] = G[i][j];
	// Initialize nodes
	for (i=0; i<n; i++) {
		distance[i] = cost[startnode][i];
		pred[i]=startnode;
		visited[i] = 0;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while (count<n-1) {
		mindistance = INF;
		for (i=0; i<n; i++)
			if (distance[i]<mindistance  && !visited[i]) {
				mindistance = distance[i];
				nextnode = i;
			}
		visited[nextnode]=1;
		for (i=0; i<n; i++) 
			if ((!visited[i]) && (mindistance + cost[nextnode][i]<distance[i] )) {
				distance[i]=mindistance + cost[nextnode][i];
			}
			count++;
	}
	for (i=0; i<n; i++) 
	if (i!= startnode) {
		cout<<"\n Distance of node" << i << "=" << distance[i];
		cout<<"\nPath="<<i;
		j=i;
		do {
			j=pred[j];
			cout<<"<-" << j;
		} while (j!=startnode);
	}
}
