#include<stdio.h>
void	ft_printf(char *arg, ...);

int main(){
	char *str = "test";
	//int	num = 2578;
	ft_printf("ft_printf : %p\n", str);
	printf("printf    : %p\n", str);
}
