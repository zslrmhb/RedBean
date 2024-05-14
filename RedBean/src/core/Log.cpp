#include "Log.h"

namespace RedBean
{
    // Log::Log()
    // {
    // }

    // Log::~Log()
    // {
    // }

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::init()
    {
    }

}