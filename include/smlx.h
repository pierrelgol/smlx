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
# define SMLX_H

# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

# define S_PI (3.14159265358979323846f)
# define S_2PI (2.0 * S_PI)
# define S_4PI (4.0 * S_PI)
# define S_HALF_PI (0.5 * S_PI)
# define S_QUARTER_PI (0.25 * S_PI)
# define S_ONE_OVER_PI (1.0 / S_PI)
# define S_SQRT_TWO (1.41421356237309504880f)
# define S_FLOAT_EPSILON (1.192092896e-07f)
# define S_DEG_TO_RAD_MULT (S_PI / 180.0f)
# define S_RAD_TO_DEG_MULT (180.0f / S_PI)
# define MIN_SCREEN_WIDTH 800
# define MIN_SCREEN_HEIGHT 600

typedef struct s_vec2
{
	float				data[2];
	union
	{
		struct
		{
			union
			{
				float	x;
				float	r;
				float	s;
			};
			union
			{
				float	y;
				float	g;
				float	t;
			};
		};
	};
}						t_vec2;

typedef struct s_vec3
{
	float				data[3];
	union
	{
		struct
		{
			union
			{
				float	x;
				float	r;
				float	s;
			};
			union
			{
				float	y;
				float	g;
				float	t;
			};
			union
			{
				float	z;
			};
		};
	};
}						t_vec3;

typedef struct s_vec4
{
	float				data[4];
	union
	{
		struct
		{
			union
			{
				float	x;
				float	r;
				float	s;
			};
			union
			{
				float	y;
				float	g;
				float	t;
			};
			union
			{
				float	z;
				float	b;
				float	p;
				float	width;
			};
			union
			{
				float	w;
				float	a;
				float	q;
				float	height;
			};
		};
	};
}						t_vec4;

typedef t_vec4			t_quat;

typedef union u_mat3x3
{
	float				data[12];
	t_vec3				rows[3];

}						t_mat3x3;

typedef union u_mat4x4
{
	float				data[16];
	t_vec4				rows[4];

}						t_mat4x4;

typedef struct s_camera
{
	t_vec3				position;
	t_vec3				euler_rotation;
	bool				is_dirty;
	t_mat4x4			view_matrix;
}						t_camera;

typedef enum e_matproj_type
{
	PROJECT_ORTHO,
	PROJECT_ISOME,
	PROJECT_PERSP,

}						t_matproj_type;

typedef struct s_view
{
	t_vec4				rect;
	float				fov;
	float				near_clip;
	float				far_clip;
	t_matproj_type		type;
	t_mat4x4			projection;

}						t_view;

typedef void			*t_handle;

typedef struct s_mlx_resources
{
	t_handle			mlx_ptr;
	t_handle			mlx_win;
	int32_t				win_height;
	int32_t				win_width;
	t_handle			mlx_img;
	int					img_lsize;
	int					img_bpp;
	int					img_height;
	int					img_width;
	int					img_endian;
	char				*img_pixels;
	bool				is_dirty;

}						t_mlx_resources;

void					*smlx_bzero(void *b, uint64_t len);
float					fmaxf(float a, float b);
float					fminf(float a, float b);
float					stepf(float edge, float x);
float					signf(float x);
float					rescale(float value, t_vec2 old_scale,
							t_vec2 new_scale);
float					fclipf(float x, float min, float max);
int32_t					clipi(int32_t x, int32_t min, int32_t max);
bool					float_compare(float f0, float f1);
float					deg_to_rad(float degrees);
float					rad_to_deg(float degrees);
void					u32_to_rgbu(uint32_t rgbu, uint32_t *out_r,
							uint32_t *out_g, uint32_t *out_b);
void					rgbu_to_u32(uint32_t r, uint32_t g, uint32_t b,
							uint32_t *out_u32);
//----------------------------------------------------------------------------//

/// creates a t_vec2 with value x and y
t_vec2					vec2_create(float x, float y);

