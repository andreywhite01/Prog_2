#include "programm_2.h"

int main()
{
    ServerPart server;
    server.createServer("127.0.0.1", 8080);
    server.createConnection();

    do {
        SOCKET ServSock = server.getServSock();
        SOCKET ClientConn = server.getClientConn();

        vector<char> buf(BUFF_SIZE);
        short packet_size = 0;

        while (true) {
            packet_size = recv(ClientConn, buf.data(), buf.size(), 0);
            if (packet_size == SOCKET_ERROR || packet_size == 0) {
                closesocket(ClientConn);
                break;
            }

            int receivedValue = convertVecCharToInt(buf);
            if (receivedValue > 9 && receivedValue % 32 == 0)
                cout << receivedValue << endl;
            else
                cout << "Error! Incorrect value was received = " << receivedValue << endl;

        }
        server.reconnect();
    } while (true);
}

int convertVecCharToInt(vector<char> vec) {
    string str(vec.begin(), vec.end());
    return atoi(str.c_str());
}