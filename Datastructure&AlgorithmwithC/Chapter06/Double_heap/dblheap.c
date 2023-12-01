/*
* Double Priority Queue double heap
입력 데이터는 표준입력을 사용한다. 입력은 T개의 테스트 데이터로 구성된다.
입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다.
각 테스트 데이터의 첫째 줄에는 Q에 적용할 연산의 개수를 나타내는 정수 k (k ≤ 1,000,000)가 주어진다.
이어지는 k 줄 각각엔 연산을 나타내는 문자(‘D’ 또는 ‘I’)와 정수 n이 주어진다. ‘I n’은 정수 n을 Q에 삽입하는 연산을 의미한다.
동일한 정수가 삽입될 수 있음을 참고하기 바란다. ‘D 1’는 Q에서 최댓값을 삭제하는 연산을 의미하며, ‘D -1’는 Q 에서 최솟값을 삭제하는 연산을 의미한다.
최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨을 유념하기 바란다.
만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시해도 좋다. Q에 저장될 모든 정수는 -2^31 이상 2^31 미만인 정수이다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
	int value;
	int key;
}element;
typedef struct {
	element heap[1000001];
	int heap_size;
}HeapType;
bool state[1000001]; //존재 여부
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max(HeapType* h, element item) {
	int i = ++(h->heap_size); //i가 1부터 시작이네? 
	while ((i != 1) && (item.value > h->heap[i / 2].value)) { // i가 1부터 시작이어야 i/2가 바로 부모노드가 됨 참일 시 i자리에 부모가 들어오고 반복
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // 마지막 자리에 값 집어 넣기
}
element delete_max(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];	// 맨 마지막 놈
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].value) < (h->heap[child + 1].value))
			child++;
		if (temp.value >= h->heap[child].value) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void insert_min(HeapType* h, element item) {
	int i = ++(h->heap_size);
	while ((i != 1) && (item.value < h->heap[i / 2].value)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_min(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].value) > (h->heap[child + 1].value))
			child++;
		if (temp.value <= h->heap[child].value) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main() {
	int T, K, N;
	char C;
	element tmp;
	HeapType* heap_max = create();
	HeapType* heap_min = create();
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		init(heap_max);
		init(heap_min);
		scanf("%d", &K);
		for (int z = 0; z < K; z++) {
			state[z] = 0;
		}
		for (int j = 0; j < K; j++) {
			scanf(" %c %d", &C, &N);
			if (C == 'I') { //그냥 넣으면 됨
				tmp.value = N;
				tmp.key = j;
				insert_max(heap_max, tmp);
				insert_min(heap_min, tmp);
			}
			if (C == 'D' && N == 1) { //최댓값
				while (heap_max->heap_size != 0) {
					tmp = delete_max(heap_max);
					if (state[tmp.key] == 1) { //이미 존재하지 않는 값
						continue;
					}
					else { //유효한 값
						//이 줄엔 값을 꺼내는 명령어 추가 가능
						state[tmp.key] = 1; //더 이상 존재하지 않음
						break; //루프 탈출
					}
				}
			}
			if (C == 'D' && N == -1) { //최솟값
				while (heap_min->heap_size != 0) {
					tmp = delete_min(heap_min);
					if (state[tmp.key] == 1) { //이미 존재하지 않는 값
						continue;
					}
					else { //유효한 값
						state[tmp.key] = 1; //더 이상 존재하지 않음
						break; //루프 탈출
					}
				}
			}
		}
		element tmp_max, tmp_min;
		int empty = 1;
		while (heap_max->heap_size != 0) {
			tmp_max = delete_max(heap_max);
			if (state[tmp_max.key] == 1) { //이미 존재하지 않는 값
				continue;
			}
			else { //유효한 값, 여기선 제거하진 않음
				empty = 0; //유효한 값이 존재하면 비어있지 않음
				break; //루프 탈출
			}
		}
		while (heap_min->heap_size != 0) {
			tmp_min = delete_min(heap_min);
			if (state[tmp_min.key] == 1) { //이미 존재하지 않는 값
				continue;
			}
			else { //유효한 값, 여기선 제거하지 않음
				empty = 0; //유효한 값이 존재하면 비어있지 않음
				break; //루프 탈출
			}
		}
		if (empty) {
			printf("EMPTY\n");
		}
		else {
			printf("%d %d\n", tmp_max.value, tmp_min.value);
		}

	}
	free(heap_max);
	free(heap_min);
	return 0;
}