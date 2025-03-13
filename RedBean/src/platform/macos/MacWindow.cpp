#include "platform/macos/MacWindow.h"

namespace RedBean
{
static bool s_GLFW_initialized = false;

Window *Window::create(const WindowProps &props)
{
    return new MacWindow(props);
}

MacWindow::MacWindow(const WindowProps &props)
{
    init(props);
}

MacWindow::~MacWindow()
{
    shutdown();
}

void MacWindow::init(const WindowProps &props)
{
    m_data.title = props.title;
    m_data.width = props.width;
    m_data.height = props.height;

    if (!s_GLFW_initialized)
    {
        int success = glfwInit();
        s_GLFW_initialized = true;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }

    m_window = glfwCreateWindow(static_cast<int>(props.width),
                                static_cast<int>(props.height),
                                m_data.title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetWindowUserPointer(m_window, &m_data);
    set_v_sync(true);

    // Set GLFW callbacks
    glfwSetWindowSizeCallback(
        m_window,
        [](GLFWwindow *window, int width, int height)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            data.width = width;
            data.height = height;
            WindowResizeEvent event(width, height);
            data.event_callback(event);
        });

    glfwSetWindowCloseCallback(
        m_window,
        [](GLFWwindow *window)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.event_callback(event);
        });

    glfwSetKeyCallback(
        m_window,
        [](GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.event_callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.event_callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data.event_callback(event);
                    break;
                }
            }
        });

    glfwSetMouseButtonCallback(
        m_window,
        [](GLFWwindow *window, int button, int action, int mods)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data.event_callback(event);
                    break;
                }

                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data.event_callback(event);
                    break;
                }
            }
        });

    glfwSetScrollCallback(
        m_window,
        [](GLFWwindow *window, double x_offset, double y_offset)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event(static_cast<float>(x_offset),
                                     static_cast<float>(y_offset));
            data.event_callback(event);
        });

    glfwSetCursorPosCallback(
        m_window,
        [](GLFWwindow *window, double x_pos, double y_pos)
        {
            WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

            MouseMovedEvent event(static_cast<float>(x_pos),
                                  static_cast<float>(y_pos));
            data.event_callback(event);
        });
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
} // namespace RedBean