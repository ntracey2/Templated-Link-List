#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "src/ll.h"

using namespace cs126linkedlist;

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

TEST_CASE("Add node to back of list") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Add to non-empty list") {
		list->push_front(4);
		list->push_back(5);
		REQUIRE(list->back() == 5);
	}
}

TEST_CASE("Remove node from front of list") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Remove from single node list") {
		list->push_front(10);
		list->pop_front();
		REQUIRE(list->size() == 0);
	}

	SECTION("Remove from several node list") {
		list->push_front(3);
		list->push_front(2);
		list->push_front(1);
		list->pop_front();

		REQUIRE(list->front() == 2);
	}
}

TEST_CASE("Remove node from back of list") {
	LinkedList<std::string> *list = new LinkedList<std::string>();

	SECTION("Remove from single node list") {
		list->push_front("a");

		list->pop_back();
		REQUIRE(list->size() == 0);
	}
	SECTION("Remove from several node list") {
		list->push_front("a");
		list->push_front("ab");
		list->push_front("abc");

		list->pop_back();
		REQUIRE(list->back() == "ab");
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

	SECTION("Empty list") {
		REQUIRE(list->size() == 0);
	}

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
		REQUIRE(s == 2);
	}
}

TEST_CASE("Clear the list") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Empty list") {
		REQUIRE(list->size() == 0);
	}

	SECTION("Populated list") {
		list->push_front(2);
		list->push_front(1);
		list->push_front(10);

		list->clear();
		REQUIRE(list->size() == 0);
	}
}

TEST_CASE("Create linked list from vector") {
	SECTION("Populated vector") {
		std::vector<float> vec;
		vec.push_back(1.1f);
		vec.push_back(1.2f);
		vec.push_back(1.3f);
		vec.push_back(1.4f);

		LinkedList<float> *list = new LinkedList<float>(vec);

		LinkedList<float>::iterator itr;
		int i = 0;
		for (itr = list->begin(); itr != list->end(); ++itr) {
			REQUIRE(*itr == vec.at(i));
			i++;
		}
	}

	SECTION("Empty vector") {
		std::vector<float> vec;

		LinkedList<float> *list = new LinkedList<float>(vec);
		REQUIRE(list->size() == 0);
	}
}

TEST_CASE("Remove odd elements from list") {
	LinkedList<int> *list = new LinkedList<int>();

	SECTION("Even length list") {
		list->push_front(3);
		list->push_front(2);
		list->push_front(1);
		list->push_front(0);

		list->RemoveOdd();

		REQUIRE(list->front() == 0);
		REQUIRE(list->back() == 2);
		REQUIRE(list->size() == 2);
	}
	SECTION("Odd length list") {
		list->push_front(3);
		list->push_front(2);
		list->push_front(1);
		list->push_front(0);
		list->push_front(-1);

		list->RemoveOdd();

		REQUIRE(list->front() == -1);
		REQUIRE(list->back() == 3);
		REQUIRE(list->size() == 3);
	}
}


TEST_CASE("Display printing") {
	LinkedList<int> *list = new LinkedList<int>();

	list->push_front(3);
	list->push_front(2);
	list->push_front(1);
	list->push_front(0);
	list->push_front(-1);

	std::cout << *list << std::endl;
}

TEST_CASE("== operator") {
	LinkedList<std::string> *list1 = new LinkedList<std::string>();
	LinkedList<std::string> *list2 = new LinkedList<std::string>();

	SECTION("Two empty lists") {
		REQUIRE(*list1 == *list2);
	}
	SECTION("Two equal populated lists") {
		list1->push_back("first");
		list1->push_back("second");
		list1->push_back("third");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE(*list1 == *list2);
	}
	SECTION("Two unequal populated lists") {
		list1->push_back("first");
		list1->push_back("fifth");
		list1->push_back("third");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE(!(*list1 == *list2));
	}
	SECTION("Two lists of different lengths") {
		list1->push_back("first");
		list1->push_back("second");
		list1->push_back("third");
		list1->push_back("fourth");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE(!(*list1 == *list2));
	}
}

TEST_CASE("!= operator") {
	LinkedList<std::string> *list1 = new LinkedList<std::string>();
	LinkedList<std::string> *list2 = new LinkedList<std::string>();

	SECTION("Two empty lists") {
		REQUIRE(!(*list1 != *list2));
	}
	SECTION("Two equal populated lists") {
		list1->push_back("first");
		list1->push_back("second");
		list1->push_back("third");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE(!(*list1 != *list2));
	}
	SECTION("Two unequal populated lists") {
		list1->push_back("first");
		list1->push_back("fifth");
		list1->push_back("third");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE((*list1 != *list2));
	}
	SECTION("Two lists of different lengths") {
		list1->push_back("first");
		list1->push_back("second");
		list1->push_back("third");
		list1->push_back("fourth");

		list2->push_front("third");
		list2->push_front("second");
		list2->push_front("first");

		REQUIRE((*list1 != *list2));
	}
}

TEST_CASE("Copy constructor") {
	LinkedList<char> *list = new LinkedList<char>();
	SECTION("Populated list") {
		list->push_back('a');
		list->push_back('b');
		list->push_back('c');

		LinkedList<char> *copy = new LinkedList<char>(*list);
		REQUIRE(*copy == *list);
	}
	SECTION("Empty list") {
		LinkedList<char> *copy = new LinkedList<char>(*list);
		REQUIRE(*copy == *list);
	}
	SECTION("Single value list") {
		list->push_back('a');
		LinkedList<char> *copy = new LinkedList<char>(*list);
		REQUIRE(*copy == *list);
	}
}

TEST_CASE("= assignment constructor") {
	LinkedList<char> *list = new LinkedList<char>();
	SECTION("Populated list") {
		list->push_back('a');
		list->push_back('b');
		list->push_back('c');

		LinkedList<char> copy;
		copy = *list;
		REQUIRE(copy == *list);
	}
	SECTION("Empty list") {
		LinkedList<char> copy;
		copy = *list;
		REQUIRE(copy == *list);
	}
}

TEST_CASE("= move assignment operator") {
	LinkedList<int> *l1 = new LinkedList<int>();
	
	l1->push_back(1);
	l1->push_back(2);
	LinkedList<int> comp = *l1;

	LinkedList<int> l2 = std::move(*l1);

	REQUIRE(l1->empty());
	REQUIRE(l2 == comp);
}