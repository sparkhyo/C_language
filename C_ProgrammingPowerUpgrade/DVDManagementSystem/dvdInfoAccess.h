/* Name : dvdInfoAccess.h	ver 1.0
 * Content : DVD 정보 저장 및 참조 함수들의 선언
 * Implementation : PHS
 *
 * Last modified 2019/01/17
 */

#ifndef __DVDACCESS_H__
#define __DVDACCESS_H__

#include "dvdInfo.h"

int AddDVDInfo(char * ISBN, char * title, int genre);
dvdInfo * GetDVDPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);

#endif
/* end of file */
