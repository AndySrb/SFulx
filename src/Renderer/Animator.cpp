#include "Animator.h"

Animator::Animator(sf::Sprite &sprite) : m_Sprite(sprite), m_CurrentTime(),m_CurrentAnimation(nullptr)
{
	std::cout << "Animator::Animator(sf::Sprite)" << std::endl;
}

Animator::Animation& Animator::CrateAnimation( const std::string &name, const std::string &textureName, sf::Time duration, bool looping)
{
	m_Animations.push_back(
			Animator::Animation(name, textureName, duration, looping)
			);
	//If we dont have any other animations, use that as current one
	if (m_CurrentAnimation == nullptr)
		SwitchAnimation(&m_Animations.back());

	return m_Animations.back();
}

void Animator::SwitchAnimation(Animator::Animation* animation)
{
	if (animation != nullptr)
	{
		m_Sprite.setTexture(AssetMenager::GetTexture(animation->m_TextureName));
	}
	
	m_CurrentAnimation = animation;
	m_CurrentTime = sf::Time::Zero; //resetTime

}

bool Animator::switchAnimation(const std::string &name)
{
	Animation* animation = FindAnimation(name);
	if (animation != nullptr)
	{
		SwitchAnimation(animation);
		return true;
	}
	
	return false;
}

Animator::Animation* Animator::FindAnimation(const std::string &name)
{
	for (auto it = m_Animations.begin(); it !=m_Animations.end(); ++it)
	{
		if (it->m_Name == name)
			return &*it;
	}

	return nullptr;
}

std::string Animator::GetCurrentAnimationName() const 
{
	if (m_CurrentAnimation != nullptr)
		return m_CurrentAnimation->m_Name;
	//If no animation is playing return ""
	return "";
}


void Animator::Update(const sf::Time &dt)
{
	//If we don't have any animations yet return
	
	if (m_CurrentAnimation == nullptr)
		return;

	m_CurrentTime += dt;

	//Get current animation frame 
	float scaledTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());
	int numFrames = m_CurrentAnimation->m_Frames.size();
	int currentFrame = (int)(scaledTime * numFrames);

	//If the animation is looping, calculate the correct frame
	if ( m_CurrentAnimation->f_IsLooping)
		currentFrame %= numFrames;
	else if (currentFrame >= numFrames) //If the current frame is greater than number of frames
		currentFrame = numFrames -1; //Show last frame

	//Set the texture rectangle, depending on the frame
	m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);


}

