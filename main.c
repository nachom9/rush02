#include "rush.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*nb;

	nb = NULL;
	if (nb)
		return (1);
	if (argc == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
		nb = argv[1];
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		nb = argv[2];
	}
	else
		return (write(2, "Error\n", 6), 0);
	if (fd == -1)
		return (0);
	ft_parse(fd, nb);
}
