/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:14:08 by torange           #+#    #+#             */
/*   Updated: 2020/08/11 21:18:45 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
дароу дароу дароу
сережа, мне похуй что искандер сказал что мне нельзя писать транлятор ассмеблера
так как его пишешь ты, если будет выебыватся то может попробовать сам у себя отсосать
и я решил помочь тебе если ты вдруг еще не начал. я немного наговнокодил если
хуйня то можешь не юзать (ну или если не актуально). в ашнике будут коменты к
функция и что они делают. в read_s есть еще два комента для тебя для понимания
где у меня понос. закончил на том что перевожу имя и комент чемпиона. на
создоваемый фал надо накинуть чмод так как я еблан и вообще я так вижу и мне похуй
*/
int main(int argc, char **argv)
{
	argc = 0;

	parse_file(f_filename(argv));
	// ft_printf("%s", f_filename(argv));
	return (0);
}