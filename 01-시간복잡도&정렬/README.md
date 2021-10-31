# week1

## 1. Big O

[Big O Explained in 10 min](https://youtu.be/BEVnxbxBqi8) 

speed of an algorithm = "steps it takes to finish"

 

**constant time** : O(1). one step to finish. size of input doesn't matter

Big O doesn't care about details of a function. doesn't care about constants 

as the array grows, number of steps increase : O(n) → if input increases, amount of time increases too 

**Quadratic Time** : 2차 시간. nested loops O(n^2) 

**Logarithmic Time** : binary search. O(logN) → 데이터 2배 되어도 한번만 더 나누면 되니까 step이 1만 증가 

![Untitled](week1%20e95aa15431554bfeaf0a9c9d9459b03e/Untitled.png)

## 2. Sorting Algorithms

**sorting** : organizing something

최악의 상황보다 평균 상황을 봐야함 

- Bubble sort
    - 배열에서 맨앞 2개부터 pick해서 비교하고 더 큰거 뒤로 옮기기
    - compare & swap (n-1)번 반복
    - worst : 내림차순으로 되어있는 경우. 매번 swap 해야함
    - 시간복잡도 : O(n^2)
- Selection sort
    - 가장 작은 숫자의 자리를 변수에 저장
    - 가장 작은 수를 0번으로 옮기기. 이거 이후의 배열을 check & swap하기
    - 시간복잡도 : O(n^2)
    - n-1comparison. 매 사이클마다 1번의 스왑만 하면 됨.
- Insertion sort
    - index '1'에서 시작. 왼쪽에 더 큰 숫자 있는지 확인하고 크면 swap.
    - index '2'로 이동.
    - 계속 왼쪽과 비교하고 왼쪽이 더 크면 자리 바꿔주기
    - selection sort보다 빠름 → 필요한 아이템만 스캔하기 때문에
    - 시간복잡도 : O(n^2) best → O(n)
    

## 3. Quick Sort

대표적인 '분할 정복' 알고리즘. 평균 속도 = O(n*logN) 

log N은 거의 상수라고 봐도 될 정도로 빠름! 

> 특정한 값을 기준으로 큰 숫자와 작은 숫자 나누기
> 

**기준 값** : pivot값. 이 값을 기준으로 왼쪽과 오른쪽 나눔 

1. 왼→오 : 기준 값보다 큰 값 선택 
오→왼 : 기준 값보다 작은 값 선택 
2. 위의 두 값들 switch 
3. 큰 값과 작은 값이 엇갈린 경우(이미 크기 순으로 정렬되어 있는 경우) → 더 작은 값과 기준 값의 자리를 바꿔줌
4. 기준값의 왼쪽, 오른쪽에서 위의 순서들 반복. 분할된 상태에서 각각 집합에서 sorting 하기 

**분할 정복이 강력한 이유** 

ex) 1 2 3 4 5 6 7 8 9 10 

1 2 3 4 5 ⇒ 5 * 5 = 25

6 7 8 9 10 ⇒ 5 * 5 = 25 

$n^2 = 10 * 10 = 100$ 

## 4. Merge Sort

시간복잡도 : O(n*logN) 

편향되게 분할할 가능성 없음. 반씩 나누기 때문에 최악의 경우에도 O(n*logN)를 보장함 

이미 정렬이 되어있는 상태에서 새롭게 정렬된 형태 만들기 

> 일단 반으로 나누고 나중에 합쳐서 정렬하기
> 
1. 계속 반씩 쪼개서 완전하게 하나씩 분해하기 
2. 2의 배수만큼 합치기 → 2개씩 정렬해서 합치기 
3. 합치는 순간에 정렬 
    
    ![Untitled](week1%20e95aa15431554bfeaf0a9c9d9459b03e/Untitled%201.png)
    
    1. i, j 중에 더 작은 값을 k에 넣고 i or j 하나 뒤로 이동 
    2. N번 비교함 

→ 너비 : N 높이 : logN 

```cpp
#include <stdio.h>

int number = 8;    //정렬할 데이터의 갯수
int sorted[8];     //정렬된 결과 배열 담을 수 있는 공간 
                   //정렬 배열은 반드시 전역 변수로 선언. 모든 함수가 공통적으로 사용하기 위해서 

void merge(int a[], int m, int middle, int n){
	int i = m; 
	int j = middle + 1;
	int k = m; 
	
	//작은 순서대로 배열에 삽입 
	while(i <= middle && j <= n){
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}

	//남은 데이터도 삽입 
	if(i > middle ) {
		for (int t = j; t <= n; t++) {
			sorted[k] = a[t];
			k++;
		}
	} else {
			for (int t = i; t <= middle; t++){
				sorted[k] = a[t];
				k++;
			}
	}

	//정렬된 배열은 삽입 
	for(int t=m; t <= n; t++){
		a[t] = sorted[t]; 
	}
}

//재귀함수로 구현 
void mergeSort(int a[], int m, int n){
	//크기가 1보다 큰 경우에만 
	if(m<n){
		int middle = (m + n)/2;
		mergeSort(a, m, middle);     //왼쪽 정렬 
		mergeSort(a, middle+1, n);   //오른쪽 정렬
		merge(a, m, middle, n); 
	}
}

int main(void){
	int array[number] = {7, 6, 5, 8, 3, 5, 9, 1};
	mergeSort(array, 0, number-1);
	for(int i=0; i< number; i++){
		printf("%d", array[i]);
	}
}
```