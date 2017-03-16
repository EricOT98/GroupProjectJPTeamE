#include "Obstacle.h"

/// <summary>
/// Simple obstacle constructor to load in the varying obstacle sprites and textures
/// </summary>
/// <param name="texture">the texture for the object to have</param>
/// <param name="textureRect">the texture rect of the sprite</param>
/// <param name="pos">The position of the obstacle</param>
/// <param name="type">the type of obstacle it is</param>
Obstacle::Obstacle(std::string texture, sf::IntRect textureRect, sf::Vector2f pos, int type, float rotation) :
	m_position(pos)
{
	m_sprite.setTexture(g_resourceMgr.textureHolder[texture]);
	std::cout << "Obstacle Texture: " << texture << std::endl;
	m_sprite.setTextureRect(textureRect);
	
	m_sprite.setPosition(m_position);
	m_sprite.setScale(sf::Vector2f(0.4f, 0.4f));
	m_sprite.setRotation(rotation);

	/*m_sprite.setOrigin((int)(m_sprite.getGlobalBounds().width / 2.0f),
		(int)(m_sprite.getGlobalBounds().height / 2.0f));*/


	switch (type)
	{
	case 0:
		m_type = Type::BUMPER;
		break;
	case 1:
		m_type = Type::ROCK;
		break;
	case 2:
		m_type = Type::BUSH;
		break;
	default:
		m_type = Type::ROCK;
		break;
	}
}
/// <summary>
/// Obstacle destructor
/// </summary>
Obstacle::~Obstacle()
{
}

/// <summary>
/// Draw the obstacle
/// </summary>
/// <param name="window"></param>
void Obstacle::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

/// <summary>
/// Return the sprite of the obstacle
/// </summary>
/// <returns>The obstacles sprite</returns>
sf::Sprite Obstacle::getSprite()
{
	return m_sprite;
}
