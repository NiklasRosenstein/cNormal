
// This file contains functions to create several meshes.

#ifndef _CNORMAL_GENERATEMESH_H
#define _CNORMAL_GENERATEMESH_H

  #include "cnUtils/cnVector.h"
  #include "cnUtils/cnMesh.h"

  bool cnCreatePlane(cnMesh& mesh, uint useg, uint vseg, double udim, double vdim);
  bool cnCreateCube(cnMesh& mesh, cnVector size);

#endif /* _CNORMAL_GENERATEMESH_H */
