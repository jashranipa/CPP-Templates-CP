// Union by Rank
class dsu
{
    private:
    int n; // no. of nodes in DSU. 
    vector<int>parent;
    vector<int>rank1; 
    
    public:
    dsu(int n1) // parameterized constructor
    {
        n=n1;
        parent.resize(n+1);rank1.resize(n+1);
        for(int i=0;i<=n;i++) // Works for both 0-based and 1-based.
        {
            parent[i]=i;
            rank1[i]=0;
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
    
    void union1(int x,int y)
    {
        int u = findPar(x);
        int v = findPar(y);
        if(u==v)
        {
            return;
        }
        if(rank1[u]>rank1[v]) // doing union by rank 
        {
            parent[v]=u;
        }
        else if(rank1[v]>rank1[u])
        {
            parent[u]=v;
        }
        else
        {
            parent[v]=u;
            rank1[u]++;
        }
    }

};
