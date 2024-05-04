#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>

char test(unsigned int a, char b)
{
	a -= a;
	return (b + 1);
}
void test1(unsigned int index, char *s)
{
	if (index != 3)
		*s = 'G';
}
int main (void)
{
	/* TOUPPER */
	int to_upper_c = -512;

	while(to_upper_c != 512)
	{
		if (ft_toupper(to_upper_c) != toupper(to_upper_c))
			printf("%c, %c\n", ft_toupper(to_upper_c), toupper(to_upper_c));
		to_upper_c++;
	}
	printf("toupper done!\n");
	/* TOLOWER */
	int to_lower_c = -512;

	while(to_lower_c != 512)
	{
		if (ft_tolower(to_lower_c) != tolower(to_lower_c))
			printf("%c, %c\n", ft_tolower(to_lower_c), tolower(to_lower_c));
		to_lower_c++;
	}
	printf("tolower done!\n");
	/* IS_ALPHA */
	int is_alpha_c = -512;

	while(is_alpha_c != 512)
	{
		if (ft_isalpha(is_alpha_c) != isalpha(is_alpha_c))
			printf("%c, %c\n", ft_isalpha(is_alpha_c), isalpha(is_alpha_c));
		is_alpha_c++;
	}
	printf("isalpha done!\n");

	/* IS_DIGIT */

	int is_digit_c = -512;

	while(is_digit_c != 512)
	{
		if (ft_isdigit(is_digit_c) != isdigit(is_digit_c))
			printf("%c, %c\n", ft_isdigit(is_digit_c), isdigit(is_digit_c));
		is_digit_c++;
	}
	printf("isdigit done!\n");

	/* IS_ALNUM */

	int is_alnum_c = -512;

	while(is_alnum_c != 512)
	{
		if (ft_isalnum(is_alnum_c) != isalnum(is_alnum_c))
			printf("%c, %c\n", ft_isalnum(is_alnum_c), isalnum(is_alnum_c));
		is_alnum_c++;
	}
	printf("isalnum done!\n");
	
	/* IS_ASCII */
	int is_ascii_c;

	is_ascii_c = -512;

	while(is_ascii_c != 512)
	{
		if (ft_isascii(is_ascii_c) != isascii(is_ascii_c))
			printf("%c, %c\n", ft_isascii(is_ascii_c), isascii(is_ascii_c));
		is_ascii_c++;
	}
	printf("isascii done!\n");
	
	/* IS_PRINT */

	int is_print_c = -512;

	while(is_print_c != 512)
	{
		if (ft_isprint(is_print_c) != isprint(is_print_c))
			printf("%c, %c\n", ft_isprint(is_print_c), isprint(is_print_c));
		is_print_c++;
	}
	printf("isprint done!\n");

	/* STRCHR */

	int is_strchr_c = -512;
	char *strchr_s = "some sasd string we have";
	while(is_strchr_c != 512)
	{
		if (ft_strchr(strchr_s, is_strchr_c) != strchr(strchr_s, is_strchr_c))
			printf("%s, %s, %d\n", ft_strchr(strchr_s, is_strchr_c), strchr(strchr_s, is_strchr_c), is_strchr_c);
		is_strchr_c++;
	}
	printf("strchr done!\n");
	/* STRRCHR */

	int is_strrchr_c = -512;
	char *strrchr_s = "some sasd string we have";
	while(is_strrchr_c != 512)
	{
		if (ft_strrchr(strrchr_s, is_strrchr_c) != strrchr(strrchr_s, is_strrchr_c))
			printf("%s, %s\n", ft_strrchr(strrchr_s, is_strrchr_c), strrchr(strrchr_s, is_strrchr_c));
		is_strrchr_c++;
	}
	printf("strrchr done!\n");

	/* strlen */
	// TODO: introduce huge string to test
	char *strlen_s = "here is some string to count its length";
	if(ft_strlen(strlen_s) != strlen(strlen_s))
		printf("%s\n", strlen_s);
	printf("strlen done!\n");

	/* memset */
	void *sys_memset_b = 0;
	void *ft_memset_b = 0;

   	sys_memset_b = (void *)malloc(10 * sizeof(char));
   	ft_memset_b = (void *)malloc(10 * sizeof(char));

	sys_memset_b = memset(sys_memset_b, 'd', 10);
	ft_memset_b = ft_memset(ft_memset_b, 'd', 10);
	if (memcmp(sys_memset_b, ft_memset_b, 11) != 0)
		printf("%s", ft_memset_b);
	free(ft_memset_b);
	free(sys_memset_b);
	printf("memset done!\n");

	/* bzero */
	char *ft_bzero_s = malloc(10*sizeof(char *));
	char *sys_bzero_s = malloc(10*sizeof(char *));

	ft_bzero((void *)ft_bzero_s, 10);
	bzero((void *)sys_bzero_s, 10);
	
	if (memcmp(ft_bzero_s, sys_bzero_s, 10))
		printf("something wrong with bzero");
	free(ft_bzero_s);
	free(sys_bzero_s);
	printf("bzero done!\n");

	/* memcpy */
	
	char ft_memcpy_dst[10];
	char sys_memcpy_dst[10];
	char ft_memcpy_src[10] = "yoyo";
	char sys_memcpy_src[10] = "yoyo";
	

	ft_memcpy((void *)ft_memcpy_dst, (void *)ft_memcpy_src,10);
	memcpy((void *)sys_memcpy_dst, (void *)sys_memcpy_src, 10);
	if(memcmp((void *)ft_memcpy_dst, (void *)sys_memcpy_dst, 10))
		printf("something wrong");
	printf("memcpy done!\n");
	
	/* memmove */
	int memmove_cache_size = 30;
	char sys_memmove_cache[memmove_cache_size];
	char ft_memmove_cache[memmove_cache_size];
	char *sys_ptr_dest;
	char *sys_ptr_src;
	char *ft_ptr_dest;
	char *ft_ptr_src;
	int curr;
	int length = 11;
	bzero(sys_memmove_cache, memmove_cache_size);
	bzero(ft_memmove_cache, memmove_cache_size);
	int sp_ft = 4;
	curr = 0;
	ft_ptr_src = &ft_memmove_cache[sp_ft];
	sys_ptr_src = &sys_memmove_cache[sp_ft];
	ft_ptr_dest = &ft_memmove_cache[sp_ft + 10];
	sys_ptr_dest = &sys_memmove_cache[sp_ft + 10];
	while (curr != memmove_cache_size)
	{
		sys_memmove_cache[curr] = 'a' + curr;
		ft_memmove_cache[curr] = 'a' + curr;
		curr++;
	}
	/*
	write(1, sys_memmove_cache, memmove_cache_size);
	write(1, "\n" ,1);
	write(1, ft_memmove_cache, memmove_cache_size);
	write(1, "\n" ,1);*/
	ft_memmove((void *)ft_ptr_dest, (void *)ft_ptr_src, length);
	memmove((void *)sys_ptr_dest, (void *)sys_ptr_src, length);
	if (memcmp(ft_memmove_cache, sys_memmove_cache, memmove_cache_size))
	{
//		printf("1st %d\n", memcmp(ft_memmove_cache, sys_memmove_cache, 20));
	write(1, sys_memmove_cache, memmove_cache_size);
	write(1, "\n" ,1);
	write(1, ft_memmove_cache, memmove_cache_size);
	write(1, "\n" ,1);
	}
	
	ft_memmove( (void *)ft_ptr_src,  (void *)ft_ptr_dest, length);
	memmove((void *) sys_ptr_src, (void *)sys_ptr_dest, length);

	if (memcmp(ft_memmove_cache, sys_memmove_cache, memmove_cache_size))
	{
		write(1, sys_memmove_cache, memmove_cache_size);
		write(1, "\n" ,1);
		write(1, ft_memmove_cache, memmove_cache_size);
		write(1, "\n" ,1);
	}
	printf("memmove done!\n");
	
	
	/* strlcpy  */
	int strlcpy_cache_length = 15;
	char ft_strlcpy_cache[15];
	char sys_strlcpy_cache[15];

	memset(ft_strlcpy_cache, 'h', strlcpy_cache_length);
	memset(sys_strlcpy_cache, 'h', strlcpy_cache_length);
	
	char *ft_cpyme = "hello world";

	int ft_strlcpy_return  = ft_strlcpy(ft_strlcpy_cache, ft_cpyme, strlcpy_cache_length);
	int sys_strlcpy_return = strlcpy(sys_strlcpy_cache, ft_cpyme, strlcpy_cache_length);
	
	if (memcmp(ft_strlcpy_cache, sys_strlcpy_cache, strlcpy_cache_length) || ft_strlcpy_return != sys_strlcpy_return)
	{
		write(1, "\n", 1);
		write(1, ft_strlcpy_cache, strlcpy_cache_length);
		write(1, "\n", 1);
		write(1, sys_strlcpy_cache, strlcpy_cache_length);
		write(1, "\n", 1);
	}
	write(1, "strlcpy done!\n", 14);

	/* strlcat */
	
	int strlcat_cache_length = 0;
	char ft_strlcat_cache[50] = "pqaasd";
	char sys_strlcat_cache[50] = "pqaasd";
	char *ft_catme = "hel";
	int ft_strlcat_return; // = ft_strlcat(ft_strlcat_cache, ft_catme, strlcat_cache_length);
	int sys_strlcat_return;// = strlcat(sys_strlcat_cache, ft_catme, strlcat_cache_length);

	while(strlcat_cache_length < 1)
	{
		ft_strlcat_return  = ft_strlcat(ft_strlcat_cache, ft_catme, strlcat_cache_length);
		sys_strlcat_return = strlcat(sys_strlcat_cache, ft_catme, strlcat_cache_length);
		if (memcmp(ft_strlcat_cache, sys_strlcat_cache, strlcat_cache_length) || ft_strlcat_return != sys_strlcat_return)
		{
			printf("ft_cache  : %s\n", ft_strlcat_cache);
			printf("sys_cache : %s\n", sys_strlcat_cache);
			printf("ft_return : %d\n", ft_strlcat_return);
			printf("sys_return: %d\n", sys_strlcat_return);
			printf("cachelength: %d\n", strlcat_cache_length);
		}
		strlcat_cache_length++;
	}
	
	
	printf("strlcat done!\n");
	/* strncmp */
	char *ft_strncmp_s1 = "some";
	char *ft_strncmp_s2 = "someradasdasdsadassdas";
	size_t ft_strncmp_n = 0;
	int ft_strncmp_return;
	int sys_strncmp_return;

	while (ft_strncmp_n != 10)
	{
		ft_strncmp_return = ft_strncmp(ft_strncmp_s1, ft_strncmp_s2, ft_strncmp_n);
		sys_strncmp_return = strncmp(ft_strncmp_s1, ft_strncmp_s2, ft_strncmp_n);
		ft_strncmp_n++;
		if (ft_strncmp_return != sys_strncmp_return)
			write(1, "strncmp error\n", 14);
	}

	write(1, "strncmp done!\n", 14);

	/* memchr */
	int is_memchr_c = -512;
	size_t memchr_n;
	char *memchr_s = "some sasd string we have";
//	char *memchr_s = "";
	while(is_memchr_c != 512)
	{
		memchr_n = 0;
		while(memchr_n < 24)
		{
			if (ft_memchr(memchr_s, is_memchr_c, memchr_n) != memchr(memchr_s, is_memchr_c, memchr_n))
				printf("%s, %s\n", ft_memchr(memchr_s, is_memchr_c, memchr_n), memchr(memchr_s, is_memchr_c, memchr_n));
			memchr_n++;
		}
		is_memchr_c++;
	}
	printf("memchr done!\n");

	/*  memcmp */
	char *memcmp_s1 = "asd";
	char *memcmp_s2 = "asdf";
	size_t memcmp_n = ft_strlen(memcmp_s2);
	int sys_memcmp_return = memcmp(memcmp_s1, memcmp_s2, memcmp_n);
	int ft_memcmp_return = ft_memcmp(memcmp_s1, memcmp_s2, memcmp_n);
	if (sys_memcmp_return != ft_memcmp_return)
		write(1, "memcmp error\n", 13);
	write(1, "memcmp done!\n", 13);
	
	/* strnstr */
	char *ft_strnstr_needle = "s";
	char *ft_strnstr_haystack = "asd";
	size_t ft_strnstr_len = ft_strlen(ft_strnstr_haystack);
	char *sys_strnstr_return;
	char *ft_strnstr_return;
	ft_strnstr_return = ft_strnstr(ft_strnstr_haystack, ft_strnstr_needle, ft_strnstr_len);
	sys_strnstr_return = strnstr(ft_strnstr_haystack, ft_strnstr_needle, ft_strnstr_len);
	if (sys_strnstr_return != ft_strnstr_return)
	{
		write(1, "strnstr error\n", 15);
	}
	write(1, "strnstr done!\n", 14);
	/* atoi */
	//do overflow underflow checks
	char *atoi_a = "12312331231231223123123";
	if (ft_atoi(atoi_a) != atoi(atoi_a))
		write(1, "smth wrong\n", 11);
	write(1, "atoi done!\n",12);
	/* calloc */



		/*
	void* k = malloc(sizeof(char) * 10);
	ft_memset(k, 97, 7);
	ft_bzero(k, 7);
	int i = 0;
	while (i < 7)
	{
		write(1, k, 1);
		write(1, "\n", 1);
		k++;
		i++;
	}*/
	/*
	
	char k[100] = "wow100";
	char z[100] = "wow";
	void* a = "somete";1000
	
	size_t res = ft_strlcat(k, a, 100);

	printf("%zu\n", res);
	printf("%zu\n", strlcat(z, a, 100));
	printf("%s\n", k);
	printf("%s\n", z);
*/
/*
	char some = ft_toupper('m');
	write(1, &some, 1);
	write(1, "\n", 1);
*/
//	char *l = ft_strchr("asd", 's');
//	char *l = ft_strchr("asd", 'm');
//	char *l = ft_strrchr("asdado", 'd');
//	char *l = ft_strchr("asd", 'd');
/*
	if (l)
		write(1, l, 2);
	else
		write(1, "no", 2);*/
	/*
	char *a = "some";
	char *b = "som";
	int k = ft_strncmp(a, b, 4);
	printf("%d\n", k);
	
	int z = strncmp(a, b, 4);
	printf("%d\n", z);*/
	/*
	void *yoo = "asd";
	void *zoo = "asf";
	int l = ft_memcmp(zoo, yoo, 3);
	printf("%d\n", l);

	int k = memcmp(zoo, yoo, 3);
	printf("%d\n", k);*/
	/*
	char *a = ft_strnstr("long ass message", "", 5);
	char *b = strnstr("long ass message", "", 5);
	printf("%s\n",a);
	printf("%s\n",b);*/
//	printf("%d\n", ft_atoi("-9223372036854775803"));
//	printf("%d\n", 	  atoi("-9223372036854775803"));
//	printf("%lu %ld \n", ULONG_MAX, LONG_MAX);
/*
	char *ptr = (char *)ft_calloc(10, sizeof(char));
	ptr[0] = 'a';
	ptr[1] = 'b';
	printf("%s", ptr);*/
/*	char  *a = ft_strdup("hello there");
	printf("%s", a);
	free(a);*/
	/*
	char *asd = "asdwow";
	char *ye = ft_strtrim(asd, "awos");
	printf("%s", ye);
	*/
/*	char *ups = ft_strjoin("asd", "wow");
	write(1, ups, 6);*/
/*	char **words;

	words = ft_split(message, ' ');
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}*/
/*
 
 	s1 = " Hello world "
	set = " Hd"
 "ello worl"
  
 */




	/*
	char *s = "  I ";
	char c = ' ';
	char **asd = ft_split(s, c);
	while (*asd != 0)
	{
		printf("%s\n", *asd);
		asd++;
	}
	char *m = ft_strmapi("abcd", test);
	write(1, m, ft_strlen(m));*/
	/*
	char ki[20] = "assd asd asd";
	ft_striteri(ki, test1);
*/
/*
	int a = open("test.txt", O_CREAT | O_APPEND | O_WRONLY, 0777 );
	if (a >= 0)
	{
		ft_putchar_fd('k', a);
		ft_putchar_fd('\n', a);
		ft_putstr_fd("asd", a);
		ft_putendl_fd("yo followed by nl", a);
		ft_putstr_fd("asd", a);
	}
*/
/*	
	ft_putnbr_fd(12312300, 1);
	ft_putchar_fd(1, '\n');
	*/
	/*
	char *some = "assd";
	t_list *a = ft_lstnew((void *)some);
	write(1, a->content, 4);
	write(1, "\n", 1);
	char next = (int)a->next + '0';
	write(1, &next, 1);*/
/*
	char *content1 = "asd";
	char *content2 = "wdsaf";

	t_list *o = ft_lstnew(content1);
	t_list *c = ft_lstnew(content2);
	ft_lstadd_front(&o, c);
	*/
	/*
	int l = ft_lstsize(c);
	char m = l + '0';
	write(1, &m, 1);
	write(1, "\n", 1);
	*/
//	t_list *some = ft_lstlast(o);
//	write(1, (char *)some->content, ft_strlen(some->content));
/*	
	char *content = "new in the end";
	t_list *new = ft_lstnew(content);
	ft_lstadd_back(&o, new);
	while (c->next)
	{
		write(1, c->content, ft_strlen(c->content));
		write(1, "\n", 1);
		c = c->next;
	}
	write(1, c->content, ft_strlen(c->content));
	*/
	return (0);
}
