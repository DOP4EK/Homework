
#include <iostream>

bool IsEqual(const char* first, const char* second) {
  int i = 0;
  while (first[i] != '\0' && second[i] != '\0') {
    if (first[i] != second[i]) {
      return false;
    }
    i++;
  }
  return first[i] == second[i];
}

void Clear(char table[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      table[i][j] = ' ';
    }
  }
}

bool Put(char table[5][10]) {
  int x;
  int y;
  char c;
  std::cin >> x >> y >> c;
  if (x > 9 || y > 4 || x < 0 || y < 0) {
    return false;
  }
  table[y][x] = c;
  return true;
}

bool Text(char table[5][10]) {
  int x;
  int y;
  char word[11];
  std::cin >> x >> y;
  std::cin.width(sizeof(word));
  std::cin >> word;
  int length = 0;
  while (word[length] != '\0') {
    length++;
  }
  if (x < 0 || y < 0 || y > 4 || x + length - 1 >= 10) {
    return false;
  }
  for (int i = 0; i < length; i++) {
    table[y][x + i] = word[i];
  }
  return true;
}

void Print(const char table[5][10]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      std::cout << table[i][j];
    }
    std::cout << "\n";
  }
}

int main() {
  char table[5][10];
  Clear(table);
  while (true) {
    char command[16];
    std::cin.width(sizeof(command));
    std::cin >> command;
    if (IsEqual(command, "quit")) {
      break;
    } else if (IsEqual(command, "clear")) {
      Clear(table);
    } else if (IsEqual(command, "put")) {
      if (!Put(table)) {
        std::cout << "error\n";
      }
    } else if (IsEqual(command, "text")) {
      if (!Text(table)) {
        std::cout << "error\n";
      }
    } else if (IsEqual(command, "print")) {
      Print(table);
    }
  }
}