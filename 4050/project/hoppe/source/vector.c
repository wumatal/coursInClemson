#include "vector.h"
#include <math.h>
#include <float.h>

void normalize(vec3 *v)
{
    float mag2 = v->x * v->x + v->y * v->y + v->z * v->z;
    float mag = sqrtf(mag2);
    v->x /= mag;
    v->y /= mag;
    v->z /= mag;
}

void minify_vec3(vec3 *a)
{
    a->x = a->y = a->z = -FLT_MAX;
}

void maxify_vec3(vec3 *a)
{
    a->x = a->y = a->z = FLT_MAX;
}
