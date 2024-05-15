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

RedBean::Application* RedBean::create_application()
{
    return new Sandbox();
}