/// returns a t_vec2 from a t_vec3 (x, y)(drop z)
t_vec2					vec2_from_vec3(t_vec3 v1);

/// returns a t_vec3 from a t_vec2 (x, y, z)
t_vec3					vec2_to_vec3(t_vec2 v1, float z);

/// creates a t_vec2 with value x and y set to 1.0f
t_vec2					vec2_create_1(void);

/// creates a t_vec2 with value x and y set to 0.0f
t_vec2					vec2_create_0(void);

/// creates a t_vec3 with value x, y and z set to {0,1}
t_vec2					vec2_up(void);

/// creates a t_vec2 with value x, y and z set to {0,-1}
t_vec2					vec2_down(void);

/// creates a t_vec2 with value x, y and z set to {-1,0}
t_vec2					vec2_left(void);

/// creates a t_vec2 with value x, y and z set to {1,0}
t_vec2					vec2_right(void);

/// returns a copy of vec
t_vec2					vec2_copy(t_vec2 vec);

/// add the x and y of v1 and v2 and returns the result
t_vec2					vec2_add(t_vec2 v1, t_vec2 v2);

/// sub the x and y of v1 and v2 and returns the result
t_vec2					vec2_sub(t_vec2 v1, t_vec2 v2);

/// div the x and y of v1 and v2 and returns the result
t_vec2					vec2_div(t_vec2 v1, t_vec2 v2);

/// mult the x and y of v1 and v2 and returns the result
t_vec2					vec2_mult(t_vec2 v1, t_vec2 v2);

/// mult the x and y of v1 by scalar and returns the result
t_vec2					vec2_mult_scalar(t_vec2 v1, float scalar);

/// mult the x and y of v1 and v2 and add v3 returns the result
t_vec2					vec2_mult_add(t_vec2 v1, t_vec2 v2, t_vec3 v3);

/// returns the result of x * x + y * y
float					vec2_len_square(t_vec2 vec);

/// returns the result of sqrt(x * x + y * y)
float					vec2_length(t_vec2 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
void					vec2_normalize(t_vec2 *vec);

/// normalize vec with it's length and return the copy vec  :
/// vec->x / (sqrt(x * x + y * y))
/// vec->y / (sqrt(x * x + y * y))
t_vec2					vec2_normalized(t_vec2 vec);

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool					vec2_compare(t_vec2 v1, t_vec2 v2, float tolerance);

/// returns the distance between v1 and v2
float					vec2_distance(t_vec2 v1, t_vec2 v2);

/// returns the squared distance of v1 and v2 (avoid sqrt)
float					vec2_ditance_squared(t_vec2 v1, t_vec2 v2);

//----------------------------------------------------------------------------//

/// creates a t_vec3 with value x, y and z
t_vec3					vec3_create(float x, float y, float z);

/// returns a t_vec3 from a t_vec4 with (x, y z) (drop w)
t_vec3					vec3_from_vec4(t_vec4 v1);

/// returns a t_vec4 from a t_vec3 with (x, y z, w)
t_vec4					vec3_to_vec4(t_vec3 v1, float w);

/// creates a t_vec3 with value x, y and z set to 1.0f
t_vec3					vec3_create_1(void);

/// creates a t_vec3 with value x, y and z set to 0.0f
t_vec3					vec3_create_0(void);

/// creates a t_vec3 with value x, y and z set to {0,1,0}
t_vec3					vec3_up(void);

/// creates a t_vec3 with value x, y and z set to {0,-1,0}
t_vec3					vec3_down(void);

/// creates a t_vec3 with value x, y and z set to {-1,0,0}
t_vec3					vec3_left(void);

/// creates a t_vec3 with value x, y and z set to {1,0,0}
t_vec3					vec3_right(void);

/// creates a t_vec3 with value x, y and z set to {0,0,-1}
t_vec3					vec3_forward(void);

/// creates a t_vec3 with value x, y and z set to {0,0,1}
t_vec3					vec3_backward(void);

/// returns a copy of vec
t_vec3					vec3_copy(t_vec3 vec);

/// add the x, y and z of v1 and v2 and returns the result
t_vec3					vec3_add(t_vec3 v1, t_vec3 v2);

/// sub the x, y and z of v1 and v2 and returns the result
t_vec3					vec3_sub(t_vec3 v1, t_vec3 v2);

/// div the x, y and z of v1 and v2 and returns the result
t_vec3					vec3_div(t_vec3 v1, t_vec3 v2);

/// div the x, y and z of v1 and v2 and returns the result
t_vec3					vec3_div_scalar(t_vec3 v1, float scalar);

/// mult the x, y and z of v1 and v2 and returns the result
t_vec3					vec3_mult(t_vec3 v1, t_vec3 v2);

/// mult the x, y and z of v1 with a scalar and returns the result
t_vec3					vec3_mult_scalar(t_vec3 v1, float scalar);

/// mult the x, y and z of v1 and v2 then add x, y,
/// z of v3 and returns the result 
t_vec3 vec3_mult_add(t_vec3 v1, t_vec3 v2,
	t_vec3 v3);

/// returns the result of x * x + y * y + z * z
float					vec3_len_square(t_vec3 vec);

/// returns the result of sqrt(x * x + y * y + z * z)
float					vec3_length(t_vec3 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
void					vec3_normalize(t_vec3 *vec);

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z))
/// vec->y / (sqrt(x * x + y * y + z * z))
/// vec->z / (sqrt(x * x + y * y + z * z))
t_vec3					vec3_normalized(t_vec3 vec);

