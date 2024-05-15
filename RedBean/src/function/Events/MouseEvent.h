#pragma once

#include "core/MouseCodes.h"
#include "function/events/Event.h"

namespace RedBean
{
        class MouseMovedEvent : public Event
        {
        public:

        private:
                float m_mouse_x, m_mouse_y;
        };
}  // namespace RedBean