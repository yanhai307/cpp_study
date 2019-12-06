//
// Created by YANHAI on 2019/12/2.
//

#include <iostream>
#include <json/json.h>

using namespace std;

static void write1()
{
    Json::Value root;
    Json::StreamWriterBuilder builder;
    builder["indentation"] = Json::nullValue;    // default a tab

    root["name"] = "ming";
    root["age"] = 19;
    root["score"] = 90.5;
    root["pass"] = true;

    auto dumps = Json::writeString(builder, root);
    cout << dumps << endl;
}

static void write2()
{
    Json::Value root;
    Json::Value students;
    Json::StreamWriterBuilder builder;

    root["school"] = "school1";
    for (int i = 0; i < 2; ++i) {
        Json::Value student;
        student["name"] = "ming";
        student["id"] = i;
        student["age"] = 19;
        student["score"] = 90.5;
        students.append(student);
    }
    root["student"] = students;

    auto dumps = Json::writeString(builder, root);
    cout << dumps << endl;
}

int main()
{
    write1();
    write2();
    return 0;
}
