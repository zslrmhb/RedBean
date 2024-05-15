#pragma once

#include <string>
#include <functional>

namespace RedBean
{
    enum class EventType
    {
        NONE = 0,
        WINDOW_CLOSE,
        WINDOW_RESIZE,
        WNDOW_FOCUS,
        WINDOW_LOST_FOCUS,
        WINDOW_MOVED,
        APP_TICK,
        APP_UPDATE,
        APP_RENDER,
        KEY_PRESSED,
        KEY_RELEASED,
        KEY_TYPED,
        MOUSE_BUTTON_PRESSED,
        MOUSE_BUTTON_RELEASED,
        MOUSE_MOVED,
        MOUSE_SCROLLED
    };

    enum EventCategory
    {
        NONE = 0,
        EVENT_CATEGORY_APPLICATION = 1 << 0;
        EVENT_CATEGORY_INPUT = 1 << 1;
        EVENT_CATEGORY_KEYBOARD = 1 << 2;
        EVENT_CATEGORY_MOUSE = 1 << 3;
        EVENT_CATEGORY_MOUSE_BUTTON = 1 << 4;
    }

    class Event
    {

    public:
        virtual ~Event() = default;

        virtual EventType get_event_type() const = 0;
        virtual const char *get_name() const = 0;
        virtual int get_category_flags() const = 0;
        virtual std::string to_string() const
        {
            return get_name();
        }

        bool is_in_category(EventCategory category)
        {
            return get_category_flags() & category;
        }

        bool m_handled = false;

    private:
    };

    class EventDispatcher
    {
    public:
    private:
    };
}