#pragma once

#include <iostream>

#include "core/Core.h"
#include "core/Log.h"
#include "core/Window.h"
#include "core/LayerStack.h"

#include "function/events/Event.h"
#include "function/events/ApplicationEvent.h"

#include "platform/macos/MacWindow.h"

namespace RedBean
{
        class Application
        {
        public:
                Application();
                virtual ~Application();

                void run();

                void on_event(Event& e);

                void push_layer(Layer* layer);
                void push_overlay(Layer* layer);

                inline static Application& get()
                {
                        return *s_instance;
                }
                inline Window& get_window()
                {
                        return *m_window;
                }
        private:
                bool on_window_close(WindowCloseEvent& e);
                
                std::unique_ptr<Window> m_window;
                bool m_running = true;
                LayerStack m_layerstack;

                static Application* s_instance;
        };

        Application* create_application();
}