#ifndef MODEL_FACE_h
#define MODEL_FACE_h

#define FACE_MAX_VERTICES 5

typedef enum {
    FACE_ATTR_NONE,
    FACE_ATTR_VERTICES,
    FACE_ATTR_VERTICES_TEXTURES,
    FACE_ATTR_VERTICES_NORMALS,
    FACE_ATTR_VERTICES_TEXTURES_NORMALS
} FACE_ATTR_t;

typedef struct FACE_s
{
    U4 idxVertices[FACE_MAX_VERTICES];
    U4 idxNormals[FACE_MAX_VERTICES];
    U4 idxTextures[FACE_MAX_VERTICES];
    U4 numberVertices;
} FACE_t;





#endif // MODEL_FACE_h