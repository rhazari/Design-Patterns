#include "Door.h"

int main() {
    auto door = std::make_unique<SecureDoor>();
    door->open("p@ssword");

    door->open("secret");
    door->close();
}