#include "HashTable.h"

void HashTable::push_back(HashBucket& element) {
    if (size == capacity) {
        capacity *= 2;
        HashBucket* newData = new HashBucket[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

void HashTable::insert_at(int index, HashBucket& element) {
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    if (size == capacity) {
        capacity *= 2;
        HashBucket* newData = new HashBucket[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++size;
}

void HashTable::remove_at(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    --size;
}

void HashTable::set_at(int index, HashBucket& element) const{
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    data[index] = element;
}

bool HashList::is_empty() const{
    return first == nullptr;
}

void HashList::push_back(string key, string value){
    HashBlock* new_elem = new HashBlock(key, value);

    if(is_empty()){
        first = new_elem;
        return;
    }

    new_elem->next = first;
    first = new_elem;
}

void HashList::delete_value(string key) {
    if (is_empty()){
        cout << "No such a key" << endl;
        return;
    }

    HashBlock* curr = first;
    HashBlock* prev = nullptr;

    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "No such a key" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

void HashList::print(string delimiter) const{
    if(is_empty()){
        cout << endl;
        return;
    }

    HashBlock* curr = first;

    while(curr->next != nullptr){
        cout << curr->key << ":" << curr->value << delimiter;
        curr = curr->next;
    }
    cout << curr->key << ":" << curr->value << endl;
}

int HashTable::hash(const string& key) const{
    int summ = 0;
    for (auto i: key){
        summ += static_cast<int>(i);
    }

    return summ % 30;
}

void HashTable::set(string key, string value){
    int valKey = hash(key);
    for (auto i = (data[valKey].data).first; i != nullptr; i = i->next){
        if (i->key == key){
            cerr << "There is same key" << endl;
            return;
        }
    }
    (data[valKey].data).push_back(key, value);
}

string HashTable::get_values(string key) const{
    int hashKey = hash(key);

    auto i = (data[hashKey].data).first;
    for (i; i != nullptr; i = i->next){
        if (i->key == key){
            return i->value;
        }
    }

    return "No such a key";
}

void HashTable::delete_value(const string& key){
    int hashKey = hash(key);

    for (auto i = (data[hashKey].data).first; i != nullptr; i = i->next){
        if (i->key == key) delete_value(key); return;
    }
    cout << "No such a key" << endl;
}

void HashTable::print() const{
    for (int i = 0; i < 30; ++i){
        cout << i << ": ";
        (data[i].data).print(", ");
    }
    cout << endl;
}