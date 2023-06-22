#include "../include/builtin.h"
#include "../include/env.h"

void	init_values(const char *str, unsigned long *res, int *sign, int *i)
{
	*sign = 1;
	*res = 0;
	*i = 0;
	while ((str[*i] > 8 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

int	extanded_atoi(const char *str, int *flag)
{
	unsigned long	res;
	int				sign;
	int				i;

	init_values(str, &res, &sign, &i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		*flag = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = 10 * (res) + str[i++] - '0';
		if ((res > (uint64_t)LLONG_MAX && sign == 1)
			|| (res > 9223372036854775806ULL && sign == -1))
			*flag = 1;
	}
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i])
		*flag = 1;
	return (sign * res);
}

int	ft_exit_command(char **args, t_env *env)
{
	int	num;
	int	flag;

	ft_putstr_fd("exit\n", 2);
	(void)env;
	flag = 0;
	if (strlen_double_ptr(args) == 1)
		num = 0;
	else
	{
		num = extanded_atoi(args[1], &flag);
		if (flag)
		{
			ft_error_check("exit", args[1], 3);
			exit(255);
		}
	}
	if (strlen_double_ptr(args) > 2)
	{
		ft_error_check("exit", 0, 2);
		return (1);
	}
	exit((unsigned char)num);
}
