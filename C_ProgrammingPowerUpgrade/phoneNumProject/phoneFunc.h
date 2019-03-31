/* Name: phoneFunc.h  ver 1.4
 * Content:
 * Implementation: PHS
 * 
 * Last modified 2018/11/21
 */
#ifndef __PHONEFUNC_H__
#define __PHONEFUNC_H__

#include "phoneData.h"

void StoreDataToFileInStruct(void);
void LoadDataFromFileInStruct(void);

void InputPhoneData(void);
void ShowAllData(void);

void SearchPhoneData(void);
void DeletePhoneData(void);

void StoreDataToFile(void);
void LoadDataFromFile(void);

void ChangePhoneData(void);

#endif

/* end of file */
