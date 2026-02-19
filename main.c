/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzu <zuzu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:27:59 by zuzu              #+#    #+#             */
/*   Updated: 2026/02/19 23:51:38 by zuzu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	ret1, ret2;

	// %c
	printf("\n===== character =====\n");
	ret1 = ft_printf("Char: %c\n", 'A');
	ret2 = printf("Char: %c\n", 'A');

	// %s
	printf("\n===== string =====\n");
	ret1 = ft_printf("String: %s%s%s\n", "Hello", "Hello", "Hello");
    ret2 = printf("String: %s%s%s\n", "Hello", "Hello", "Hello");
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	//%p
	printf("\n===== pointer =====\n");
	int num = 42;
	ret1 = ft_printf("Pointer: %p\n", &num);
    ret2 = printf("Pointer: %p\n", &num);
	printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

    // %d
	printf("\n===== decimal =====\n");
	ret1 = ft_printf("Decimal: %d\n", 888);
    ret2 = printf("Decimal: %d\n", 888);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	// %i
	printf("\n===== integer =====\n");
	ret1 = ft_printf("Integer: %i\n", -5778844);
    ret2 = printf("Integer: %i\n", -5778844);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	ret1 = ft_printf("Integer: %i\n", INT_MIN);
    ret2 = printf("Integer: %i\n", INT_MIN);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);


	// %u
	printf("\n===== unsigned decimal =====\n");
	ret1 = ft_printf("unsigned decimal: %u\n", 5778844);
    ret2 = printf("unsigned decimal: %u\n", 5778844);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	ret1 = ft_printf("unsigned decimal: %u\n", UINT_MAX);
    ret2 = printf("unsigned decimal: %u\n", UINT_MAX);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	// %x
	printf("\n===== hexadecimal number lower =====\n");
	ret1 = ft_printf("Hexadecimal number lower: %x\n", 255);
    ret2 = printf("Hexadecimal number lower: %x\n", 255);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);
	ret1 = ft_printf("Hexadecimal number lower: %x\n", 0);
    ret2 = printf("Hexadecimal number lower: %x\n", 0);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	// %X
	printf("\n===== hexadecimal number upper =====\n");
	ret1 = ft_printf("Hexadecimal number upper: %X\n", 5778844);
    ret2 = printf("Hexadecimal number upper: %X\n", 5778844);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

    // %%
	printf("\n===== percent =====\n");
	ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	// mix
	printf("\n===== mix =====\n");
	ret1 = ft_printf("%c%c%c*", '\0', '1', 1);
    ret2 = printf("%c%c%c*", '\0', '1', 1);
    printf("ft_printf returned: %d, printf returned: %d\n", ret1, ret2);

	int ret_mine, ret_real;

    printf("--- 测试无效转换符 (%%y) ---\n");
    // 测试 %y (y 不是定义的转换符)
    ret_mine = ft_printf("Mine: [%y]\n");
    ret_real =    printf("Real: [%y]\n");
    printf("返回值: Mine: %d | Real: %d\n\n", ret_mine, ret_real);

    printf("--- 测试末尾单独的 %% ---\n");
    // 测试字符串末尾只有一个 %
    ret_mine = ft_printf("Mine: [%%]\n"); // 注意：C语言中代码里写 %% 代表打印一个 %
    ret_real =    printf("Real: [%%]\n");
    printf("返回值: Mine: %d | Real: %d\n\n", ret_mine, ret_real);

    printf("--- 测试无效格式跟随有效格式 ---\n");
    ret_mine = ft_printf("Mine: %y %s %k\n", "test");
    ret_real =    printf("Real: %y %s %k\n", "test");
    printf("返回值: Mine: %d | Real: %d\n", ret_mine, ret_real);

    return (0);
}
