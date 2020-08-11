/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:14:34 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 21:18:43 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "libftprintf.h"
# include "stdlib.h"
# include <unistd.h>
# include <fcntl.h>

# define SIZE_T_DIR		"zjmp ldi sti fork lldi lfork"
# define NO_ASM_FILE	"Error"
# define NOT_VALID_NAME	"Not valid name"
# define CHAMP_NAME		".name"
# define CHAMP_COMMENT	".comment"
# define ERROR			"Error"
# define ERROR1			"loh"

/*  открывает файл и бегает по его строкам
так же создает файл с расширением .cor
принимает в себя огромный жирный... нет не член)
а argv
*/
void 	parse_file(char *filename);
/*
проверяет имя файла нашего ЧЕМПИОНА!11!!1!
не знаю есть ли смысОл это делать, но я уже сделал
*/
char	*f_filename(char **argv);
char	*check_file_name(char *filename);
/*
собственно создает имя для нового файла на основе имеющегося
*/
char	*create_files_name(char *filename);
/*
эта залупа переводит числа из десятично системы счисления в шестанваимлчыаа в 16
этого недостаточно так как нужно реализовать еще из двоичной в 16 для перевода
команд в наш байт код
*/
char	*decToHexa(int n);

#endif
