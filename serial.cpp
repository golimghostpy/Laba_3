#include <iostream>
#include <fstream>
#include <sstream>
#include "includes/Array.h"
#include "includes/OList.h"
#include "includes/DList.h"
#include "includes/Queue.h"
#include "includes/Stack.h"
#include "includes/AVLTree.h"
#include "includes/HashTable.h"

using namespace std;

void serial_array()
{
    string filename = "array.bin";
    Array testArr;
    testArr.push_back("hello");
    testArr.push_back("my");
    testArr.push_back("friend");

    cout << "Before array serial:" << endl;
    cout << testArr.print();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size = testArr.size;
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (auto i = 0; i < size; ++i) {
        string str = testArr.get_at(i);
        size_t length = str.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(str.c_str(), length);
    }

    outFile.close();
}

void deserial_array() {
    string filename = "array.bin";
    Array testArr;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

        string str(length, '\0');
        inFile.read(&str[0], length);
        testArr.push_back(str);
    }

    inFile.close();

    cout << "After array deserialization:" << endl;
    cout << testArr.print() << endl;
}



void serialize_tree(TreeNode* node, ofstream& outFile) {
    if (node == nullptr) {
        // Записываем 0 для обозначения пустого узла
        int nullMarker = 0;
        outFile.write(reinterpret_cast<const char*>(&nullMarker), sizeof(nullMarker));
        return;
    }

    // Записываем 1 для обозначения непустого узла
    int nullMarker = 1;
    outFile.write(reinterpret_cast<const char*>(&nullMarker), sizeof(nullMarker));

    // Записываем ключ узла
    size_t keyLength = node->key.size();
    outFile.write(reinterpret_cast<const char*>(&keyLength), sizeof(keyLength));
    outFile.write(node->key.c_str(), keyLength);

    // Рекурсивно сериализуем левое и правое поддеревья
    serialize_tree(node->left, outFile);
    serialize_tree(node->right, outFile);
}

void serial_tree() {
    string filename = "tree.bin";
    AVLTree tree;
    tree.insert("hello");
    tree.insert("my");
    tree.insert("friend");

    cout << "Before tree serial:" << endl;
    tree.print();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    serialize_tree(tree.get_root(), outFile);
    outFile.close();
}

TreeNode* deserialize_tree(ifstream& inFile) {
    int nullMarker;
    inFile.read(reinterpret_cast<char*>(&nullMarker), sizeof(nullMarker));

    if (nullMarker == 0) {
        return nullptr; // Если встретили 0, возвращаем nullptr
    }

    TreeNode* node = new TreeNode();

    size_t keyLength;
    inFile.read(reinterpret_cast<char*>(&keyLength), sizeof(keyLength));

    node->key.resize(keyLength);
    inFile.read(&node->key[0], keyLength);

    // Рекурсивно десериализуем левое и правое поддеревья
    node->left = deserialize_tree(inFile);
    node->right = deserialize_tree(inFile);

    return node;
}

void deserial_tree() {
    string filename = "tree.bin";
    AVLTree tree;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    tree.root = deserialize_tree(inFile);
    inFile.close();

    cout << "After tree deserialization:" << endl;
    tree.print();
}


// для односвязного списка все абсолютно точно также
void serial_tlist() {
    string filename = "tlist.bin";
    TList testTlist;
    testTlist.push_back("hello");
    testTlist.push_back("my");
    testTlist.push_back("friend");

    cout << "Before list serial:" << endl;
    cout << testTlist.print(", ");

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size = testTlist.size;
    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    TNode* current = testTlist.find_at(0);
    while (current != nullptr) {
        size_t length = current->data.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(current->data.c_str(), length);
        current = current->next;
    }

    outFile.close();
}

void deserial_tlist() {
    string filename = "tlist.bin";
    TList testTlist;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

        string str(length, '\0');
        inFile.read(&str[0], length);
        testTlist.push_back(str);
    }

    inFile.close();

    cout << "After list deserialization:" << endl;
    cout << testTlist.print(", ") << endl;
}



