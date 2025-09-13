#ifndef MODEL_CAMERA_h
#define MODEL_CAMERA_h

#include "defs.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix44.h"

typedef struct CAMERA_s
{
    VECTOR3_t   vecPosition;
    VECTOR3_t   vecRotation;
    VECTOR3_t   vecLight;
    MATRIX44_t  matView;
    MATRIX44_t  matProjection;
    MATRIX44_t  matViewProjected;
    R4          aspectRatio;
    R4          fieldOfView;
    R4          planeNear;
    R4          planeFar;
} CAMERA_t;

void camera_setViewProjected(
    INOUT CAMERA_t* pCamera);

void camera_setView(
    INOUT CAMERA_t* pCamera);

void camera_setProjection(
    INOUT CAMERA_t* pCamera);

#endif // MODEL_CAMERA_h