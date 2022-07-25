#ifndef CHARACTER_SIZE_H_
#define CHARACTER_SIZE_H_
#include <unordered_map>

namespace CharacterSchema {
enum struct Size { Small = 0, Medium, Large };

std::unordered_map<Size, const char*> SizeToString({
    {Size::Small, "Small"},
    {Size::Medium, "Medium"},
    {Size::Large, "Large"},
});
}  // namespace CharacterSchema

#endif  // CHARACTER_SIZE_H_