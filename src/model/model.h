#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "vector3.h"
#include "face.h"

#include <stdio.h>


#define MODEL_MAX_NAME 100
#define MODEL_MAX_VERTICES 10
#define MODEL_MAX_FACES 100

#define FACE_IDX(x) (x-1)

typedef struct MODEL_S
{
    VECTOR3_t   vertices[MODEL_MAX_VERTICES];
    VECTOR3_t   normals[MODEL_MAX_VERTICES];
    VECTOR3_t   textures[MODEL_MAX_VERTICES];

    FACE_t faces[MODEL_MAX_FACES];

    U4 numberFaces;
    U4 numberVertices;
    U4 numberNormals;
    U4 numberTextures;

    CH name[MODEL_MAX_NAME];
    PAD(12);

} MODEL_t;

void model_print_vertices(
    IN const MODEL_t* pk_model);

#endif //MODEL_MODEL_H