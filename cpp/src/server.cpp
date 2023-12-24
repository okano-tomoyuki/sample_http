#include "httplib.h"
#include <string>
#include <fstream>
#include <iostream>

int main(void)
{
    using httplib::Server;
    using httplib::Request;
    using httplib::Response;

    Server svr;

    svr.Get("/image", [](const Request& req, Response& res){
        std::cout << req.path;
        std::ifstream ifs("original.bmp", std::ios::binary);

        ifs.seekg(0, std::ios::end);
        long long int size = ifs.tellg();
        ifs.seekg(0);
        char *data = new char[size];
        ifs.read(data, size);

        std::string body;
        body.append(data, size);
    
        res.set_content(body, "image/bmp"); 
        
    });

    svr.Get("/download", [](const Request& req, Response& res){ 

        req.path.c_str();
        std::ifstream ifs("original.zip", std::ios::binary);

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