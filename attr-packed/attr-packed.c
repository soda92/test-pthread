#include<stdio.h>

struct mystruct_A
{
	char a;
	int b;
	char c;
} x;

#pragma pack(push, 1)
struct mystruct_A_p
{
	char a;
	int b;
	char c;
} y;
#pragma pack(pop)


int main() {
	short s;
	float f;
	int i;
	
	printf("%d\n", sizeof(x));
	printf("%d\n", sizeof(y));
	printf("%d\n", (short)'A');
	printf("%c\n", (char)67);
	printf("%p\n", (unsigned short)-1);
	i = 0b100'0000'0000'0000'0000'0000'0000'0000;
	f = *(float*)&i;
	printf("%p\n", f);
	printf("%lf\n", f);

	f = 70000000000000.0f;
	s = *(short*)&f;
	printf("%d\n", s);
	printf("%p\n", s);
}