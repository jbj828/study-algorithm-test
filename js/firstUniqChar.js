/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
  // 문자열을 전부 확인한 후, 중복되지 않는 최초 char의 인덱스를 반환하라,
  // 전부 중복한다면 -1 을 반환

  // 모든 char을 반복문으로 돈다
  // 새로운 배열을 길이 26으로 한 뒤 0으로 채운다
  // 아스키 문자에서 a는 1로 만든다.
  // 각 문자의 위치에 char이 나올 때마다 ++한다

  const map = {};

  for (let char of s) {
    map[char] ? map[char]++ : (map[char] = 1);
  }

  for (let i = 0; i < s.length; i++) {
    if (map[s[i]] === 1) return i;
  }
  return -1;
};
