#include <Windows.h>
#include <string>

class DoubleBuffer {
public:
	DoubleBuffer();
	~DoubleBuffer();
	void write(const std::string& str);

private:
	void swapBuffer();

	HANDLE mHandle1;
	HANDLE mHandle2;
	bool mIsSwaped;
};
