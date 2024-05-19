#pragma once

#include <iostream>

#include "core/Core.h"
#include "core/Log.h"
#include "core/Window.h"

#include "platform/macos/MacWindow.h"

#include "function/events/ApplicationEvent.h"

namespace RedBean
{
        class Application
        {
        public:
                Application();
                virtual ~Application();

                void run();

                void on_event(Event& e);
        private:
                bool on_window_close(WindowCloseEvent& e);
                
                std::unique_ptr<Window> m_window;
                bool m_running = true;
        };

        Application* create_application();
}