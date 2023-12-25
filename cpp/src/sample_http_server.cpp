#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include "httplib.h"

int main(void)
{
    using httplib::Server;
    using httplib::Request;
    using httplib::Response;

    Server svr;

    const std::string PROJECT_ROOT(std::getenv("PROJECT_ROOT") ? std::getenv("PROJECT_ROOT") : ".");
    std::cout << PROJECT_ROOT;

    svr.Get("/", [](const Request&, Response& res){
        const std::string PROJECT_ROOT(std::getenv("PROJECT_ROOT") ? std::getenv("PROJECT_ROOT") : ".");
        std::ifstream ifs(PROJECT_ROOT + "/data/index.html");
        std::stringstream ss;
        ss << ifs.rdbuf();
        std::string body(ss.str());    
        res.set_content(body, "text/html"); 
    });

    svr.Get("/sample.xml", [](const Request&, Response& res){
        const std::string PROJECT_ROOT(std::getenv("PROJECT_ROOT") ? std::getenv("PROJECT_ROOT") : ".");
        std::ifstream ifs(PROJECT_ROOT + "/data/sample.xml");
        std::stringstream ss;
        ss << ifs.rdbuf();
        std::string body(ss.str());    
        res.set_content(body, "text/html"); 
    });

    svr.Get("/sample.bmp", [](const Request&, Response& res){
        const std::string PROJECT_ROOT(std::getenv("PROJECT_ROOT") ? std::getenv("PROJECT_ROOT") : ".");
        std::ifstream ifs(PROJECT_ROOT + "/data/sample.bmp", std::ios::binary);
        ifs.seekg(0, std::ios::end);
        long long int size = ifs.tellg();
        ifs.seekg(0);
        char *data = new char[size];
        ifs.read(data, size);
        std::string body;
        body.append(data, size);
        res.set_content(body, "image/bmp"); 
    });

    svr.Get("/sample.zip", [](const Request&, Response& res){
        const std::string PROJECT_ROOT(std::getenv("PROJECT_ROOT") ? std::getenv("PROJECT_ROOT") : ".");
        std::ifstream ifs(PROJECT_ROOT + "/data/sample.zip", std::ios::binary);
        ifs.seekg(0, std::ios::end);
        long long int size = ifs.tellg();
        ifs.seekg(0);
        char *data = new char[size];
        ifs.read(data, size);
        std::string body;
        body.append(data, size);
        res.set_content(body, "application/zip"); 
    });

    svr.listen("0.0.0.0", 80);
}