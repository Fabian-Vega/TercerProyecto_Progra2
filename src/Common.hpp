// Copyright 2022 Jeisson Hidalgo ECCI-UCR

#ifndef COMMON_HPP
#define COMMON_HPP

#define DECLARE_RULE4(Class, action) \
  Class(const Class& other) = action; \
  Class(Class&& other) = action; \
  Class& operator=(const Class& other) = action; \
  Class& operator=(Class&& other) = action

#define DISABLE_COPY(Class) \
  DECLARE_RULE4(Class, delete)

#endif  // COMMON_HPP
