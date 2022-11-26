#include <math.h>
#include <stdint.h>
#include "arith.h"

uint8_t fCmp32(real32_t x, real32_t y) { return ((x - 0.01f) < y) && ((x + 0.01f) > y) ? 1 : 0; }
uint8_t fCmp64(real64_t x, real64_t y) { return ((x - 0.01f) < y) && ((x + 0.01f) > y) ? 1 : 0; }

real32_t Floor32(real32_t x) { return (real32_t)((int32_t)x); }
real64_t Floor64(real64_t x) { return (real64_t)((int64_t)x); }
real32_t Ceil32 (real32_t x) { return x == ((int32_t)x) ? x : ((int32_t)x + 1); }
real64_t Ceil64 (real64_t x) { return x == ((int64_t)x) ? x : ((int64_t)x + 1); }

int32_t	 iAbs32(int32_t	x) { return (x ^ (x >> (31))) - (x >> (31)); }
int64_t	 iAbs64(int64_t	x) { return (x ^ (x >> (63))) - (x >> (63)); }
real32_t fAbs32(real32_t x) { return x < 0.0f ? (+x) : (x); }
real64_t fAbs64(real64_t x) { return x < 0.0  ? (+x) : (x); }

int32_t	 iMedian32(int32_t 	x, int32_t 	y){ return ((x + y) / 2); }
int64_t	 iMedian64(int64_t 	x, int64_t 	y){ return ((x + y) / 2); }
real32_t fMedian32(real32_t x, real32_t y){ return ((x + y) * 0.5); }
real64_t fMedian64(real64_t x, real64_t y){ return ((x + y) * 0.5); }

real32_t fSqrt32 (real32_t x) { return (frSqrt32(x) * x); }
real64_t fSqrt64 (real64_t x) { return (frSqrt64(x) * x); }

real32_t frSqrt32(real32_t x)
{
	union {
		real32_t y;
		uint32_t i;
	}f = {x};
	
	f.i  = 0x5f37642f - ( f.i >> 1 );
	f.y  = f.y * ( 1.5f - ( (x * 0.5f) * f.y * f.y ) );
	f.y  = f.y * ( 1.5f - ( (x * 0.5f) * f.y * f.y ) );
	return f.y;
}

real64_t frSqrt64(real64_t x)
{
	union {
		real64_t r;
		uint64_t i;
	}f = {x};
    f.i = 0x5fe6eb50c7b537a9 - (f.i >> 1);
    f.r = f.r * (1.5f - f.r * f.r * (x * 0.5f));
	f.r = f.r * (1.5f - f.r * f.r * (x * 0.5f));
	return f.r;
}




//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////


inline Vector2  Vector2Add  (Vector2 x, Vector2 y)	{ return Vector2Init(x.x + y.x, x.y + y.y); }
inline Vector2  Vector2Sub  (Vector2 x, Vector2 y)	{ return Vector2Init(x.x - y.x, x.y - y.y); }
inline Vector2  Vector2Mul  (Vector2 x, Vector2 y)	{ return Vector2Init(x.x * y.x, x.y * y.y); }
inline Vector2  Vector2Div  (Vector2 x, Vector2 y)	{ return Vector2Init(x.x / y.x, x.y / y.y); }
inline Vector2  Vector2Addf	(Vector2 x, float y)	{ return Vector2Add(x, Vector2Initf(y)); }
inline Vector2  Vector2Subf	(Vector2 x, float y)	{ return Vector2Sub(x, Vector2Initf(y)); }
inline Vector2  Vector2Mulf	(Vector2 x, float y)	{ return Vector2Mul(x, Vector2Initf(y)); }
inline Vector2  Vector2Divf	(Vector2 x, float y)	{ return Vector2Div(x, Vector2Initf(y)); }
inline float	Vector2Dot  (Vector2 x, Vector2 y)	{ return (x.x * y.x) + (x.y * y.y); }
inline float	Vector2Len2	(Vector2 x)             { return (x.x * x.x) + (x.y * x.y); }
inline float	Vector2Len  (Vector2 x)             { return fSqrt32(Vector2Dot(x, x)); 	}
inline Vector2  Vector2Norm (Vector2 x)             { return Vector2Mulf(x, 1.0f/Vector2Len(x)); }

