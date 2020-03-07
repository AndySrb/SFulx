#include "AudioManager.h"

AudioManager::AudioManager()
{
	if (s_audioManager == nullptr)
		s_audioManager = this;

}


void AudioManager::addAudio(std::string filename, enum Type type)
{

	switch (type)
	{
		case Type::SOUND:
			addSound(filename);
			m_countSoundID++;
			m_audioID++;
			break;

		case Type::MUSIC: 
			addMusic(filename);
			m_countMusicID++;
			m_audioID++;
			break;

		default:
			std::cout << "AudioManager::Error: Invalid Type" << std::endl;
			break;
	}//Switch

}

void AudioManager::addSound(const std::string &filename)
{
	sf::SoundBuffer *obj = new sf::SoundBuffer;

	sf::SoundBuffer *soundBuffer = new sf::SoundBuffer();
	soundBuffer->loadFromFile(filename);
	m_audioClass[filename] = CustomSound(obj, Type::SOUND, m_countSoundID);

	sf::Sound *ptr = new sf::Sound();
	obj->loadFromSamples(soundBuffer->getSamples() ,soundBuffer->getSampleCount(), soundBuffer->getChannelCount(), soundBuffer->getSampleRate());

	m_sound.push_back(ptr);
}

void AudioManager::addMusic(const std::string &filename)
{

	sf::Music *music= new sf::Music();
	music->openFromFile(filename);

	m_audioClass[filename] = CustomSound(nullptr , Type::SOUND, m_countMusicID);

}


void AudioManager::checkIsPlaying()
{
	for (auto iter = m_audioClass.begin(); iter != m_audioClass.end(); ++iter)
	{
			if (m_sound[iter->second.m_id]->Playing == sf::SoundSource::Playing)
				iter->second.m_bPlaying = true;
			else
				iter->second.m_bPlaying = false;
	}

}

void AudioManager::play(const std::string &filename)
{
	if(m_audioClass[filename].m_type == Type::SOUND)
	{
		m_sound[(m_audioClass[filename].m_id)]->play();
		m_audioClass[filename].m_bPlaying = true;
	}
	else
	{
		m_music[(m_audioClass[filename].m_id)]->play();
		m_audioClass[filename].m_bPlaying = true;
	}

}

void AudioManager::pause(const std::string &filename)
{
	if(m_audioClass[filename].m_type == Type::SOUND)
	{
		m_sound[(m_audioClass[filename].m_id)]->pause();
		m_audioClass[filename].m_bPlaying = false;
	}
	else
	{
		m_music[(m_audioClass[filename].m_id)]->pause();
		m_audioClass[filename].m_bPlaying = false;
	}

}

void AudioManager::pauseAllMusic()
{
	checkIsPlaying();

	for (auto iter = m_audioClass.begin() ;iter != m_audioClass.cend(); ++iter)
	{
		if (iter->second.m_type == Type::MUSIC && iter->second.m_bPlaying == true)
		{
			this->pause(iter->first);
		}
			
	}

}

void AudioManager::pauseAllSounds()
{
	checkIsPlaying();

	for (auto iter = m_audioClass.begin() ;iter != m_audioClass.cend(); ++iter)
	{
		if (iter->second.m_type == Type::SOUND && iter->second.m_bPlaying == true)
		{
			this->pause(iter->first);
		}
	}
}

