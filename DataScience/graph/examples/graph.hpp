#ifndef GRAPH
#define GRAPH

template <class typeofVer, class TypeofEdge>
class graph{
    public:
        virtual void insert(typeofVer x, typeofVer y, TypeofEdge w)=0;
        virtual void remove(typeofVer x, typeofVer y)=0;
        virtual bool exist(typeofVer x, typeofVer y) const=0;
        int numOfVer() const {return Vers;}
        int numofEdge() const {return Edges;}

    protected:
    int Vers, Edges;
};

//基于邻接矩阵
template <class typeofVer, class TypeofEdge>
class adjMatrixGraph: public graph<typeofVer, TypeofEdge>{
    public:
        adjMatrixGraph(int vSize, const typeofVer d[], const TypeofEdge noEdgeFlag);
        ~adjMatrixGraph();
        bool exist(typeofVer x, typeofVer y) const;
        void insert(typeofVer x, typeofVer y, TypeofEdge w);
        void remove(typeofVer x, typeofVer y);

    private:
        typeofVer *ver;
        TypeofEdge **edge;
        TypeofEdge noEdge;
        int find(typeofVer v) const {for (int i=0; i<Vers; i++) if (ver[i]==v) return i;}
};

#endif