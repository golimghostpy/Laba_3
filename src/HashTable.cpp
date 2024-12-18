#include "../includes/HashTable.h"

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
    HashBlock* curr = first;
    HashBlock* prev = nullptr;

    while (curr != nullptr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr)
    {
        delete curr;
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

int hash_find(const string& key){
    int summ = 0;
    for (auto i: key){
        summ += static_cast<int>(i);
    }

    return summ % 30;
}

void HashTable::set(string key, string value){
    int valKey = hash_find(key);
    for (auto i = (data[valKey].data).first; i != nullptr; i = i->next){
        if (i->key == key){
            cerr << "There is same key" << endl;
            return;
        }
    }
    (data[valKey].data).push_back(key, value);
}

string HashTable::get_values(string key) const{
    int hashKey = hash_find(key);

    auto i = (data[hashKey].data).first;
    for (i; i != nullptr; i = i->next){
        if (i->key == key){
            return i->value;
        }
    }

    return "No such a key";
}

void HashTable::delete_value(const string& key){
    int hashKey = hash_find(key);

    for (auto i = (data[hashKey].data).first; i != nullptr; i = i->next){
        if (i->key == key)
        {
            (data[hashKey].data).delete_value(key);
            return;
        }
    }
    throw out_of_range("No such a key");
}

void HashTable::print() const{
    for (int i = 0; i < 30; ++i){
        cout << i << ": ";
        (data[i].data).print(", ");
    }
    cout << endl;
}