/// returns the dot product between v1 and v2 (eg. difference in direction)
float					vec3_dot(t_vec3 v1, t_vec3 v2);

/// returns the cross product between v1 and v2 ak the othogonal vectors to v1 and v2
t_vec3					vec3_cross(t_vec3 v1, t_vec3 v2);

/// compare all elemtn of v1 and v2 and ensure the diff is within the tolerance
bool					vec3_compare(t_vec3 v1, t_vec3 v2, float tolerance);

/// returns the distance between v1 and v2
float					vec3_distance(t_vec3 v1, t_vec3 v2);

/// returns the squared distance between v1 and ve
float					vec3_distance_squared(t_vec3 v1, t_vec3 v2);

/// transform v by m (pass 1.0f in w for pont and 0.0f for a direction)
t_vec3					vec3_transform(t_vec3 v, float w, t_mat4x4 m);

/// returns a vector containing the minimum (x,y,z) of v1,v2
t_vec3					vec3_min(t_vec3 v1, t_vec3 v2);

/// returns a vector containing the maximum (x,y,z) of v1,v2
t_vec3					vec3_max(t_vec3 v1, t_vec3 v2);

/// returns a vector containing the sign (x,y,z) of v1
t_vec3					vec3_sign(t_vec3 v1);

/// returns a vector rotated by the quat q
t_vec3					vec3_rotate(t_vec3 v1, t_quat q);

//----------------------------------------------------------------------------//

/// creates a t_vec4 with value x, y, z and w
t_vec4					vec4_create(float x, float y, float z, float w);

/// creates a t_vec3 from a t_vec4 with value x, y, z (drop the w)
t_vec3					vec4_to_vec3(t_vec4 v1);

/// creates a t_vec4 from a t_vec3 with value x, y, z, w
t_vec4					vec4_from_vec3(t_vec3 v1, float w);

/// creates a t_vec4 with value x, y, z and w set to 1.0f
t_vec4					vec4_create_1(void);

/// creates a t_vec4 with value x, y, z and w set to 0.0f
t_vec4					vec4_create_0(void);

/// add and the x, y, z, and w of v1 and v2 and returns the result
t_vec4					vec4_add(t_vec4 v1, t_vec4 v2);

/// sub and the x, y, z, and w of v1 and v2 and returns the result
t_vec4					vec4_sub(t_vec4 v1, t_vec4 v2);

/// div and the x, y, z, and w of v1 and v2 and returns the result
t_vec4					vec4_div(t_vec4 v1, t_vec4 v2);

