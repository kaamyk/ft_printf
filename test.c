#include <stdio.h>

int	main(void)
{
	printf("pf = %d\n", printf("'%6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6d'\n", 140));
	printf("pf = %d\n", printf("'%6.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.6d'\n", 140));
	printf("pf = %d\n", printf("'%5.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%5.6d'\n", 140));
	printf("==================================\n");

	printf("f > len\n");
	printf("	=> p < len && < f\n");
	printf("pf = %d\n", printf("'%6.d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.d'\n", 140));
	printf("	=> p = len && < f\n");
	printf("pf = %d\n", printf("'%6.3d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.3d'\n", 140));
	printf("	=> p > len && < f\n");
	printf("pf = %d\n", printf("'%6.4d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.4d'\n", 140));
	printf("==================================\n");
	printf("p > len\n");
	printf("	=> f < len && < p\n");
	printf("pf = %d\n", printf("'%2.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%2.6d'\n", 140));
	printf("	=> f = len && < p\n");
	printf("pf = %d\n", printf("'%3.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%3.6d'\n", 140));
	printf("	=> f > len && < p\n");
	printf("pf = %d\n", printf("'%4.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%4.6d'\n", 140));
	printf("==================================\n");
	printf("p = f = len\n");
	printf("pf = %d\n", printf("'%3.3d'\n", 140));
	printf("pf = %d\n", ft_printf("'%3.3d'\n", 140));
	printf("==================================\n");
	printf("p = f\n");
	printf("	=> pf < len\n");
	printf("pf = %d\n", printf("'%2.2d'\n", 140));
	printf("pf = %d\n", ft_printf("'%2.2d'\n", 140));
	printf("	=> pf > len\n");
	printf("pf = %d\n", printf("'%6.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.6d'\n", 140));
	printf("==================================\n");
	printf("p = f\n");
	printf("	=> pf < len\n");
	printf("pf = %d\n", printf("'%2.2d'\n", 140));
	printf("pf = %d\n", ft_printf("'%2.2d'\n", 140));
	printf("	=> pf > len\n");
	printf("pf = %d\n", printf("'%6.6d'\n", 140));
	printf("pf = %d\n", ft_printf("'%6.6d'\n", 140));
	printf("==================================\n");
	printf("pf = %d\n", printf("'%#6.6x'\n", 140));
	printf("pf = %d\n", ft_printf("'%#6.6x'\n", 140));
	printf("==================================\n");
	return (0);
}
