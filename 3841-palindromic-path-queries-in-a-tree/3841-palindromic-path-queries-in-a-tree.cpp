class FenwickTree {
    int n;
    vector<int> tree;
public:
    void init(int n) {
        this->n = n;
        tree.assign(n + 2, 0);
    }
    // Standard point update
    void add(int idx, int val) {
        for (++idx; idx <= n + 1; idx += idx & -idx) {
            tree[idx] ^= val;
        }
    }
    // Range XOR update: flips bits in range [l, r]
    void range_xor(int l, int r, int val) {
        add(l, val);
        add(r + 1, val);
    }
    // Point query: retrieves the accumulated XOR value at a specific index
    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum ^= tree[idx];
        }
        return sum;
    }
};


class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> depth, parent;
    vector<int> tin, tout;
    int timer;
    string s;

    int LOG = 18; // 18 is safe for N up to 2 * 10^5
    vector<vector<int>> up;
    FenwickTree bit;

    void dfs(int u, int p, int d, int current_mask) {
        parent[u] = p;
        depth[u] = d;
        tin[u] = timer++;
        current_mask ^= (1 << (s[u] - 'a'));
        
        // Seed the Fenwick tree with the initial mask for just this node position
        bit.range_xor(tin[u], tin[u], current_mask);

        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[u][i - 1] != -1)
                up[u][i] = up[up[u][i - 1]][i - 1];
            else
                up[u][i] = -1;
        }

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1, current_mask);
            }
        }
        tout[u] = timer - 1;
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != -1 && up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return parent[u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        adj.assign(n, vector<int>());
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        depth.assign(n, 0);
        parent.assign(n, -1);
        tin.assign(n, 0);
        tout.assign(n, 0);
        timer = 0;
        up.assign(n, vector<int>(LOG, -1));
        bit.init(n);

        // Precompute depths, LCA tables, and flatten the tree
        dfs(0, -1, 0, 0);

        vector<bool> answer;
        for (const string& q : queries) {
            if (q[0] == 'u') { // "update ui c"
                size_t space1 = q.find(' ', 7);
                int ui = stoi(q.substr(7, space1 - 7));
                char c = q.back();

                int old_val = s[ui] - 'a';
                int new_val = c - 'a';
                if (old_val != new_val) {
                    int diff_mask = (1 << old_val) ^ (1 << new_val);
                    s[ui] = c;
                    // O(log N) Range update covering the entire subtree of ui
                    bit.range_xor(tin[ui], tout[ui], diff_mask);
                }
            } else { // "query ui vi"
                size_t space1 = q.find(' ', 6);
                int ui = stoi(q.substr(6, space1 - 6));
                int vi = stoi(q.substr(space1 + 1));

                int lca = getLCA(ui, vi);
                
                // O(log N) Point queries to get the current masks from root
                int mask_ui = bit.query(tin[ui]);
                int mask_vi = bit.query(tin[vi]);
                
                int path_mask = mask_ui ^ mask_vi ^ (1 << (s[lca] - 'a'));
                int set_bits = __builtin_popcount(path_mask);
                answer.push_back(set_bits <= 1);
            }
        }
        return answer;
    }
};