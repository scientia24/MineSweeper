#include <Windows.h>
#include <string>

// ŒÄ‚Ño‚·‚ÆDLL Initialization failed ‚É‚È‚é‚Ì‚Åg‚Á‚Ä‚¢‚È‚¢
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
