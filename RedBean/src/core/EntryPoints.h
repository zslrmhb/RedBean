#pragma once

extern RedBean::Application* RedBean::create_application();

int main(int argc, char** argv)
{
        RedBean::Log::init();
        RB_CORE_CRITICAL("Initialized Log!!!!!");
        RB_CRITICAL("Hello!");

        auto app = RedBean::create_application();
        app->run();
        delete app;
}