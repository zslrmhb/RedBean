#pragma once

#include "core/MouseCodes.h"
#include "function/events/Event.h"

namespace RedBean
{
class MouseMovedEvent : public Event
{
  public:
    MouseMovedEvent(const float x, const float y) : m_mouse_x(x), m_mouse_y(y)
    {
    }

    float get_x() const
    {
        return m_mouse_x;
    }
    float get_y() const
    {
        return m_mouse_y;
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << m_mouse_x << ", " << m_mouse_y;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MOUSE_MOVED)
    EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)

  private:
    float m_mouse_x, m_mouse_y;
};

class MouseScrolledEvent : public Event
{
  public:
    MouseScrolledEvent(const float x_offset, const float y_offset)
        : m_x_offset(x_offset), m_y_offset(y_offset)
    {
    }

    float get_x_offset() const
    {
        return m_x_offset;
    }
    float get_y_offset() const
    {
        return m_y_offset;
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << get_x_offset() << ", "
           << get_y_offset();
        return ss.str();
    }

    EVENT_CLASS_TYPE(MOUSE_SCROLLED)
    EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT)
  private:
    float m_x_offset, m_y_offset;
};

class MouseButtonEvent : public Event
{
  public:
    MouseCode get_mouse_button() const
    {
        return m_button;
    }
    EVENT_CLASS_CATEGORY(EVENT_CATEGORY_MOUSE | EVENT_CATEGORY_INPUT |
                         EVENT_CATEGORY_MOUSE_BUTTON)
  protected:
    MouseButtonEvent(const MouseCode button) : m_button(button) {}
    MouseCode m_button;
};

class MouseButtonPressedEvent : public MouseButtonEvent
{
  public:
    MouseButtonPressedEvent(const MouseCode button) : MouseButtonEvent(button)
    {
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MOUSE_BUTTON_PRESSED)
};
class MouseButtonReleasedEvent : public MouseButtonEvent
{
  public:
    MouseButtonReleasedEvent(const MouseCode button) : MouseButtonEvent(button)
    {
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << m_button;
        return ss.str();
    }

    EVENT_CLASS_TYPE(MOUSE_BUTTON_RELEASED)
};

} // namespace RedBean