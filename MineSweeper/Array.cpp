#include "Array.hpp"

template <typename T>
Array<T>::Array() : mWidth(10), mHeight(10) {
	for (int i = 0; i < 100; i++) {
		mArray[i] = false;
	}
}