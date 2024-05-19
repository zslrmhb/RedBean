#pragma once

#include "function/events/Event.h"

namespace RedBean
{
        struct WindowProps
        {
                std::string title;
                uint32_t width;
                uint32_t height;

                WindowProps(const std::string& title = "RedBean Engine",
                                      uint32_t width = 400,
                                     uint32_t height = 400) :
                        title(title), width(width), height(height)
                {
                }
        };

        // Window Interface     
        class Window
        {
        public:
                using event_callback_fn = std::function<void(Event&)>;

                virtual ~Window() = default;

                virtual void on_update() = 0;

                virtual uint32_t get_width() const = 0;
                virtual uint32_t get_height() const = 0;

                virtual void set_event_callback
                (const event_callback_fn& callback) = 0;
                virtual void set_v_sync(bool enabled) = 0;
                virtual bool is_v_sync() const = 0;

                // virtual void* get_native_window() const = 0;
                static Window* create(const WindowProps& props = WindowProps());

        };
}