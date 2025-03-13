#include "RedBean.h"

class ExampleLayer : public RedBean::Layer
{
  public:
    ExampleLayer() : Layer("Example") {}

    void on_update() override
    {
        RB_INFO("ExampleLayer::Update");
    }

    void on_event(RedBean::Event &event) override
    {
        RB_TRACE("{0}", event.to_string());
    }
};

class Sandbox : public RedBean::Application
{
  public:
    Sandbox()
    {
        push_layer(new ExampleLayer());
        push_overlay(new RedBean::ImGuiLayer());
    }
    ~Sandbox() {}
};

RedBean::Application *RedBean::create_application()
{
    return new Sandbox();
}
