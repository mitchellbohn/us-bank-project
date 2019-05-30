#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main() {
	WSADATA WSAData;
	SOCKET server;
	SOCKADDR_IN addr;
	WSAStartup(MAKEWORD(2, 0), &WSAData);
	server = socket(AF_INET, SOCK_STREAM, 0);

	InetPton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(server, (SOCKADDR *)&addr, sizeof(addr));

	cout << "Connected to server!" << endl;
	char buffer[1024];
	cout << "Please enter your message: " << endl;
	cin >> buffer;
	send(server, buffer, sizeof(buffer), 0);
	cout << "Message sent!" << endl;

	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl;
	cin.get();
	cin.get();
	return 0;
}