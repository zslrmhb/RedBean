#pragma once

extern RedBean::Application *RedBean::CreateApplication();

int main(int argc, char **argv)
{
    auto app = RedBean::CreateApplication();
    app->run();
    delete app;
}