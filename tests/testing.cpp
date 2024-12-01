#include "../includes/libs.h"
#include "gtest/gtest.h"
#include "../includes/Array.h"
#include "../includes/OList.h"
#include "../includes/DList.h"
#include "../includes/Queue.h"
#include "../includes/Stack.h"
#include "../includes/AVLTree.h"
#include "../includes/HashTable.h"

int main(int, char **);

// Array testing --------------------------------------------------
TEST(Array, Create)
{
    auto testArr = new Array;

    ASSERT_TRUE(testArr != nullptr);
}

TEST(Array, Push_back_and_get)
{
    Array testArr;

    ASSERT_TRUE(testArr.size == 0 && testArr.capacity == 1);
    testArr.push_back("hello");
    testArr.push_back("world");
    ASSERT_TRUE(testArr.size == 2 && testArr.capacity == 2);

    ASSERT_TRUE(testArr.get_at(0) == "hello");
    ASSERT_THROW(testArr.get_at(5), out_of_range);
}

TEST(Array, Insert_at)
{
    Array testArr;

    ASSERT_TRUE(testArr.size == 0 && testArr.capacity == 1);
    testArr.insert_at(0, "hello");
    testArr.insert_at(0, "world");
    ASSERT_TRUE(testArr.size == 2 && testArr.capacity == 2);

    ASSERT_TRUE(testArr.get_at(0) == "world");
    ASSERT_THROW(testArr.insert_at(100, "bye");, out_of_range);
}

TEST(Array, Remove_at)
{
    Array testArr;
    testArr.push_back("hello");
    testArr.push_back("how");
    testArr.push_back("you");

    testArr.remove_at(2);
    ASSERT_THROW(testArr.get_at(2), out_of_range);
    ASSERT_THROW(testArr.remove_at(3);, out_of_range);
}

TEST(Array, Set_at)
{
    Array testArr;
    testArr.push_back("hello");
    testArr.push_back("how");
    testArr.push_back("you");

    testArr.set_at(1, "changed");

    ASSERT_TRUE(testArr.get_at(1) == "changed");
    ASSERT_THROW(testArr.set_at(3, "bye");, out_of_range);
}

TEST(Array, Print)
{
    Array testArr;
    testArr.push_back("hello");
    testArr.push_back("world");

    ASSERT_TRUE(testArr.print() == "hello world \n");
}

// One way list testing --------------------------------------------------
TEST(OList, Create)
{
    auto testList = new OList;

    ASSERT_TRUE(testList != nullptr);
}

TEST(OList, Is_empty)
{
    OList testList;
    ASSERT_TRUE(testList.is_empty());

    testList.push_back("hello");
    ASSERT_FALSE(testList.is_empty());
}

TEST(OList, Push_front)
{
    OList testList;

    testList.push_front("hello");
    testList.push_front("bye");
    ASSERT_TRUE(testList.find_at(0)->data == "bye");
}

TEST(OList, Push_back)
{
    OList testList;

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_at(1)->data == "bye");
}

TEST(OList, Delete_front)
{
    OList testList;

    ASSERT_THROW(testList.delete_front(), out_of_range);

    testList.push_front("hello");
    testList.push_front("bye");
    testList.delete_front();
    ASSERT_TRUE(testList.find_at(0)->data == "hello");
}

TEST(OList, Delete_back)
{
    OList testList;

    ASSERT_THROW(testList.delete_back(), out_of_range);

    testList.push_back("hello");
    testList.push_back("bye");
    testList.delete_back();
    ASSERT_TRUE(testList.find_at(0)->data == "hello");
}

TEST(OList, Delete_value)
{
    OList testList;

    ASSERT_THROW(testList.delete_value("hi"), out_of_range);

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_THROW(testList.delete_value("hi"), out_of_range);
    testList.delete_value("hello");
    ASSERT_TRUE(testList.find_at(0)->data == "bye");
}

TEST(OList, Find_value)
{
    OList testList;

    ASSERT_TRUE(testList.find_value("hello") == -1);

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_value("hi") == -1);
    ASSERT_TRUE(testList.find_value("bye") == 1);
}

TEST(OList, Find_at)
{
    OList testList;

    ASSERT_THROW(testList.find_at(0), out_of_range);

    testList.push_back("hello");
    ASSERT_THROW(testList.find_at(-5), out_of_range);

    testList.push_back("and");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_at(1)->data == "and");
}

TEST(OList, Join)
{
    OList testList;

    testList.push_back("hello");
    testList.push_back("and");
    testList.push_back("bye");
    ASSERT_TRUE(testList.join(' ') == "hello and bye ");
}

TEST(OList, Print)
{
    OList testList;

    ASSERT_TRUE(testList.print(" ") == "\n");

    testList.push_back("hello");
    testList.push_back("world");

    ASSERT_TRUE(testList.print(" ") == "hello world\n");
}

TEST(OList, Split)
{
    string testString = "hello world";

    OList testList = split(testString, " ");
    ASSERT_TRUE(testList.find_at(0)->data == "hello" && testList.find_at(1)->data == "world");
}

