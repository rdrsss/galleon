
#include "gtest/gtest.h"

// TODO :: write usit tests
#include "linkedlist.hpp"


TEST(LinkedListAddFrontTest, AddFront) {
	hepp::linked_list<int> ll;
	ll.add_front(0);
	ll.add_front(1);
	ll.add_front(2);
	ll.add_front(3);
	ll.add_front(4);
	ll.add_front(5);
	EXPECT_EQ(6, ll.count());
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
