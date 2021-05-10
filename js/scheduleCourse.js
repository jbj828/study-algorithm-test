/**
 * @param {number[][]} courses
 * @return {number}
 */
// courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
var scheduleCourse = function (courses) {
  if (!courses.length) return 0;

  courses.sort(([t1, d1], [t2, d2]) => d2 - d1);

  let arr = new Array(courses.length + 1).fill(-1);
  arr[0] = Number.MAX_SAFE_INTEGER;
  let maxCount = 0;

  for (let [t, d] of courses) {
    for (let i = maxCount + 1; i > 0; i--) {
      arr[i] = Math.max(arr[i], Math.min(arr[i - 1], d) - t);
      if (arr[i] > -1 && i > maxCount) maxCount = i;
    }
  }
  return maxCount;
};
