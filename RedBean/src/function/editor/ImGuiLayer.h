#pragma once

#include "imgui.h"

#include "core/Layer.h"
#include "core/Application.h"

#include "platform/opengl/ImGuiOpenGLRenderer.h"

namespace RedBean
{
        class ImGuiLayer : public Layer
        {
        public:
                ImGuiLayer();
                ~ImGuiLayer();

                void on_attach();
                void on_detach();
                void on_update();
                void on_event(Event& event);
        private:
                float m_time = 0.0f;
        };
}