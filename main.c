#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

struct stat stat1, stat2;
struct tm *time1, *time2;
int mon1, mon2, d1, d2;
int h1, h2, min1, min2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(void)
{
    char* file1 = "text1";
    if(stat(file1,&stat1) < 0)
    {
	printf("%s is not exist!\n",file1);
	exit(0);
    }
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
    char* file2 = "text2";
    if(stat(file2,&stat2) <0)
    {
	printf("%s is not exist\n",file2);
	exit(0);
    }
}


//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
    time1 = localtime(&stat1.st_mtime);
    mon1 = time1->tm_mon;
    d1 = time1->tm_mday;
    h1 = time1->tm_hour;
    min1 = time1->tm_min;
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
    time2 = localtime(&stat2.st_mtime);
    mon2 = time2->tm_mon;
    d2 = time2->tm_mday;
    h2 = time2->tm_hour;
    min2 = time2->tm_min;
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	int file1_size = stat1.st_size;
	int file2_size = stat2.st_size;

	// compare with size text1 & text2
	if (file1_size == file2_size)
		printf("sizes are equal\n");
	else
	{
		if (file1_size > file2_size)
			printf("text1 is bigger\n");
		else
			printf("text2 is bigger\n");
	}
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	int file1_blk_amount = stat1.st_blksize;
	int file2_blk_amount = stat2.st_blksize;

	// compare with block size text1 & text2
	if (file1_blk_amount == file2_blk_amount)
		printf("sizes are equal\n");
	else
	{
		if (file1_blk_amount > file2_blk_amount)
			printf("text1 is bigger\n");
		else
			printf("text2 is bigger\n");
	}
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	int result = 0;


	if(d1 < d2)
		result = 1;
	if(d1 > d2)
		result = 2;
	if(mon1 < mon2)
		result = 1;
	if(mon1 > mon2)
		result = 2;

	if(result == 0)
		printf("same time\n");
	else if(result == 1)
		printf("text1 is early\n");
	else
		printf("text2 is early\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(void)
{
	int result = 0;

	if(min1 < min2)
		result = 1;
	if(min1 > min2)
		result = 2;
	if(h1 < h2)
		result = 1;
	if(h1 > h2)
		result = 2;

	if(result == 0)
		printf("same time\n");
	else if(result == 1)
		printf("text1 is early\n");
	else
		printf("text2 is early\n");
}
