# DataStructure

## 실습 목차
[[Week1] C언어 복습](#[Week1]-c언어-복습)


## [Week1] C언어 복습


### 1번
![image](https://user-images.githubusercontent.com/108220648/222317120-e3156110-f31f-4513-9421-ffd7948eae97.png)


### 2번
![image](https://user-images.githubusercontent.com/108220648/222957630-28234d2f-ffc6-411a-a06d-6edb4990be0d.png)


### 3번
![image](https://user-images.githubusercontent.com/108220648/222957643-4da1f633-c195-48c9-8cb5-858cf9b7aeac.png)


#### 헷갈린 점


포인터에서 * 의 의미


**1.포인터 변수의 선언**
	
	
	자료형* ptr = &변수 -> 변수의 값을 가르키고 있는 포인터 ptr 
	
	
**2. 포인터 변수가 가르키고 있는 메모리로의 접근**


  변수 = 값1
  자료형 * ptr = &변수
  * ptr = 값2 
  *변수의 값은 값2로 바뀜*
	 
	 
```
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

```
	
swap 할때 a,b 앞에 * 안붙이면 함수 안에서만 a와 b의 값을 swap한 것뿐, 


밖에서도 바뀌기 위해서는 메모리로 접근해서 포인터가 가르키고 있는 메모리의 변수를 바꾸어 주어야함


(따라서 temp에는 * a, 즉 a포인터가 가르키고 있는 메모리의 값이 들어있음)
