#ifndef STDTYPES_H_
#define STDTYPES_H_

/* For Char type */
typedef unsigned char    u8;
typedef signed char    s8;

/* For Short type */
typedef unsigned short    u16;
typedef signed short    s16;

/* For Long type */
typedef unsigned long    u32;
typedef signed long     s32;

/* For Ranges */
#define  MAX_u16     ((u16)65535)
#define  MIN_u16     ((u16)0)
#define  MAX_s16     ((s16)32767)
#define  MIN_s16     ((s16)-32768)

/* For Typedef: If Condition */
typedef enum{
	FALSE=0x55,
	TRUE=0xAA
}bool_t;

/* For Error Types */
typedef enum{
	OK=0,
	NOK,
	NULL_PTR,
	OUT_OF_RANGE,
	BUSY,

}error_t;

/* For REG Functions */
#define  GET_BIT(reg,bit)     (((reg)>>(bit))&1)                   // Determining the value of Bit
#define  SET_BIT(reg,bit)     ((reg)=((reg)|(1<<(bit))))           // Setting a 1 to bit register
#define  CLR_BIT(reg,bit)     ((reg)=((reg)&~(1<<(bit))))          // Clearing Bit to 0
#define TOG_BIT(reg,bit)      ((reg) ^= (reg << (bit)))	          // Inverting the state of Bit

#endif /* STDTYPES_H_ */