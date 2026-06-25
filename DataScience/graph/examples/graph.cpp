#include "graph.hpp"

template <class typeofVer, class TypeofEdge>
adjMatrixGraph<typeofVer, TypeofEdge>::adjMatrixGraph(int vSize, const typeofVer d[], const TypeofEdge noEdgeFlag){
    Vers = vSize;
    Edges = 0;
    noEdge = noEdgeFlag;
    ver = new TypeofEdge[vSize];
    for (int i=0; i<vSize; i++) ver[i] = d[i];
}