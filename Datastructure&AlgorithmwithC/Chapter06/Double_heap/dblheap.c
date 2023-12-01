/*
* Double Priority Queue double heap
�Է� �����ʹ� ǥ���Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �����ȴ�.
�Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����.
�� �׽�Ʈ �������� ù° �ٿ��� Q�� ������ ������ ������ ��Ÿ���� ���� k (k �� 1,000,000)�� �־�����.
�̾����� k �� ������ ������ ��Ÿ���� ����(��D�� �Ǵ� ��I��)�� ���� n�� �־�����. ��I n���� ���� n�� Q�� �����ϴ� ������ �ǹ��Ѵ�.
������ ������ ���Ե� �� ������ �����ϱ� �ٶ���. ��D 1���� Q���� �ִ��� �����ϴ� ������ �ǹ��ϸ�, ��D -1���� Q ���� �ּڰ��� �����ϴ� ������ �ǹ��Ѵ�.
�ִ�(�ּڰ�)�� �����ϴ� ���꿡�� �ִ�(�ּڰ�)�� �� �̻��� ���, �ϳ��� �������� �����ϱ� �ٶ���.
���� Q�� ����ִµ� ������ ������ ��D����� �� ������ �����ص� ����. Q�� ����� ��� ������ -2^31 �̻� 2^31 �̸��� �����̴�.
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
bool state[1000001]; //���� ����
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) {
	h->heap_size = 0;
}
void insert_max(HeapType* h, element item) {
	int i = ++(h->heap_size); //i�� 1���� �����̳�? 
	while ((i != 1) && (item.value > h->heap[i / 2].value)) { // i�� 1���� �����̾�� i/2�� �ٷ� �θ��尡 �� ���� �� i�ڸ��� �θ� ������ �ݺ�
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // ������ �ڸ��� �� ���� �ֱ�
}
element delete_max(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];	// �� ������ ��
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
			if (C == 'I') { //�׳� ������ ��
				tmp.value = N;
				tmp.key = j;
				insert_max(heap_max, tmp);
				insert_min(heap_min, tmp);
			}
			if (C == 'D' && N == 1) { //�ִ�
				while (heap_max->heap_size != 0) {
					tmp = delete_max(heap_max);
					if (state[tmp.key] == 1) { //�̹� �������� �ʴ� ��
						continue;
					}
					else { //��ȿ�� ��
						//�� �ٿ� ���� ������ ��ɾ� �߰� ����
						state[tmp.key] = 1; //�� �̻� �������� ����
						break; //���� Ż��
					}
				}
			}
			if (C == 'D' && N == -1) { //�ּڰ�
				while (heap_min->heap_size != 0) {
					tmp = delete_min(heap_min);
					if (state[tmp.key] == 1) { //�̹� �������� �ʴ� ��
						continue;
					}
					else { //��ȿ�� ��
						state[tmp.key] = 1; //�� �̻� �������� ����
						break; //���� Ż��
					}
				}
			}
		}
		element tmp_max, tmp_min;
		int empty = 1;
		while (heap_max->heap_size != 0) {
			tmp_max = delete_max(heap_max);
			if (state[tmp_max.key] == 1) { //�̹� �������� �ʴ� ��
				continue;
			}
			else { //��ȿ�� ��, ���⼱ �������� ����
				empty = 0; //��ȿ�� ���� �����ϸ� ������� ����
				break; //���� Ż��
			}
		}
		while (heap_min->heap_size != 0) {
			tmp_min = delete_min(heap_min);
			if (state[tmp_min.key] == 1) { //�̹� �������� �ʴ� ��
				continue;
			}
			else { //��ȿ�� ��, ���⼱ �������� ����
				empty = 0; //��ȿ�� ���� �����ϸ� ������� ����
				break; //���� Ż��
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