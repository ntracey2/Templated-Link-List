#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "src/ll.h"

using cs126linkedlist::LinkedList;

TEST_CASE("Add node to front of list: push_front()") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Add to empty list") {
		list->push_front(7);
		REQUIRE(list->front() == 7);
	}
	SECTION("Add to non-empty list") {
		list->push_front(7);
		list->push_front(8);
		REQUIRE(list->front() == 8);
	}
}

TEST_CASE("View nodes") {
	LinkedList<int> *list = new LinkedList<int>();

	list->push_front(3);
	list->push_front(4);
	REQUIRE(list->back() == 3);
}

TEST_CASE("Test size") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Populated list") {
		list->push_front(2);
		list->push_front(1);
		list->push_front(10);
		REQUIRE(list->size() == 3);
	}
}

TEST_CASE("Test iterator") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Dereferencing") {
		list->push_front(5);
		LinkedList<int>::iterator itr = list->begin();
		REQUIRE(*itr == 5);
	}
	SECTION("Incrementing") {
		list->push_front(2);
		list->push_front(1);

		LinkedList<int>::iterator itr = list->begin();
		
		++itr;
		REQUIRE(*itr == 2);
	}
	SECTION("!= operator") {
		list->push_front(2);
		list->push_front(1);

		int s = 0;
		LinkedList<int>::iterator itr;
		for (itr = list->begin(); itr != list->end(); ++itr) {
			s++;
		}
		REQUIRE(s == 1);
	}
}
