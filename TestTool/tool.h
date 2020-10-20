#ifndef _TOOL_H
#define _TOOL_H

#define TT_LEVEL			(0)
#if TT_LEVEL > 0
	#define TT_PRINT(format, args...) do {\
				printf("[%s: %d] "format"\n", __FUNCTION__, __LINE__, ##args);\
			} while(0)
#else
	#define TT_PRINT(format, args)
#endif

#endif