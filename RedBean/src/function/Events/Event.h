#pragma once

#include <functional>
#include <sstream>
#include <string>

namespace RedBean
{
enum class EventType
{
    NONE = 0,
    WINDOW_CLOSE,
    WINDOW_RESIZE,
    WINDOW_FOCUS,
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
    EVENT_CATEGORY_APPLICATION = 1 << 0,
    EVENT_CATEGORY_INPUT = 1 << 1,
    EVENT_CATEGORY_KEYBOARD = 1 << 2,
    EVENT_CATEGORY_MOUSE = 1 << 3,
    EVENT_CATEGORY_MOUSE_BUTTON = 1 << 4,
};

#define EVENT_CLASS_TYPE(type)                                                \
    static EventType get_static_type()                                        \
    {                                                                         \
        return EventType::type;                                               \
    }                                                                         \
    virtual EventType get_event_type() const override                         \
    {                                                                         \
        return get_static_type();                                             \
    }                                                                         \
    virtual const char *get_name() const override                             \
    {                                                                         \
        return #type;                                                         \
    }

#define EVENT_CLASS_CATEGORY(category)                                        \
    virtual int get_category_flags() const override                           \
    {                                                                         \
        return category;                                                      \
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
    EventDispatcher(Event &event) : m_event(event) {}

    template <typename T, typename F> bool dispatch(const F &func)
    {
        if (m_event.get_event_type() == T::get_static_type())
        {
            m_event.m_handled |= func(static_cast<T &>(m_event));
            return true;
        }
        return false;
    }

  private:
    Event &m_event;
};

inline std::ostream &operator<<(std::ostream &os, const Event &e)
{
    return os << e.to_string();
}
} // namespace RedBean