/*
 * file name: clock.c
 * author   : Yu Liu
 * email    : <ilhanwnz@hotmail.com>
 * time     : Tue 23 Oct 2018 10:21:03 AM CST
 */

#include <include/ninix/inline-asm.h>
#include <kernel/rtc_clock.h>

unsigned long mc146818_read(unsigned reg)
{
	unsigned long ret; 
	outb(CMOS_RTC, reg);
	ret = inb(CMOS_RTC + 1);
	return ret;
}

unsigned long mc146818_write(unsigned reg, unsigned data)
{
	outb(CMOS_RTC, reg);
	outb(CMOS_RTC + 1, data);
}
static uin32_t nvram_read(int reg) 
{
	uint32_t ret;
	ret = mc146818_read(reg) | (mc146818_read(reg + 1) << 8);
	return ret; 
}
static void i386_find_memory(void)
{
	uint32_t base_memory, ext_memory, total_memory;
	base_memory = nvram_read(NVRAM_BASELSB);
	ext_memory  = nvram_read(NVRAM_EXTLSB);
	total_memory = ext_memory ? (1024 + ext_memory) : base_memory;
	kprintf("Physical memory: %uK available, base memory: %uK,
			extend memory = %uK\n",
			total_memory, base_memory, ext_memory);
}

