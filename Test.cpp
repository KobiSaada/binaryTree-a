#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("int BT ")
{
    BinaryTree<int> tree_of_ints;
    CHECK_NOTHROW(tree_of_ints.add_root(4));
    CHECK_NOTHROW(tree_of_ints.add_left(4, 8));
    CHECK_NOTHROW(tree_of_ints.add_left(8, 7));
    CHECK_NOTHROW(tree_of_ints.add_right(2, 5));
    CHECK_NOTHROW(tree_of_ints.add_right(5, 3));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
    CHECK_THROWS(tree_of_ints.add_right(12, 14));
    CHECK_THROWS(tree_of_ints.add_left(31, 2));
   
}
TEST_CASE ("add left and check pos order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 5; i++) {
        tree.add_left(i, i + 1);
    }
    int j = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
       
    }
}
TEST_CASE ("add right and check pos order") {
    BinaryTree<int> tree;
    tree.add_root(0);
    for (int i = 0; i < 5; i++) {
        tree.add_right(i, i + 1);
    }
    int j = 0;
    for (auto t = tree.begin_preorder(); t != tree.end_preorder(); t++,j++) {
                CHECK((*t) == j);
    }
}
TEST_CASE("string BT ")
{
    BinaryTree<string> tree_of_strings;
    CHECK_NOTHROW(tree_of_strings.add_root("ro"));
    CHECK_NOTHROW(tree_of_strings.add_left("ro", "left"));
    CHECK_NOTHROW(tree_of_strings.add_left("left", "left2"));
    CHECK_NOTHROW(tree_of_strings.add_right("left", "right"));
    CHECK_NOTHROW(tree_of_strings.add_right("right", "right2"));
    CHECK_NOTHROW(tree_of_strings.add_left("ro", "left3"));
    CHECK_THROWS(tree_of_strings.add_right("kobi", "no"));
    CHECK_THROWS(tree_of_strings.add_left("saada", "no"));
    
    CHECK_NOTHROW(tree_of_strings.add_root("my"));
    
    CHECK_THROWS(tree_of_strings.add_right("my1", "no"));
    CHECK_THROWS(tree_of_strings.add_left("ro", "no"));
 
}

TEST_CASE("char BT")
{
    BinaryTree<char> tree_of_char;
    CHECK_NOTHROW(tree_of_char.add_root('r'));
    CHECK_NOTHROW(tree_of_char.add_right('r', 'h'));
    CHECK_NOTHROW(tree_of_char.add_right('h', 'y'));

    CHECK_NOTHROW(tree_of_char.add_left('r', 'f'));
    CHECK_NOTHROW(tree_of_char.add_left('f', 'g'));

    CHECK_NOTHROW(tree_of_char.add_right('f', 'b'));
   
    CHECK_NOTHROW(tree_of_char.add_right('y', 's'));
 
    CHECK_NOTHROW(tree_of_char.add_left('s', 'a'));
    CHECK_THROWS(tree_of_char.add_right('z', 'g'));
    CHECK_THROWS(tree_of_char.add_left('q', 'a'));
    CHECK_NOTHROW(tree_of_char.add_root('n'));
    CHECK_THROWS(tree_of_char.add_right('p', 'y'));
    CHECK_THROWS(tree_of_char.add_left('l', 'a'));

}
