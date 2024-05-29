#include "core/Application.h"

namespace RedBean
{
        Application* Application::s_instance = nullptr;
        Application::Application()
        {
                s_instance = this;
                m_window = std::unique_ptr<Window>(Window::create());
                m_window->set_event_callback(std::bind(&Application::on_event,
                                                       this,
                                                       std::placeholders::_1));
        }
        
        Application::~Application()
        {
                RB_CORE_WARN("EXIT ENGINE");
        }

        void Application::on_event(Event& e)
        {
                EventDispatcher dispatcher(e);
                dispatcher.dispatch<WindowCloseEvent>(std::bind(
                                             &Application::on_window_close,
                                             this,
                                             std::placeholders::_1));
                RB_CORE_INFO(e.to_string());

                for (auto it = m_layerstack.end(); it != m_layerstack.begin();)
                {
                        (*--it)->on_event(e);
                        if (e.m_handled)
                        {
                                break;
                        }
                }
        }

        void Application::push_layer(Layer* layer)
        {
                m_layerstack.push_layer(layer);
                layer->on_attach();
        }

        void Application::push_overlay(Layer* layer)
        {
                m_layerstack.push_overlay(layer);
                layer->on_attach();
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

                        for (Layer* layer : m_layerstack)
                        {
                                layer->on_update();
                        }

                        m_window->on_update();
                }
        }
}
