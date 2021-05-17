/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function (columnTitle) {
  /*
        length가 2면 26 * B(2), 26 * C(3), 
        첫번째 자리는 a,b,c에 해당하는 1,2,3... 더 하기
        BCD : 26 * 26 * B(2) + (26 * C(3)) + D(4);
    */
  const size = columnTitle.length;
  const charCodeBase = 'A'.charCodeAt(0) - 1;
  let result = 0;
  for (let i = 0; i < size; i++) {
    result +=
      (columnTitle.charCodeAt(i) - charCodeBase) * Math.pow(26, size - i - 1);
  }
  return result;
};
