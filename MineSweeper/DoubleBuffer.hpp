#include <Windows.h>
#include <string>

// �Ăяo����DLL Initialization failed �ɂȂ�̂Ŏg���Ă��Ȃ�
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
