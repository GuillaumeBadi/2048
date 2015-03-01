#include "game.h"

int		ft_get_pair(int val)
{
	int		i;
	int		ret;

	i = 2;
	ret = 31;
	if (val == EMPTY)
		return (COLOR_EMPTY);
	while (i < 100000)
	{
		if (i == val)
			return (ret);
		i *= 2;
		ret++;
	}
	return (0);
}
