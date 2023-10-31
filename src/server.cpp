#include <iostream>
#include <cstring>
#include <iterator>
#include <ostream>
#include <string>
#include <sys/_endian.h>
#include <sys/_types/_socklen_t.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 50000

void print(std::string &&some_str) {
    std::cout << some_str << std::endl;
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t address_len = sizeof(address);
    char buffer[1024] = {0};

    print("creating socket"); 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation failed!" << std::endl;
        return -1;
    }

    address.sin_family = AF_INET;
    // listen on every interface in the computer.
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    print("binding socket"); 
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        std::cerr << "Socket binding failed!" << std::endl;
        return -1;
    }

    print("start listening"); 
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }

    print("accept connection");
    if ((client_fd = accept(server_fd, (struct sockaddr *) &address, &address_len)) < 0) {
        std::cerr << "Accept failed" << std::endl;
        std::cerr << client_fd << std::endl;
        return -1;
    }

    print("reading from client");
    read(client_fd, buffer, 1024);

    std::cout << "Received data: " << buffer << std::endl;

    close(client_fd);
    close(server_fd);

    return 0;
}
