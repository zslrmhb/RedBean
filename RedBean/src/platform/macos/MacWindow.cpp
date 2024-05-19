#include "platform/macos/MacWindow.h"

namespace RedBean
{
        static bool s_GLFW_initialized = false;

        Window* Window::create(const WindowProps& props)
        {
                return new MacWindow(props);
        }

        MacWindow::MacWindow(const WindowProps& props)
        {
                init(props);
        }

        MacWindow::~MacWindow()
        {
                shutdown();
        }

        void MacWindow::init(const WindowProps& props)
        {
                m_data.title = props.title;
                m_data.width = props.width;
                m_data.height = props.height;

                if (~s_GLFW_initialized)
                {
                        int success = glfwInit();
                        s_GLFW_initialized = true;
                        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
                        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
                        glfwWindowHint(GLFW_OPENGL_PROFILE,
                                       GLFW_OPENGL_CORE_PROFILE);
                        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
                }

                m_window = glfwCreateWindow(static_cast<int>(props.width),
                        static_cast<int>(props.height),
                        m_data.title.c_str(),
                        nullptr,
                        nullptr);
                glfwMakeContextCurrent(m_window);
                glfwSetWindowUserPointer(m_window, &m_data);
                set_v_sync(true);
        }

        void MacWindow::shutdown()
        {
                glfwDestroyWindow(m_window);
        }

        void MacWindow::on_update()
        {
                glfwPollEvents();
                glfwSwapBuffers(m_window);
        }

        void MacWindow::set_v_sync(bool enabled)
        {
                if (enabled)
                {
                        glfwSwapInterval(1);
                }
                else
                {
                        glfwSwapInterval(0);
                }
                m_data.v_sync = enabled;

        }

        bool MacWindow::is_v_sync() const
        {
                return m_data.v_sync;
        }
}