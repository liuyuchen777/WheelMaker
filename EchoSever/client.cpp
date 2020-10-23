#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

// error code
const int PARAMETER_ERROR = -1;
const int SOCKET_ERROR = -2;
const int IP_ADDRESS_ERROR = -3;
const int VALID_ADDRESS_ERROR = -4;
const int CONNECT_ERROR = -5;
// const number
const int BUF_LEN = 4096;
// other function
bool is_int(char *c);

int main(int argc, char **argv) // argv[2] is port number, argv[1] is ipv4 address
{
    // Check arguments
    if (argc < 3 || !is_int(argv[2])) 
    {
        std::cerr << "[ERROR] Parameters are not valid!\n";
        return PARAMETER_ERROR;
    }

    int             port {std::atoi(argv[2])};
    sockaddr_in     server_addr;
    hostent         *server;
    // Create a socket & get the file descriptor
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    // Check If the socket is created
    if (sock_fd < 0) 
    {
        std::cerr << "[ERROR] Socket cannot be created!\n";
        return SOCKET_ERROR;
    }

    std::cout << "[INFO] Socket has been created.\n";

    // Get host information by name, gethostbyname is not thread-safe, checkout getaddrinfo
    server = gethostbyname(argv[1]);
    if (!server) 
    {
        std::cerr << "[ERROR] No such host!\n";
        return IP_ADDRESS_ERROR;
    }
    std::cout << "[INFO] Hostname is found.\n";

    // Fill address fields before try to connect
    std::memset((char*)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Check if there is an address of the host
    if (server->h_addr_list[0])
        std::memcpy((char*)server->h_addr_list[0], (char*)&server_addr.sin_addr, server->h_length);
    else 
    {
        std::cerr << "[ERROR] There is no a valid address for that hostname!\n";
        return VALID_ADDRESS_ERROR;
    }

    if (connect(sock_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection cannot be established!\n";
        return CONNECT_ERROR;
    }
    std::cout << "[INFO] Connection established.\n";

    char buf[BUF_LEN];
    std::string temp;
    // While user input is not empty or "quit"
    // Send data to the server
    // Wait for a message/response
    // Print the response
    do 
    {
        // Clear buffer, get user input
        std::memset(buf, 0, 4096);
        std::cout << "> ";
        std::getline(std::cin, temp, '\n');
        std::strcpy(buf, temp.c_str());

        if (!strlen(buf)) 
            continue;   // buf is empty, continue
        else if (!strcmp(buf, "quit")) 
            break;

        // Send the data that buffer contains
        int bytes_send = send(sock_fd, &buf, (size_t)strlen(buf), 0);
        // Check if message sending is successful
        if (bytes_send < 0) 
        {
            std::cerr << "[ERROR] Message cannot be sent!\n";
            break;
        }

        // Wait for a message
        int bytes_recv = recv(sock_fd, &buf, 4096, 0);

        // Check how many bytes recieved
        // If something gone wrong
        if (bytes_recv < 0) 
        {
            std::cerr << "[ERROR] Message cannot be recieved!\n";
        }
        // If there is no data, it means server is disconnected
        else if (bytes_recv == 0) 
        {
            std::cout << "[INFO] Server is disconnected.\n";
        }
        // If there is some bytes, print
        else 
        {
            std::cout << "server> " << std::string(buf, 0, bytes_recv) << "\n";
        }
    } while (true);

    // Close socket
    close(sock_fd);
    std::cout << "[INFO] Socket is closed.\n";

    return 0;
}

bool is_int(char *c)
{
    while (*c != '\0')
    {
        if (*c < '0' || *c > '9')
            return false;
        c++;
    }
    return true;
}