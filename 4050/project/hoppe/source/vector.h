#pragma once

typedef struct
{
    float x;
    float y;
    float z;
} vec3;

void normalize(vec3 *);
void maxify_vec3(vec3 *);
void minify_vec3(vec3 *);

inline void zerify_vec3(vec3 *a)
{
    a->x = a->y = a->z = 0;
}

inline vec3 add_vec3(vec3 a, vec3 b)
{
    vec3 v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    v.z = a.z + b.z;
    return v;
}

inline vec3 sub_vec3(vec3 a, vec3 b)
{
    vec3 v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}

inline void acc_vec3(vec3 *a, vec3 b) // accumulate
{
    a->x += b.x;
    a->y += b.y;
    a->z += b.z;
}

inline void macc_vec3(vec3 *a, float s, vec3 b) // multiply and accumulate
{
    a->x = s * a->x + b.x;
    a->y = s * a->y + b.y;
    a->z = s * a->z + b.z;
}

inline void dwin_vec3(vec3 *a, vec3 b) // dwindle
{
    a->x -= b.x;
    a->y -= b.y;
    a->z -= b.z;
}

inline void scale_vec3(vec3 *a, float s)
{
    a->x *= s;
    a->y *= s;
    a->z *= s;
}

inline void min_vec3(vec3 *a, const vec3 *b)
{
    a->x = a->x < b->x ? a->x : b->x;
    a->y = a->y < b->y ? a->y : b->y;
    a->z = a->z < b->z ? a->z : b->z;
}

inline void max_vec3(vec3 *a, const vec3 *b)
{
    a->x = a->x > b->x ? a->x : b->x;
    a->y = a->y > b->y ? a->y : b->y;
    a->z = a->z > b->z ? a->z : b->z;
}

inline vec3 cross_vec3(vec3 a, vec3 b)
{
    vec3 v;
    v.x = a.y*b.z-a.z*b.y;
    v.y = a.z*b.x-a.x*b.z;
    v.z = a.x*b.y-a.y*b.x;
    return v;
}

inline vec3 midpoint(vec3 *verts, int a, int b)
{
    vec3 v;
    v.x = (verts[a].x + verts[b].x) / 2;
    v.y = (verts[a].y + verts[b].y) / 2;
    v.z = (verts[a].z + verts[b].z) / 2;
    return v;
}

inline vec3 lerp(vec3 *verts, float mu, int a, int b)
{
    vec3 v;
    v.x = mu * verts[a].x + (1 - mu) * verts[b].x;
    v.y = mu * verts[a].y + (1 - mu) * verts[b].y;
    v.z = mu * verts[a].z + (1 - mu) * verts[b].z;
    return v;
}
