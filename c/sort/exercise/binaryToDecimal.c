#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main() {
  printf("Binary (stirng) to Decimal conversion\n");

  unsigned char i = to_decimal("00000110");
  unsigned char mask = to_decimal("00010110");

  print_binary(i);
  print_binary(mask);
  print_binary(i & mask);
  return 0;
}

unsigned char to_decimal(const char bi[]) {
  const size_t bits = strlen(bi);
  unsigned char sum = 0;

  for (size_t i = 0; i < bits; i++) {
    if (bi[i] == '1') {
      sum += (int)pow(2, bits - 1 - i);
    } else if (bi[i] != '0') {
      printf("Wrong character: %c", bi[i]);
      exit(1);
    }
  }

  return sum;
}

void print_binary(const unsigned char num) {
  const size_t bits =
      sizeof(num) * 8;  // size_t를 쓰는 이유는 다양한 OS에서 같은 동작을 하는
                        // 자료형이기 때문에 유연성이 높아지기 때문이다
                        // * 8 을 하는 이유는 비트를 구하는 것이기 때문. char은
                        // 1byte이고 8bit이다

  for (size_t i = 0; i < bits; i++) {
    const unsigned char mask =
        (unsigned char)pow((double)2, (double)(bits - 1 - i));

    if ((num & mask) == mask) {
      printf("%d", 1);
    } else {
      printf("%d", 0);
    }
  }
}
