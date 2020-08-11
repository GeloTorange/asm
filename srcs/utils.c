/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:04:29 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 20:12:56 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*decToHexa(int n)
{
	char	*hexaDeciNum;
	int		i;
	int		j;
	int		temp;

	i = 0;
	hexaDeciNum = ft_memalloc(100);
	while(n != 0)
	{
		temp = n % 16;
		if(temp < 10)
			hexaDeciNum[i++] = temp + 48;
		else
			hexaDeciNum[i++] = temp + 55;
		n = n / 16;
	}
	j = i - 1;
	ft_strrev(hexaDeciNum);
	return (hexaDeciNum);
}

char	*f_filename(char **argv)
{
	while (*argv)
	{
		if (ft_strstr(*argv, ".s") != 0 \
		&& ft_strcmp(check_file_name(*argv), NOT_VALID_NAME))
				return (*argv);
		argv++;
	}
	return (NO_ASM_FILE);
}

char	*check_file_name(char *filename)
{
	char *str;

	if (filename[ft_strlen(filename) - 1] != 's' \
		&& filename[ft_strlen(filename) - 2] != '.')
		return (NOT_VALID_NAME);
	ft_strncpy(str = (char *)malloc(sizeof(char) * ft_strlen(filename) - 1), \
	filename, ft_strlen(filename) - 3);
	while (*str)
		if (ft_isalpha(*str++) != 1)
			return (NOT_VALID_NAME);
	return (filename);
}

char	*create_files_name(char *filename)
{
	char *str;

	ft_strncpy(str = (char *)malloc(sizeof(char) * ft_strlen(filename) + 3), \
	filename, ft_strlen(filename) - 1);
	ft_strcat(str, "txt");
	return (str);
}
