/* Name: screenOut.h  ver 1.1
 * Content:
 * Implementation: PHS
 * 
 * Last modified 2018/11/17
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);

void ShowPhoneInfo(phoneData phone);

void ShowPhoneInfoByPtr(const phoneData * pPhone);
#endif

/* end of file */

