#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include "dlfcn.h"
#else
#include <dlfcn.h>
#endif
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

typedef void * (*malloc_like_function)(size_t size);
typedef void (*free_like_function)(void *);

static malloc_like_function sysmalloc = NULL;
static free_like_function sysfree = NULL;


static FILE *fp = NULL;
//static char *filename = "allocs.log";
static bool init = false;
static int fd = 1;


void write_int(unsigned int n)
{
	if ((n / 10) > 0)
		write_int(n / 10);

	char b[1];
	b[0] = '0' + (n%10);

	write(fd, b, 1);
	return;
}

void initcheck()
{
	if (!init)
	{
		init = true;
		sysmalloc = (malloc_like_function)dlsym(RTLD_NEXT, "malloc");
		sysfree = (free_like_function)dlsym(RTLD_NEXT, "free");
		fp = fopen("allocs.log", "w");
		fd = fileno(fp);
		//write_int(fd);
	}
}

void * malloc(size_t size)
{
	initcheck();
	void *result = sysmalloc(size);
	//printf("%u,M,%u\n", (uintptr_t)result, size);
	write_int((uintptr_t)result);
	write(fd, " M ", 3);
	write_int(size);
	write(fd, "\n", 1);
	return result;
}

void free(void *p)
{
	initcheck();
	//printf("%u,F\n" , (uintptr_t)p);
	write_int((uintptr_t)p);
	write(fd, " F\n", 3);
	sysfree(p);
}

