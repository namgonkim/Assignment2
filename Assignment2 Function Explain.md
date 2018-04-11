# Assignment2 Function Explain

본 과제는 linux Unbuntu 상에서 두개의 파일을 비교하는 프로그램이다.

프로그램을 구성하는 function의 기능은 아래와 같다.

===============================================================================

1. 파일 정보 받아오기

   - void filestat1() : file1의 정보를 가져오는 함수

   - void filestat2() : file2의 정보를 가져오는 함수

     ​

2. 파일시간 받아오기

   - void filetime1() : file1의 시간 정보를 가져오는 함수 

   - void filetime2() : file2의 시간 정보를 가져오는 함수

     ​

3. 파일 사이즈 비교

   - void sizecmp() : 두 개의 파일 크기를 비교하는 함수

   - 둘 중 하나가 크면 [ 000 is bigger] 출력

   - 같으면 [ sizes are equal ] 출력

     ​

4. 파일 블락 수 비교

   - void blockcmp() : 두 개의 파일 블락 수를 비교하는 함수

     ​

5. 파일 수정 날짜(월/일) 비교

   - void datecmp() : 두 개의 파일 수정 날짜를 비교하는 함수

   - 둘 중 하나가 빠르면 [ 000 is early ] 출력

   - 같으면 [ same time ] 출력

     ​

6. 파일 수정 시간(시/분) 비교

   - void timecmp() :  두 개의 파일 수정 시간을 비교하는 함수
   - 둘 중 하나가 빠르면 [ 000 is early ] 출력
   - 같으면 [ same time ] 출력