#ifndef _ARITH_H_
#define _ARITH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


extern int32_t	iabs32(int32_t	x);
extern int64_t	iabs64(int64_t	x);
extern float	fabs32(float	x);
extern double	fabs64(double	x);

extern int32_t	imedian32(int32_t 	x, int32_t 	y);
extern int64_t	imedian64(int64_t 	x, int64_t 	y);
extern float	fmedian32(float  	x, float  	y);
extern double	fmedian64(double 	x, double 	y);

extern int		fcmp32(float  x, float  y);
extern int		fcmp64(double x, double y);

// reciprocal of the square root, or 1/sqrt
extern float	frsqrt32	(float x);
extern double	frsqrt64	(double x);
extern float	fsqrt32		(float x);
extern double	fsqrt64		(double x);

//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////

typedef struct {
	union  {
		struct { float x, y; };
		float elm[2];
	};
}Vector2;

typedef struct {
	union  {
		struct { float x, y, z; };
		float elm[3];
	};
}Vector3;

typedef struct {
	union  {
		struct { float x, y, z, w; };
		float elm[4];
	};
}Vector4;

#define Vector2Init(...)   (Vector2){ __VA_ARGS__ }
#define Vector3Init(...)   (Vector3){ __VA_ARGS__ }
#define Vector4Init(...)   (Vector4){ __VA_ARGS__ }

#define Vector2Initf(x) Vector2Init(x, x)
#define Vector3Initf(x) Vector3Init(x, x, x)
#define Vector4Initf(x) Vector4Init(x, x, x, x)

extern inline Vector2 Vector2Add  (Vector2 x, Vector2 y);
extern inline Vector2 Vector2Sub  (Vector2 x, Vector2 y);
extern inline Vector2 Vector2Mul  (Vector2 x, Vector2 y);
extern inline Vector2 Vector2Div  (Vector2 x, Vector2 y);
extern inline Vector2 Vector2Addf (Vector2 x, float y);
extern inline Vector2 Vector2Subf (Vector2 x, float y);
extern inline Vector2 Vector2Mulf (Vector2 x, float y);
extern inline Vector2 Vector2Divf (Vector2 x, float y);
extern inline float   Vector2Dot  (Vector2 x, Vector2 y);
extern inline float   Vector2Len2 (Vector2 x);
extern inline float   Vector2Len  (Vector2 x);
extern inline Vector2 Vector2Norm (Vector2 x);

extern inline Vector3 Vector3Add  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3sub  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Mul  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Div  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Addf (Vector3 x, float y);
extern inline Vector3 Vector3subf (Vector3 x, float y);
extern inline Vector3 Vector3Mulf (Vector3 x, float y);
extern inline Vector3 Vector3Divf (Vector3 x, float y);
extern inline float	  Vector3Dot  (Vector3 x, Vector3 y);
extern inline float	  Vector3Len2 (Vector3 x);
extern inline float	  Vector3Len  (Vector3 x);
extern inline Vector3 Vector3Norm (Vector3 x);

extern inline Vector4 Vector4Add  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4sub  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Mul  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Div  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Addf (Vector4 v, float f);
extern inline Vector4 Vector4subf (Vector4 v, float f);
extern inline Vector4 Vector4Mulf (Vector4 v, float f);
extern inline Vector4 Vector4Divf (Vector4 v, float f);
extern inline float   Vector4Dot  (Vector4 v, Vector4 u);
extern inline float   Vector4Len2 (Vector4 v);
extern inline float   Vector4Len  (Vector4 v);
extern inline Vector4 Vector4Norm (Vector4 x);


//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////


typedef union {
	Vector2	vec[2];
	float	mat[2][2];
	float	elm[4];
} Matrix2x2;

typedef union {
	Vector3	vec[3];
	float	mat[3][3];
	float	elm[9];
} Matrix3x3;

typedef union {
	Vector4	vec[4];
	float	mat[4][4];
	float	elm[16];
} Matrix4x4;

// ID component (diagonal matrix of 1's. top-right to bottom-left)
extern Matrix2x2 Matrix2x2Id (void);
extern Matrix3x3 Matrix3x3Id (void);
extern Matrix4x4 Matrix4x4Id (void);

// Add the diagonal components (top-right to bottom-left)
extern float Matrix2x2Trace (Matrix2x2 x);
extern float Matrix3x3Trace (Matrix3x3 x);
extern float Matrix4x4Trace (Matrix4x4 x);

// ID Vector where the vector input is the bottom matrix.
extern Matrix2x2 Matrix2x2Translate (Vector2 v);
extern Matrix3x3 Matrix3x3Translate (Vector3 v);
extern Matrix4x4 Matrix4x4Translate (Vector4 v);

extern Matrix2x2 Matrix2x2Add   (Matrix2x2 x, Matrix2x2 y);
extern Matrix2x2 Matrix2x2sub   (Matrix2x2 x, Matrix2x2 y);
extern Matrix2x2 Matrix2x2Addf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2subf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2Mulf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2Divf  (Matrix2x2 x, float y);

extern Matrix3x3 Matrix3x3Add   (Matrix3x3 x, Matrix3x3 y);
extern Matrix3x3 Matrix3x3sub   (Matrix3x3 x, Matrix3x3 y);
extern Matrix3x3 Matrix3x3Addf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3subf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3Mulf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3Divf  (Matrix3x3 x, float y);

extern Matrix4x4 Matrix4x4Add   (Matrix4x4 x, Matrix4x4 y);
extern Matrix4x4 Matrix4x4sub   (Matrix4x4 x, Matrix4x4 y);
extern Matrix4x4 Matrix4x4Addf  (Matrix4x4 x, float y);
extern Matrix4x4 Matrix4x4subf  (Matrix4x4 x, float y);
extern Matrix4x4 Matrix4x4Mulf  (Matrix4x4 x, float y);
extern Matrix4x4 Matrix4x4Divf  (Matrix4x4 x, float y);


extern Matrix2x2 Matrix2x2Mul (Matrix2x2 a, Matrix2x2 b);
extern Matrix3x3 Matrix3x3Mul (Matrix3x3 a, Matrix3x3 b);
extern Matrix4x4 Matrix4x4Mul (Matrix4x4 a, Matrix4x4 b);

extern Matrix2x2 Matrix2x2Transpose (Matrix2x2 x);
extern Matrix3x3 Matrix3x3Transpose (Matrix3x3 x);
extern Matrix4x4 Matrix4x4Transpose (Matrix4x4 x);




#ifdef __cplusplus
}
#endif 

#endif // _vectorTRON_H_