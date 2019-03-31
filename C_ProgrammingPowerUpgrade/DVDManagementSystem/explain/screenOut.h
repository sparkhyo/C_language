/*	Name : screenOut.h	ver 1.0
 *	Content : 콘솔 출력을 위한 함수들의 선언
 *	Implementation : PHS
 *
 *	Last modified 2019/01/17
 */

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "cusInfo.h"
#include "dvdInfo.h"
#include "rentInfo.h"

void ShowMenu(void);
void ShowCustomerInfo(cusInfo * pCus);
void ShowCustomerInfoContinue(cusInfo * pCus);
void ShowGenre(int gen);
void ShowDVDInfo(dvdInfo * pDVD);
void ShowDVDRentInfoContinue(dvdRentInfo dvd);

#endif
/* end of file */
