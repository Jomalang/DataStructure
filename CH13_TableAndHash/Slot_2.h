#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

typedef struct _slot
{
	Key key;
	Value val;
}Slot;

// Slot과 관련해서는 별도의 함수를 정의하지 않는다.
#endif