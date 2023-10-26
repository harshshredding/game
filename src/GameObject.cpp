#include "GameObject.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "Util.hpp"
#include <algorithm>
#include <locale>
#include <string>
#include <memory>

GameObject::GameObject(
    float positionX,
    float positionY,
    std::string texture_file_path,
    float speed
):
_speed(speed)
{
    _texture = std::make_unique<sf::Texture>();
    if (!_texture->loadFromFile(texture_file_path)) {
        print("Could not load texture from " + texture_file_path);
        throw std::exception();
    }
    _sprite.setTexture(*_texture);
    _sprite.setPosition(positionX, positionY);
}


GameObject::GameObject():
_speed(0)
{}


GameObject::GameObject(GameObject &&other)
{
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
}

GameObject& GameObject::operator=(GameObject&& other) {
    _texture = std::move(other._texture);
    _sprite = std::move(other._sprite);
    _speed = other._speed;
    return *this;
}
