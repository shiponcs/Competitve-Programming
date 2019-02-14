#include <bits/stdc++.h>
using namespace std;
int vis[100][100];
string grid[100];
int r, c;
int dx[] = {0, 1, -1, 0}, dy[] = {-1, 0, 0, 1};
void dfs(int x, int y)
{
	if(vis[x][y]) return;
	//first, check if it crosses the range
	if( x < 0 || y < 0 || x >= r || y >= grid[x].size() ) return;
	//secondly, check if it hits wall
	if(grid[x][y] != '*' && grid[x][y] != '\n' && grid[x][y] != ' ') return;
	vis[x][y] = 1, grid[x][y] = '#';
	for(int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}

int main()
{
	int t, x, y;
	cin >> t;
	getchar();
	while(t){
		
		string ss;
		r = 0, c = 0;
		while( getline(cin, ss) && ss[0] != '_'){
			grid[r++] = ss;
			c = ss.size();
			//cout << ss;
			for(int i = 0; i < c; i++) 
				if(ss[i] == '*') x = r, y = c;
		}
		//for(int i = 0; i < r; ++i) cout << ss[i] << endl;
		
		memset(vis, 0, sizeof vis);
		t--;
		dfs(x, y);
		for(int i = 0; i < r; ++i) cout << ss[i] << endl;
	}
	
}
