//
// Created by YANHAI on 2019/9/10.
//

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

void init_logger(spdlog::level::level_enum log_level = spdlog::level::info,
                 const char *filename = nullptr);

int main()
{
//    init_logger();
//    init_logger(spdlog::level::trace);
    init_logger(spdlog::level::trace, "test3.log");

    int i = 20000;  // test3.1.log  test3.log

    while (--i > 0) {
        spdlog::info("Welcome to spdlog version {}.{}.{}  !", SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH);
        spdlog::warn("Easy padding in numbers like {:08d}", 12);
        spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", i);
        spdlog::info("Support for floats {:03.2f}", 1.23456);
        spdlog::info("Positional args are {1} {0}..", "too", "supported");
        spdlog::info("{:>8} aligned, {:<8} aligned", "right", "left");
    }

    spdlog::drop_all();
//    spdlog::info("{:>8} aligned, {:<8} aligned", "right", "left");
    return 0;
}

/**
 * init console
 * @param log_level
 */
std::shared_ptr<spdlog::sinks::sink> init_logger_console(spdlog::level::level_enum log_level)
{
    auto logger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    logger->set_level(log_level);
    return logger;
}

/**
 * init file
 * @param log_level
 * @param base_filename
 * @param max_size
 * @param max_files
 * @return
 */
std::shared_ptr<spdlog::sinks::sink> init_logger_file(spdlog::level::level_enum log_level,
                                                      const std::string &base_filename,
                                                      std::size_t max_size,
                                                      std::size_t max_files)
{
    auto logger = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(base_filename, max_size, max_files);
    logger->set_level(log_level);
    return logger;
}

/**
 * init logger
 * @param log_level
 * @param filename
 */
void init_logger(spdlog::level::level_enum log_level, const char *filename)
{
    std::vector<spdlog::sink_ptr> sinks;

    sinks.push_back(init_logger_console(log_level));
    if (filename) {
        sinks.push_back(init_logger_file(log_level, filename, 1048576 * 5, 3)); // 5MB
    }

    auto logger = std::make_shared<spdlog::logger>("main", sinks.begin(), sinks.end());
    logger->set_level(log_level);
    logger->flush_on(log_level);
    spdlog::set_default_logger(logger);
}
