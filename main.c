/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cul.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/16 13:39:13 by seanseau     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/17 18:18:08 by seanseau    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	ft_printf("%d\n", ft_printf("|%x|\n", (unsigned long long)-1248759650));
	printf("%d\n", printf("|%x|\n", (unsigned long long)-1248759650));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%9hhx|\n", (unsigned long)-1248759650));
	printf("%d\n", printf("|%9hhx|\n", (unsigned long)-1248759650));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%.0x|\n", 0));
	printf("%d\n", printf("|%.0x|\n", 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%01hhX|\n", (unsigned char)0));
	printf("%d\n", printf("|%01hhX|\n", (unsigned char)0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|t %#7.5X|\n", 0xab));
	printf("%d\n", printf("|t %#7.5X|\n", 0xab));
	ft_printf("%d\n", ft_printf("|%0006.2x|\n", 0x876));
	printf("%d\n", printf("|%0006.2x|\n", 0x876));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%lX|\n", 0xff11ff11ff1));
	printf("%d\n", printf("|%lX|\n", 0xff11ff11ff1));
	printf("\n");
	ft_printf("%d\n", ft_printf("|toto %0##0.4X%#4.2xet c'est fini|\n", 0x037a, 0x9e));
	printf("%d\n", printf("|toto %0##0.4X%#4.2xet c'est fini|\n", 0x037a, 0x9e));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#.X|  |%###.1x|\n", 0, 0));
	printf("%d\n", printf("|%#.X|  |%###.1x|\n", 0, 0));
	ft_printf("%d\n", ft_printf("|%x|\n", 0));
	printf("%d\n", printf("|%x|\n", 0));
	ft_printf("%d\n", ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("%d\n", printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 5, 5, 5, 5, 5, 5, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.x| |%#02.x| |%03.x|\n", -45, 20, 96000));
	printf("%d\n", printf("|%#01.x| |%#02.x| |%03.x|\n", -45, 20, 96000));
	printf("\n");
	ft_printf("%d\n" ,ft_printf("|%1.X| |%2.X| |%.1X| |%.2X|\n", 2, -1, 60, -47));
	printf("%d\n", printf("|%1.X| |%2.X| |%.1X| |%.2X|\n", 2, -1, 60, -47));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%llX|\n", (unsigned long long)0xaaffee11996677));
	printf("%d\n", printf("|%llX|\n", (unsigned long long)0xaaffee11996677));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("%d\n", printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x| |%-.1x| |%-.2x|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("%d\n", printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 0, 0, 0, 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#0+10.x| |%#0-10.x|\n", 9, 8));
	printf("%d\n", printf("|%#0+10.x| |%#0-10.x|\n", 9, 8));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%+1.1x| |%+2.0lx| |%+3.1x| |%+1.0x| |%+2.1x| |%+1.0x| |%+0.2x|\n", 300, 922337203685477, 140, 9, 7, 15488, 20345));
	printf("%d\n", printf("|%+1.1x| |%+2.0lx| |%+3.1x| |%+1.0x| |%+2.1x| |%+1.0x| |%+0.2x|\n", 300, 922337203685477, 140, 9, 7, 15488, 20345));
	printf("\n");
	ft_printf("%d\n", ft_printf("|% .20lx| |%-.10x| |%+.10x| |% .10x| |%- .5x| |%+ .5x| |%+ .10x|\n", 922337203685477, 2, 4, 1, 5, 9, 8));
	printf("%d\n", printf("|% .20lx| |%-.10x| |%+.10x| |% .10x| |%- .5x| |%+ .5x| |%+ .10x|\n", 922337203685477, 2, 4, 1, 5, 9, 8));
	ft_printf("%d\n", ft_printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 922337203685477, 2, 4, 1, 5, 9, 8));
	printf("%d\n", printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x| |%5.x| |%-5.x|\n", 922337203685477, 2, 4, 1, 5, 9, 8));
	printf("\n");
	ft_printf("%d\n", ft_printf("1hexa 1 %x hexa 2 %x\n", 42, -42));
	printf("%d\n", printf("1hexa 1 %x hexa 2 %x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa 1 %   x hexa 2 % x\n", 42, -42));
	printf("%d\n", printf("3hexa 1 %   x hexa 2 % x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %12x hexa 2 %12x\n", 42, -42));
	printf("%d\n", printf("4hexa 1 %12x hexa 2 %12x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %-12x hexa 2 %-12x\n", 42, -42));
	printf("%d\n", printf("4hexa 1 %-12x hexa 2 %-12x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa 1 %0x hexa 2 %0x\n", 42, -42));
	printf("%d\n", printf("5hexa 1 %0x hexa 2 %0x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa 1 %012x hexa 2 %012x\n", 42, -42));
	printf("%d\n", printf("6hexa 1 %012x hexa 2 %012x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa 1 %-012x hexa 2 %012x\n", 42, -42));
	printf("%d\n", printf("7hexa 1 %-012x hexa 2 %012x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa 1 %+x hexa 2 %+x\n", 42, 6, -42, 6));
	printf("%d\n", printf("9hexa 1 %+x hexa 2 %+x\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa 1 %+12x hexa 2 %+12x\n", 42, 6, -42, 6));
	printf("%d\n", printf("10hexa 1 %+12x hexa 2 %+12x\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa 1 %-+5x hexa 2 %-+5x\n", 42, -42));
	printf("%d\n", printf("12hexa 1 %-+5x hexa 2 %-+5x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa 1 %-+05x hexa 2 %-+05x\n", 42, -42));
	printf("%d\n", printf("13hexa 1 %-+05x hexa 2 %-+05x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa 1 %+-5x hexa 2 %+-5x\n", 42, -42));
	printf("%d\n", printf("14hexa 1 %+-5x hexa 2 %+-5x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa 1 %.x hexa 2 %.x\n", 42, -42));
	printf("%d\n", printf("15hexa 1 %.x hexa 2 %.x\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("16hexa 1 %.6x hexa 2 %.6x\n", 42, -42));
	printf("%d\n", printf("16hexa 1 %.6x hexa 2 %.6x\n", 42, -42));
	ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("%d\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("%d\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("%d\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("%d\n", printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("%d\n", printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("%d\n", printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("%d\n", printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("%d\n", printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("%d\n", printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	printf("%d\n", printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	ft_printf("%d\n", ft_printf("|%#015.lx| |%025.lx| |%-035.lx| |%15.lx| |%25.lx| |%-.15lx| |%-.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#015.lx| |%025.lx| |%-035.lx| |%15.lx| |%25.lx| |%-.15lx| |%-.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#016.lx| |%#025.lx| |%035.lx| |%15.lx| |%25.lx| |%.15lx| |%.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#016.lx| |%#025.lx| |%035.lx| |%15.lx| |%25.lx| |%.15lx| |%.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lX| |%#028.lX| |%038.lX| |%18.lX| |%2.58lX| |%#28.5lX| |%.28lX|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lX| |%#028.lX| |%038.lX| |%18.lX| |%2.58lX| |%#28.5lX| |%.28lX|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lx| |%#028.lx| |%-#038.lx| |%#18.lx| |%#28.lx| |%#-.18lx| |%#-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lx| |%#028.lx| |%-#038.lx| |%#18.lx| |%#28.lx| |%#-.18lx| |%#-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lx| |%028.lx| |%-038.lx| |%18.lx| |%28.lx| |%-.18lx| |%-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lx| |%028.lx| |%-038.lx| |%18.lx| |%28.lx| |%-.18lx| |%-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%18.lx| |%-18.lx| |%15.lx sku| |%18.lx| |%-18.lx| |%28.lx| |%-28.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%18.lx| |%-18.lx| |%15.lx sku| |%18.lx| |%-18.lx| |%28.lx| |%-28.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018lx| |%#0.18lx| |%#018lx| |%#0-18lx| |%#0+18lx| |%#0+18.lx| |%#0-18.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018lx| |%#0.18lx| |%#018lx| |%#0-18lx| |%#0+18lx| |%#0+18.lx| |%#0-18.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%+16.1lx| |%+26.0lx| |%+36.1lx| |%+16.0lx| |%+26.1lx| |%+16.0lx| |%+0.26lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%+16.1lx| |%+26.0lx| |%+36.1lx| |%+16.0lx| |%+26.1lx| |%+16.0lx| |%+0.26lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|% .20lx| |%-.16lx| |%+.16lx| |% .16lx| |%- .15lx| |%+ .16lx| |%+ .0lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|% .20lx| |%-.16lx| |%+.16lx| |% .16lx| |%- .15lx| |%+ .16lx| |%+ .0lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%16.lx| |%-16.lx| |%8.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%16.lx| |%-16.lx| |%8.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("1hexa 1 %lx hexa 2 %lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("1hexa 1 %lx hexa 2 %lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa 1 %   lx hexa 2 % lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("3hexa 1 %   lx hexa 2 % lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %18lx hexa 2 %18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("4hexa 1 %18lx hexa 2 %18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %-18lx hexa 2 %-18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("4hexa 1 %-18lx hexa 2 %-18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa 1 %0lx hexa 2 %0lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("5hexa 1 %0lx hexa 2 %0lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa 1 %018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("6hexa 1 %018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa 1 %-018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("7hexa 1 %-018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa 1 %+lx hexa 2 %+lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n\n", printf("9hexa 1 %+lx hexa 2 %+lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa 1 %+18lx hexa 2 %+18lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n\n", printf("10hexa 1 %+18lx hexa 2 %+18lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa 1 %-+18lx hexa 2 %-+18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("12hexa 1 %-+18lx hexa 2 %-+18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa 1 %-+018lx hexa 2 %-+018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("13hexa 1 %-+018lx hexa 2 %-+018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa 1 %+-18lx hexa 2 %+-18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("14hexa 1 %+-18lx hexa 2 %+-18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa 1 %.lx hexa 2 %.lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("15hexa 1 %.lx hexa 2 %.lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("%d\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("%d\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("%d\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("%d\n", printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("%d\n", printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("%d\n", printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("%d\n", printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("%d\n", printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("%d\n", printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	printf("%d\n", printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	ft_printf("%d\n", ft_printf("16hexa 1 %.16lx hexa 2 %.16lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("16hexa 1 %.16lx hexa 2 %.16lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.lx| |%02.lx| |%-03.lx| |%1.lx| |%2.lx| |%-.1lx| |%-.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#01.lx| |%02.lx| |%-03.lx| |%1.lx| |%2.lx| |%-.1lx| |%-.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01lx| |%#0.10lx| |%#010lx| |%#0-10lx| |%#0+10lx| |%#0+10.lx| |%#0-10.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#01lx| |%#0.10lx| |%#010lx| |%#0-10lx| |%#0+10lx| |%#0+10.lx| |%#0-10.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%+1.1lx| |%+2.0lx| |%+3.1lx| |%+1.0lx| |%+2.1lx| |%+1.0lx| |%+0.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%+1.1lx| |%+2.0lx| |%+3.1lx| |%+1.0lx| |%+2.1lx| |%+1.0lx| |%+0.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|% .10lx| |%-.10lx| |%+.10lx| |% .10lx| |%- .5lx| |%+ .5lx| |%+ .10lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|% .10lx| |%-.10lx| |%+.10lx| |% .10lx| |%- .5lx| |%+ .5lx| |%+ .10lx|\n", 922337203685477, 922337203685477 , 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.lx| |%-10.lx| |%10.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%10.lx| |%-10.lx| |%10.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	ft_printf("%d\n", ft_printf("|%#015.lx| |%025.lx| |%-035.lx| |%15.lx| |%25.lx| |%-.15lx| |%-.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#015.lx| |%025.lx| |%-035.lx| |%15.lx| |%25.lx| |%-.15lx| |%-.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#016.lx| |%#025.lx| |%035.lx| |%15.lx| |%25.lx| |%.15lx| |%.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#016.lx| |%#025.lx| |%035.lx| |%15.lx| |%25.lx| |%.15lx| |%.25lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lX| |%#028.lX| |%038.lX| |%18.lX| |%2.58lX| |%#28.5lX| |%.28lX|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lX| |%#028.lX| |%038.lX| |%18.lX| |%2.58lX| |%#28.5lX| |%.28lX|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lx| |%#028.lx| |%-#038.lx| |%#18.lx| |%#28.lx| |%#-.18lx| |%#-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lx| |%#028.lx| |%-#038.lx| |%#18.lx| |%#28.lx| |%#-.18lx| |%#-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018.lx| |%028.lx| |%-038.lx| |%18.lx| |%28.lx| |%-.18lx| |%-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018.lx| |%028.lx| |%-038.lx| |%18.lx| |%28.lx| |%-.18lx| |%-.28lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%18.lx| |%-18.lx| |%15.lx| |%18.lx| |%-18.lx| |%28.lx| |%-28.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%18.lx| |%-18.lx| |%15.lx| |%18.lx| |%-18.lx| |%28.lx| |%-28.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#018lx| |%#0.18lx| |%#018lx| |%#0-18lx| |%#0+18lx| |%#0+18.lx| |%#0-18.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#018lx| |%#0.18lx| |%#018lx| |%#0-18lx| |%#0+18lx| |%#0+18.lx| |%#0-18.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%+16.1lx| |%+26.0lx| |%+36.1lx| |%+16.0lx| |%+26.1lx| |%+16.0lx| |%+0.26lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%+16.1lx| |%+26.0lx| |%+36.1lx| |%+16.0lx| |%+26.1lx| |%+16.0lx| |%+0.26lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|% .20lx| |%-.16lx| |%+.16lx| |% .16lx| |%- .15lx| |%+ .16lx| |%+ .0lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|% .20lx| |%-.16lx| |%+.16lx| |% .16lx| |%- .15lx| |%+ .16lx| |%+ .0lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%16.lx| |%-16.lx| |%8.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%16.lx| |%-16.lx| |%8.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");/*
	ft_printf("%d\n", ft_printf("1hexa 1 %lx hexa 2 %lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("1hexa 1 %lx hexa 2 %lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa 1 %   lx hexa 2 % lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("3hexa 1 %   lx hexa 2 % lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %18lx hexa 2 %18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("4hexa 1 %18lx hexa 2 %18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa 1 %-18lx hexa 2 %-18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("4hexa 1 %-18lx hexa 2 %-18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa 1 %0lx hexa 2 %0lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("5hexa 1 %0lx hexa 2 %0lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa 1 %018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("6hexa 1 %018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa 1 %-018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("7hexa 1 %-018lx hexa 2 %018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa 1 %+lx hexa 2 %+lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n\n", printf("9hexa 1 %+lx hexa 2 %+lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa 1 %+18lx hexa 2 %+18lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n\n", printf("10hexa 1 %+18lx hexa 2 %+18lx\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa 1 %-+18lx hexa 2 %-+18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("12hexa 1 %-+18lx hexa 2 %-+18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa 1 %-+018lx hexa 2 %-+018lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("13hexa 1 %-+018lx hexa 2 %-+018lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa 1 %+-18lx hexa 2 %+-18lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("14hexa 1 %+-18lx hexa 2 %+-18lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa 1 %.lx hexa 2 %.lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("15hexa 1 %.lx hexa 2 %.lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("16hexa 1 %.16lx hexa 2 %.16lx\n", 922337203685477, 922337203685477));
	printf("%d\n\n", printf("16hexa 1 %.16lx hexa 2 %.16lx\n", 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("%d\n", printf("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("2hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("%d\n", printf("3hexa-maj 1 %   X hexa-maj 2 % X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %12X hexa-maj 2 %12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("%d\n", printf("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("%d\n", printf("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("%d\n", printf("7hexa-maj 1 %-012X hexa-maj 2 %012X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("%d\n", printf("9hexa-maj 1 %+X hexa-maj 2 %+X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("%d\n", printf("10hexa-maj 1 %+12X hexa-maj 2 %+12X\n", 42, 6, -42, 6));
	printf("\n");
	ft_printf("%d\n", ft_printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("%d\n", printf("12hexa-maj 1 %-+5X hexa-maj 2 %-+5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("%d\n", printf("13hexa-maj 1 %-+05X hexa-maj 2 %-+05X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("%d\n", printf("14hexa-maj 1 %+-5X hexa-maj 2 %+-5X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("%d\n", printf("15hexa-maj 1 %.X hexa-maj 2 %.X\n", 42, -42));
	printf("\n");
	ft_printf("%d\n", ft_printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	printf("%d\n", printf("16hexa-maj 1 %.6X hexa-maj 2 %.6X\n", 42, -42));
	ft_printf("%d\n", ft_printf("|%#01.lx| |%02.lx| |%-03.lx| |%1.lx| |%2.lx| |%-.1lx| |%-.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#01.lx| |%02.lx| |%-03.lx| |%1.lx| |%2.lx| |%-.1lx| |%-.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01lx| |%#0.10lx| |%#010lx| |%#0-10lx| |%#0+10lx| |%#0+10.lx| |%#0-10.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%#01lx| |%#0.10lx| |%#010lx| |%#0-10lx| |%#0+10lx| |%#0+10.lx| |%#0-10.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	ft_printf("%d\n", ft_printf("|%+1.1lx| |%+2.0lx| |%+3.1lx| |%+1.0lx| |%+2.1lx| |%+1.0lx| |%+0.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%+1.1lx| |%+2.0lx| |%+3.1lx| |%+1.0lx| |%+2.1lx| |%+1.0lx| |%+0.2lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|% .10lx| |%-.10lx| |%+.10lx| |% .10lx| |%- .5lx| |%+ .5lx| |%+ .10lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|% .10lx| |%-.10lx| |%+.10lx| |% .10lx| |%- .5lx| |%+ .5lx| |%+ .10lx|\n", 922337203685477, 922337203685477 , 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.lx| |%-10.lx| |%10.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("%d\n", printf("|%10.lx| |%-10.lx| |%10.lx| |%10.lx| |%-10.lx| |%5.lx| |%-5.lx|\n", 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477, 922337203685477));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.lx|\n", 922337203685477));
	printf("%d\n", printf("|%10.lx|\n", 922337203685477));
	ft_printf("%d\n", ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x|\n", 5, 5, 5, 5, 5));
	printf("%d\n", printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x|\n", 5, 5, 5, 5, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%.1x| |%.2x| |%-.1x| |%-.2x|\n", -60, -47, 5, 5));
	printf("%d\n", printf("|%.1x| |%.2x| |%-.1x| |%-.2x|\n", -60, -47, 5, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.x| |%#02.x| |%03.x| |%1.x| |%2.x|\n", -45, 20, 96000, 2, -1));
	printf("%d\n", printf("|%#01.x| |%#02.x| |%03.x| |%1.x| |%2.x|\n", -45, 20, 96000, 2, -1));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.X| |%#02.X| |%03.X| |%1.X| |%2.X|\n", -45, 20, 96000, 2, -1));
	printf("%d\n", printf("|%#01.X| |%#02.X| |%03.X| |%1.X| |%2.X|\n", -45, 20, 96000, 2, -1));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%.1X| |%.2X| |%#-.1x| |%#-.2x|\n", -60, -47, 0, 0));
	printf("%d\n", printf("|%.1X| |%.2X| |%#-.1x| |%#-.2x|\n", -60, -47, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.x| |%#02.x| |%-#03.x| |%#1.x| |%#2.x|\n", 0, 0, 0, 0, 0));
	printf("%d\n", printf("|%#01.x| |%#02.x| |%-#03.x| |%#1.x| |%#2.x|\n", 0, 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x|\n", 0, 0, 0, 0, 0));
	printf("%d\n", printf("|%#01.x| |%02.x| |%-03.x| |%1.x| |%2.x|\n", 0, 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%-.1x| |%-.2x| |%5.x| |%-5.x|\n", 0, 0, 0, 0));
	printf("%d\n", printf("|%-.1x| |%-.2x| |%5.x| |%-5.x|\n", 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x|\n", 0, 0, 0, 0, 0));
	printf("%d\n", printf("|%10.x| |%-10.x| |%10.x| |%10.x| |%-10.x|\n", 0, 0, 0, 0, 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#01x| |%#0.10x| |%#010x| |%#0-10x| |%#0+10x|\n", 4, 2, 4, 1, 5));
	printf("%d\n", printf("|%#01x| |%#0.10x| |%#010x| |%#0-10x| |%#0+10x|\n", 4, 2, 4, 1, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf(" |%#0+10.x| |%#0-10.x| |%+1.0x| |%+0.2x|\n", 9, 8, 15488, 203));
	printf("%d\n", printf(" |%#0+10.x| |%#0-10.x| |%+1.0x| |%+0.2x|\n", 9, 8, 15488, 203));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%+1.1x| |%+2.0x| |%+3.1x| |%+1.0x| |%+2.1x|\n", 15, 300, 140, 9, 7));
	printf("%d\n", printf("|%+1.1x| |%+2.0x| |%+3.1x| |%+1.0x| |%+2.1x|\n", 15, 300, 140, 9, 7));
	printf("\n");	
	ft_printf("%d\n", ft_printf("|% .10lx| |%-.10x| |%+.10x| |% .10x| |%- .5x|\n", 4, 2, 4, 1, 5));
	printf("%d\n", printf("|% .10lx| |%-.10x| |%+.10x| |% .10x| |%- .5x|\n", 4, 2, 4, 1, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x|\n", 4, 2, 4, 1, 5));
	printf("%d\n", printf("|%10.lx| |%-10.x| |%10.x| |%10.x| |%-10.x|\n", 4, 2, 4, 1, 5));
	printf("\n");
	ft_printf("%d\n", ft_printf(" |%5.x| |%-5.x| |%+ .5x| |%+ .10x|\n", 9, 8, 9, 8));
	printf("%d\n", printf(" |%5.x| |%-5.x| |%+ .5x| |%+ .10x|\n", 9, 8, 9, 8));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%x|\n", 0));
	printf("%d\n", printf("|%x|\n", 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#X|\n", 0));
	printf("%d\n", printf("|%#X|\n", 0));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%#x|\n", 0x78aa));
	printf("%d\n", printf("|%#x|\n", 0x78aa));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%.x|\n", 12));
	printf("%d\n", printf("|%.x|\n", 12));
	printf("\n");
	ft_printf("%d\n", ft_printf("|%0#x|\n", 0));
	printf("%d\n", printf("|%0#x|\n", 0));
	printf("\n");*/
	return (0);
}
