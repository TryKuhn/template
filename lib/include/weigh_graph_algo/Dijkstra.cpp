void Dijkstra(int start)
{
    for (int i = 1; i <= vertex; i++) 
        distance [i] = MAX;
    distance [start] = 0;
    heap_Dijkstra q;
    q.push({0, start});
    while (!q.empty()) {
        pair<int, int> c = q.top();
        q.pop();
        int dst = c.first, v = c.second;
        if (distance [v] < dst) 
            continue;
        for (pair<int, int> e: gr[v]) {
            int u = e.first, len_vu = e.second;

            int n_dst = dst + len_vu;
            if (n_dst < distance [u]) {
                distance [u] = n_dst;
                q.push({n_dst, u});
            }
        }
    }
}