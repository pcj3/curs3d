#include <stdlib.h>

#include "obj.h"
#include "vector3.h"
#include "face.h"

typedef enum {
    OBJ_FACE_NONE,
    OBJ_FACE_VERTICES,
    OBJ_FACE_VERTICES_TEXTURES,
    OBJ_FACE_VERTICES_NORMALS,
    OBJ_FACE_VERTICES_NORMALS_TEXTURES
} OBJ_FACE_CONTENT_t;

static void obj_update_face_content(
    IN CH* word,
    OUT OBJ_FACE_CONTENT_t* p_faceContent
)
{
    *p_faceContent = OBJ_FACE_VERTICES_NORMALS_TEXTURES;
}

static void obj_add_entry_to_face(
    IN CH* word,
    IN U1 faceIdx,
    INOUT OBJ_FACE_CONTENT_t* p_faceContent,
    OUT FACE_t* p_face
)
{
    // Check if we need to find type of face content
    if (*p_faceContent == OBJ_FACE_NONE)
    {
        obj_update_face_content(word, p_faceContent);
    }
    // CH wordCpy[10];
    // strcpy(wordCpy, word);
    // printf(wordCpy);
    CH* vertexIdx = strtok(word, "/");
    switch (*p_faceContent)
    {
    case OBJ_FACE_VERTICES:
        break;
    case OBJ_FACE_VERTICES_TEXTURES:
        break;
    case OBJ_FACE_VERTICES_NORMALS:
        break;
    case OBJ_FACE_VERTICES_NORMALS_TEXTURES:
        break;
    default:
        break;

    }

}

void obj_read_model(
    OUT MODEL_t* p_model)
{
    // Open obj file
    FILE* file = fopen("res/cube.obj", "r");
    if (file == NULL)
    {
        printf("Couldn't open obj file.\n");
        return;
    }

    // Clear model data
    memset(p_model, 0, sizeof(MODEL_t));

    // Prepare vars for parsing
    CH line[OBJ_LINE_BUFFER];
    CH lineCpy[OBJ_LINE_BUFFER];
    OBJ_FACE_CONTENT_t faceContent = OBJ_FACE_NONE;

    // Get ptrs from model
    VECTOR3_t* p_vertices   = p_model->vertices;
    // VECTOR3_t* p_normals    = p_model->normals;
    // VECTOR3_t* p_textures   = p_model->textures;

    FACE_t* p_faces = p_model->faces;
    // Get line
    while (fgets(line, OBJ_LINE_BUFFER, file)) {
        // Remove new line from the end of line
        line[strcspn(line, "\n")] = 0;

        //Copy line
        strcpy(lineCpy, line);

        // Get the first word and parse line type
        CH* word = strtok(line, " ");
        // Check if valid
        if (word == NULL)
        {
            continue;
        }

        // Check if vertex line type
        if (!strcmp(word, "v"))
        {
            p_vertices->e0 = atof(strtok(NULL, " "));
            p_vertices->e1 = atof(strtok(NULL, " "));
            p_vertices->e2 = atof(strtok(NULL, " "));

            p_vertices++;
            p_model->numberVertices++;
        }
        // Check if face line type
        else if (!strcmp(word, "f"))
        {
            strtok(lineCpy, " ");
            CH* subword = strtok(NULL, " ");
            U1 faceIdx = 0;
            while (subword != NULL)
            {
                printf("%d %s  ",faceIdx, subword);
                obj_add_entry_to_face(subword, faceIdx, &faceContent, p_faces);
                subword = strtok(NULL, " ");
                faceIdx++;
            }
            printf("\n");
            p_faces++;
            p_model->numberFaces++;
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

