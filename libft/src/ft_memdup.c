

#include "libft.h"

void	*ft_memdup(void *data, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if ((res = malloc(sizeof(char) * size)))
	{
		while (i < size)
		{
			((char *)res)[i] = ((char *)data)[i];
			i++;
		}
		return (res);
	}
	return (NULL);
}
