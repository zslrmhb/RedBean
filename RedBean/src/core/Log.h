#pragma once

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace RedBean
{
class Log
{
  public:
    static void init();

    static std::shared_ptr<spdlog::logger> &get_corelogger()
    {
        return s_corelogger;
    }
    static std::shared_ptr<spdlog::logger> &get_clientlogger()
    {
        return s_clientlogger;
    }

  private:
    static std::shared_ptr<spdlog::logger> s_corelogger;
    static std::shared_ptr<spdlog::logger> s_clientlogger;
};
} // namespace RedBean

// Core log macros
#define RB_CORE_TRACE(...) ::RedBean::Log::get_corelogger()->trace(__VA_ARGS__)
#define RB_CORE_INFO(...) ::RedBean::Log::get_corelogger()->info(__VA_ARGS__)
#define RB_CORE_WARN(...) ::RedBean::Log::get_corelogger()->warn(__VA_ARGS__)
#define RB_CORE_ERROR(...) ::RedBean::Log::get_corelogger()->error(__VA_ARGS__)
#define RB_CORE_CRITICAL(...)                                                 \
    ::RedBean::Log::get_corelogger()->critical(__VA_ARGS__)

// Client log macros
#define RB_TRACE(...) ::RedBean::Log::get_clientlogger()->trace(__VA_ARGS__)
#define RB_INFO(...) ::RedBean::Log::get_clientlogger()->info(__VA_ARGS__)
#define RB_WARN(...) ::RedBean::Log::get_clientlogger()->warn(__VA_ARGS__)
#define RB_ERROR(...) ::RedBean::Log::get_clientlogger()->error(__VA_ARGS__)
#define RB_CRITICAL(...)                                                      \
    ::RedBean::Log::get_clientlogger()->critical(__VA_ARGS__)