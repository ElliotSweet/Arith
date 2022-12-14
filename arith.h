#ifndef _ARITH_H_
#define _ARITH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define A_PI32 3.1415926535f
#define A_PI64  3.141592653589793238462643383279
				
#define A_TAU32 6.283185307f
#define A_TAU64 6.283185307179586476925286766559

typedef float  real32_t;
typedef double real64_t;


extern uint8_t fCmp32(real32_t x, real32_t y);
extern uint8_t fCmp64(real64_t x, real64_t y);

real32_t Floor32(real32_t x);
real64_t Floor64(real64_t x);
real32_t Ceil32 (real32_t x);
real64_t Ceil64 (real64_t x);

extern int32_t	iAbs32(int32_t	x);
extern int64_t	iAbs64(int64_t	x);
extern real32_t	fAbs32(real32_t	x);
extern real64_t	fAbs64(real64_t	x);

extern int32_t	iMedian32(int32_t x, int32_t y);
extern int64_t	iMedian64(int64_t x, int64_t y);
extern real32_t	fMedian32(real32_t x, real32_t y);
extern real64_t	fMedian64(real64_t x, real64_t y);

extern real32_t	fSqrt32  (real32_t x);
extern real64_t	fSqrt64  (real64_t x);
extern real32_t	frSqrt32 (real32_t x); // reciprocal of the square root, or 1/sqrt
extern real64_t	frSqrt64 (real64_t x); // reciprocal of the square root, or 1/sqrt

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
extern inline Vector3 Vector3Sub  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Mul  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Div  (Vector3 x, Vector3 y);
extern inline Vector3 Vector3Addf (Vector3 x, float y);
extern inline Vector3 Vector3Subf (Vector3 x, float y);
extern inline Vector3 Vector3Mulf (Vector3 x, float y);
extern inline Vector3 Vector3Divf (Vector3 x, float y);
extern inline float	  Vector3Dot  (Vector3 x, Vector3 y);
extern inline float	  Vector3Len2 (Vector3 x);
extern inline float	  Vector3Len  (Vector3 x);
extern inline Vector3 Vector3Norm (Vector3 x);

extern inline Vector4 Vector4Add  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Sub  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Mul  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Div  (Vector4 v, Vector4 u);
extern inline Vector4 Vector4Addf (Vector4 v, float f);
extern inline Vector4 Vector4Subf (Vector4 v, float f);
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
extern Matrix2x2 Matrix2x2Sub   (Matrix2x2 x, Matrix2x2 y);
extern Matrix2x2 Matrix2x2Addf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2Subf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2Mulf  (Matrix2x2 x, float y);
extern Matrix2x2 Matrix2x2Divf  (Matrix2x2 x, float y);

extern Matrix3x3 Matrix3x3Add   (Matrix3x3 x, Matrix3x3 y);
extern Matrix3x3 Matrix3x3Sub   (Matrix3x3 x, Matrix3x3 y);
extern Matrix3x3 Matrix3x3Addf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3Subf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3Mulf  (Matrix3x3 x, float y);
extern Matrix3x3 Matrix3x3Divf  (Matrix3x3 x, float y);

extern Matrix4x4 Matrix4x4Add   (Matrix4x4 x, Matrix4x4 y);
extern Matrix4x4 Matrix4x4Sub   (Matrix4x4 x, Matrix4x4 y);
extern Matrix4x4 Matrix4x4Addf  (Matrix4x4 x, float y);
extern Matrix4x4 Matrix4x4Subf  (Matrix4x4 x, float y);
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