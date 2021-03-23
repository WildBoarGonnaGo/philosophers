#include "./philo_one/philo_one.h"

int main(void)
{
	printf("test 443: == %d\n", wb_atoi("443", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 0: == %d\n", wb_atoi("0", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 4: == %d\n", wb_atoi("4", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 9: == %d\n", wb_atoi("9", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 10: == %d\n", wb_atoi("10", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 1000: == %d\n", wb_atoi("1000", 0, ZERO | SPACE | PLUSMINUS));
	printf("test 2845: == %d\n", wb_atoi("2845", 0, ZERO | SPACE | PLUSMINUS));
	printf("test -0004449: == %d\n", wb_atoi("-0004449", 0, ZERO | SPACE | PLUSMINUS));
	printf("test -000857a4e: == %d\n", wb_atoi("-000857a4e", 0, ZERO | SPACE | PLUSMINUS)); 
	return (0);
}
