#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 200;
	void * a[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = malloc(10 + rand() % (500 - 10));
	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	return 0;
}
