#pragma once

#include "core/KeyCodes.h"
#include "function/events/Event.h"

namespace RedBean
{
class KeyEvent : public Event
{
  public:
    KeyCode get_keycode() const
    {
        return m_keycode;
    }

    EVENT_CLASS_CATEGORY(EVENT_CATEGORY_KEYBOARD | EVENT_CATEGORY_INPUT)
  protected:
    KeyEvent(const KeyCode keycode) : m_keycode(keycode) {}

    KeyCode m_keycode;
};

class KeyPressedEvent : public KeyEvent
{
  public:
    KeyPressedEvent(const KeyCode keycode, bool is_repeat = false)
        : KeyEvent(keycode), m_is_repeat(is_repeat)
    {
    }

    bool is_repeat() const
    {
        return m_is_repeat;
    }

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "KeyPressedEvent: " << m_keycode << " (repeat = " << m_is_repeat
           << ")";
        return ss.str();
    }

    EVENT_CLASS_TYPE(KEY_PRESSED)
  private:
    bool m_is_repeat;
};

class KeyReleasedEvent : public KeyEvent
{
  public:
    KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "KeyReleasedEvent: " << m_keycode;
        return ss.str();
    }

    EVENT_CLASS_TYPE(KEY_RELEASED)
  private:
};

class KeyTypedEvent : public KeyEvent
{
  public:
    KeyTypedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

    std::string to_string() const override
    {
        std::stringstream ss;
        ss << "KeyTypedEvent: " << m_keycode;
        return ss.str();
    }

    EVENT_CLASS_TYPE(KEY_TYPED)
};
} // namespace RedBean