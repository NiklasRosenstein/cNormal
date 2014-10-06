#define DEBUG

#include "cNormal/cNormal.h"
#include <stdlib.h>

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
        cout << "\n\n.................................\n";
        cout << "Total allocations:      " << totalAllocs << endl;
        cout << "Total deallocations:    " << totalDeallc << endl;
        cout << "Total memory allocated: " << totalMemory << " Bytes" << endl;
}
#endif

#if 1 // print functions
    void print(cnVector v) {
        cout << "cnVector(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
    }
    void print(cnVertex v) {
        cout << "cnVertex {\n";
        cout << "    "; print(v.WORLD);
        cout << "    "; print(v.UV);
        cout << "}\n";
    }
    void print(cnMatrix m) {
        cout << "cnMatrix {\n";
        cout << "    "; print(m.T);
        cout << "    "; print(m.B);
        cout << "    "; print(m.N);
        cout << "    "; print(m.M);
        cout << "}\n";
    }
#endif

#if 1 // mesh creations
    cnMesh* cnConstructPlane() {
        cnMesh* mesh = new cnMesh(4, 2);
        mesh->point(0) = cnVector(0, 0, 0);
        mesh->point(1) = cnVector(0, 0, 100);
        mesh->point(2) = cnVector(100, 0, 100);
        mesh->point(3) = cnVector(100, 0, 0);

        mesh->uvpoint(0) = cnVector(0, 0);
        mesh->uvpoint(1) = cnVector(0, .5);
        mesh->uvpoint(2) = cnVector(.5, .5);
        mesh->uvpoint(3) = cnVector(.5, .5);

        mesh->polygon(0) = cnPolygon(0, 1, 2);
        mesh->polygon(1) = cnPolygon(0, 2, 3);
        return mesh;
    }
    #define cV cnVector
    #define cP cnPolygon
    cnMesh* cnConstructCube() {
        cnMesh* mesh = new cnMesh(8, 12);
        cnVertex verts[8] = {
            cnVertex( cV(-50, -50, -50), cV(0.649, 0.649) ),
            cnVertex( cV(-50,  50, -50), cV(0.018, 0.982) ),
            cnVertex( cV( 50, -50, -50), cV(0.649, 0.685) ),
            cnVertex( cV( 50,  50, -50), cV(0.315, 0.982) ),
            cnVertex( cV( 50, -50,  50), cV(0.649, 0.982) ),
            cnVertex( cV( 50,  50,  50), cV(0.315, 0.685) ),
            cnVertex( cV(-50, -50,  50), cV(0.351, 0.982) ),
            cnVertex( cV(-50,  50,  50), cV(0.649, 0.018) )
        };

        cnPolygon polys[12] = {
            cP(0, 1, 3), // 0
            cP(2, 3, 5), // 1
            cP(4, 5, 7), // 2
            cP(6, 7, 1), // 3
            cP(1, 7, 5), // 4
            cP(6, 0, 2), // 5
            cP(0, 3, 2), // 6
            cP(2, 5, 4), // 7
            cP(4, 7, 6), // 8
            cP(6, 1, 0), // 9
            cP(1, 5, 3), // 10
            cP(6, 2, 4)  // 11
        };

        for (int i = 0; i < 8; i++) {
            mesh->vertex(i) = verts[i];
        }

        for (int i = 0; i < 12; i++) {
            mesh->polygon(i) = polys[i];
        }

        delete verts;
        delete polys;

        return mesh;
    }
#endif

#if 1 // other stuff
    void cnTestComputeIntersection() {
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


void myMain() {
}
int main() {
    try {
        myMain();
    }
    catch (cnException& e) {
        cout << "\nException occured.\n";
    }
    end();
}










