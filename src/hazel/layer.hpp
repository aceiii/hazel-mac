#pragma once

#include "hazel/core.hpp"
#include "hazel/events/event.hpp"

namespace hazel
{
class HZ_API Layer
{
public:
  Layer(const std::string& debug_name = "Layer");
  virtual ~Layer();

  virtual void on_attach() {}
  virtual void on_detach() {}
  virtual void on_update() {}
  virtual void on_event(Event& /*event */) {}

  const std::string& name() const { return debug_name_; }

protected:
  std::string debug_name_;
};
} // namespace hazel