// Two way list testing --------------------------------------------------
TEST(TList, Create)
{
    auto testList = new TList;

    ASSERT_TRUE(testList != nullptr);
}

TEST(TList, Is_empty)
{
    TList testList;
    ASSERT_TRUE(testList.is_empty());

    testList.push_back("hello");
    ASSERT_FALSE(testList.is_empty());
}

TEST(TList, Push_front)
{
    TList testList;

    testList.push_front("hello");
    testList.push_front("bye");
    ASSERT_TRUE(testList.find_at(0)->data == "bye");
}

TEST(TList, Push_back)
{
    TList testList;

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_at(1)->data == "bye");
}

TEST(TList, Delete_front)
{
    TList testList;

    ASSERT_TRUE(testList.is_empty());
    ASSERT_THROW(testList.delete_front(), out_of_range);

    testList.push_front("hello");
    testList.push_front("bye");
    testList.delete_front();
    ASSERT_FALSE(testList.is_empty());
    ASSERT_TRUE(testList.find_at(0)->data == "hello");
}

TEST(TList, Delete_back)
{
    TList testList;

    ASSERT_THROW(testList.delete_back(), out_of_range);

    testList.push_back("hello");
    testList.push_back("bye");
    testList.delete_back();
    ASSERT_TRUE(testList.find_at(0)->data == "hello");
}

TEST(TList, Delete_value)
{
    TList testList;

    ASSERT_THROW(testList.delete_value("hi"), out_of_range);

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_THROW(testList.delete_value("hi"), out_of_range);
    testList.delete_value("hello");
    ASSERT_TRUE(testList.find_at(0)->data == "bye");
}

TEST(TList, Find_value)
{
    TList testList;

    ASSERT_TRUE(testList.find_value("hello") == -1);

    testList.push_back("hello");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_value("hi") == -1);
    ASSERT_TRUE(testList.find_value("bye") == 1);
}

TEST(TList, Find_at)
{
    TList testList;

    ASSERT_THROW(testList.find_at(0), out_of_range);

    testList.push_back("hello");
    ASSERT_THROW(testList.find_at(-5), out_of_range);

    testList.push_back("and");
    testList.push_back("bye");
    ASSERT_TRUE(testList.find_at(1)->data == "and");
}

TEST(TList, Print)
{
    TList testList;

    testList.push_back("hello");
    testList.push_back("world");
    ASSERT_TRUE(testList.print(" ") == "hello world\n");
}

// Stack testing --------------------------------------------------
TEST(Stack, Create)
{
    auto testStack = new Stack;

    ASSERT_TRUE(testStack != nullptr);
}

TEST(Stack, Is_empty)
{
    Stack testStack;

    ASSERT_TRUE(testStack.is_empty());

    testStack.push("hello");
    ASSERT_FALSE(testStack.is_empty());
}

TEST(Stack, Push)
{
    Stack testStack;

    testStack.push("hello");
    testStack.push("bye");
    ASSERT_TRUE(testStack.get_head() == "bye");
}

TEST(Stack, Pop)
{
    Stack testStack;

    ASSERT_THROW(testStack.pop(), out_of_range);

    testStack.push("hello");
    testStack.push("bye");
    testStack.pop();
    ASSERT_TRUE(testStack.get_head() == "hello");
}

TEST(Stack, Print)
{
    Stack testStack;

    testStack.push("hello");
    testStack.push("world");
    ASSERT_TRUE(testStack.print() == "world->hello\n");
}

// Queue testing --------------------------------------------------
TEST(Queue, Create)
{
    auto testQueue = new Queue;

    ASSERT_TRUE(testQueue != nullptr);
}

TEST(Queue, Is_empty)
{
    Queue testQueue;

    ASSERT_TRUE(testQueue.is_empty());

    testQueue.push("hello");
    ASSERT_FALSE(testQueue.is_empty());
}

TEST(Queue, Push)
{
    Queue testQueue;

    testQueue.push("hello");
    testQueue.push("bye");
    ASSERT_TRUE(testQueue.get_head() == "hello");
}

TEST(Queue, Pop)
{
    Queue testQueue;

    ASSERT_THROW(testQueue.pop(), out_of_range);

    testQueue.push("hello");
    testQueue.push("bye");
    testQueue.pop();
    ASSERT_TRUE(testQueue.get_head() == "bye");
}

TEST(Queue, Print)
{
    Queue testQueue;

    testQueue.push("hello");
    testQueue.push("world");
    ASSERT_TRUE(testQueue.print() == "hello<-world\n");
}

// AVLTree testing --------------------------------------------------
TEST(Tree, Create)
{
    auto testTree = new AVLTree;

    ASSERT_TRUE(testTree != nullptr);
}

TEST(Tree, Get_root)
{
    AVLTree testTree;

    ASSERT_TRUE(testTree.get_root() == nullptr);

    testTree.insert("hello");
    ASSERT_TRUE(testTree.get_root()->key == "hello");
}

