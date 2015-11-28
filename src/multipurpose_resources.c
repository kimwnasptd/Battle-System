#include "get_attr.h"
#include "types.h"

u16 rand(void);
u32 divmod_remainder(u32, u32);
u32 div(u32, u32);
void *malloc(u32 size);
void free(void *ptr);

u32 random(u32 end) {
	u32 result = (u32) rand();
	return (divmod_remainder(result, end));
}

u32 get_attr(u32 *pokemon, u8 arg) {
	return (get_attribute(*pokemon, arg));
}