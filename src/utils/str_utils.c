#include "../../includes/push_swap.h"

int	ft_array_len(char **array)
{
    int	len;

    len = 0;
    if (!array)
        return (0);
    while (array[len])
        len++;
    return (len);
}

char	*ft_strdup(const char *s1)
{
    char	*str;
    size_t	i;

    i = 0;
    while (s1[i])
        i++;
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

long long	ft_atoi(char *str)
{
    int			i;
    long long	content;
    long long	sign;

    content = 0;
    sign = 1;
    i = 0;
    if (str[i] == '+')
        i++;
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        content = (content * 10) + (str[i] - '0');
        if (content > INT32_MAX || content < INT32_MIN)
            error();
        i++;
    }
    return (content * sign);
}

void	ft_free_array(char **array)
{
    int	i;

    i = 0;
    if (!array)
        return ;
    while (array[i])
        free(array[i++]);
    free(array);
}

size_t	ft_strlen(char *s)
{
    size_t	i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}