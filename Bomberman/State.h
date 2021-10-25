#pragma once
namespace Simao
{
	class State
	{
	public:
		virtual void Init() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float dt) = 0;
		virtual void Draw(float dt) = 0;
		virtual void Resume() {}
		virtual void Pause() {}
	};

}