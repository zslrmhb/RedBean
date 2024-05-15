#pragma once

#include "function/events/Event.h"

namespace RedBean
{
        class WindowResizeEvent : public Event
        {
        };

        class WindowCloseEvent : public Event
        {
        };

        class AppTickEvent : public Event
        {
        };

        class AppUpdateEvent : public Event
        {
        };

        class AppRenderEvent : public Event
        {
        };
}