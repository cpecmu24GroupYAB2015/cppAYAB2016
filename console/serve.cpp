#include "serve.h"

#include <string>
using namespace std;

sf::Http Serv::connect(string header) {
    int i = 1;

    while(1) {


        sf::Http::Request request("/getpos.php", sf::Http::Request::Post);
        ostringstream stream;
        stream << "rn=99&s=j&id=1&t=set&pos=x&x="<< i <<"&y=66";
        request.setBody(stream.str());
        i++;


        sf::Http http(header);
        sf::Http::Response response = http.sendRequest(request);



        // check the status
        if (response.getStatus() == sf::Http::Response::Ok) {
            // check the contents of the response
            std::cout << response.getBody().c_str() << std::endl;
        } else {
            std::cout << "request failed" << std::endl;
        }
        sf::Time t = sf::seconds(0.1f);
        sf::sleep(t);
    }
}



