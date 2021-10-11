# GDSC 2주차 알고리즘 스터디


A - [[10828](https://www.acmicpc.net/problem/10828)] 스택(S4)

B - [[10799](https://www.acmicpc.net/problem/10799)] 쇠막대기(S3)

C - [[2346](https://www.acmicpc.net/problem/2346)] 풍선 터트리기(S3)

D - [[3078](https://www.acmicpc.net/problem/3078)] 좋은 친구(G3)



***
# 스택(Stack) 
### 후입선출 방식의 자료구조(LIFO; Last-In, First-Out)

<br>

  * 먼저 삽입(push)된 데이터가 가장 아래에 있고, 나중에 삽입된 데이터가 가장 위에 있는 형태
  * ex) 택배 상하차
  * 데이터를 삭제(pop)시 가장 나중(최근)에 삽입된 데이터를 꺼낸다. (중간 부분 변경 불가)

<br>

***

# 큐(Queue)
###  선입선출방식의 자료구조(FIFO; First-In, First-Out)

<br>

  * 먼저 삽입(put)된 데이터가 앞에 있고, 나중에 삽입된 데이터가 뒤에 있는 형태
  * ex) 은행 창구
  * 데이터를 삭제(get)시 가장 먼저(오래전) 삽입된 데이터를 꺼낸다. (중간 부분 변경 불가)


<br>

***

# 덱(Deque) 
### Double-ended Queue; 양 방향에서 삽입/삭제 가능

<br>

  * 가장 앞(먼저), 뒤(나중)를 삭제하는 형태
  * index로 접근할 수 있음
  * 구현시 0번지부터 시작하면 양방향으로 확장이 불가능하므로, 중간부터 양방향으로 자람


<br>

***



# 문제풀이

* [BOJ 1158](https://www.acmicpc.net/problem/1158)
<img src="https://user-images.githubusercontent.com/68985625/135991520-47325f14-16e3-4682-8ac1-704e66d239d7.png" width="80%">


 - 핵심 풀이
  + 시작 후 시작점의 명확히 파악하는 것이 중요함
  + 처음에 있던 원소가 마지막으로 가서 반복됨 -> Queue
  + 제거가 되지 않으면 다시 넣어주고(push), 제거되면 pop
  + 벡터를 활용할 경우, 벡터 두 개 혹은 한 벡터의 인덱스를 갖고 활용(큐가 더 간단함)

<br><br>

* [BOJ 9012](https://www.acmicpc.net/problem/9012)
<img src="https://user-images.githubusercontent.com/68985625/135991675-dc663d21-e624-4830-a074-79c04561b972.png" width="80%">     


 - 핵심 풀이     
  + 올바른 괄호 문자열이 되기 위한 조건: 여는 괄호와 닫는 괄호의 개수가 동일해야함     
  + 올바른 괄호 문자열은 생략 가능함     
  + 닫는 괄호는 그보다 앞에 있으면서 여는 괄호 중 가장 뒤에 있는 여는 괄호와 매칭되어야 함(가장 마지막에 들어온 원소가 가장 먼저 나감) -> Stack     

<br><br>

* [BOJ 3078](https://www.acmicpc.net/problem/3078)
<img src="https://user-images.githubusercontent.com/68985625/135991855-27df263a-597e-4ee2-9dc8-307b0b67dfe3.png" width="80%">    


 - 핵심 풀이     
  + 학생들이 이미 성적 순으로 주어져 있음 -> 순서대로 탐색하면 됨     
  + x등 학생과 좋은 친구가 될 수 있는 등수의 범위: [max(1, x-k), min(x+k, N)]     
  + x에서 x+1로, x+k+1 넘어갈 때, x+2k+2 번째 학생으로 넘어가면 그 뒤의 학생은 좋은 친구가 될 수 없음     
  + 먼저 좋은 친구가 될 수 있는 학생을 추가했다가 더이상 불가하면 삭제 -> Queue     
  + 현재 큐에 있으면서 내 이름과 동일한 길이인 학생의 수를 더하면 됨     

<br><br>

* [BOJ 18115](https://www.acmicpc.net/problem/18115)
<img src="https://user-images.githubusercontent.com/68985625/135991932-7a8f5e85-e85c-4be8-9438-ccc41556b678.png" width="80%">     


 - 핵심 풀이     
  + 최종적으로 위에서부터 순서대로 적혀있음     
  + 제일 먼저 놓는 카드가 N부터 마지막이 1까지     
  + 카드 더미를 거꾸로 구성하는 것이 중요함     
  + 현재 존재하는 카드를 앞에서도/뒤에서도 삭제 가능함 -> Deque     
  + 두 번째에 삽입하는 경우: 앞에 있는 원소를 빼서 3을 넣고 다시 2를 앞에 넣어주면 두 번째 넣는 것과 동일     


***
