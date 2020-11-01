cmake_minimum_required(VERSION 3.16)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2 main.cpp src/Prepod.cpp header/Prepod.h src/Person.cpp header/Person.h src/Man.cpp header/Man.h header/Departament.h src/Learner.cpp header/Learner.h src/Teacher.cpp header/Teacher.h src/Student.cpp header/Student.h)