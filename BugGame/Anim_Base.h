#pragma once
#include <string>
class SpriteSheet;

using Frame = unsigned int;

class Anim_Base
{
	friend class SpriteSheet;
public:
	Anim_Base();
	virtual ~Anim_Base() {};

	void SetSpriteSheet(SpriteSheet* l_sheet) { m_spriteSheet = l_sheet; }
	void SetFrame(Frame l_frame);
	void SetName(const std::string l_name) { m_name = l_name; }
	void SetLooping(bool l_loop) { m_loop = l_loop; }

	bool IsInAction();

	void Play() { m_playing = true; }
	void Pause() { m_playing = false; }
	void Stop() { m_playing = false; Reset(); }
	void Reset();

	virtual void Update(const float& l_dT);

	friend std::stringstream& operator >>(std::stringstream& l_stream, Anim_Base& a) {
		a.ReadIn(l_stream);
		return l_stream;
	}
protected:
	virtual void FrameStep() = 0;
	virtual void CropSprite() = 0;
	virtual void ReadIn(std::stringstream& l_stream) = 0;

	Frame m_frameCurrent;
	Frame m_frameStart;
	Frame m_frameEnd;
	Frame m_frameRow;
	int m_frameActionStart;
	int m_frameActionEnd;
	float m_frameTime;
	float m_elapsedTime;
	bool m_loop;
	bool m_playing;
	std::string m_name;
	SpriteSheet* m_spriteSheet;
};

