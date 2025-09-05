#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "model.h"

void model_print_vertices(
    IN const MODEL_t* pk_model)
{
    const VECTOR3_t* pk_vertex = pk_model->vertices;
    for (U4 i = 0; i < pk_model->numberVertices; i++, pk_vertex++)
    {
        vector3_print(pk_vertex);
        printf("\n");
    }
}

