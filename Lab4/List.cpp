// Daniel Polak
#include <iostream>

class Item
{
public:
	int data;
	Item* nextItemPointer;

};
class List
{
public:
	Item* frontPointer;
	List() :frontPointer(NULL) {};
	~List()
	{

	}
	
	void pushFront(int data)
	{
		Item* newItemPointer = new Item();
		newItemPointer->data = data;
		newItemPointer->nextItemPointer = frontPointer;
		frontPointer = newItemPointer;
	}
	
	void Display()
	{
		std::cout << "List [";
		for (Item* curItemPointer = frontPointer; curItemPointer != NULL; curItemPointer = curItemPointer->nextItemPointer)
		{
			std::cout << curItemPointer->data;
			if (curItemPointer->nextItemPointer != NULL) {
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;

	}

	Item* Search(int data) {
		Item* location = frontPointer;
		if (location != NULL) {
			while (location->nextItemPointer != NULL) {
				if (location->data == data) {
					return location;
				}
				location = location->nextItemPointer;
			}
			if (location->data == data) {
				return location;
			}
		}
		return nullptr;
	}

	void Erase(Item *location) {
		Item* beforePointer = frontPointer;
		if (location != nullptr) {
			while (beforePointer->nextItemPointer != location) {
				beforePointer = beforePointer->nextItemPointer;
			}
			beforePointer->nextItemPointer = location->nextItemPointer;
			delete(location);
		}
		else {
			std::cout << "Location not found" << std::endl;
		}

	}

	void insertBefore(Item* location, int data) {
		Item* beforePointer = frontPointer;
		Item* newPointer = new Item();
		newPointer->data = data;

		if (beforePointer == location) {
			pushFront(data);
		}
		else if (location == nullptr) {
			newPointer->nextItemPointer = beforePointer->nextItemPointer;
			beforePointer->nextItemPointer = newPointer;
		}
		else if (beforePointer == NULL) {
			beforePointer->nextItemPointer = newPointer;
		}
		else {
			while (beforePointer->nextItemPointer != location) {
				beforePointer = beforePointer->nextItemPointer;
			}
			newPointer->nextItemPointer = location;
			beforePointer->nextItemPointer = newPointer;
		}
	}

	void insertAfter(Item* location, int data) {
		Item* pointer = frontPointer;
		Item* newPointer = new Item();
		newPointer->data = data;

		if (frontPointer == NULL) {
			frontPointer = newPointer;
		}
		else if (location == nullptr) {
			while (pointer->nextItemPointer != NULL) {
				pointer = pointer->nextItemPointer;
			}
			pointer->nextItemPointer = newPointer;
		}
		else {
			newPointer->nextItemPointer = location->nextItemPointer;
			location->nextItemPointer = newPointer;
		}

	}

	void PushBack(int data) {
		Item* curr = frontPointer;
		Item* newPointer = new Item();
		newPointer->data = data;

		while (curr->nextItemPointer != NULL) {
			curr = curr->nextItemPointer;
		}

		curr->nextItemPointer = newPointer;
	}

	bool popBack(int& data) {
		Item* pointer = frontPointer;
		Item* beforePointer = frontPointer;

		if (pointer == NULL) {
			return false;
		}
		else if (pointer->nextItemPointer == nullptr || beforePointer->nextItemPointer == nullptr) {
			return false;
		}
		else {
			while (pointer->nextItemPointer != NULL) {
				pointer = pointer->nextItemPointer;
			}
			data = pointer->data;
			while (beforePointer->nextItemPointer != pointer) {
				beforePointer = beforePointer->nextItemPointer;
			}
			beforePointer->nextItemPointer = NULL;
			return true;
		}
	}

	bool popFront(int& data) {		
		if (frontPointer == NULL) {
			return false;
		}
		else if (frontPointer == nullptr) {
			return false;
		}
		else {
			data = frontPointer->data;
			frontPointer = frontPointer->nextItemPointer;
			return true;
		}
	}

	void deleteFront() {
		Item* temp = frontPointer;
		if (frontPointer != nullptr) {
			frontPointer = frontPointer->nextItemPointer;
			delete(temp);
		}
		
	}

	void deleteAll() {
		Item* curr = frontPointer;
		if (frontPointer != NULL) {
			while (curr->nextItemPointer != NULL) {
				curr = curr->nextItemPointer;
				delete frontPointer;
				frontPointer = curr;
			}
			frontPointer = NULL;
		}
	}
};
int main()
{
	List myList;
	Item* search;
	std::cout << "EMPTY LIST" << std::endl;
	int value = 0;
	myList.Display();
	std::cout << std::endl;
	std::cout << "PUSH FRONT FUNCTION" << std::endl;
	myList.pushFront(1);
	myList.pushFront(2);
	myList.pushFront(3);
	myList.pushFront(4);
	myList.pushFront(5);
	myList.Display();
	std::cout << std::endl;
	std::cout << "PUSH BACK FUNCTION" << std::endl;
	myList.PushBack(6);
	myList.PushBack(7);
	myList.PushBack(8);
	myList.PushBack(9);
	myList.PushBack(10);
	myList.Display();
	std::cout << std::endl;
	std::cout << "INSERT BEFORE FUNCTION" << std::endl;
	std::cout << "Insert before first element: ";
	search = myList.Search(5);
	myList.insertBefore(search, 12);
	myList.Display();
	std::cout << "Insert before anywhere in the list: ";
	search = myList.Search(8);
	myList.insertBefore(search, 12);
	myList.Display();
	std::cout << "Insert before if the location is nullptr: ";
	search = myList.Search(0);
	myList.insertBefore(search, 12);
	myList.Display();
	std::cout << "Insert before if the list is empty: ";
	myList.deleteAll();
	myList.insertBefore(NULL, 1);
	myList.Display();
	myList.deleteAll();
	myList.pushFront(10);
	myList.pushFront(9);
	myList.pushFront(8);
	myList.pushFront(7);
	myList.pushFront(6);
	myList.pushFront(5);
	myList.pushFront(4);
	myList.pushFront(3);
	myList.pushFront(2);
	myList.pushFront(1);
	std::cout << std::endl;
	std::cout << "INSERT AFTER FUNCTION" << std::endl;
	std::cout << "Insert after first element: ";
	search = myList.Search(1);
	myList.insertAfter(search, 12);
	myList.Display();
	std::cout << "Insert after anywhere in the list: ";
	search = myList.Search(8);
	myList.insertAfter(search, 12);
	myList.Display();
	std::cout << "Insert after if the location is nullptr: ";
	search = myList.Search(0);
	myList.insertAfter(search, 12);
	myList.Display();
	std::cout << "Insert after if the list is empty: ";
	myList.deleteAll();
	myList.insertAfter(NULL, 1);
	myList.Display();
	myList.deleteAll();
	myList.pushFront(10);
	myList.pushFront(9);
	myList.pushFront(8);
	myList.pushFront(7);
	myList.pushFront(6);
	myList.pushFront(5);
	myList.pushFront(4);
	myList.pushFront(3);
	myList.pushFront(2);
	myList.pushFront(1);
	std::cout << std::endl;
	std::cout << "POP BACK FUNCTION" << std::endl;
	myList.popBack(value);
	std::cout << "Value: " << value << std::endl;
	myList.Display();
	std::cout << std::endl;
	std::cout << "POP FRONT FUNCTION" << std::endl;
	myList.popFront(value);
	std::cout << "Value: " << value << std::endl;
	myList.Display();
	std::cout << std::endl;
	std::cout << "ERASE FUNCTION" << std::endl;
	std::cout << "Erase number: ";
	search = myList.Search(4);
	myList.Erase(search);
	myList.Display();
	myList.deleteAll();
	std::cout << "Erase if the list is empty: ";
	myList.Erase(NULL);
	std::cout << std::endl;
	myList.pushFront(10);
	myList.pushFront(9);
	myList.pushFront(8);
	myList.pushFront(7);
	myList.pushFront(6);
	myList.pushFront(5);
	myList.pushFront(4);
	myList.pushFront(3);
	myList.pushFront(2);
	myList.pushFront(1);
	std::cout << "DELETE FRONT FUNCTION" << std::endl;
	myList.deleteFront();
	myList.Display();
	std::cout << std::endl;
	std::cout << "DELETE ALL FUNCTION" << std::endl;
	myList.deleteAll();
	myList.Display();
	return 0;
}