#include "GameObject.h"

GameObject::GameObject(int x, int y, int size) :
	m_size(size) {

	m_position.x = x;
	m_position.y = y;
}
GameObject::GameObject(int size) : m_size(size) {

}