/// div the x, y, z, and w of v1 by scalar and returns the result
t_vec4					vec4_div_scalar(t_vec4 v1, float scalar);

/// mult and the x, y, z, and w of v1 and v2 and returns the result
t_vec4					vec4_mult(t_vec4 v1, t_vec4 v2);

/// mult the x, y, z, and w of v1 by scalar and returns the result
t_vec4					vec4_mult_scalar(t_vec4 v1, float scalar);

/// mult the x, y, z, and w of v1 by v2 and add v3 returns the result
t_vec4					vec4_mult_add(t_vec4 v1, t_vec4 v2, t_vec4 v3);

/// returns the result of x * x + y * y + z * z + w * w
float					vec4_len_square(t_vec4 vec);

/// returns the result of sqrt(x * x + y * y + z * z + w * w)
float					vec4_length(t_vec4 vec);

/// normalize vec with it's length :
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
void					vec4_normalize(t_vec4 *vec);

/// normalize vec with it's length and return the copy vec
/// vec->x / (sqrt(x * x + y * y + z * z + w * w))
/// vec->y / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
/// vec->z / (sqrt(x * x + y * y + z * z + w * w))
t_vec4					vec4_normalized(t_vec4 vec);

/// returns the dot product of v1 and v2
float					vec4_dot(t_vec4 v1, t_vec4 v2);

/// compare all data of v0 and v1 and ensure the difference is less than tolerance
bool					vec4_compare(t_vec4 v1, t_vec4 v2, float tolerance);

//----------------------------------------------------------------------------//

/// returns a "default" matrix
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
/// {0, 0, 0, 0}
t_mat4x4				mat4_create(void);

/// returns a "default" matrix
/// {1, 0, 0, 0}
/// {0, 1, 0, 0}
/// {0, 0, 1, 0}
/// {0, 0, 0, 1}
t_mat4x4				mat4_identity(void);

/// returns the result of multiplying matrix m1 and m2
t_mat4x4				mat4_mult(t_mat4x4 m1, t_mat4x4 m2);

/// returns an ortographic projection matrix
/// lrb is for (left, right, bottom)
/// tnf is for (top, near_clip, far_clip)
t_mat4x4				mat4_orthographic(t_vec3 lrb, t_vec3 tnf);

/// returns an perspective projection matrix
// t_vec2 fov_ar (fov_rad, aspect_ratio)
// t_vec2 nc_fc (near_clip, far_clip)
t_mat4x4				mat4_perspective(t_vec2 fov_ar, t_vec2 nc_fc);

/// creates and return a loot-at matrix for looking at target from the
/// perspective of the postion
/// @TODO verify correctness (kohi23 16:00)
t_mat4x4				mat4_look_at(t_vec3 pos, t_vec3 target, t_vec3 up);

/// returns a transposed copy of the provided matrix (row->columns)
t_mat4x4				mat4_transposed(t_mat4x4 mat);

/// returns the determinant of the provided matrix
float					mat4_determinant(t_mat4x4 m, float *o, float *t);

/// returns the inverse of the provided matrix
t_mat4x4				mat4_inverse(t_mat4x4 matrix);

/// returns a translation matrix from a t_vec3 postion
t_mat4x4				mat4_translation(t_vec3 position);

/// returns a scaling matrix from a t_vec3 scale
t_mat4x4				mat4_scale(t_vec3 scale);

/// returns a matrix to modify the angle of x
t_mat4x4				mat4_euler_x(float angle_radian);

/// returns a matrix to modify the angle of y
t_mat4x4				mat4_euler_y(float angle_radian);

/// returns a matrix to modify the angle of z
t_mat4x4				mat4_euler_z(float angle_radian);

/// returns a matrix to modify the angle of xyz
t_mat4x4				mat4_euler_xyz(float x_ar, float y_ar, float z_ar);

/// returns a forward vector relative to the provided matrix
t_vec3					mat4_forward(t_mat4x4 matrix);

