
// cnMesh.h implementation

#include "cnMesh.h"

#include <stdio.h>

cnMesh::cnMesh(uint vertexCount, uint polygonCount)
: verts(vertexCount), polygons(polygonCount) {

}

cnMesh::cnMesh(const cnMesh& other) {
    verts = other.verts;
    polygons = other.polygons;
}

cnMesh::cnMesh(const cnMesh* other) {
    verts = other->verts;
    polygons = other->polygons;
}

cnMesh::~cnMesh() {
}

cnVector& cnMesh::point(uint index) {
    return verts[index].WORLD;
}

const cnVector& cnMesh::point(uint index) const {
    return verts[index].WORLD;
}

cnVector& cnMesh::uvpoint(uint index) {
    return verts[index].UV;
}

const cnVector& cnMesh::uvpoint(uint index) const {
    return verts[index].UV;
}

cnVertex& cnMesh::vertex(uint index) {
    return verts[index];
}

const cnVertex& cnMesh::vertex(uint index) const {
    return verts[index];
}

cnPolygon& cnMesh::polygon(uint index) {
    return polygons[index];
}

const cnPolygon& cnMesh::polygon(uint index) const {
    return polygons[index];
}

uint cnMesh::getVertexCount() const {
    return verts.size();
}

uint cnMesh::getPolygonCount() const {
    return polygons.size();
}
