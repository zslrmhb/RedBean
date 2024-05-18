#pragma once

#include <iostream>

#include "core/Core.h"
#include "core/Log.h"

#include "function/events/ApplicationEvent.h"

namespace RedBean
{
        class Application
        {
        public:
                Application();
                virtual ~Application();

                void run();
        };

        Application* create_application();
}