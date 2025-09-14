#include "model.h"
#include "face.h"

void model_print(
    IN const MODEL_t* pk_model)
{   

    FILE* f = fopen("output.txt", "w");
    const FACE_t* pk_face = pk_model->faces;
    for (U4 i = 0; i < pk_model->numberFaces; i++, pk_face++)
    {   
        fprintf(f, "%lu face with %lu vertices and %d attrs \n", 
            i,
            pk_face->numberVertices,
            pk_model->faceAttr);
        for (U4 j = 0; j < pk_face->numberVertices; j++)
        {   
            U4 idx = pk_face->idxVertices[j];
            fprintf(f, " Vertex %lu -> X: %f Y: %f Z: %f W: %f\n", 
                idx,
                pk_model->vertices[idx].x,
                pk_model->vertices[idx].y,
                pk_model->vertices[idx].z,
                pk_model->vertices[idx].w
            );
        }
        for (U4 jj = 0; jj < pk_face->numberVertices; jj++)
        {   
            U4 idxa = pk_face->idxNormals[jj];
            fprintf(f, " Normal %lu -> X: %f Y: %f Z: %f\n", 
                idxa,
                pk_model->normals[idxa].x,
                pk_model->normals[idxa].y,
                pk_model->normals[idxa].z
            );
        }
    }
    fclose(f);
}

