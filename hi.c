#include <stdio.h>
#include <math.h>
#include "arith.h"

void PrintVector4(Vector4 v) { printf("[%.1f, %.1f, %.1f, %.1f]\n", v.x, v.y, v.z, v.w); }

void PrintMatrix4x4(Matrix4x4 m1)
{
	PrintVector4(m1.vec[0]);
	PrintVector4(m1.vec[1]);
	PrintVector4(m1.vec[2]);
	PrintVector4(m1.vec[3]);
}

void CeilFloorTest(void)
{
	real32_t x = 19.5f;
	real64_t y = 19.5f;

	printf("Ceil32  %.2f\n", Ceil32(x));
	printf("Floor32 %.2f\n", Floor32(x));
	printf("Ceil64  %.2f\n", Ceil64(y));
	printf("Floor64 %.2f\n", Floor64(y));



}



int main(const int argc, const char **argv)
{
	CeilFloorTest();
	return 0;
}


void Test1(void)
{
	Matrix4x4 m1, m2;

	m1.vec[0] = Vector4Init(1, 2, 3, 4);
	m1.vec[1] = Vector4Init(5, 6, 7, 8);
	m1.vec[2] = Vector4Init(9, 1, 2, 3);
	m1.vec[3] = Vector4Init(4, 5, 6, 7);

	m2 = m1;

	Matrix4x4 m3 = Matrix4x4Transpose(m1);

	PrintMatrix4x4(m1); puts("\n");
	PrintMatrix4x4(m2); puts("\n");
	PrintMatrix4x4(m3);

}