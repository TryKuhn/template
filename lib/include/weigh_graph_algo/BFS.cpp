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