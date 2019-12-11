find_package(libmongocxx 3.4.0)
if (libmongocxx_FOUND)
    message(STATUS "Found libmongocxx version ${LIBMONGOCXX_PACKAGE_VERSION}")
    include_directories(${LIBMONGOCXX_INCLUDE_DIRS})

    set(MONGOCXX_EXAMPLES
            dm01_helloworld.cpp
            dm02_connect.cpp
            dm03_create.cpp
            dm04_query.cpp
            dm05_update.cpp
            dm06_remove.cpp
            dm07_inserted_id.cpp
            dm08_query_projection.cpp
            dm09_view_or_value_variant.cpp
            dm10_exception.cpp
            dm11_document_validation.cpp
            dm12_get_values_from_documents.cpp
            dm13_tailable_cursor.cpp
            dm14_bulk_write.cpp
            dm15_gridfs.cpp
            dm16_index.cpp
            dm17_aggregate.cpp
            dm18_client_session.cpp
            dm20_change_streams.cpp
            dm21_instance_management.cpp
            dm22_usage_overview.cpp
            dm23_documentation_examples.cpp
            dm24_runcommand_examples.cpp
            dm25_index_examples.cpp
            dm26_aggregation_examples.cpp
            )

    foreach (EXAMPLE_SRC ${MONGOCXX_EXAMPLES})
        get_filename_component(EXAMPLE_TARGET ${EXAMPLE_SRC} NAME_WE)
        set(EXAMPLE_TARGET "10_mongodb_${EXAMPLE_TARGET}")
        add_executable(${EXAMPLE_TARGET} ${EXAMPLE_SRC})
        target_link_libraries(${EXAMPLE_TARGET} ${LIBMONGOCXX_LIBRARIES})
    endforeach (EXAMPLE_SRC)

    add_executable(10_mongodb_dm19_pool dm19_pool.cpp)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
    target_link_libraries(10_mongodb_dm19_pool ${LIBMONGOCXX_LIBRARIES} Threads::Threads)
endif()
