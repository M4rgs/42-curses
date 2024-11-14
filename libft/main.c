#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <libc.h>

int main() 
{
	int y = 0;
	printf("%p\n", &y);
	ft_memset(&y, 0, 4);
	ft_memset(&y, 0, 3);
	ft_memset(&y, 5, 2);
	ft_memset(&y, 57, 1);
	printf("%p", &y);
}
