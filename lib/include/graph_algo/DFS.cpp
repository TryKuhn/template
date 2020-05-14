void DFS(int u)
{
    visited [u] = 1;
    for (int v = 0; v < gr [u].size(); v++)
    {
        if (!visited [v])
            DFS(v);
    }
}