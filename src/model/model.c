#include "model.h"
#include "face.h"

void model_print(
    IN const MODEL_t* pk_model)
{
    const FACE_t* pk_face = pk_model->faces;
    for (U4 i = 0; i < pk_model->numberFaces; i++, pk_face++)
    {   
        printf("%lu face with %lu vertices\n", i, pk_face->numberVertices);
        for (U4 j = 0; j < pk_face->numberVertices; j++)
        {
            printf("%lu ", pk_face->idxVertices[j]);
        }
        printf("\n");
    }
}

