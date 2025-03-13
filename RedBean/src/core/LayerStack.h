#pragma once

#include <vector>

#include "core/Core.h"
#include "core/Layer.h"

namespace RedBean
{
class LayerStack
{
  public:
    LayerStack();
    ~LayerStack();

    void push_layer(Layer *layer);
    void push_overlay(Layer *overlay);
    void pop_layer(Layer *layer);
    void pop_overlay(Layer *overlay);

    std::vector<Layer *>::iterator begin()
    {
        return m_layers.begin();
    }
    std::vector<Layer *>::iterator end()
    {
        return m_layers.end();
    }

  private:
    std::vector<Layer *> m_layers;
    std::vector<Layer *>::iterator m_layer_insert;
};
} // namespace RedBean