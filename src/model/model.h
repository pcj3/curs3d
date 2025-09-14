#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "vector3.h"
#include "vector4.h"
#include "face.h"

#define MODEL_MAX_NAME 100
#define MODEL_MAX_VERTICES 100000
#define MODEL_MAX_FACES 100000

typedef struct MODEL_S
{
    VECTOR4_t   vertices[MODEL_MAX_VERTICES];
    VECTOR3_t   normals[MODEL_MAX_VERTICES];
    VECTOR3_t   textures[MODEL_MAX_VERTICES];

    FACE_t faces[MODEL_MAX_FACES];

    U4 numberFaces;
    U4 numberVertices;
    U4 numberNormals;
    U4 numberTextures;
    
    CH name[MODEL_MAX_NAME];
    FACE_ATTR_t faceAttr;
} MODEL_t;

void model_print(
    IN const MODEL_t* pk_model);

#endif //MODEL_MODEL_H