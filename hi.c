#include <stdio.h>
#include <math.h>
#include "arith.h"


typedef struct {
	union { 
		struct { float x, y, z, w };
		float elm[4];
	};
} Quaternion;

void PrintMatrix4x4(Matrix4x4 m1)
{
	printf("[%.1f, %.1f, %.1f, %.1f]\n", m1.elm[0],  m1.elm[1],  m1.elm[2],  m1.elm[3]);
	printf("[%.1f, %.1f, %.1f, %.1f]\n", m1.elm[4],  m1.elm[5],  m1.elm[6],  m1.elm[7]);
	printf("[%.1f, %.1f, %.1f, %.1f]\n", m1.elm[8],  m1.elm[9],  m1.elm[10], m1.elm[11]);
	printf("[%.1f, %.1f, %.1f, %.1f]\n", m1.elm[12], m1.elm[13], m1.elm[14], m1.elm[15]);
}

int main(const int argc, const char **argv)
{
	Matrix4x4 m1, m2;

	m1.vec[0] = Vector4Init(1, 3, 3, 4);
	m1.vec[1] = Vector4Init(5, 6, 8, 8);
	m1.vec[2] = Vector4Init(9, 6, 1, 9);
	m1.vec[3] = Vector4Init(2, 4, 5, 6);

	m2 = m1;

	Matrix4x4 m3 = Matrix4x4Mul(m1, m2);

	PrintMatrix4x4(m1); puts("\n\n");
	PrintMatrix4x4(m2); puts("\n\n");
	PrintMatrix4x4(m3);

	return 0;
}
