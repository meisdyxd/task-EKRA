#include <iostream>


template< typename T>
struct ListNode
{
	T val;
	ListNode* next;
};

template< typename T>
void reorderList(ListNode<T>* head);

template<typename T>
void addElement(ListNode<T>*& head, T value);

template<typename T>
void printElements(ListNode<T>* head);

template<typename T>
void clearMemory(ListNode<T>*& head);


int main() {
	ListNode<int>* head = nullptr;
	for (int i = 0; i < 10; i++) {
		addElement(head, i);
	}
	printElements(head);
	reorderList(head);
	std::cout << "reorderList" << std::endl;
	printElements(head);
	clearMemory(head);
	std::cin.get();
}

template< typename T>
void reorderList(ListNode<T>* head) {
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
		std::cout << "Can't reorderList" << std::endl;
		return;
	}
	ListNode<T>* second_element = head->next;
	ListNode<T>* temp = head;
	while (temp->next->next != nullptr) {
		temp = temp->next;
	}
	head->next = temp->next;
	head->next->next = second_element;
	temp->next = nullptr;
}

template<typename T>
void addElement(ListNode<T>*& head, T value) {
	if (head == nullptr) {
		head = new ListNode<T>{ value, nullptr };
	}
	else {
		ListNode<T>* t = head;
		while (t->next != nullptr) {
			t = t->next;
		}
		t->next = new ListNode<T>{ value, nullptr };
	}
}

template<typename T>
void printElements(ListNode<T>* head) {
	if (head == nullptr) {
		return;
	}
	ListNode<T>* t = head;
	while (t != nullptr) {
		std::cout << t->val << std::endl;
		t = t->next;
	}
}


template<typename T>
void clearMemory(ListNode<T>*& head) {
	while (head != nullptr) {
		ListNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
}