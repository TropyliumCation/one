#include <bits/stdc++.h>
using namespace std;

class bfsofgraph
{
public:
	// Function to return Breadth First Traversal of given graph.
	// adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
	vector<int> bfs(vector<vector<int>> &adj)
	{
		int n = adj.size();
		int vis[n] = {0};
		vis[0] = 1;
		queue<int> q;
		q.push(0);
		vector<int> bfs;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			bfs.push_back(node);

			for (auto it : adj[node])
			{
				if (!vis[it])
				{
					vis[it] = 1;
					q.push(it);
				}
			}
		}
		return bfs;
	}
};

class dfsofgraph
{
public:
	void dfsfunc(int node, vector<vector<int>> &adj, int vis[], vector<int> &ls)
	{
		vis[node] = 1;
		ls.push_back(node);
		for (auto it : adj[node])
		{
			if (!vis[it])
			{
				dfsfunc(it, adj, vis, ls);
			}
		}
	}
	vector<int> dfs(vector<vector<int>> &adj)
	{
		int n = adj.size();
		int vis[n] = {0};
		vector<int> ls;
		dfsfunc(0, adj, vis, ls);
		return ls;
	}
};

class numberofprovinces
{
public:
	void bfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
	{
		int n = isConnected.size();
		vis[node] = 1;
		queue<int> q;
		q.push(node);

		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int it = 0; it < n; ++it)
			{
				if (isConnected[x][it] == 1 && !vis[it])
				{
					vis[it] = 1;
					q.push(it);
				}
			}
		}
	}
	void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
	{
		vis[node] = 1;
		for (int i = 0; i < isConnected.size(); i++)
		{
			if (isConnected[node][i] && !vis[i])
			{
				dfs(i, isConnected, vis);
			}
		}
	}

	int findCircleNum(vector<vector<int>> &isConnected)
	{
		int provinces = 0;
		int n = isConnected.size();
		vector<int> vis(n, 0);

		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
			{
				provinces++;
				dfs(i, isConnected, vis);
			}
		}

		return provinces;
	}
};
