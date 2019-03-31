/*	Name : blManager.h		ver 1.0
 *	Content : 관련 업무 처리 함수들의 선언
 *  Implementation : PHS
 *
 *	Last modified 2019/01/23
 */

#ifndef __BLMGR_H__
#define __BLMGR_H__

void InitData(void);

void RegistCustomer(void);
void SearchCusInfo(void);

void RegistDVD(void);
void SearchDVDInfo(void);
void RentDVD(void);
void ReturnDVD(void);
void ShowDVDRentAllCusInfo(void);
void ShowCusRentAllDVDInfo(void);


#endif
/* end of file */
