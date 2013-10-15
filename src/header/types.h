
#ifndef __TYPES_H__
#define __TYPES_H__

typedef char int8;
typedef char INT8;
typedef char int8_t;
typedef char INT8_t;
typedef unsigned char uchar;
typedef unsigned char UCHAR;
typedef unsigned char uint8;
typedef unsigned char UINT8;
typedef unsigned char uint8_t;
typedef unsigned char UINT8_t;
typedef unsigned char byte;
typedef unsigned char BYTE;

typedef int int16;
typedef int INT16;
typedef int int16_t;
typedef int INT16_t;

typedef unsigned int uint16;
typedef unsigned int UINT16;
typedef unsigned int uint16_t;
typedef unsigned int UINT16_t;

typedef long int32;
typedef long INT32;
typedef long int32_t;
typedef long INT32_t;

typedef unsigned long uint32;
typedef unsigned long UINT32;
typedef unsigned long uint32_t;
typedef unsigned long UINT32_t;


typedef unsigned char _BOOL;
#define _BOOL bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#ifndef NULL
#define NULL (void*)0
#endif


#endif