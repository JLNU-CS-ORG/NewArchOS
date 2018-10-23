/*
 * file name: lib/printf.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Sat 20 Oct 2018 09:49:22 AM CST
 */

#include <include/ninix/kstdio.h>
#include <include/ninix/console.h>

#define kputchar(c) 	cga_putc(c)

inline int kputs(enum cons_stat cs, const char *s)
{
	switch (cs) {
	case KERN_DEFAULT:
	case KERN_INFO:
		cga_set_attribute(FONT_DEF);
		break;
	case KERN_WARNING:
		cga_set_attribute(FONT_ERR);
		break;
	default:
		cga_set_attribute(FONT_DEF);
		break; 
	}
	int ret = 0; 
	while (*s != '\0') {
		kputchar(*s);
		s++;
		ret++;
	}
	return ret; 	/* return strlen(puts) */
}

int kprintf(enum cons_stat cs, const char *fmt, ...)
{
	return 0;	
}
