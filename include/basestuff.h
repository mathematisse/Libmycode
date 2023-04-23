/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base char functions
*/

#ifndef STUFF_H
    #define STUFF_H
    #include <stddef.h>

typedef unsigned char uchar_t;

typedef int int2_t[2];
typedef float float2_t[2];
typedef int int3_t[3];
typedef float float3_t[3];

typedef float transform_t[16];
typedef float quaternion_t[4];

typedef struct matrix_s matrix_t;
typedef struct filter_s filter_t;
typedef struct links_s link_t;
typedef struct panel_s panel_t;
typedef struct entity_s entity_t;

// function pointers typedefs for panels
typedef void (*panel_init_t)(panel_t *self);
typedef void (*panel_update_t)(panel_t *self);
typedef void (*panel_draw_t)(panel_t *self);
typedef void (*panel_event_t)(panel_t *self, sfEvent *event);
typedef void (*panel_destroy_t)(panel_t *self);

// function pointers typedefs for entities
typedef void (*entity_init_t)(entity_t *self);
typedef void (*entity_update_t)(entity_t *self);
typedef void (*entity_draw_t)(entity_t *self);
typedef void (*entity_event_t)(entity_t *self, sfEvent *event);
typedef void (*entity_destroy_t)(entity_t *self);

struct ctransform_s {
    transform_t value;
};

struct c

struct framebf_s {
    uchar_t *pixels;
    size_t width;
    size_t height;
    size_t pitch;
};

struct matrix_s {
    size_t rows;
    size_t cols;
    float *values;
};

struct filter_s {
    unsigned int belongs_to;
    unsigned int collides_with;
    int extra;
};

struct links_s {
    void *data;
    link_t *next;
};

struct panel_s {
    panel_t *parent;
    link_t *children;
    void *data;
    panel_init_t init;
    panel_update_t update;
    panel_draw_t draw;
    panel_event_t event;
    panel_destroy_t destroy;
};

struct entity_s {
    entity_t *parent;
    link_t *children;
    void *data;
    entity_init_t init;
    entity_update_t update;
    entity_draw_t draw;
    entity_event_t event;
    entity_destroy_t destroy;
};

typedef enum anchor_type_e anchor_type_t;
enum anchor_type_e {
    ANCHOR_NONE,
    ANCHOR_START,
    ANCHOR_MIDDLE,
    ANCHOR_END
};

enum resize_type_e {
    RESIZE_NONE = 0b00,
    RESIZE_X = 0b01,
    RESIZE_Y = 0b10,
    RESIZE_XY = 0b11
} resize_type_t;

typedef struct rectransform_s {
    float2_t pos;
    float2_t size;
    anchor_type_t xanchor;
    anchor_type_t yanchor;
    resize_type_t resize;
} rectransform_t;


#endif /* !STUFF_H */
