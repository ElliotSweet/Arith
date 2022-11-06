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


int main(const int argc, const char **argv)
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

	return 0;
}
