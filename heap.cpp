#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyDown(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        if (i && heap[(i-1)/2] < heap[i]) {
            swap(heap[i], heap[(i-1)/2]);
            heapifyUp((i-1)/2);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void deleteRoot() {
        if (heap.size() == 0) return;

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void buildMaxHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i)
            heapifyDown(i);
    }

    void heapSort() {
        vector<int> originalHeap = heap;
        int size = heap.size();
        for (int i = size - 1; i > 0; --i) {
            swap(heap[0], heap[i]);
            size--;
            heapifyDownRec(0, size);
        }

        // Show sorted array
        cout << "Heap Sorted Array: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;

        heap = originalHeap; // restore heap
    }

    void heapifyDownRec(int i, int size) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDownRec(largest, size);
        }
    }

    void displayHeap() {
        cout << "Heap: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(40);
    h.insert(20);
    h.insert(30);
    h.insert(50);

    h.displayHeap();

    h.deleteRoot();
    cout << "After deleting root: ";
    h.displayHeap();

    vector<int> arr = {4, 10, 3, 5, 1};
    h.buildMaxHeap(arr);
    cout << "After building max heap from array: ";
    h.displayHeap();

    h.heapSort();

    return 0;
}
