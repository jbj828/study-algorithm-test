
// 10진수를 16진수로 바꾸시오
void parseInt(unsigned int number, const int base) {
  char* conversion = "0123456789ABCDE";
  int index = number % base;

  if (number /= base) {
    parseInt(number, base);
  }

  printf("%c", conversion[index]);
}