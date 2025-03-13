#include "function/editor/ImGuiLayer.h"

namespace RedBean
{
ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {}

ImGuiLayer::~ImGuiLayer() {}

void ImGuiLayer::on_attach()
{
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO &io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiLayer::on_detach() {}

void ImGuiLayer::on_update()
{
    ImGuiIO &io = ImGui::GetIO();
    Application &app = Application::get();
    io.DisplaySize =
        ImVec2(app.get_window().get_width(), app.get_window().get_height());

    float time = static_cast<float>(glfwGetTime());
    io.DeltaTime = m_time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
    m_time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::on_event(Event &event)
{
    EventDispatcher dispatcher(event);
    dispatcher.dispatch<MouseButtonPressedEvent>(
        RB_BIND_EVENT_FN(ImGuiLayer::on_mouse_button_pressed_event));
}

bool ImGuiLayer::on_mouse_button_pressed_event(MouseButtonPressedEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
}

bool ImGuiLayer::on_mouse_button_released_event(MouseButtonReleasedEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
}

bool ImGuiLayer::on_mouse_moved_event(MouseMovedEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
}

bool ImGuiLayer::on_mouse_scrolled_event(MouseScrolledEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
}

bool ImGuiLayer::on_key_pressed_event(KeyPressedEvent &e)
{

    ImGuiIO &io = ImGui::GetIO();
}

bool ImGuiLayer::on_key_released_event(KeyReleasedEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
    io.KeysDown[e.get_keycode()] = false;
    return false;
}

bool ImGuiLayer::on_key_typed_event(KeyTypedEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
    unsigned int c = e.get_keycode();
    if (c > 0 && c < 0x10000)
    {
        io.AddInputCharacter(static_cast<unsigned short>(c));
    }
    return false;
}

bool ImGuiLayer::on_window_resized_event(WindowResizeEvent &e)
{
    ImGuiIO &io = ImGui::GetIO();
    io.DisplaySize = ImVec2(e.get_width(), e.get_height());
    io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
    glViewport(0, 0, e.get_width(), e.get_height());
}

} // namespace RedBean
