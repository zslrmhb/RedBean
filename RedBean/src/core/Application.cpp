#include "Application.h"

namespace RedBean
{
        Application::Application()
        {
        }

        Application::~Application()
        {
        }

        void Application::run()
        {
                std::cout << "Welcome to RedBean Engine!\n";
                WindowResizeEvent e(1280, 720);
        }
}
