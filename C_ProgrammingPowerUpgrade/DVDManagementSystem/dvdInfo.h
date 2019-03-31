/* Name : dvdInfo.h		ver 1.0
 * Content : 영화 DVD 관리 구조체
 * Implementation : PHS
 * 
 * Last modified 2019/01/18
 */

#ifndef __DVDINFO_H__
#define __DVDINFO_H__

#include "cusInfo.h"

#define ISBN_LEN	30
#define TITLE_LEN	30
#define RENT_LEN	100

enum {ACTION=1, COMIC, SF, ROMANTIC}; // 장르 정보
enum {RENTED, RETURNED}; // 대여 상태를 나타내는 상수!

/* 반납일등 추가할 정보 많지만 간략히! */
typedef struct __dvdRentInfo
{
	char cusID[ID_LEN];		// 대여 고객 ID
	unsigned int rentDay;	// 대여일
} dvdRentInfo;

typedef struct __dvdInfo
{
	char ISBN[ISBN_LEN];
	char title[TITLE_LEN];
	int genre;

	int rentState; // 대여 상태 정보
	int numOfRentCus;	// 등록된 대여 정보의 개수
	dvdRentInfo rentList[RENT_LEN];
}dvdInfo;

#endif
/* end of file */
