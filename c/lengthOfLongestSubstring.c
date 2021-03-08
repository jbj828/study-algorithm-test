

int lengthOfLongestSubstring(char* s) {
  int letter_map[128] = {0}, res = 0;
  // start와 end에 인자로 넘어온 문자열이 시작하는 주소를 넣어준다.
  char *start = s, *end = s;

  while (*end) {  // *end는 인자로 넘어온 문자열의 값이다. 즉 end는 주소고
                  // *end는 문자열의 첫번째 문자이다. *end의 값이 null이면
                  // while문은 정지한다
    if (letter_map[*end]) {  // letter_map['p'] : char은 그냥 8비트 integer이기
                             // 때문에 대괄호 안에 넣을 수 있다.
      res = (end - start > res) ? end - start : res;
      while (*start != *end) {
        letter_map[*start] = 0;
        start++;
      }
      start++;
      end++;
    } else {
      letter_map[*end] = 1;
      end++;
    }
  }
  return end - start > res ? end - start : res;
}