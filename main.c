#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libasm.h"

char *new_line(char buffer, char *line, int len)
{
    char *tmp = NULL;
    int i = -1; 

    tmp = malloc(sizeof(char) * (len + 2));
    while (++i < len)
        tmp[i] = line[i];
    tmp[i++] = buffer;
    tmp[i++] = 0;
    return (tmp);
}

int get_next_line(char **line)
{
    int ret = 0;
    char buffer = 0;
    int line_size = 0;
    char *tmp = NULL;
	
	*line = NULL;
    while ((ret = ft_read(0, &buffer, 1)) > 0)
    {   
        if (buffer == '\n')
            break;
        tmp = new_line(buffer, *line, line_size);
        free(*line);
        *line = tmp;
        line_size++;
    }   
    return (ret == 0 ? 0 : 1);
}

char *strjoin(const char* s1, const char* s2)
{
    char* result = malloc(strlen(s1) + strlen(s2) + 1);

    if (result)
    {
        strcpy(result, s1);
        strcat(result, s2);
    }

    return result;
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + 48;
	ft_write(1, &(nb), 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\033[1mWrong input\n");
		printf("This libasm test takes a string as input\nIt will get its length (ft_strlen)\nCreates two copies (ft_strdup and ft_strcpy)\nWrites it in standard output (ft_write).\n");
		printf("reads from standard input (ft_read)\ncompare your input with the first string (ft_strcmp)\n");
	}
	else
	{
		char *dst = ft_strdup(argv[1]);

		printf("ft_strlen -> [%ld]\n", ft_strlen(argv[1]));
		printf("ft_strdup\n	CPY : [%p] %s\n	SRC : [%p] %s\n", dst, dst, argv[1], argv[1]);
		memset(dst, '0', ft_strlen(argv[1]));
		printf("Reseting copy... \n	CPY : [%p] %s\n", dst, dst);
		dst = ft_strcpy(dst, argv[1]);
		printf("ft_strcpy\n	CPY : [%p] %s\n", dst, dst);

		char line[1024];
		int i;
		int ret;
		char *info = ft_strdup("Now reading from stdin (ft_read).\nEnter a string, it will be compared with your first string (ft_strcmp).\nThe output of ft_strcmp will be printed with ft_write.\n(Enter exit to close the program)\n");
		ft_write(1, info, ft_strlen(info));
		char *arg = strjoin(argv[1], "\n");
		while ((ret = read(0, &line, 1024)) > 0)
		{
			line[ret] = 0;
			i = ft_strcmp(line, arg);
			ft_putnbr(i);
			ft_write(1, " :", 2);
			ft_write(1, &line, ft_strlen(line));
			if (ft_strcmp(line, "exit\n") == 0)
				break;
		}
		free(arg);
		free(info);
	}
	return (0);
}
