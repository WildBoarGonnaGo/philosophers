#include "philo_three.h"

int		wb_isdigit(char c)
{
	return ((c >= '0' && c <= '9'));
}

int		wb_pow(int digit, uint32 pow)
{
	if (!pow)
		return (1);
	else if (pow == 1)
		return (digit);
	return (digit * wb_pow(digit, --pow));
}

uint16		wb_atoi(char *str, uint16 res, int flags)
{
	if (!str)
		return (0);
	if (*str > 8 && *str < 12 && (flags & SPACE))
		return (wb_atoi(++str, res, flags));
	else if ((*str == '-') && (flags & PLUSMINUS))
		return (wb_atoi(++str, res, (flags | SUBZERO)
		& ~(SPACE | PLUSMINUS)));
	else if ((*str == '+') && (flags & PLUSMINUS))
		return (wb_atoi(++str, res, flags & ~(SPACE | PLUSMINUS)));
	else if (*str == '0' && (flags & ZERO))
		return (wb_atoi(++str, res, (flags & ~SPACE)));
	else if (wb_isdigit(*str) && *str)
	{
		res *= 10;
		res += (*str - 48) * wb_pow(-1, ((flags & SUBZERO) != 0));
		return (wb_atoi(++str, res, (flags & ~ZERO)));
	}
	return (res);
}