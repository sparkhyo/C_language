/* Name: phoneFunc.c  ver 1.7
 * Content: 전화번호 컨트롤 함수
 * Implementation: PHS
 * 
 * Last modified 2018/11/21
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData=0;

//phoneData phoneList[LIST_NUM];
phoneData * phoneList[LIST_NUM];

void StoreDataToFileInStruct(void)
{
	int i;

	FILE * fp = fopen("phoneNum.dat", "wb");
	if(fp==NULL)
	{
		puts("파일 'phoneNum.dat'가 열리지 않습니다.");
		return;
	}
	fwrite(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		fwrite(phoneList[i], sizeof(phoneData), 1, fp);
		free(phoneList[i]);
	}

	fclose(fp);
}

void LoadDataFromFileInStruct(void)
{
	int i=0;

	FILE * fp = fopen("phoneNum.dat", "rb");
	if(fp==NULL)
	{
		puts("파일 'phoneNum.dat'가 열리지 않습니다.");
		return;
	}
	
	fread(&numOfData, sizeof(int), 1, fp);
	for(i=0; i<numOfData; i++)
	{	
		phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
		fread(phoneList[i], sizeof(phoneData), 1, fp);
	}

	fclose(fp);
}

void InputPhoneData(void)
{
	//phoneData data;
	phoneData * pData;
	
	int i;

	if(numOfData >= LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}

	pData = (phoneData *)malloc(sizeof(phoneData));

	fputs("이름 입력: ", stdout);
	fgets(pData->name, NAME_LEN, stdin);

	fputs("전화번호 입력: ", stdout);
	fgets(pData->phoneNum, PHONE_LEN, stdin);
	
	for(i = 0; i < numOfData; i++)
	{
		if( !strcmp(phoneList[i]->name, pData->name) && 
		    !strcmp(phoneList[i]->phoneNum, pData->phoneNum) )
		{
			puts("이미 입력된 데이터 입니다.");
			free(pData); //주의
			getchar();
			return;
		}
	}
	
	phoneList[numOfData] = pData;
	numOfData += 1; 

	StoreDataToFileInStruct();

	puts("입력이 완료되었습니다.");
	getchar();
}

void ShowAllData(void)
{
	int i;
	LoadDataFromFileInStruct();

	for(i = 0; i < numOfData; i++)
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}
	puts("출력이 완료되었습니다.");
	getchar();
}

void SearchPhoneData(void)
{
	int i;
	LoadDataFromFileInStruct();
	
	//phoneData data; 
	//이름만 비교하기 때문에 굳이 구조체형 변수를 선언 할 필요가 없다.

	char searchName[NAME_LEN];

	fputs("찾는 이름은? ", stdout);
	fgets(searchName, NAME_LEN, stdin);

	for(i = 0; i < numOfData; i++)
	{
		if( !strcmp(phoneList[i]->name, searchName) )
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			if(i == numOfData-1)
			{
				puts("검색이 완료되었습니다.");
				getchar();
				return;
			}
		}
	}

	puts("찾는 이름의 데이터가 존재하지 않습니다.");
	getchar();
}

void DeletePhoneData(void)
{
	/*
	 	변수는 올바른 이름으로 명확하게 선언하자.
	 */

	/*
	int i;
	int j = 0;
	int choice;
	//phoneData data;
	char delName[NAME_LEN];
	int num[LIST_NUM];
	phoneData * temp[LIST_NUM];

	fputs("삭제할 이름은? ", stdout);
	fgets(delName, NAME_LEN, stdin);
	
	for(i = 0; i < numOfData; i++)
	{	
		if( !strcmp(phoneList[i]->name, delName) )
		{
			temp[j] = phoneList[i];
			num[j] = i;
			j++;
		}		
	}

	if(j == 1)
	{
		free(temp[j-1]);

		for(j=num[j-1]; j < numOfData-1; j++)
		{
			phoneList[j] = phoneList[j+1];
		}
		numOfData--;
		puts("삭제가 완료되었습니다.");
		getchar();
		return;
	}
	else if(j == 0)
	{
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}

	for(i = 0; i < j; i++)
	{
		printf("NUM. %d\n", i+1);
		ShowPhoneInfoByPtr(temp[i]);
	}
	
	fputs("선택: ", stdout);
	scanf("%d", &choice);
	while(getchar() != '\n');

	free(temp[choice-1]);

	for(j=num[choice-1]; j < numOfData-1; j++)
	{
		phoneList[j] = phoneList[j+1];
	}

	numOfData--;
	puts("삭제가 완료되었습니다.");
	getchar();
	*/

	int i;
	char delName[NAME_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount=0;
	int selection=0;
	int delIdx=0;

	fputs("찾는 이름은? ", stdout);
	fgets(delName, NAME_LEN, stdin);

	for(i=0; i<numOfData; i++)
	{
		if( !strcmp(phoneList[i]->name, delName) )
			idxOfMatchingData[matchedCount++]=i;
	}

	if(matchedCount == 0)
	{
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}
	else if(matchedCount == 1)
	{
		delIdx = idxOfMatchingData[0];
	}
	else
	{
		for(i=0; i<matchedCount; i++)
		{
			printf("NUM. %d \n", i+1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		fputs("선택 : ", stdout);
		scanf("%d", &selection);
		while(getchar() != '\n');
		
		delIdx = idxOfMatchingData[selection-1];
	}

	free(phoneList[delIdx]);

	for(i=delIdx; i<numOfData-1; i++)
	{
		phoneList[i] = phoneList[i+1];
	}
	numOfData--;

	StoreDataToFileInStruct();
	puts("삭제가 완료되었습니다.");
	getchar();
}

void StoreDataToFile(void)
{
	int i;

	FILE * fp = fopen("phoneNum.dat", "w");
	if(fp==NULL)
	{
		puts("파일 'phoneNum.dat'가 열리지 않습니다.");
		return;
	}
	fwrite(&numOfData, sizeof(int), 1, fp);

	for(i=0; i<numOfData; i++)
	{
		fputs(phoneList[i]->name, fp);
		fputs(phoneList[i]->phoneNum, fp);
		free(phoneList[i]);
	}

	fclose(fp);
}

void LoadDataFromFile(void)
{
	int i=0;

	FILE * fp = fopen("phoneNum.dat", "r");
	if(fp==NULL)
	{
		puts("파일 'phoneNum.dat'가 열리지 않습니다.");
		return;
	}
	
	fread(&numOfData, sizeof(int), 1, fp);
	for(i=0; i<numOfData; i++)
	{	
		phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
		fgets(phoneList[i]->name, NAME_LEN, fp);
		fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);
	}

	fclose(fp);
}

void ChangePhoneData(void)
{
	int i;
	char chName[NAME_LEN];

	int idxOfMatchingData[LIST_NUM];
	int matchedCount=0;
	int selection=0;
	int chIdx=0;

	fputs("변경 대상의 이름은? ", stdout);
	fgets(chName, NAME_LEN, stdin);

	for(i=0; i<numOfData; i++)
	{
		if( !strcmp(phoneList[i]->name, chName) )
			idxOfMatchingData[matchedCount++]=i;
	}

	if(matchedCount == 0)
	{
		puts("찾는 이름의 데이터가 존재하지 않습니다.");
		getchar();
		return;
	}
	else if(matchedCount == 1)
	{
		chIdx = idxOfMatchingData[0];
	}
	else
	{
		for(i=0; i<matchedCount; i++)
		{
			printf("NUM. %d \n", i+1);
			ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
		}

		fputs("선택 : ", stdout);
		scanf("%d", &selection);
		while(getchar() != '\n');
		
		chIdx = idxOfMatchingData[selection-1];
	}

	fputs("변경할 전화번호는? ", stdout);
	fgets(phoneList[chIdx]->phoneNum, PHONE_LEN, stdin);
	// 010-1234-5678에서 123으로 변경하면 123-1234-5678로 출력 될 것이라고
	// 예측 했는데 123으로 출력된다. 어떻게 이렇게 되는것인가?
	// 이 부분에 대한 이해가 부족하다.

	StoreDataToFileInStruct();

	puts("변경이 완료되었습니다.");
	getchar();

}

/* end of file */
