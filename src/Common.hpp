#ifndef COMMON_HPP
#define COMMON_HPP

static const double outOfScreenX = 1690;
static const double outOfScreenY = 1690;

#define DECLARE_RULE4(Class, action) \
  Class(const Class& other) = action; \
  Class(Class&& other) = action; \
  Class& operator=(const Class& other) = action; \
  Class& operator=(Class&& other) = action

#define DISABLE_COPY(Class) \
  DECLARE_RULE4(Class, delete)

void wait(int seconds);

/// Function adapted from Jeisson Hidalgo-Cespedes 2022
int random(int min, int max);

#endif  // COMMON_HPP
