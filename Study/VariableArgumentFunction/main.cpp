#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#pragma warning(disable:4996)

DWORD sum(DWORD count, ...)
{
	int sum = 0;

	va_list list;
	va_start(list, count);
	for (DWORD i = 0; i < count; i++)
	{
		sum += va_arg(list, DWORD);
	}
	va_end(list);
	return sum;
}

void main()
{
	printf("%d\n", sum(4, 1, 2, 3, 4));

	getch();
}