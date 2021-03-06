const int N = 1e5;
bool is_art[N + 1];
int gid = 1, rch = 0, id[N], lo[N];
vector<int> adj[N];
vector<pair<int, int>> bridges;
void clear(int n){
  bridges.clear();
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
    id[i] = lo[i] = 0;
    is_art[i] = 0;
  }
}
// Resetear rch = 0, gid = 1
void dfs(int u, int p = -1){
  id[u] = lo[u] = gid++;
  for(int v : adj[u]){
    if (!id[v]) {
      if (p == -1) rch++;
      dfs(v, u);
      if (lo[v] >= id[u]) is_art[u] = 1;
      if (lo[v] > id[u]) bridges.pb({u, v});
      lo[u] = min(lo[u], lo[v]);
    } else if (v != p) lo[u] = min(lo[u], id[v]);
  }
  if (p == -1) is_art[u] = (rch > 1);
}
