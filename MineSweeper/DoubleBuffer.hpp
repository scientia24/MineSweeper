#include <Windows.h>
#include <string>

// 呼び出すとDLL Initialization failed になるので使っていない
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
