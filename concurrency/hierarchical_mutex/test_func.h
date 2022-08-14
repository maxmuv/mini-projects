#include <mutex>
#include <vector>
#include "hierarchical_mutex.h"

hierarchical_mutex hm(100);
hierarchical_mutex lm(50);
hierarchical_mutex cm(10);

int high_level_count = 0;
int low_level_count = 0;

void low_level() {
  std::lock_guard<hierarchical_mutex> low_lg(lm);
  ++low_level_count;
}

void high_level() {
  std::lock_guard<hierarchical_mutex> high_lg(hm);
  ++high_level_count;
  low_level();
}

void check() {
  std::lock_guard<hierarchical_mutex> cg(cm);
  low_level();
}
