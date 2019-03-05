#pragma once

namespace slowStrike {
	class State
	{
	public:
		virtual void initialize() = 0;

		virtual void handleInput() = 0;
		virtual void update(float dt) = 0;
		virtual void draw(float dt) = 0;

		virtual void pause() {}
		virtual void resume() {}
	private:

	};
}