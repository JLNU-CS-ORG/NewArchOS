/*
 * file name: init.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 19 Oct 2018 10:06:24 AM CST
 */

#include <include/string.h>
#include <include/console.h>
#include <include/stdio.h>
#include <include/interrupt.h>

void kpanic(const char *msg);
void i386_init(void)
{
	extern char edata[], end[];

	memset(edata, 0, end - edata);

	console_init();
	int ret = kputs("Testing CGA.\n");
	if (ret) 
		kputs("Test successful.\n\n"
		"Welcome into NINIX kernel!\n"); 	
#if 1
	/* Shouldn't got here */
	kpanic("Just a debug information, disabled it!\n");
#endif 
		
}

void kpanic(const char *msg)
{
	/* Use kprintf or kputs implements */
	cli();
	cga_set_attribute(FONT_ERR);
	kputs(msg);
died:
	while (1); 
}
