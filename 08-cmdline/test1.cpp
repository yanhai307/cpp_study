//
// Created by YANHAI on 2019/9/9.
//

#include <iostream>
#include "cmdline.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    cmdline::parser args;
    args.add<string>("host", 'H', "host name", true, "");
    args.add<int>("port", 'p', "port number", false, 80, cmdline::range(1, 65535));
    args.add<string>("type", 't', "protocol type", false, "http", cmdline::oneof<string>("http", "https", "ssh", "ftp"));
    args.add("gzip", 0, "gzip when transfer");

    args.parse_check(argc, argv);

    cout << args.get<string>("type") << "://"
         << args.get<string>("host") << ":"
         << args.get<int>("port") << endl;

    if (args.exist("gzip")) cout << "gzip" << endl;

    return 0;
}
