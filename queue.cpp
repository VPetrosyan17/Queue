#include <iostream>
#include <stdexcept>

template<typename T>

class Queue	{
	public:
	//constructor and destructor
	Queue(int size = SIZE) {
		arr = new T[size];
		capacity = size;
		front = 0;
		rear = -1;
		count = 0;
	}

	~Queue(){
		delete[] arr;
	}

	//dequeue element
	void dequeue() {
		if(isEmpty()){
			throw std::underflow_error("Program terminated!");
		}
		front = (front + 1) % capacity;
		count--;
	}
	
	//adding element
	void enqueue(const T& value) {
		if(isFull()){
			throw std::underflow_error("Program terminated!");
		}
		rear = (rear + 1) % capacity;
		arr[rear] = value;
		count++;
	}
	
	//return the element of the front
	T& peek(){
		if(isEmpty()){
			throw std::underflow_error("Program terminated!");
		}
		return arr[front];
	}

	//return the size of queue
	int size(){
		return count;
	}

	//return whether is it full or empty
	bool isEmpty(){
		return size() == 0;
	}

	bool isFull(){
		return count == capacity;
	}

	private:
	//default capacity
	static const int SIZE = 1000;
	T* arr;
	int capacity;
	int front;
	int rear;
	int count;
};

int main(){
	Queue<int> myQueue(6);

	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);
	
	std::cout << myQueue.peek();

	myQueue.dequeue();

	std::cout << myQueue.peek();
}
