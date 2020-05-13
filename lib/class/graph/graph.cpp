class graph
{
    public:
        int vertex, edge;
        di distance;
        graph();
        deque <di> gr;
    private:
        deque <bool> visited, used;
    public:
        void DFS(int u)
        {
            visited [u] = 1;
            for (int v = 0; v < gr [u].size(); v++)
            {
                if (!visited [v])
                    DFS(v);
            }
        }
        void BFS(int start)
        {
            queue<int> q;
            q.push(start);
            used [start] = 1;
            distance [start] = 0;
            while (!q.empty()) 
            {
                int cur = q.front();
                q.pop();
                //Здесь должна быть обработка текущей вершины.
                for (int v: gr[cur]) 
                {
                    if (!used[v]) {
                        q.push(v);
                        used[v] = 1;
                        distance [v] = distance [cur] + 1;
                    }
                }
            }
        }
};

graph::graph()
{
    cin >> vertex >> edge;
    gr.resize(vertex + 1);
    visited.resize(vertex + 1);
    used.resize(vertex + 1);
    distance.resize(vertex + 1);
    visited = {};
    distance = {};
    used = {};
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        gr [u].pb(v);
        gr [v].pb(u);
    }
}