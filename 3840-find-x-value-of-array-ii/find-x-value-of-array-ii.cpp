class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int n, K;
    vector<Node> tree;

    Node mergeNode(const Node& A, const Node& B) {
        Node C;

        C.prod = (A.prod * B.prod) % K;

        // Prefixes completely inside A
        for (int r = 0; r < K; r++) {
            C.pref[r] = A.pref[r];
        }

        // Prefixes that enter B
        for (int r = 0; r < K; r++) {
            int nr = (A.prod * r) % K;
            C.pref[nr] += B.pref[r];
        }

        return C;
    }

    void build(int p, int l, int r, vector<int>& nums) {

        if (l == r) {
            int rem = nums[l] % K;

            tree[p].prod = rem;
            tree[p].pref[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        build(p << 1, l, mid, nums);
        build(p << 1 | 1, mid + 1, r, nums);

        tree[p] = mergeNode(tree[p << 1], tree[p << 1 | 1]);
    }

    void update(int p, int l, int r, int idx, int value) {

        if (l == r) {
            int rem = value % K;

            tree[p].prod = rem;

            for (int i = 0; i < K; i++)
                tree[p].pref[i] = 0;

            tree[p].pref[rem] = 1;

            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(p << 1, l, mid, idx, value);
        else
            update(p << 1 | 1, mid + 1, r, idx, value);

        tree[p] = mergeNode(tree[p << 1], tree[p << 1 | 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr)
            return tree[p];

        int mid = (l + r) >> 1;

        if (qr <= mid)
            return query(p << 1, l, mid, ql, qr);

        if (ql > mid)
            return query(p << 1 | 1, mid + 1, r, ql, qr);

        Node left = query(p << 1, l, mid, ql, qr);
        Node right = query(p << 1 | 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        n = nums.size();
        K = k;

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // All possible remaining arrays are
            // non-empty prefixes of [start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.pref[x]);
        }

        return ans;
    }
};