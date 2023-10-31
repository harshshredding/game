#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>

#define PORT 50000

void print(std::string &&some_str) {
    std::cout << some_str << std::endl;
}

int main() {
    int client_fd;
    struct sockaddr_in address;
    char buffer[1024]  = {0};

    print("Create socket");
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);

    // Initialize IP address 
    if(inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0) {
        std::cerr << "Invalid address" << std::endl;
        return -1;
    }

    print("Connect");
    if (connect(client_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }

    const char *msg = "Hello from client!";
    send(client_fd, msg, strlen(msg), 0);
    std::cout << "Message sent to server" << std::endl;

    return 0;
}
