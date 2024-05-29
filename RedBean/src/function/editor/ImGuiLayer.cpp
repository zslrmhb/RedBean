#include "function/editor/ImGuiLayer.h"

namespace RedBean
{
        ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
        {

        }

        ImGuiLayer::~ImGuiLayer()
        {      
        }

        void ImGuiLayer::on_attach()
        {
                ImGui::CreateContext();
                ImGui::StyleColorsDark();

                ImGuiIO& io = ImGui::GetIO();
                io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
                io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

                ImGui_ImplOpenGL3_Init("#version 410");



        }

        void ImGuiLayer::on_detach()
        {
                
        }

        void ImGuiLayer::on_update()
        {
                ImGuiIO& io = ImGui::GetIO();
                Application& app = Application::get();
                io.DisplaySize = ImVec2(app.get_window().get_width(),
                                        app.get_window().get_height());

                

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

        void ImGuiLayer::on_event(Event& event)
        {
                
        }
}