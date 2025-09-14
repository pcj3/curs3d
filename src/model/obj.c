#include <stdlib.h>

#include "obj.h"
#include "vector3.h"
#include "face.h"

#define OBJ_LINE_BUFFER 128

#define OBJ_IDX_TO_MAT_IDX(x) ((U4)atoi((x))-1)

static void obj_setFaceAttrType(
    IN CH* word,
    OUT FACE_ATTR_t* p_faceAttr)
{
    if (!strchr(word, '/'))
    {
        *p_faceAttr = FACE_ATTR_VERTICES;
    }
    else if (strstr(word, "//"))
    {
        *p_faceAttr = FACE_ATTR_VERTICES_NORMALS;
    }
    else if (strchr(word, '/') == strrchr(word, '/'))
    {
        *p_faceAttr = FACE_ATTR_VERTICES_TEXTURES;
    }
    else
    {
        *p_faceAttr = FACE_ATTR_VERTICES_TEXTURES_NORMALS;
    }
}

static void obj_addAttrsToFace(
    IN CH* word,
    IN U1 faceIdx,
    INOUT FACE_ATTR_t* p_faceAttr,
    OUT FACE_t* p_face
)
{
    // Check if we need to find type of face content
    if (*p_faceAttr == FACE_ATTR_NONE)
    {
        obj_setFaceAttrType(word, p_faceAttr);
    }
    CH* p_word = word;
    switch (*p_faceAttr)
    {
    case FACE_ATTR_VERTICES_TEXTURES:
        p_face->idxVertices[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
        p_face->idxTextures[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
        break;
    case FACE_ATTR_VERTICES_NORMALS:
        p_face->idxVertices[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "//", &p_word));
        p_face->idxNormals[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "//", &p_word));
        break;
    case FACE_ATTR_VERTICES_TEXTURES_NORMALS:
        p_face->idxVertices[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
        p_face->idxTextures[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
        p_face->idxNormals[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
        break;
    case FACE_ATTR_VERTICES:
        p_face->idxVertices[faceIdx] = OBJ_IDX_TO_MAT_IDX(strtok_r(p_word, "/", &p_word));
    default:
        break;
    }

}

void obj_read_model(
    IN const CH* pkModelFileName,
    OUT MODEL_t* p_model)
{
    // Open obj file
    FILE* file = fopen(pkModelFileName, "r");
    if (file == NULL)
    {
        printf("Couldn't open obj file.\n");
        return;
    }

    // Clear model data
    memset(p_model, 0, sizeof(MODEL_t));

    // Prepare vars for parsing
    CH line[OBJ_LINE_BUFFER];
    CH* p_word;

    // Get ptrs from model
    VECTOR4_t* p_vertices   = p_model->vertices;
    VECTOR3_t* p_normals    = p_model->normals;
    VECTOR3_t* p_textures   = p_model->textures;

    FACE_t* p_faces = p_model->faces;

    // Get line
    while (fgets(line, OBJ_LINE_BUFFER, file)) {
        // Remove new line from the end of line
        line[strcspn(line, "\n")] = 0;

        // Get the first word and parse line type
        CH* word = strtok_r(line, " ", &p_word);
        // Check if valid
        if (word == NULL)
        {
            continue;
        }

        // Check if vertex line type
        if (!strcmp(word, "v"))
        {
            p_vertices->x = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_vertices->y = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_vertices->z = (R4) atof(strtok_r(NULL, " ", &p_word));
            word = strtok_r(NULL, " ", &p_word);
            if (word)
            {
                p_vertices->w = (R4) atof(word);
            }
            else
            {
                p_vertices->w = 1.f;
            }
            p_vertices++;
            p_model->numberVertices++;
        }
        // Check if texture line type
        else if (!strcmp(word, "vt"))
        {
            p_textures->x = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_textures->y = (R4) atof(strtok_r(NULL, " ", &p_word));
            word = strtok_r(NULL, " ", &p_word);
            if (word)
            {
                p_textures->z = (R4) atof(word);
            }
            p_textures++;
            p_model->numberTextures++;
        }
        // Check if normal line type
        else if (!strcmp(word, "vn"))
        {
            p_normals->x = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_normals->y = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_normals->z = (R4) atof(strtok_r(NULL, " ", &p_word));
            p_normals++;
            p_model->numberNormals++;
        }
        // Check if face line type
        else if (!strcmp(word, "f"))
        {
            word = strtok_r(NULL, " ", &p_word);
            U1 faceIdx = 0;
            while (word != NULL)
            {
                obj_addAttrsToFace(word, faceIdx, &p_model->faceAttr, p_faces);
                word = strtok_r(NULL, " ", &p_word);
                faceIdx++;
            }
            p_faces->numberVertices = faceIdx;
            p_model->numberFaces++;
            p_faces++;

        }
        // Rest of line types is not supported
        else
        {
            continue;
        }
    }
    // Close obj file
    fclose(file);
}

