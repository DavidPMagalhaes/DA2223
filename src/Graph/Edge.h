//
// Created by bianca on 23/05/21.
//

#ifndef CAL_PROJ_EDGE_H
#define CAL_PROJ_EDGE_H

#include "Graph.h"
#include "Vertex.h"

using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

template <class T>
class Edge {
    // destination vertex
    double weight;         // edge weight
public:
    Edge(Vertex<T> *d, double w);
    friend class Graph<T>;
    friend class Vertex<T>;

    Vertex<T> * dest;
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {}


#endif //CAL_PROJ_EDGE_H
