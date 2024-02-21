#include <stdio.h>

void PrintBytes(void* data, size_t len)
{
	unsigned char* ptr = data;

	for (size_t i = 0; i < len; i++)
	{
		printf("%x ", *ptr);
		ptr++;
	}
	printf("\n");
}

int main()
{
	int a = -2147483647;
	double b = 10;
	PrintBytes(&a, sizeof(int));
	PrintBytes(&b, sizeof(double));
}