#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	int_len(int n)
{
	size_t len;

	len = 0;
	if (n < 0)
		len++;
	 while (n / 10 != 0)
	 {
		 len++;
		 n /= 10;
	 }
	 return (++len);
}

int main()
{
	//char s1[] = "ABCD";
	//char s2[] = "ABC";
	//printf("%d", atoi("\n\n-+123"));
	//printf("%s", s1);
	int a = -12345;
	printf("%d", a / -10);
    return 0;
}
