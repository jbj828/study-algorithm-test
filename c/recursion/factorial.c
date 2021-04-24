
int factorial(unsigned int i) {
  //  i * (i -1) * (i-2) * ... * 2 * 1
  if (i <= 1) {
    return 1;
  }

  return i * factorial(i - 1);
}
