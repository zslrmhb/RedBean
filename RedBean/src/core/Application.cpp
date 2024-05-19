#include "core/Application.h"

#include <GLFW/glfw3.h>

namespace RedBean
{
        Application::Application()
        {
                m_window = std::unique_ptr<Window>(Window::create());
                m_window->set_event_callback(std::bind(&Application::on_event,
                                                       this,
                                                       std::placeholders::_1));
        }

        Application::~Application()
        {
        }

        void Application::on_event(Event& e)
        {
                EventDispatcher dispatcher(e);
                dispatcher.dispatch<WindowCloseEvent>(std::bind(
                                             &Application::on_window_close,
                                             this,
                                             std::placeholders::_1));
                RB_CORE_INFO(e.to_string());
        }

        bool Application::on_window_close(WindowCloseEvent& e)
        {
                m_running = false;
                return true;
        }

        void Application::run()
        {
                while (m_running)
                {
                        glClearColor(1, 0, 1, 1);
                        glClear(GL_COLOR_BUFFER_BIT);
                        m_window->on_update();
                }
        }
}
