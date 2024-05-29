#pragma once 

// glad header MUST come first!
#include <glad/glad.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#endif

#include "core/Window.h"
#include "function/events/ApplicationEvent.h"
#include "function/events/MouseEvent.h"
#include "function/events/KeyEvent.h"

namespace RedBean
{
        class MacWindow : public Window
        {
        public:
                MacWindow(const WindowProps& props);
                virtual ~MacWindow();

                void on_update() override;

                inline unsigned int get_width() const override
                {
                        return m_data.width;
                };
                inline unsigned int get_height() const override
                {
                        return m_data.height;
                }

                // Window Attributes
                inline void set_event_callback\
                        (const event_callback_fn& callback) override
                {
                        m_data.event_callback = callback;
                }
                void set_v_sync(bool enabled) override;
                bool is_v_sync() const override;


        private:
                virtual void init(const WindowProps& props);
                virtual void shutdown();


                struct WindowData
                {
                        std::string title;
                        unsigned int width, height;
                        bool v_sync;

                        event_callback_fn event_callback;
                };
                GLFWwindow* m_window;
                WindowData m_data;

        };
}