TEST(Tree, Min_value_node)
{
    AVLTree testTree;
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("40");

    ASSERT_TRUE(testTree.minValueNode(testTree.get_root())->key == "20");
}

TEST(Tree, Insert) {
    AVLTree testTree;
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("40");

    ASSERT_TRUE(testTree.search("30"));
    ASSERT_TRUE(testTree.search("20"));
    ASSERT_TRUE(testTree.search("40"));
    ASSERT_FALSE(testTree.search("10"));
}

TEST(Tree, Remove) {
    AVLTree testTree;
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("40");
    testTree.insert("10");

    ASSERT_TRUE(testTree.search("10"));

    testTree.remove("10");
    ASSERT_FALSE(testTree.search("10"));
}

TEST(Tree, Insert_and_balance) {
    AVLTree testTree;
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("10");
    testTree.insert("10");

    ASSERT_TRUE(testTree.get_root()->key == "20");

    AVLTree testTree1;
    testTree1.insert("10");
    testTree1.insert("20");
    testTree1.insert("30");

    ASSERT_TRUE(testTree1.get_root()->key == "20");

    AVLTree testTree2;
    testTree2.insert("30");
    testTree2.insert("10");
    testTree2.insert("20");

    ASSERT_TRUE(testTree2.get_root()->key == "20");

    AVLTree testTree3;
    testTree3.insert("10");
    testTree3.insert("30");
    testTree3.insert("20");

    ASSERT_TRUE(testTree3.get_root()->key == "20");
}

TEST(Tree, Remove_and_balance) {
    AVLTree testTree;
    testTree.insert("2");
    testTree.insert("1");
    testTree.insert("3");
    testTree.insert("4");

    ASSERT_TRUE(testTree.get_root()->key == "2");

    testTree.remove("1");
    ASSERT_TRUE(testTree.get_root()->key == "3");

    AVLTree testTree1;
    testTree1.insert("3");
    testTree1.insert("2");
    testTree1.insert("4");
    testTree1.insert("1");

    ASSERT_TRUE(testTree1.get_root()->key == "3");

    testTree1.remove("4");
    ASSERT_TRUE(testTree1.get_root()->key == "2");

    AVLTree testTree2;
    testTree2.insert("3");
    testTree2.insert("2");
    testTree2.insert("4");
    testTree2.insert("1");

    ASSERT_TRUE(testTree2.get_root()->key == "3");

    testTree2.remove("2");
    ASSERT_TRUE(testTree2.get_root()->key == "3");
}

TEST(Tree, Print_empty_tree) {
    AVLTree testTree;
    testing::internal::CaptureStdout();
    testTree.print();
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "");
}

TEST(Tree, Print_nonempty_tree) {
    AVLTree testTree;
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("40");

    testing::internal::CaptureStdout();
    testTree.print();
    string output = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(output.find("30") != string::npos);
    ASSERT_TRUE(output.find("20") != string::npos);
    ASSERT_TRUE(output.find("40") != string::npos);
}

TEST(Tree, To_string_tree) {
    AVLTree testTree;
    ASSERT_EQ(testTree.to_string_tree(), "");
    testTree.insert("30");
    testTree.insert("20");
    testTree.insert("40");

    ASSERT_EQ(testTree.to_string_tree(), "30 20 40 ");
}

// HashTable testing --------------------------------------------------
TEST(HashTable, Insert_and_get) {
    HashTable testTable;
    testTable.set("key1", "value1");
    ASSERT_EQ(testTable.get_values("key1"), "value1");

    testTable.set("key2", "value2");
    ASSERT_EQ(testTable.get_values("key2"), "value2");
}

TEST(HashTable, Get_non_exist) {
    HashTable testTable;
    ASSERT_EQ(testTable.get_values("nonexistent_key"), "No such a key");
}

TEST(HashTable, Insert_duplicate) {
    HashTable testTable;
    testTable.set("key1", "value1");
    testTable.set("key1", "value2");
    ASSERT_EQ(testTable.get_values("key1"), "value1");
}

TEST(HashTable, Delete) {
    HashTable testTable;
    ASSERT_THROW(testTable.delete_value("key1"), out_of_range);

    testTable.set("key1", "value1");
    ASSERT_THROW(testTable.delete_value("key2"), out_of_range);

    testTable.delete_value("key1");
    ASSERT_EQ(testTable.get_values("key1"), "No such a key");
}

TEST(HashTable, Print) {
    HashTable testTable;
    testTable.set("key1", "value1");
    testTable.set("key2", "value2");

    testing::internal::CaptureStdout();
    testTable.print();
    string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("0: "), string::npos);
}

TEST(HashTable, Insert_alot) {
    HashTable testTable;
    for (int i = 0; i < 100; ++i) {
        testTable.set("key" + to_string(i), "value" + to_string(i));
    }
    ASSERT_EQ(testTable.get_values("key99"), "value99");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}