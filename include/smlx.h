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

typedef struct s_vec2
{
	float elements[2];
	union
	{
		struct
		{
			union
			{
				float x;
				float r;
				float s;
			};
			union
			{
				float y;
				float g;
				float t;
			};
		};
	};
} t_vec2;

typedef struct s_vec3
{
	float elements[3];
	union
	{
		struct
		{
			union
			{
				float x;
				float r;
				float s;
			};
			union
			{
				float y;
				float g;
				float t;
			};
			union
			{
				float z;
				float b;
				float p;
			};
		};
	};
} t_vec3;

typedef struct s_vec4
{
	float elements[4];
	union
	{
		struct
		{
			union
			{
				float x;
				float r;
				float s;
			};
			union
			{
				float y;
				float g;
				float t;
			};
			union
			{
				float z;
				float b;
				float p;
			};
			union
			{
				float w;
				float a;
				float q;
			};
		};
	};
} t_vec4;

typedef t_vec4 t_quat;

typedef union u_mat3x3
{
	float  elements[12];
	t_vec3 rows[3];

} t_mat3x3;

typedef union u_mat4x4
{
	float  elements[16];
	t_vec4 rows[4];

} t_mat4x4;

/// creates a t_vec2 with value x and y
t_vec2 vec2_create(float x, float y);

/// returns a t_vec2 from a t_vec3 (x, y)(drop z)
t_vec2 vec2_from_vec3(t_vec3 v1);

/// returns a t_vec3 from a t_vec2 (x, y, z)
t_vec3 vec2_to_vec3(t_vec2 v1, float z);

/// creates a t_vec2 with value x and y set to 1.0f
t_vec2 vec2_create_1(void);

/// creates a t_vec2 with value x and y set to 0.0f
t_vec2 vec2_create_0(void);

/// creates a t_vec3 with value x, y and z set to {0,1}
t_vec2 vec2_up(void);

/// creates a t_vec2 with value x, y and z set to {0,-1}
t_vec2 vec2_down(void);

/// creates a t_vec2 with value x, y and z set to {-1,0}
t_vec2 vec2_left(void);

/// creates a t_vec2 with value x, y and z set to {1,0}
t_vec2 vec2_right(void);

/// returns a copy of vec
t_vec2 vec2_copy(t_vec2 vec);

/// add the x and y of v1 and v2 and returns the result
t_vec2 vec2_add(t_vec2 v1, t_vec2 v2);

/// sub the x and y of v1 and v2 and returns the result
t_vec2 vec2_sub(t_vec2 v1, t_vec2 v2);

/// div the x and y of v1 and v2 and returns the result
t_vec2 vec2_div(t_vec2 v1, t_vec2 v2);

/// mult the x and y of v1 and v2 and returns the result
t_vec2 vec2_mult(t_vec2 v1, t_vec2 v2);

/// returns the result of x * x + y * y
float vec2_len_square(t_vec2 vec);

