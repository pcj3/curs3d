#include "defs.h"
#include "camera.h"
#include "trans.h"

void camera_setViewProjected(
    INOUT CAMERA_t* pCamera)
{   
    matrix44_multiply(&pCamera->matProjection,
        &pCamera->matView,
        &pCamera->matViewProjected);
}

void camera_setView(
    INOUT CAMERA_t* pCamera)
{   
    VECTOR3_t axisX = {1, 0, 0,};
    VECTOR3_t axisY = {0, 1, 0};
    VECTOR3_t axisZ = {0, 0, 1};

    matrix44_setToIdentity(&pCamera->matView);

    trans_rotateMatrix44ByVector3(&pCamera->matView,
        &axisX, 
        pCamera->vecRotation.x, 
        &pCamera->matView);
    trans_rotateMatrix44ByVector3(&pCamera->matView,
        &axisY, 
        pCamera->vecRotation.y, 
        &pCamera->matView);
    trans_rotateMatrix44ByVector3(&pCamera->matView,
        &axisZ, 
        pCamera->vecRotation.z, 
        &pCamera->matView);

    trans_tranlateMatrix44ByVector3(&pCamera->matView,
        &pCamera->vecPosition,
        &pCamera->matView);
}

void camera_setProjection(
    INOUT CAMERA_t* pCamera)
{   
    R4 tanHalfFov = tanf(pCamera->fieldOfView / 2);
    R4 planeDist = pCamera->planeFar  - pCamera->planeNear;
    matrix44_setToIdentity(&pCamera->matProjection);
    pCamera->matProjection.e00 = 1.f / (pCamera->aspectRatio * tanHalfFov);
    pCamera->matProjection.e11 = 1.f / tanHalfFov;
    pCamera->matProjection.e22 = - (pCamera->planeFar + pCamera->planeNear) / planeDist;
    pCamera->matProjection.e23 = - 1.f;
    pCamera->matProjection.e32 = - (2.f * pCamera->planeFar * pCamera->planeNear) / planeDist;
}