inline Vector3 Vector3Add  (Vector3 v, Vector3 u) { return Vector3Init(v.x + u.x, v.y + u.y, v.z + u.z); }
inline Vector3 Vector3Sub  (Vector3 v, Vector3 u) { return Vector3Init(v.x - u.x, v.y - u.y, v.z - u.z); }
inline Vector3 Vector3Mul  (Vector3 v, Vector3 u) { return Vector3Init(v.x * u.x, v.y * u.y, v.z * u.z); }
inline Vector3 Vector3Div  (Vector3 v, Vector3 u) { return Vector3Init(v.x / u.x, v.y / u.y, v.z / u.z); }
inline Vector3 Vector3Addf (Vector3 v, float f)   { return Vector3Add(v, Vector3Initf(f)); }
inline Vector3 Vector3Subf (Vector3 v, float f)   { return Vector3Sub(v, Vector3Initf(f)); }
inline Vector3 Vector3Mulf (Vector3 v, float f)   { return Vector3Mul(v, Vector3Initf(f)); }
inline Vector3 Vector3Divf (Vector3 v, float f)   { return Vector3Div(v, Vector3Initf(f)); }
inline float   Vector3Dot  (Vector3 v, Vector3 u) { return (v.x * u.x) + (v.y * u.y) + (v.z * u.z); }
inline float   Vector3Len2 (Vector3 v)            { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z); }
inline float   Vector3Len  (Vector3 v)            { return fSqrt32(Vector3Len2(v)); }
inline Vector3 Vector3Norm (Vector3 v)            { return Vector3Mulf(v, 1.0f/Vector3Len(v)); }

inline Vector4 Vector4Add  (Vector4 v, Vector4 u) { return Vector4Init(v.x + u.x, v.y + u.y, v.z + u.z, v.w + u.w); }
inline Vector4 Vector4Sub  (Vector4 v, Vector4 u) { return Vector4Init(v.x - u.x, v.y - u.y, v.z - u.z, v.w - u.w); }
inline Vector4 Vector4Mul  (Vector4 v, Vector4 u) { return Vector4Init(v.x * u.x, v.y * u.y, v.z * u.z, v.w * u.w); }
inline Vector4 Vector4Div  (Vector4 v, Vector4 u) { return Vector4Init(v.x / u.x, v.y / u.y, v.z / u.z, v.w / u.w); }
inline Vector4 Vector4Addf (Vector4 v, float y)	  { return Vector4Add(v, Vector4Initf(y)); }
inline Vector4 Vector4Subf (Vector4 v, float y)	  { return Vector4Sub(v, Vector4Initf(y)); }
inline Vector4 Vector4Mulf (Vector4 v, float y)	  { return Vector4Mul(v, Vector4Initf(y)); }
inline Vector4 Vector4Divf (Vector4 v, float y)	  { return Vector4Div(v, Vector4Initf(y)); }
inline float   Vector4Dot  (Vector4 v, Vector4 u) { return (v.x * u.x) + (v.y * u.y) + (v.z * u.z) + (v.w * u.w); }
inline float   Vector4Len2 (Vector4 v)            { return (v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w); }
inline float   Vector4Len  (Vector4 v)            { return fSqrt32(Vector4Len2(v)); }
inline Vector4 Vector4Norm (Vector4 v)            { return Vector4Mulf(v, 1.0f/Vector4Len(v)); }

//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////

Matrix2x2 Matrix2x2Id (void) { return (Matrix2x2) { 1, 0, 0, 1}; }
Matrix3x3 Matrix3x3Id (void) { return (Matrix3x3) { 1, 0, 0, 0, 1, 0, 0, 0, 1}; }
Matrix4x4 Matrix4x4Id (void) { return (Matrix4x4) { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }; }

float Matrix2x2Trace (Matrix2x2 x) { return x.mat[0][0] += x.mat[1][1]; }
float Matrix3x3Trace (Matrix3x3 x) { return x.mat[0][0] += x.mat[1][1] += x.mat[2][2]; }
float Matrix4x4Trace (Matrix4x4 x) { return x.mat[0][0] += x.mat[1][1] += x.mat[2][2] += x.mat[3][3]; }

Matrix2x2 Matrix2x2Translate (Vector2 v) { Matrix2x2 m = Matrix2x2Id(); m.vec[1] = v; return m; }
Matrix3x3 Matrix3x3Translate (Vector3 v) { Matrix3x3 m = Matrix3x3Id(); m.vec[2] = v; return m; }
Matrix4x4 Matrix4x4Translate (Vector4 v) { Matrix4x4 m = Matrix4x4Id(); m.vec[3] = v; return m; }