/// returns a backward vector relative to the provided matrix
t_vec3					mat4_backward(t_mat4x4 matrix);

/// returns a upward vector relative to the provided matrix
t_vec3					mat4_up(t_mat4x4 matrix);

/// returns a downward vector relative to the provided matrix
t_vec3					mat4_down(t_mat4x4 matrix);

/// returns a left vector relative to the provided matrix
t_vec3					mat4_left(t_mat4x4 matrix);

/// returns a right vector relative to the provided matrix
t_vec3					mat4_right(t_mat4x4 matrix);

/// returns the position relative to the provided matrix
t_vec3					mat4_position(t_mat4x4 matrix);

//----------------------------------------------------------------------------//

t_quat					quat_identify(void);

/// returns the normal of a quat
float					quat_normal(t_quat q);

/// normalize the quat
void					quat_normalize(t_quat *q);

/// returns a normalized copy of the quat
t_quat					quat_normalized(t_quat q);

/// returns the conjugate copy of the quat
t_quat					quat_conjugate(t_quat q);

/// returns the inverse copy of the quat
t_quat					quat_inverse(t_quat q);

/// returns the result of the multiplication of q1 and q2
t_quat					quat_mult(t_quat q1, t_quat q2);

/// returns the rotation matrix of a rotation quaternion
t_mat4x4				quat_to_mat4(t_quat q);

/// returns the dot product of q1 and q2
float					quat_dot(t_quat q1, t_quat q2);

/// returns the rotation matrix corresponding to the quat
t_mat4x4				quat_to_rotation_matrix(t_quat q, t_vec3 center);

/// returns the quaternion equivalent form the vec3 and angle (normalized or not)
t_quat					quat_from_axis_angle(t_vec3 axis, float angle,
							bool normalize);

/// returns the quaternion equivalent of the slerp of q1 and q2 adjusted by factor p
t_quat					quat_slerp(t_quat q1, t_quat q2, float p);

// typedef struct s_camera
// {
// 	t_vec3	position;
// 	t_vec3	euler_rotation;
// 	bool	is_dirty;
// 	t_mat4x4 view_matrix;
// }t_camera;

//----------------------------------------------------------------------------//

/// returns a default camera
t_camera				camera_create(void);

/// reset the current camera to the default value
void					camera_reset(t_camera *c);

/// returns a copy of the current postion vector of the camera c
t_vec3					camera_position_get(t_camera *c);

/// sets the current postion vector of the camera c
void					camera_position_set(t_camera *c, t_vec3 position);

/// returns a copy of the current euler_rotation vector of the camera c
t_vec3					camera_euler_rotation_get(t_camera *c);

/// sets the current euler_rotation vector of the camera c
void					camera_euler_rotation_set(t_camera *c, t_vec3 rotation);

/// returns a copy of the current camera's view matrix
t_mat4x4				camera_view_matrix_get(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_forward(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_backward(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_left(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_right(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_up(t_camera *c);

/// returns a copy of the camera postion vector adjusted of a step
t_vec3					camera_down(t_camera *c);

/// moves the camera postin vector by the step
void					camera_move_forward(t_camera *c, float amount);

/// moves the camera postin vector by the step
void					camera_move_backward(t_camera *c, float amount);

/// moves the camera postin vector by the step
void					camera_move_left(t_camera *c, float amount);

/// moves the camera postin vector by the step
void					camera_move_right(t_camera *c, float amount);

/// moves the camera postin vector by the step
void					camera_move_up(t_camera *c, float amount);

/// moves the camera postin vector by the step
void					camera_move_down(t_camera *c, float amount);

/// adjust the current camera's pitch by the amount given
void					camera_pitch(t_camera *c, float amount);

/// adjust the current camera's yaw by the amount given
void					camera_yaw(t_camera *c, float amount);

//----------------------------------------------------------------------------//

void					view_create(t_vec4 rect, t_vec3 param,
							t_matproj_type type, t_view *out);
void					view_resize(t_view *v, t_vec4 rect);
void					view_destroy(t_view *v);

#endif
