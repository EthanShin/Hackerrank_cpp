#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int value;
	int key;
	Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
	Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
	map<int, Node*> mp; //map the key to the node in the linked list
	int cp;  //capacity
	Node* tail; // double linked list tail pointer
	Node* head; // double linked list head pointer
	virtual void set(int, int) = 0; //set function
	virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
	LRUCache(int capacity) {
		cp = capacity;
		head = NULL;
	}

	void set(int key, int value) {

		if (mp.size() == cp) {
			mp.erase(head->key);
			head->next->prev = NULL;
			head = head->next;
		}

		if (mp[key] == NULL) {
			if (head == NULL) {
				Node* n = new Node(key, value);
				head = n;
				tail = n;
				mp[key] = n;
			}
			else {
				Node* n = new Node(tail, NULL, key, value);
				tail->next = n;
				tail = n;
				mp[key] = n;
			}

		}
		else {
			Node* temp = head;
			for (int i = 0; i < mp.size(); i++) {
				if (temp->key == key) {
					if (temp != head && temp != tail) {
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
					}
					else if (temp == head) {
						head = head->next;
					}
					else {
						tail->prev->next = NULL;
						tail = tail->prev;
					}
					Node* n = new Node(tail, NULL, key, value);
					tail->next = n;
					tail = n;
					mp[key] = n;

					if (head == NULL)
						head = n;

					break;
				}
				temp = temp->next;
			}
		}
	}

	int get(int key) {
		if (mp[key] == NULL)
			return -1;
		return mp[key]->value;
	}
};