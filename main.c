#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

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
    stat(file1,&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(void)
{
    char* file2 = "text2";
    stat(file2,&stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(void)
{
    time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(void)
{
    time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(void)
{
	char *file1 = "text1";
	char *file2 = "text2";

	stat(file1, &stat1);
	stat(file2, &stat2);

	int file1_size = 0;
	int file2_size = 0;

	// stat.st_size text1 & text2
	if (0 > file1)
		printf("Text1 is not exist.\n");
	else
		file1_size = stat1.st_size;
	if (0 > file2)
		printf("Text2 is not exist.\n");
	else
		file2_size = stat2.st_size;

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
	printf("\n");

}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(void)
{
	char *file1 = "text1";
	char *file2 = "text2";

	stat(file1, &stat1);
	stat(file2, &stat2);

	int file1_size = 0;
	int file2_size = 0;

	// stat.st_blocksize text1 & text2
	if (0 > file1)
		printf("Text1 is not exist.\n");
	else
		file1_size = stat1.st_blksize;
	if (0 > file2)
		printf("Text2 is not exist.\n");
	else
		file2_size = stat2.st_blksize;

	// compare with block size text1 & text2
	if (file1_size == file2_size)
		printf("sizes are equal\n");
	else
	{
		if (file1_size > file2_size)
			printf("text1 is bigger\n");
		else
			printf("text2 is bigger\n");
	}
	printf("\n");

}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(void)
{
	char* file1 = "text1";
	char* file2 = "text2";

	int result = 0;
	int m1, d1;
	int m2, d2;

	m1 = time1->tm_mon;
	d1 = time1->tm_mday;

	m2 = time2->tm_mon;
	d2 = time2->tm_mday;

	if(d1 < d2)
		result = 1;
	if(d1 > d2)
		result = 2;
	if(m1 < m2)
		result = 1;
	if(m1 > m2)
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
	char* file1 = "text1";
	char* file2 = "text2";

	int result = 0;
	int h1, m1;
	int h2, m2;

	h1 = time1->tm_hour;
	m1 = time1->tm_min;

	h2 = time2->tm_hour;
	m2 = time2->tm_min;

	if(m1 < m2)
		result = 1;
	if(m1 > m2)
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
