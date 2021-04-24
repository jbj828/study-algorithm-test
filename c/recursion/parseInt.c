
// 10진수를 16진수로 바꾸시오
void parseInt(unsigned int number, const int base) {
  char* conversion = "0123456789ABCDE";
  int index = number % base;

  if (number /= base) {
    parseInt(number, base);
  }

  printf("%c", conversion[index]);
}

/*
    재귀적으로 함수를 호출할 때마다 스택에 함수가 쌓이고, 종료 조건에 의해 더
   이상 함수가 스택에 쌓이지 않을 때부터 함수호출 행 이후의 소스가 실행된다.
*/