#ifndef _ASSERT_H
#define _ASSERT_H

#define assert(condition) ((void)((condition) || (assert_failed(#condition, __FILE__, __LINE__), 0)))

void assert_failed(const char *expression, const char *file, int line);

#endif 
