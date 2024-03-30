/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:44:37 by pollivie          #+#    #+#             */
/*   Updated: 2024/03/30 12:44:40 by pollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMLX_H
#define SMLX_H

#include "clib.h"
#include "mlx.h"
#include <math.h>

typedef void *t_handle;

typedef uint32_t t_color;

t_color color_create(char r, char g, char b, char a);
t_color color_adjust_lerp(t_color start, t_color end, float dist);

typedef struct s_vec2
{
	float x;
	float y;
} t_vec2;

t_vec2 vec2_create(float x, float y);
t_vec2 vec2_create_rotation_x(float angle);
t_vec2 vec2_create_rotation_y(float angle);
void   vec2_mult_scalar(t_vec2 *vec, float scalar);
void   vec2_mult_vec2(t_vec2 *a, t_vec2 *b, t_vec2 *c);
void   vec2_rot(t_vec2 *a, t_vec2 *r, t_vec2 *c);

void vec2_copy(t_vec2 *dest, t_vec2 *source);
void vec2_add(t_vec2 *a, t_vec2 *b, t_vec2 *c);
void vec2_sub(t_vec2 *a, t_vec2 *b, t_vec2 *c);
int  vec2_comp(t_vec2 *a, t_vec2 *b, int(fn)(float a, float b));

typedef struct s_vec3
{
	float x;
	float y;
	float z;

} t_vec3;

t_vec3 vec3_create(float x, float y, float z);
t_vec3 vec3_create_rotation_x(float angle);
t_vec3 vec3_create_rotation_y(float angle);
t_vec3 vec3_create_rotation_z(float angle);
void   vec3_mult_scalar(t_vec3 *vec, float scalar);
void   vec3_mult_vec3(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void   vec3_rot_x(t_vec3 *a, t_vec3 *r, t_vec3 *c);
void   vec3_rot_y(t_vec3 *a, t_vec3 *r, t_vec3 *c);
void   vec3_rot_z(t_vec3 *a, t_vec3 *r, t_vec3 *c);

void vec3_copy(t_vec3 *dest, t_vec3 *source);
void vec3_add(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void vec3_sub(t_vec3 *a, t_vec3 *b, t_vec3 *c);
int  vec3_comp(t_vec3 *a, t_vec3 *b, int(fn)(float a, float b));

typedef struct s_vec4
{
	float x;
	float y;
	float z;
	float w;
} t_vec4;

t_vec4 vec4_create(float x, float y, float z, float w);
t_vec4 vec4_create_rotation_x(float angle);
t_vec4 vec4_create_rotation_y(float angle);
t_vec4 vec4_create_rotation_z(float angle);
void   vec4_normalize_w(t_vec4 *q);
void   vec4_mult_scalar(t_vec4 *vec, float scalar);
void   vec4_mult_vec4(t_vec4 *a, t_vec4 *b, t_vec4 *c);
void   vec4_rot_x(t_vec4 *a, t_vec4 *r, t_vec4 *c);
void   vec4_rot_y(t_vec4 *a, t_vec4 *r, t_vec4 *c);
void   vec4_rot_z(t_vec4 *a, t_vec4 *r, t_vec4 *c);

void vec4_copy(t_vec4 *dest, t_vec4 *source);
void vec4_add(t_vec4 *a, t_vec4 *b, t_vec4 *c);
void vec4_sub(t_vec4 *a, t_vec4 *b, t_vec4 *c);
int  vec4_comp(t_vec4 *a, t_vec4 *b, int(fn)(float a, float b));

typedef struct s_camera
{
	float  fznear;
	float  fzfar;
	float  ffov;
	t_vec3 pos;

} t_camera;

typedef struct s_mat2x2
{
	float m[2][2];
} t_mat2x2;

t_mat2x2 *mat2_create(t_allocator *allocator, t_vec2 a, t_vec2 b);
t_mat2x2 *mat2_create_rotation(t_allocator *allocator, float angle);
void      mat2_mult_scalar(t_mat2x2 *m, float scalar);
void      mat2_mult_mat2(t_mat2x2 *a, t_mat2x2 *b, t_mat2x2 *c);
void      mat2_rot(t_mat2x2 *a, t_mat2x2 *r, t_mat2x2 *c);

typedef struct s_mat3x3
{
	float m[3][3];
} t_mat3x3;

t_mat3x3 *mat3_create(t_allocator *allocator, t_vec3 a, t_vec3 b, t_vec3 c);
t_mat3x3 *mat3_create_rotation(t_allocator *allocator, float angle);
void      mat3_mult_scalar(t_mat3x3 *m, float scalar);
void      mat3_mult_mat3(t_mat3x3 *a, t_mat3x3 *b, t_mat3x3 *c);
void      mat3_rot(t_mat3x3 *a, t_mat3x3 *r, t_mat3x3 *c);

typedef struct s_mat4x4
{
	float m[4][4];
} t_mat4x4;

t_mat4x4 *mat4_create(t_allocator *allocator, t_vec4 v[4]);
t_mat4x4 *mat4_create_rotation(t_allocator *allocator, float angle, t_vec3 axis);
void mat4_mult_scalar(t_mat4x4 *m, float scalar);
void mat4_mult_mat4(t_mat4x4 *a, t_mat4x4 *b, t_mat4x4 *c);
void mat4_rot(t_mat4x4 *a, t_mat4x4 *r, t_mat4x4 *c);

typedef struct s_triangle
{
	t_vec3 v[3];

} t_triangle;
t_triangle *triangle_create(t_allocator *allocator, t_vec3 vertices[3]);

typedef struct s_pixel
{
	int     x;
	int     y;
	t_color color;

} t_pixel;

void    pixel_put(t_pixel *pixel, char *out, uint screen_width);
t_pixel pixel_create(t_vec2 pos, uint color);
void    draw_line(t_pixel *a, t_pixel *b, char *pix, uint screen_width);



typedef struct s_screen
{
	int height;
	int width;

} t_screen;

typedef struct s_mesh
{
	uint64_t    capacity;
	uint64_t    size;
	t_triangle *buffer;

} t_mesh;

typedef struct s_renderer
{
	float    ffovrad;
	float    fznear;
	float    faspr;
	float    fzfar;
	float    ffov;
	t_mat4x4 mat;

} t_renderer;

typedef struct s_rasterizer
{
	t_renderer render;
	t_camera   cam;
	t_mesh    *raw;
	char      *out;

} t_rasterizer;

typedef struct s_smlx
{
	t_handle mlx;
	t_handle img;
	t_handle win;
	char    *pixels;

	t_rasterizer rast;
	t_renderer   rend;
	t_mesh      *map;
	t_screen     screen;
} t_smlx;

#endif
