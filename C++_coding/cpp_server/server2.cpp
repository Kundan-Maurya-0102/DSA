// #include "httplib.h"

// int main() {
//     httplib::Server svr;

//     svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
//         res.set_content("<h1>Hello from C++!</h1>", "text/html");
//     });

//     svr.Get("/about", [](const httplib::Request&, httplib::Response& res) {
//         res.set_content("About page", "text/plain");
//     });

//     svr.listen("0.0.0.0", 8080);
// }

#include "httplib.h"

int main() {
    httplib::Server svr;

    svr.set_mount_point("/", "./public");

    svr.listen("0.0.0.0", 8080);
}