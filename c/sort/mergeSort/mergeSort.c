#include <stdio.h>
#include <stdlib.h>

/*
    병합정렬은 항상 배열을 반으로 나누고 두 반쪽을 합치는 데 선형 시간이
   필요하므로 시간복잡도는 세 가지 경우(최선, 평균, 최악) 모두 O(nlogn)이다.
   병합 정렬을 할 때는 정렬되지 않은 배열과 같은 크기의 추가 공간이 필요하다.
   따라서 큰 배열의 정렬에 사용하는 것은 추천하지 않으며, 연결 리스트를 정렬하는
   데 가장 적합하다.

   time : O(nlogn)
   space : O(n)
*/

void Merge(int* arr, int* tempArray, int lowerIndex, int middleIndex,
           int upperIndex) {
  int lowerStart = lowerIndex;
  int lowerStop = middleIndex;
  int upperStart = middleIndex + 1;
  int upperStop = upperIndex;
  int count = lowerIndex;

  while (lowerStart <= lowerStop && upperStart <= upperStop) {
    // lowerStart와 upperStart를 비교해서 낮은 값을 먼저 tempArray에 넣는다.
    if (arr[lowerStart] < arr[upperStart]) {
      tempArray[count++] = arr[lowerStart++];
    } else {
      tempArray[count++] = arr[upperStart++];
    }
  }

  // 위 반복문을 끝내고 나서도 전자의 배열에 남은 요소가 있으면 tempArray에
  // 마지막까지 넣는다.
  while (lowerStart <= lowerStop) {
    tempArray[count++] = arr[lowerStart++];
  }
  while (upperStart <= upperStop) {
    tempArray[count++] = arr[upperStart++];
  }

  // tempArray에 저장된 순서대로 arr의 값을 바꾼다.
  for (int i = lowerIndex; i <= upperIndex; i++) {
    arr[i] = tempArray[i];
  }
}

void MergeSortUtil(int* arr, int* tempArray, int lowerIndex, int upperIndex) {
  if (lowerIndex >= upperIndex)
    return;  // 종료 조건으로 더 이상 반으로 나눌 수 없을 때를 의미한다.

  int middleIndex = (lowerIndex + upperIndex) / 2;
  MergeSortUtil(
      arr, tempArray, lowerIndex,
      middleIndex);  // 배열을 반으로 나누는 것을 재귀로 계속 반복한다.
  MergeSortUtil(arr, tempArray, middleIndex + 1, upperIndex);
  Merge(arr, tempArray, lowerIndex, middleIndex,
        upperIndex);  // 반으로 나눈 배열이 종료조건을 받아 더 이상 진행되지
                      // 않을 경우, 현재의 행으로 와서 스택의 가장 윗단부터
                      // 차례대로 Merge 함수를 호출한다
}

void MergeSort(int* arr, int size) {
  int* tempArray = (int*)malloc(size * sizeof(int));
  MergeSortUtil(arr, tempArray, 0, size - 1);
}
