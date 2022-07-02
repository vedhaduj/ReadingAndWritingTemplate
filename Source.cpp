#include <iostream>
#include <Windows.h>

void ReadM(HANDLE process, LPCVOID address, LPVOID output)
{
	ReadProcessMemory(process, (LPCVOID)address, output, sizeof(output), nullptr);
}
void WriteM(HANDLE process, LPVOID destination, LPVOID source)
{
	WriteProcessMemory(process, destination, source, sizeof(source), 0);
}

HANDLE GetProcess()
{
	DWORD pid;
	HANDLE process{};
	HWND window = FindWindowA(0, "AssaultCube");
	//lazy moment
	if (!window)
	{
		std::cout << "Window Error\n";
	}
	GetWindowThreadProcessId(window, &pid);
	process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (!process)
	{
		std::cout << "Process Error\n";
	}
	return process;
}


int main()
{
	int outty{};
	int newammo = 5000;
	HANDLE Process = GetProcess();
	
}
