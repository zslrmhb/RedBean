#pragma once

#include <iostream>

#include "Core.h"

namespace RedBean
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void run();
    };

    Application *CreateApplication();
}