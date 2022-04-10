#include <iostream>
const int HEAP_SIZE = 1000;
using namespace std;

class maxheap {
public:
	maxheap() {
		for (int i = 0; i < HEAP_SIZE; i++)
			heap[i] = 0;
		heap_count = 0;
	}
	void heap_push(int x) {
		heap[++heap_count] = x;
		if (heap_count != 1)
			upheap();
		
	}
	void upheap() {
		int child = heap_count;
		int parent = child / 2;
		while (child > 1 && heap[parent] < heap[child]) {
			this->swap(parent, heap_count);
			child = parent;
			parent = child / 2;
		}
		
	}
	int heap_pop() {
		int k = heap[heap_count];
		this->swap(1, heap_count);
		heap_count--;
		
		int parent = 1;
		int child = parent * 2;
		if (child + 1 <= heap_count) 
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		
		while (child <= heap_count && heap[parent] < heap[child]) {
			this->swap(parent, child);
			parent = child;
			child *= 2;
			if (child + 1 <= heap_count) {
				child = (heap[child] > heap[child + 1]) ? child : child + 1;
			}
		}
		return k;
	}
	void swap(int a, int b) {
		int temp = heap[a];
		heap[a] = heap[b];
		heap[b] = heap[a];
	}


private:
	int heap[HEAP_SIZE];
	int heap_count;
};


int main() {
	maxheap myMaxheap;
	myMaxheap.
}