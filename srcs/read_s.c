/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:17:09 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 21:03:35 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*

1. надо исправить проеб стрсплит пропускает "", а это валидное имя чемпиона
2. проверка длинны имени. Надо подтягивать масимальную длинну имени из op.h
там есть define PROG_NAME_LENGTH

P.S. см. продолжение в след коменте

3. так же нужно разнообразие символов разделителей между .name(comment) и самим
именем если разделять табуляцией то мой код срет под себя(((((
*/

char	*parse_name(char *line)
{
	int		i;
	char	*byte_name;
	char	**str;

	i = 0;
	byte_name = ft_memalloc(257);
	str = ft_strsplit(line, ' ');
	if (ft_arrlen(str) != 2)
		return (ERROR);
	else if (ft_strcmp(str[0], CHAMP_NAME) != 0)
		return (ERROR);
	else if (!str[1])
		return (ERROR);
	else if (ft_strlen(str[1]) > 128)
		return (ERROR);
	while (str[1][i])
	{
		if (str[1][i] == '"')
			i++;
		ft_strcat(byte_name, decToHexa((int)str[1][i++]));
	}
	// ft_printf("%s", byte_name);
	return (byte_name);
}

/*

1. таже проблема с стрсплит. Пришел к тому что нужна совершенно иная функция
наш сплит делит все что вокруг пробелов. Возможно нужен иной способ валидации
коментария. тоже самое касается и валидации имени.
2. так же надо подтягивать максимальную длинну комента из op.h

*/

char	*parse_comment(char *line)
{
	int		i;
	char	*byte_name;
	char	**str;

	i = 0;
	byte_name = ft_memalloc(2048);
	str = ft_strsplit(line, ' ');
	if (ft_arrlen(str) != 2)
		return (ERROR);
	else if (ft_strcmp(str[0], CHAMP_COMMENT) != 0)
		return (ERROR);
	else if (!str[1])
		return (ERROR);
	else if (ft_strlen(str[1]) > 2048)
		return (ERROR);
	while (str[1][i])
	{
		if (str[1][i] == '"')
			i++;
		ft_strcat(byte_name, decToHexa((int)str[1][i++]));
	}
	return (byte_name);
}

/*
таксс короче тут мем такой. если читал кукбук бражника и видел каким должен быть
байткод в итоге то думаю заметил его структуру. каждые 4 символа пробел, каждые
8 блоков перенос строки. то что написал я пишет чисто в одну строку. Закончил на
том что перевожу в байт код имя и комент. Для полной картины и понимания всех нюансов
читай 2 предыдущих комента.
*/

static char	*parse_string(char *line, int file_descriptor)
{
	if (ft_strstr(line, CHAMP_NAME) != 0)
		ft_putstr_fd(parse_name(line), file_descriptor);
	if (ft_strstr(line, CHAMP_COMMENT) != 0)
		ft_putstr_fd(parse_comment(line), file_descriptor);
	return (ERROR);
}

void 	parse_file(char *filename)
{
	size_t	size;
	char	*line;
	int		file;
	int		new_file;

	create_files_name(filename);
	file = open(filename, O_RDONLY);
	new_file = open(create_files_name(filename), O_CREAT | O_WRONLY | O_RDONLY);
	while ((size = get_next_line(file, &line)) > 0)
	{
		parse_string(line, new_file);
	}
	close(file);
}
