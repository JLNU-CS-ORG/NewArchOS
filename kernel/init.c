/*
 * file name: init.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Fri 19 Oct 2018 10:06:24 AM CST
 */

#include <include/ninix/kstring.h>
#include <include/ninix/console.h>
#include <include/ninix/kstdio.h>
#include <include/ninix/interrupt.h>

void kpanic(const char *msg);
void i386_init(void)
{
	extern char edata[], end[];

	memset(edata, 0, end - edata);

	console_init();
	int ret = kputs(KERN_WARNING, "Testing CGA.\n");
	if (ret) 
		kputs(KERN_INFO, "Test successful.\n\n"
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
	kputs(KERN_WARNING, msg);
died:
	while (1); 
}
