/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 08:09:30 by cgarrot      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 16:22:54 by cgarrot     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int main(void)
{
/*FLAG %s*/
	printf("Salut\n");
	//ft_printf("Salut\n");
	printf("%s\n", "Salut string");
	//ft_printf("%s\n", "Salut string");
	printf("Salut %s\n", "Salut string");
	//ft_printf("Salut %s\n", "Salut string");
/*FLAG %c*/
	printf("a + b =  %c\n", 'c');
	//ft_printf("a + b =  %c\n", 'c');
	printf("%c\n", 'c');
	//ft_printf("%c\n", 'c');
/*FLAG %d*/
	printf("%d\n", 42);
	//ft_printf("%d\n", 42);
	printf("Salut %d\n", 42);
	//ft_printf("Salut %d\n", 42);
/*FLAG #*/
/*FLAG 0*/
/*FLAG -*/
	printf("%-d\n", 42);
	//ft_printf("%-d\n", 42);
	printf("Salut %-d\n", 42);
	//ft_printf("Salut %-d\n", 42);
	printf("%-s\n", "Salut string");
	//ft_printf("%-s\n", "Salut string");
	printf("Salut %-s\n", "Salut string");
	//ft_printf("Salut %-s\n", "Salut string");//
/*FLAG +*/
	printf("%+d\n", 42);
	//ft_printf("%+d\n", 42);
	printf("Salut %+d\n", 42);
	//ft_printf("Salut %+d\n", 42);
	//
	//
	printf("%05d\n", 85);
	printf("%05.d\n", 85);
	printf("%0.5d\n", 85);
	printf("%-5.0d\n", 85);
	return (0);
}