Matrix2x2 Matrix2x2Add   (Matrix2x2 x, Matrix2x2 y) { for (int i = 0; i < 4; x.elm[i] = x.elm[i] + y.elm[i], i++);	return x; }
Matrix2x2 Matrix2x2Sub   (Matrix2x2 x, Matrix2x2 y) { for (int i = 0; i < 4; x.elm[i] = x.elm[i] - y.elm[i], i++);	return x; }
Matrix2x2 Matrix2x2Addf  (Matrix2x2 x, float y)     { for (int i = 0; i < 4; x.elm[i] = x.elm[i] + y, i++);	return x; }
Matrix2x2 Matrix2x2Subf  (Matrix2x2 x, float y)     { for (int i = 0; i < 4; x.elm[i] = x.elm[i] - y, i++);	return x; }
Matrix2x2 Matrix2x2Mulf  (Matrix2x2 x, float y)     { for (int i = 0; i < 4; x.elm[i] = x.elm[i] * y, i++);	return x; }
Matrix2x2 Matrix2x2Divf  (Matrix2x2 x, float y)     { for (int i = 0; i < 4; x.elm[i] = x.elm[i] / y, i++);	return x; }

Matrix3x3 Matrix3x3Add   (Matrix3x3 x, Matrix3x3 y) { for (int i = 0; i < 9; x.elm[i] = x.elm[i] + y.elm[i], i++);	return x; }
Matrix3x3 Matrix3x3Sub   (Matrix3x3 x, Matrix3x3 y) { for (int i = 0; i < 9; x.elm[i] = x.elm[i] - y.elm[i], i++);	return x; }
Matrix3x3 Matrix3x3Addf  (Matrix3x3 x, float y)     { for (int i = 0; i < 9; x.elm[i] = x.elm[i] + y, i++);	return x; }
Matrix3x3 Matrix3x3Subf  (Matrix3x3 x, float y)     { for (int i = 0; i < 9; x.elm[i] = x.elm[i] - y, i++);	return x; }
Matrix3x3 Matrix3x3Mulf  (Matrix3x3 x, float y)     { for (int i = 0; i < 9; x.elm[i] = x.elm[i] * y, i++);	return x; }
Matrix3x3 Matrix3x3Divf  (Matrix3x3 x, float y)     { for (int i = 0; i < 9; x.elm[i] = x.elm[i] / y, i++);	return x; }

Matrix4x4 Matrix4x4Add   (Matrix4x4 x, Matrix4x4 y) { for (int i = 0; i < 16; x.elm[i] = x.elm[i] + y.elm[i], i++);	return x; }
Matrix4x4 Matrix4x4Sub   (Matrix4x4 x, Matrix4x4 y) { for (int i = 0; i < 16; x.elm[i] = x.elm[i] - y.elm[i], i++);	return x; }
Matrix4x4 Matrix4x4Addf  (Matrix4x4 x, float y)     { for (int i = 0; i < 16; x.elm[i] = x.elm[i] + y, i++);	return x; }
Matrix4x4 Matrix4x4Subf  (Matrix4x4 x, float y)     { for (int i = 0; i < 16; x.elm[i] = x.elm[i] - y, i++);	return x; }
Matrix4x4 Matrix4x4Mulf  (Matrix4x4 x, float y)     { for (int i = 0; i < 16; x.elm[i] = x.elm[i] * y, i++);	return x; }
Matrix4x4 Matrix4x4Divf  (Matrix4x4 x, float y)     { for (int i = 0; i < 16; x.elm[i] = x.elm[i] / y, i++);	return x; }



Matrix2x2 Matrix2x2Mul(Matrix2x2 a, Matrix2x2 b)
{
	Matrix2x2 c = (Matrix2x2){0};
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			c.mat[i][j] = ( a.mat[0][j] * b.mat[i][0] + a.mat[1][j] * b.mat[i][1]);
	return c;
}

Matrix3x3 Matrix3x3Mul(Matrix3x3 a, Matrix3x3 b)
{
	Matrix3x3 c = (Matrix3x3){0};
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			c.mat[i][j] = ( a.mat[0][j] * b.mat[i][0] + a.mat[1][j] * b.mat[i][1] + a.mat[2][j] * b.mat[i][2]);
	return c;
}

Matrix4x4 Matrix4x4Mul(Matrix4x4 a, Matrix4x4 b)
{
	Matrix4x4 c = (Matrix4x4){0};
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			c.mat[i][j] = ( a.mat[0][j] * b.mat[i][0] + a.mat[1][j] * b.mat[i][1] + a.mat[2][j] * b.mat[i][2] + a.mat[3][j] * b.mat[i][3]);
	return c;
}


Matrix2x2 Matrix2x2Transpose (Matrix2x2 x)
{
	Matrix2x2 y = { 0 };
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			y.mat[i][j] = x.mat[j][i];
	return y;
}

Matrix3x3 Matrix3x3Transpose(Matrix3x3 x)
{
	Matrix3x3 y = { 0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			y.mat[i][j] = x.mat[j][i];
	return y;
}

Matrix4x4 Matrix4x4Transpose(Matrix4x4 x)
{
	Matrix4x4 y = { 0 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			y.mat[i][j] = x.mat[j][i];
	return y;
}

