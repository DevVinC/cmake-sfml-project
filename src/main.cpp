#include "box2d/b2_body.h"
#include "box2d/b2_fixture.h"
#include "box2d/b2_polygon_shape.h"
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

int main()
{
    // Create the SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML + Box2D Example");

    // Create the Box2D world
    b2Vec2 gravity(0.0f, 9.8f);
    b2World world(gravity);


    // Create static ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(50.f, 500.f);

    b2PolygonShape groundBoxShape;
    groundBoxShape.SetAsBox(50.f, 50.f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    groundBody->CreateFixture(&groundBoxShape, 0.0f);

    // Create dynamic body
    b2BodyDef dynamicBoxDef;
    dynamicBoxDef.type = b2_dynamicBody;
    dynamicBoxDef.position.Set(100.f, 100.f);

    b2PolygonShape dynamicBoxShape;
    dynamicBoxShape.SetAsBox(50.f, 50.f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBoxShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;

    b2Body* dynamicBox = world.CreateBody(&dynamicBoxDef);
    dynamicBox->CreateFixture(&fixtureDef);

    dynamicBox->ApplyForce(b2Vec2(0.0f, 10.0f), b2Vec2(100.0f, 100.0f), true);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Step the Box2D world
        world.Step(1.0f / 60.0f, 6, 2);

        // Clear the window
        window.clear();

        dynamicBoxShape

        // Display the window
        window.display();
    }

    return 0;
}
