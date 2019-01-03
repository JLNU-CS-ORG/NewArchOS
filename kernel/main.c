/*
 * file name: main.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Thu 03 Jan 2019 09:20:23 PM CST
 */

extern void i386_init();
extern void kpanic(const char *msg);

int main(void)
{
	i386_init();	
//	kpanic("Panic");
}
