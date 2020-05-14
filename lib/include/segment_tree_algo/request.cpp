int tree_request(int v, int l, int r, int rl, int rr)
{
    if (rl > rr)
        return 0;
    if (l == rl && r == rr)
        return tree [v];
    int mid = (l + r) / 2;
    return tree_request(v * 2, l, mid, rl, min(mid, rr)) + tree_request(v * 2 + 1, mid + 1, r, max(mid + 1, rl), rr);
}