#include <iostream>

int main() {
  /*
  Программа хранит количество жильцов в нескольких зданиях.
  В каждом здании есть несколько этажей, а на каждом этаже -
  несколько комнат.

  int*** используется для динамического хранения данных:
  здание -> этаж -> комната -> количество жильцов.

  void* используется в массиве room_info для хранения указателей
  на данные разных типов: код здания типа char и количество
  жильцов в комнате типа int.
  */
  int building;
  int floor;
  int room;
  std::cin >> building >> floor >> room;
  char* building_code = new char[building];
  for (int i = 0; i < building; i++) {
    std::cin >> building_code[i];
  }
  int*** people = new int**[building];
  for (int i = 0; i < building; i++) {
    people[i] = new int*[floor];
    for (int j = 0; j < floor; j++) {
      people[i][j] = new int[room];
    }
  }
  for (int i = 0; i < building; i++) {
    for (int j = 0; j < floor; j++) {
      for (int k = 0; k < room; k++) {
        std::cin >> people[i][j][k];
      }
    }
  }
  int building_number;
  int floor_number;
  std::cin >> building_number >> floor_number;
  int total = 0;
  for (int i = 0; i < room; i++) {
    total += people[building_number][floor_number][i];
  }
  std::cout << total << '\n';
  int room_number;
  std::cin >> room_number;
  void* room_info[2];
  room_info[0] = &building_code[building_number];
  room_info[1] = &people[building_number][floor_number][room_number];
  int option;
  std::cin >> option;
  if (option == 1) {
    std::cout << *static_cast<char*>(room_info[0]) << '\n';
  } else if (option == 2) {
    std::cout << *static_cast<int*>(room_info[1]) << '\n';
  }
  for (int i = 0; i < building; i++) {
    for (int j = 0; j < floor; j++) {
      delete[] people[i][j];
    }
    delete[] people[i];
  }
  delete[] people;
  delete[] building_code;
}