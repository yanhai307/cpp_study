// Copyright 2015 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <cstdlib>
#include <iostream>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/bulk_write_exception.hpp>
#include <mongocxx/exception/error_code.hpp>
#include <mongocxx/exception/logic_error.hpp>
#include <mongocxx/exception/operation_exception.hpp>
#include <mongocxx/exception/server_error_code.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::basic::make_document;
using bsoncxx::builder::basic::kvp;

int main(int, char **)
{
    // The mongocxx::instance constructor and destructor initialize and shut down the driver,
    // respectively. Therefore, a mongocxx::instance must be created before using the driver and
    // must remain alive for as long as the driver is in use.
    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    // @begin: cpp-logic-error
    // Using an uninitialized collection throws a mongocxx::logic_error.
    // A mongocxx::logic_error is-a mongocxx::exception is-a std::system_error.
    mongocxx::collection coll;
    try {
        coll.name();
    } catch (const mongocxx::logic_error &e) {
        std::cout << "Using an uninitialized collection throws:" << std::endl;

        // Local errors, like those generated by mis-use of the
        // library itself, exist in the mongocxx 'error_category'
        // object. This is to be distinguished from the mongocxx
        // 'server_error_category' object, which tracks errors
        // returned by the server.
        //
        // NOTE: At this time, the server_error_category has no
        // associated symbolic errors. You must use numeric codes to
        // understand the errors returned in this category. See below
        // for more discussion.
        if (e.code().category() != mongocxx::error_category()) {
            return EXIT_FAILURE;
        }

        // We can compare the error_code to a known mongocxx::error_code.
        if (e.code() != mongocxx::error_code::k_invalid_collection_object) {
            return EXIT_FAILURE;
        }

        std::cout << e.what() << std::endl << std::endl;
    }
    // @end: cpp-logic-error

    // @begin: cpp-operation-exception
    // Renaming a collection that does not exist throws a mongocxx::operation_exception.
    // A mongocxx::operation_exception is-a mongocxx::exception is-a std::system_error.
    coll = conn["test"]["coll"];
    coll.drop();
    try {
        coll.rename("coll2");
    } catch (const mongocxx::operation_exception &e) {
        std::cout << "Renaming a collection that does not exist throws:" << std::endl;

        // We expect this error to arise from the server
        if (e.code().category() != mongocxx::server_error_category()) {
            return EXIT_FAILURE;
        }

        // We can compare the error_code to a known server side error
        // code number. Please see
        // https://github.com/mongodb/mongo/blob/master/src/mongo/base/error_codes.err
        // for details on the sort of error codes the server might
        // return. In this case, 26 means 'NamespaceNotFound'.
        //
        // NOTE: Due to a design flaw in the C driver which currently
        // is the underlying implementation of the C++11 driver, it is
        // not possible to reliably distinguish between error codes
        // generated locally by libmongoc, or error codes generated
        // remotely by the server. Clients of libmongocxx are
        // therefore required to interpret the code numerically and
        // contextually.  When the C driver fixes its error handling
        // strategy, we will add symbolic codes for server errors, and
        // report local library errors from libmongoc in the
        // mongocxx::error_code enumeration.
        if (e.code().value() != 26) {
            return EXIT_FAILURE;
        }

        std::cout << e.what() << std::endl;
        if (e.raw_server_error()) {
            std::cout << bsoncxx::to_json(*(e.raw_server_error())) << std::endl;
        }
        std::cout << std::endl;
    }
    // @end: cpp-operation-exception

    // @begin: cpp-bulk-write-exception
    // Adding a document whose "_id" is already present throws a mongocxx::bulk_write_exception.
    // A mongocxx::bulk_write_exception is-a mongocxx::operation_exception is-a mongocxx::exception
    // is-a std::system_error.
    auto doc = make_document(kvp("_id", 1));
    coll.insert_one(doc.view());
    try {
        coll.insert_one(doc.view());
    } catch (const mongocxx::bulk_write_exception &e) {
        std::cout << "Adding a document whose _id is already present throws:" << std::endl;

        // We expect this error to arise from the server
        if (e.code().category() != mongocxx::server_error_category()) {
            return EXIT_FAILURE;
        }

        // We can compare the error_code to a known server side error code number
        if (e.code().value() != 11000) {
            return EXIT_FAILURE;
        }

        std::cout << e.what() << std::endl;
        if (e.raw_server_error()) {
            std::cout << "Raw server error:" << std::endl;
            std::cout << bsoncxx::to_json(*(e.raw_server_error())) << std::endl;
        }
        std::cout << std::endl;
    }
    // @end: cpp-bulk-write-exception

    return EXIT_SUCCESS;
}