#include "RedBean.h"

class Sandbox : public RedBean::Application
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};

RedBean::Application* RedBean::CreateApplication()
{
    return new Sandbox();
}
