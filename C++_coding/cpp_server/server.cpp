#include <iostream>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    // 1. socket banao
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // port reuse allow (restart pe "address already in use" na aaye)
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 2. address + port set karke bind karo
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    bind(server_fd, (sockaddr*)&address, sizeof(address));

    // 3. listen
    listen(server_fd, 5);
    std::cout << "Server running on http://127.0.0.1:8080\n";

    // 4. loop: client accept karo, response bhejo
    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);

        char buffer[2048] = {0};
        read(client_fd, buffer, sizeof(buffer) - 1);   // browser ki request
        std::cout << buffer << "\n";

        std::string body = "<h1>Hello from C++ server! How are you</h1>";
        std::string navbar = "<h2>I'm Kundan Maurya </h2>";
        std::string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: " + std::to_string(body.size()) + "\r\n"
            "\r\n" + body ;

        write(client_fd, response.c_str(), response.size());
        close(client_fd);
    }
}