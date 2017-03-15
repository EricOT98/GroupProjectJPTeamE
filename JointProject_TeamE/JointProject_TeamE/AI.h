#ifndef AI_H
#define AI_H

#include "Racer.h"
#include <SFML\Graphics.hpp>
#include "MathUtility.h"

struct Waypoint;

class AI : public Racer
{
public:
	AI();
	~AI();

	void update(float dt);
	void setWayPoints(std::vector<Waypoint> &m_wayPoints);

protected:
	std::vector<Waypoint> *m_wayPoints;
	unsigned int m_currentNode;
	sf::Vector2f m_steering;
	const float WAYPOINT_RADIUS = 50.0f;
	const float SPEED = 5.0f;

	sf::Vector2f pathFollowing();
};

#endif