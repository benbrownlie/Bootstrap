#include "DragonWorld.h"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light 1
	m_light1 = new Light(
		{5.0f, 0.0f, 0.0f},
		{0.5f, 0.5f, 0.5f, 1.0f},
		{1.0f, 0.0f, 0.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f}
	);
	add(m_light1);
	m_light1->setIndex(1);

	//Light 2
	m_light2 = new Light(
		{ -5.0f, 0.0f, 0.0f },
		{ 0.5f, 0.5f, 0.5f, 1.0f },
		{ 0.0f, 0.0f, 1.0f, 1.0f },
		{ 1.0f, 1.0f, 1.0f, 1.0f }
	);
	add(m_light2);
	m_light2->setIndex(2);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	m_dragon->getTransform()->setScale(glm::vec3(0.2f));
	add(m_dragon);

	//Quad
	m_quad = new Quad("earth_diffuse.jpg", { 0.05, 0.05, 0.05, 1 });
	m_quad->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
	m_quad->getTransform()->setScale(glm::vec3(2.0f, 1.0f, 2.0f));
	add(m_quad);

	//Cube
	m_cube = new Cube();
	m_cube->setColor(glm::vec4(0.8f, 0.2f, 0.4f, 1.0f));
	m_cube->getTransform()->setPosition(glm::vec3(4.0f, -3.0f, 0.0f));
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light1);
	destroy(m_light2);
	destroy(m_dragon);
	destroy(m_quad);
}
