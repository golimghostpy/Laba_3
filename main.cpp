#include "libs.h"
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree test;
    for (int i = 0; i < 10; ++i)
    {
        test.insert(to_string(i));
    }

    cout << test.to_string_tree() << endl;
    return 0;
}
