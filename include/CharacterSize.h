#ifndef CHARACTER_SIZE_H_
#define CHARACTER_SIZE_H_
#include <unordered_map>

namespace server {
enum struct CharacterSize { Small = 0, Medium, Large };

std::unordered_map<CharacterSize, const char*> characterSizeToString({
    {CharacterSize::Small, "Small"},
    {CharacterSize::Medium, "Medium"},
    {CharacterSize::Large, "Large"},
});
}  // namespace server

#endif  // CHARACTER_SIZE_H_