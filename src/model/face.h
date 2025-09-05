#ifndef MODEL_FACE_h
#define MODEL_FACE_h

#define FACE_MAX_VERTICES 3


typedef struct FACE_s
{
    U4 idxVertices[FACE_MAX_VERTICES];
    U4 idxNormals[FACE_MAX_VERTICES];
    U4 idxTextures[FACE_MAX_VERTICES];
}FACE_t;




#endif // MODEL_FACE_h