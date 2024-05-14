#pragma once

#include "spdlog/spdlog.h"

namespace RedBean
{
    class Log
    {
    public:
        // Log();
        // ~Log();

        static void init();

        inline static std::shared_ptr<spdlog::logger> &getCoreLogger()
        {
            return s_CoreLogger;
        }
        inline static std::shared_ptr<spdlog::logger> &getClientLogger()
        {
            return s_ClientLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}
