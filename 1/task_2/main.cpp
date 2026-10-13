#include <iostream>

using Operation = void (*)(int&);

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

void Deposit(int& balance) {
  int amount;
  std::cin >> amount;
  if (amount <= 0) {
    std::cout << "error\n";
    return;
  }
  balance += amount;
}

void Withdraw(int& balance) {
  int amount;
  std::cin >> amount;
  if (amount <= 0 || amount > balance) {
    std::cout << "error\n";
    return;
  }
  balance -= amount;
}

void PrintBalance(int& balance) {
  std::cout << balance << "\n";
}

void Reset(int& balance) {
  balance = 0;
}

void Increment(int& balance) {
  balance++;
}

int main() {
  int balance = 0;
  const int CommandCount = 5;
  const char* command_names[CommandCount] = {
    "deposit",
    "withdraw",
    "balance",
    "reset",
    "inc"
  };
  Operation operations[CommandCount] = {
    Deposit,
    Withdraw,
    PrintBalance,
    Reset,
    Increment
  };
  while (true) {
    char command[16];
    std::cin.width(sizeof(command));
    std::cin >> command;
    if (IsEqual(command, "stop")) {
      break;
    }
    bool found = false;
    for (int i = 0; i < CommandCount; i++) {
      if (IsEqual(command, command_names[i])) {
        operations[i](balance);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "error\n";
    }
  }
}