void serial_hash_table() {
    string filename = "hashtable.bin";
    HashTable hashTable;

    hashTable.set("key1", "value1");
    hashTable.set("key2", "value2");
    hashTable.set("key3", "value3");

    cout << "Before hash table serial:" << endl;
    hashTable.print();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t capacity = 30;
    outFile.write(reinterpret_cast<const char*>(&capacity), sizeof(capacity));

    for (int i = 0; i < capacity; ++i) {
        HashList& list = hashTable.data[i].data;
        size_t listSize = 0;

        for (HashBlock* curr = list.first; curr != nullptr; curr = curr->next) {
            ++listSize;
        }

        outFile.write(reinterpret_cast<const char*>(&listSize), sizeof(listSize));

        for (HashBlock* curr = list.first; curr != nullptr; curr = curr->next) {
            size_t keyLength = curr->key.size();
            size_t valueLength = curr->value.size();

            outFile.write(reinterpret_cast<const char*>(&keyLength), sizeof(keyLength));
            outFile.write(curr->key.c_str(), keyLength);

            outFile.write(reinterpret_cast<const char*>(&valueLength), sizeof(valueLength));
            outFile.write(curr->value.c_str(), valueLength);
        }
    }

    outFile.close();
}

void deserial_hash_table() {
    string filename = "hashtable.bin";
    HashTable hashTable;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t capacity;
    inFile.read(reinterpret_cast<char*>(&capacity), sizeof(capacity));

    for (int i = 0; i < capacity; ++i) {
        size_t listSize;
        inFile.read(reinterpret_cast<char*>(&listSize), sizeof(listSize));

        for (size_t j = 0; j < listSize; ++j) {
            size_t keyLength;
            inFile.read(reinterpret_cast<char*>(&keyLength), sizeof(keyLength));

            string key(keyLength, '\0');
            inFile.read(&key[0], keyLength);

            size_t valueLength;
            inFile.read(reinterpret_cast<char*>(&valueLength), sizeof(valueLength));

            string value(valueLength, '\0');
            inFile.read(&value[0], valueLength);

            hashTable.set(key, value);
        }
    }

    inFile.close();

    cout << "After hash table deserialization:" << endl;
    hashTable.print();
}



void serial_queue() {
    string filename = "queue.bin";
    Queue testQueue;
    testQueue.push("hello");
    testQueue.push("my");
    testQueue.push("friend");

    cout << "Before queue serial:" << endl;
    cout << testQueue.print();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size = 0;
    ONode* current = testQueue.head;
    while (current != nullptr) {
        ++size;
        current = current->next;
    }

    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    current = testQueue.head;
    while (current != nullptr) {
        size_t length = current->data.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(current->data.c_str(), length);
        current = current->next;
    }

    outFile.close();
}

void deserial_queue() {
    string filename = "queue.bin";
    Queue testQueue;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

        string str(length, '\0');
        inFile.read(&str[0], length);
        testQueue.push(str);
    }

    inFile.close();

    cout << "After queue deserialization:" << endl;
    cout << testQueue.print() << endl;
}



void serial_stack() {
    string filename = "stack.bin";
    Stack testStack;
    testStack.push("hello");
    testStack.push("my");
    testStack.push("friend");

    cout << "Before stack serial:" << endl;
    cout << testStack.print();

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size = 0;
    ONode* current = testStack.head;
    while (current != testStack.tail) {
        ++size;
        current = current->next;
    }
    ++size;

    outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

    current = testStack.head;
    for (auto i = 0; i < size; ++i) {
        size_t length = current->data.size();
        outFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
        outFile.write(current->data.c_str(), length);
        current = current->next;
    }

    outFile.close();
}

void deserial_stack() {
    string filename = "stack.bin";
    Stack testStack;

    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Error to open file: " << filename << endl;
        return;
    }

    size_t size;
    inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

    for (size_t i = 0; i < size; ++i) {
        size_t length;
        inFile.read(reinterpret_cast<char*>(&length), sizeof(length));

        string str(length, '\0');
        inFile.read(&str[0], length);
        testStack.push(str);
    }

    inFile.close();

    // реверсим стек, потому что читается он в обратном порядке
    Stack result;
    auto curr = testStack.head;
    for (auto i = 0; i < size; ++i)
    {
        result.push(curr->data);
        curr = curr->next;
    }

    cout << "After stack deserialization:" << endl;
    cout << result.print() << endl;
}


int main(){
    serial_array();
    deserial_array();

    serial_tree();
    deserial_tree();

    serial_tlist();
    deserial_tlist();

    serial_hash_table();
    deserial_hash_table();

    serial_queue();
    deserial_queue();

    serial_stack();
    deserial_stack();
    return 0;
}