/// returns the result of sqrt(x * x + y * y)
float vec2_length(t_vec2 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
void vec2_normalize(t_vec2 *vec);

/// normalize vec with it's length and return the copy vec  :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
t_vec2 vec2_normalized(t_vec2 vec);

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool vec2_compare(t_vec2 v1, t_vec2 v2, float tolerance);

/// returns the distance between v1 and v2
float vec2_distance(t_vec2 v1, t_vec2 v2);

//----------------------------------------------------------------------------//

/// creates a t_vec3 with value x, y and z
t_vec3 vec3_create(float x, float y, float z);

/// returns a t_vec3 from a t_vec4 with (x, y z) (drop w)
t_vec3 vec3_from_vec4(t_vec4 v1);

/// returns a t_vec4 from a t_vec3 with (x, y z, w)
t_vec4 vec3_to_vec4(t_vec3 v1, float w);

/// creates a t_vec3 with value x, y and z set to 1.0f
t_vec3 vec3_create_1(void);

/// creates a t_vec3 with value x, y and z set to 0.0f
t_vec3 vec3_create_0(void);

/// creates a t_vec3 with value x, y and z set to {0,1,0}
t_vec3 vec3_up(void);

/// creates a t_vec3 with value x, y and z set to {0,-1,0}
t_vec3 vec3_down(void);

/// creates a t_vec3 with value x, y and z set to {-1,0,0}
t_vec3 vec3_left(void);

/// creates a t_vec3 with value x, y and z set to {1,0,0}
t_vec3 vec3_right(void);

/// creates a t_vec3 with value x, y and z set to {0,0,-1}
t_vec3 vec3_forward(void);

/// creates a t_vec3 with value x, y and z set to {0,0,1}
t_vec3 vec3_backward(void);

/// returns a copy of vec
t_vec3 vec3_copy(t_vec3 vec);

/// add the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_add(t_vec3 v1, t_vec3 v2);

/// sub the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_sub(t_vec3 v1, t_vec3 v2);

/// div the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_div(t_vec3 v1, t_vec3 v2);

/// mult the x, y and z of v1 and v2 and returns the result
t_vec3 vec3_mult(t_vec3 v1, t_vec3 v2);

/// mult the x, y and z of v1 with a scalar and returns the result
t_vec3 vec3_mult_scalar(t_vec3 v1, float scalar);

/// returns the result of x * x + y * y + z * z
float vec3_len_square(t_vec3 vec);

/// returns the result of sqrt(x * x + y * y + z * z)
float vec3_length(t_vec3 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
void vec3_normalize(t_vec3 *vec);

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
t_vec3 vec3_normalized(t_vec3 vec);

/// returns the dot product between v1 and v2 (eg. difference in direction)
float vec3_dot(t_vec3 v1, t_vec3 v2);

/// returns the cross product between v1 and v2 ak the othogonal vectors to v1 and v2
t_vec3 vec3_cross(t_vec3 v1, t_vec3 v2);

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool vec3_compare(t_vec3 v1, t_vec3 v2, float tolerance);

/// returns the distance between v1 and v2
float vec3_distance(t_vec3 v1, t_vec3 v2);

//----------------------------------------------------------------------------//

/// creates a t_vec4 with value x, y, z and w
t_vec4 vec4_create(float x, float y, float z, float w);

/// creates a t_vec3 from a t_vec4 with value x, y, z (drop the w)
t_vec3 vec4_to_vec3(t_vec4 v1);

/// creates a t_vec4 from a t_vec3 with value x, y, z, w
t_vec4 vec4_from_vec3(t_vec3 v1, float w);

/// creates a t_vec4 with value x, y, z and w set to 1.0f
t_vec4 vec4_create_1(void);

/// creates a t_vec4 with value x, y, z and w set to 0.0f
t_vec4 vec4_create_0(void);

/// add and the x, y, z, and w of v1 and v2 and returns the result
t_vec4 vec4_add(t_vec4 v1, t_vec4 v2);

/// sub and the x, y, z, and w of v1 and v2 and returns the result
t_vec4 vec4_sub(t_vec4 v1, t_vec4 v2);

/// div and the x, y, z, and w of v1 and v2 and returns the result
t_vec4 vec4_div(t_vec4 v1, t_vec4 v2);

/// mult and the x, y, z, and w of v1 and v2 and returns the result
t_vec4 vec4_mult(t_vec4 v1, t_vec4 v2);

/// returns the result of x * x + y * y + z * z + w * w
float vec4_len_square(t_vec4 vec);

/// returns the result of sqrt(x * x + y * y + z * z + w * w)
float vec4_length(t_vec4 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
void vec4_normalize(t_vec4 *vec);

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
t_vec4 vec4_normalized(t_vec4 vec);

/// returns the dot product of v1 and v2
float vec4_dot(t_vec4 v1, t_vec4 v2);

//----------------------------------------------------------------------------//

/// returns a "default" matrix
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
t_mat4x4 *mat4_create(t_allocator *allocator);

/// returns a "default" matrix
/// {1, 0, 0, 0}
/// {0, 1, 0, 0}
/// {0, 0, 1, 0}
/// {0, 0, 0, 1}
t_mat4x4 *mat4_identity(t_allocator *allocator);

/// returns the result of multiplying matrix m1 and m2
t_mat4x4 *mat4_mult(t_allocator *allocator, t_mat4x4 *m1, t_mat4x4 *m2);

/// returns an ortographic projection matrix
/// lrb is for (left, right, bottom)
/// tnf is for (top, near_clip, far_clip)
t_mat4x4 *mat4_orthographic(t_allocator *allocator, t_vec3 lrb, t_vec3 tnf);

/// returns an perspective projection matrix
// t_vec2 fov_ar (fov_rad, aspect_ratio)
// t_vec2 nc_fc (near_clip, far_clip)
t_mat4x4 *mat4_perspective(t_allocator *allocator, t_vec2 fov_ar, t_vec2 nc_fc);

/// creates and return a loot-at matrix for looking at target from the
/// perspective of the postion
/// @TODO verify correctness (kohi23 16:00)
t_mat4x4 *mat4_look_at(t_allocator *allocator, t_vec3 pos, t_vec3 target, t_vec3 up);

/// returns a transposed copy of the provided matrix (row->columns)
t_mat4x4 *mat4_transpose(t_allocator *allocat0r, t_mat4x4 *mat);

/// creates and returns the inverse value of a matrix
t_mat4x4 *mat4_inverse1(t_allocator *allocator, t_mat4x4 *matrix);

/// returns a translation matrix from a t_vec3 postion
t_mat4x4 *mat4_translation(t_allocator *allocator, t_vec3 position);

/// returns a scaling matrix from a t_vec3 scale
t_mat4x4 *mat4_scale(t_allocator *allocator, t_vec3 scale);

/// returns a matrix to modify the angle of x
t_mat4x4 *mat4_euler_x(t_allocator *allocator, float angle_radian);

/// returns a matrix to modify the angle of y
t_mat4x4 *mat4_euler_y(t_allocator *allocator, float angle_radian);

/// returns a matrix to modify the angle of z
t_mat4x4 *mat4_euler_z(t_allocator *allocator, float angle_radian);

/// returns a matrix to modify the angle of xyz
t_mat4x4 *mat4_euler_xyz(t_allocator *allocator, float x_ar, float y_ar, float z_ar);

/// returns a forward vector relative to the provided matrix
t_vec3 mat4_forward(t_mat4x4 *matrix);

/// returns a backward vector relative to the provided matrix
t_vec3 mat4_forward(t_mat4x4 *matrix);

/// returns a upward vector relative to the provided matrix
t_vec3 mat4_up(t_mat4x4 *matrix);

/// returns a downward vector relative to the provided matrix
t_vec3 mat4_down(t_mat4x4 *matrix);

/// returns a left vector relative to the provided matrix
t_vec3 mat4_left(t_mat4x4 *matrix);

/// returns a right vector relative to the provided matrix
t_vec3 mat4_right(t_mat4x4 *matrix);

//----------------------------------------------------------------------------//

t_quat quat_identify(void);

/// returns the normal of a quat
float quat_normal(t_quat q);

/// normalize the quat
void quat_normalize(t_quat *q);

/// returns a normalized copy of the quat
t_quat quat_normalized(t_quat q);

/// returns the conjugate copy of the quat
t_quat quat_conjugate(t_quat q);

/// returns the inverse copy of the quat
t_quat quat_inverse(t_quat q);

/// returns the result of the multiplication of q1 and q2
t_quat quat_mult(t_quat q1, t_quat q2);

/// returns the rotation matrix of a rotation quaternion
t_mat4x4 *quat_to_mat4(t_allocator *allocator, t_quat q);

#endif

