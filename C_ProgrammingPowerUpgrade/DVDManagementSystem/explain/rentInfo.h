/*	Name : rentInfo.h	ver 1.0
 *	Content : 영화 DVD 대여 정보 구조체
 *	Implementation : PHS
 *
 *	Last modified 2019/01/22
 */

#ifndef __RENTINFO_H__
#define __RENTINFO_H__

#include "dvdInfo.h"
#include "cusInfo.h"

typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];		// 대여 고객 ID
	char ISBN[ISBN_LEN];	// 대여 DVD ISBN, 새로 추가된 멤버
	unsigned int rentDay;	// 대여일
} dvdRentInfo;
#endif
/* end of file */
