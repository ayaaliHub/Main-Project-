/*
 * MemMap.h
 *
 * Created: 9/25/2024 6:20:03 AM
 *  Author: ayaali
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

/* For Peripheral: DIOD */
#define  PORTD  (*(volatile u8*)0x32)
#define  DDRD   (*(volatile u8*)0x31)
#define  PIND    (*(volatile u8*)0x30)
/* For Peripheral: DIOC */
#define  PORTA   (*(volatile u8*)0x35)
#define  DDRC    (*(volatile u8*)0x34)
#define  PINC    (*(volatile u8*)0x33)

/* For Peripheral: DIOB */
#define  PORTB   (*(volatile u8*)0x38)
#define  DDRB    (*(volatile u8*)0x37)
#define  PINB   (*(volatile u8*)0x36)
/* For Peripheral: DIOA */
#define  PORTA  (*(volatile u8*)0x3B)
#define  DDRA    (*(volatile u8*)0x3A)
#define  PINA    (*(volatile u8*)0x39)


#endif /* MEMMAP_H_ */