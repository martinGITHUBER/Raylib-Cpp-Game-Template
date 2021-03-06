#ifndef ENTITY_HPP
#define ENTITY_HPP
#pragma once

#include <raylib-cpp.hpp>

#include "health.hpp"

class Entity {
	public:
		Entity(Vector2 position, Vector2 size, float speed = 10, Color color = RED, Health health = Health{ 100 });
		virtual ~Entity() = default;
		Vector2 position;
		Vector2 previous_position;
		Vector2 velocity;
		Vector2 acceleration;
		float speed;
		Vector2 size;
		Color color;
		Health health;
		virtual void tick(const double& delta);
		virtual void render(const double& alpha);
		Vector2 interpolate(const double& alpha) const;
		virtual void reset_values() final;
		virtual bool check_collision(Rectangle collision_area) const;
		virtual bool check_collision(Vector2 collision_point) const;
		virtual Vector2 get_center() const;
		void move(Vector2 position, const double& delta);
		void move_to(Vector2 position);
		void teleport(Vector2 position, const double& delta);
		void teleport_to(Vector2 position);
		void update_interpolation();
	protected:
		virtual void update_values(const double& delta) final;
};

#endif
