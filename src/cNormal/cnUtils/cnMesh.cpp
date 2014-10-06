
// cnMesh.h implementation

#include "cnMesh.h"

#include <stdio.h>

cnMesh::cnMesh(uint vertexCount, uint polygonCount)
        : vertexCount(vertexCount),
          polygonCount(polygonCount) {
    verts = new cnVertexArray(vertexCount);
    polygons = new cnPolygonArray(polygonCount);
}

cnMesh::cnMesh(const cnMesh& other) {
    printf("Copy constructor called. !! \n");
    vertexCount = other.vertexCount;
    polygonCount = other.polygonCount;
    verts = other.verts->getCopy();
    polygons = other.polygons->getCopy();
}

cnMesh::cnMesh(const cnMesh* other) {
    vertexCount = other->vertexCount;
    polygonCount = other->polygonCount;
    verts = other->verts->getCopy();
    polygons = other->polygons->getCopy();
}

cnMesh::~cnMesh() {
    delete verts;
    delete polygons;
    verts = null;
    polygons = null;
    vertexCount = 0;
    polygonCount = 0;
}

cnVector& cnMesh::point(uint index) {
    return (*verts)[index].WORLD;
}

cnVector& cnMesh::uvpoint(uint index) {
    return (*verts)[index].UV;
}

cnVertex& cnMesh::vertex(uint index) {
    return (*verts)[index];
}

cnPolygon& cnMesh::polygon(uint index) {
    return (*polygons)[index];
}

uint cnMesh::getVertexCount() const {
    return vertexCount;
}

uint cnMesh::getPolygonCount() const {
    return polygonCount;
}
