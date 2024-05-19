#pragma once

#include "function/events/Event.h"

namespace RedBean
{
        class WindowResizeEvent : public Event
        {
        public:
                WindowResizeEvent(unsigned int width, unsigned int height)
                        : m_width(width), m_height(height)
                {
                }

                unsigned int get_width() const
                {
                        return m_width;
                }
                unsigned int get_height() const
                {
                        return m_height;
                }

                EVENT_CLASS_TYPE(WINDOW_RESIZE)
                        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
        private:
                unsigned int m_width, m_height;
        };

        class WindowCloseEvent : public Event
        {
        public:
                WindowCloseEvent() = default;

                EVENT_CLASS_TYPE(WINDOW_CLOSE)
                        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
        };

        class AppTickEvent : public Event
        {
        public:
                AppTickEvent() = default;

                EVENT_CLASS_TYPE(APP_TICK)
                        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
        };

        class AppUpdateEvent : public Event
        {
        public:
                AppUpdateEvent() = default;

                EVENT_CLASS_TYPE(APP_UPDATE)
                        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)

        };

        class AppRenderEvent : public Event
        {
        public:
                AppRenderEvent() = default;

                EVENT_CLASS_TYPE(APP_RENDER)
                        EVENT_CLASS_CATEGORY(EVENT_CATEGORY_APPLICATION)
        };
}