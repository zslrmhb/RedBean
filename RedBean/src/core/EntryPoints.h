#pragma once

extern RedBean::Application* RedBean::create_application();

int main(int argc, char** argv)
{
        RedBean::Log::init();
        RB_CORE_WARN("Initialized Log!");
        RB_INFO("Hello!");

        auto app = RedBean::create_application();
        app->run();
        delete app;
}