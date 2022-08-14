#include <mutex>

// using in static space
class hierarchical_mutex {
  std::mutex m;
  int prev_hierarchy_value;
  const int pres_hierarchy_value;
  static thread_local int this_thread_hierarchy_value;

  bool has_violation() {
    if (this_thread_hierarchy_value > pres_hierarchy_value) {
      return false;
    }
    return true;
  }

  void update_value() {
    prev_hierarchy_value = this_thread_hierarchy_value;
    this_thread_hierarchy_value = pres_hierarchy_value;
  }

 public:
  explicit hierarchical_mutex(const int value) : pres_hierarchy_value(value) {
    prev_hierarchy_value = 0;
  }
  void lock() {
    if (has_violation()) throw std::runtime_error("has violation");
    m.lock();
    update_value();
  }
  void unlock() {
    if (this_thread_hierarchy_value != pres_hierarchy_value)
      throw std::runtime_error("has violation");
    this_thread_hierarchy_value = prev_hierarchy_value;
    m.unlock();
  }
  bool try_lock() {
    if (has_violation()) throw std::runtime_error("has violation");
    if (!m.try_lock()) return false;
    update_value();
    return true;
  }
};

thread_local int hierarchical_mutex::this_thread_hierarchy_value =
    std::numeric_limits<int>::max();
