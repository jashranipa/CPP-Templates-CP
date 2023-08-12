// Union by Size
class dsu
{
    private:
    int n; // no. of nodes in DSU. 
    vector<int>parent;
    vector<int>size1; 
    
    public:
    dsu(int n1) // parameterized constructor
    {
        n=n1;
        parent.resize(n+1);size1.resize(n+1);
        for(int i=0;i<=n;i++) // Works for both 0-based and 1-based.
        {
            parent[i]=i;
            size1[i]=1;
        }
    }

    int findPar(int node) // to check if in same group or not --> use findPar(), do not use parent[] array.
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node] = findPar(parent[node]); // doing path compression
    }
    
    bool find(int x,int y)
    {
        if(findPar(x)==findPar(y))
        {
            return 1;
        }
        return 0;
    }
    
    void unionBySize(int x,int y)
    {
        int u = findPar(x);
        int v = findPar(y);
        if(u==v)
        {
            return;
        }
        if(size1[u]>size1[v]) // doing union by size 
        {
            parent[v]=u;
            size1[u] += size1[v];
        }
        else
        {
            parent[u]=v;
            size1[v] += size1[u];
        }
    }

};
