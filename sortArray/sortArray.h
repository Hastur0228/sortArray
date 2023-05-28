#ifndef Hasturas
#define Hasturas

#include <iostream>

using namespace std;

template<class KEY, class OTHER>
struct SET
{
    KEY key;
    OTHER other;
};

template<class KEY, class OTHER>
class sortArray {
private:
    SET<KEY, OTHER>* root;
    int curSize;

public:
    sortArray(const SET<KEY, OTHER> data[], int size);
    ~sortArray() { delete[] root; };
    void arrSort();
    void show();
};

template<class KEY, class OTHER>
sortArray<KEY, OTHER>::sortArray(const SET<KEY, OTHER>* data, int size) {
    curSize = size;
    root = new SET<KEY, OTHER>[curSize];
    for (int i = 0; i < size; ++i) {
        root[i].key = data[i].key;
        root[i].other = data[i].other;
    }
}

template<class KEY, class OTHER>
void sortArray<KEY, OTHER>::arrSort() 
{
int i, j, k;
	for (i = 1; i < curSize; ++i) {
		for (j = i - 1; j >= 0; --j) {
			if (root[j].key < root[i].key) {
				break;
			}
		}
		SET<KEY, OTHER> temp = root[i];
		for (k = i - 1; k > j; --k) {
			root[k + 1] = root[k];
		}
		root[k + 1] = temp;
	}
}

template<class KEY, class OTHER>
void sortArray<KEY, OTHER>::show() {
    for (int i = 0; i < curSize; ++i) {
        cout << "(" << root[i].key << ", " << root[i].other << ") ";
    }
    cout << endl;
}

#endif //Hasturas
