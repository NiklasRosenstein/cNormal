#define DEBUG

#include "cNormal/cNormal.h"
#include "cNormal/cnGenerateMesh.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#if 1 // memory overview
    uint totalAllocs = 0;
    uint totalMemory = 0;
    uint totalDeallc = 0;
    void* operator new (size_t size) {
        totalAllocs++;
        totalMemory += size;
        return malloc(size);
    }
    void operator delete (void* p) {
        totalDeallc++;
        free(p);
    }
    void end() {
        using namespace std;
        printf("\n\n.................................\n");
        printf("Total allocations:      %u\n", totalAllocs);
        printf("Total deallocations:    %u\n", totalDeallc);
        printf("Total memory allocated: %u\n", totalMemory);
    }
#endif

#if 1 // print functions
    void print(cnVector v) {
        std::cout << "cnVector(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    }
    void print(cnVertex v) {
        using namespace std;
        cout << "cnVertex {\n";
        cout << "    "; print(v.WORLD);
        cout << "    "; print(v.UV);
        cout << "}\n";
    }
    void print(cnMatrix m) {
        using namespace std;
        cout << "cnMatrix {\n";
        cout << "    "; print(m.T);
        cout << "    "; print(m.B);
        cout << "    "; print(m.N);
        cout << "    "; print(m.M);
        cout << "}\n";
    }
#endif

#if 1 // other stuff
    void cnTestComputeIntersection() {
        using namespace std;

        cnVector v1(0),
                 v2(50, 0, 0),
                 v3(0, 0, 50);
        cnVector intersection;
        cnRay ray(cnVector(10, 100, 10),
                  cnVector(0, -1, 0));

        double t, u, v;

        for (int i = 0; i < 10; i++) {
            ray.setDirection(cnVector(0, -24, i));

            cout << "Rotating ray.\n";
            cout << "Ray direction: "; print(ray.getDirection());

            int r = cnComputeTriangleIntersection(ray,
                                                  v1, v2, v3,
                                                  t, u, v,
                                                  intersection);

            if (!r) {
                cout << "The ray does not intersect the triangle.\n";
            }
            else {
                cout << "Intersection at: "; print(intersection);
            }
            cout << "----------------------\n";
        }

    }
#endif

int main() {
    cnMesh mesh;
    if (!cnCreateCube(mesh, cnVector(100, 100, 100))) {
        std::cerr << "cnCreateCube() failed\n";
    }
    else {
        std::cout << "cnCreateCube() succeeded. " << mesh.getVertexCount() << " vertices, " << mesh.getPolygonCount() << " polygons.\n";
    }
    if (!cnCreatePlane(mesh, 10, 10, 100, 100)) {
        std::cerr << "cnCreatePlane() failed\n";
    }
    else {
        std::cout << "cnCreatePlane() succeeded. " << mesh.getVertexCount() << " vertices, " << mesh.getPolygonCount() << " polygons.\n";
    }
    return 0;
}










