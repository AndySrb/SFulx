#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <utility>
#include <map>

#define MAX_PLAYABLE_SOUNDS = 256 // SFML can't play more than 256 sounds and music at the time its limited by libary.

class AudioManager
{


	private:
		AudioManager(const AudioManager &obj);
		AudioManager(AudioManager &&obj);

		enum Type {MUSIC, SOUND};

		struct CustomSound
		{
			CustomSound(sf::SoundBuffer *_sound, Type _type, int _id)
			{
				m_sound = _sound;
				m_type = _type;
				m_id = _id;
			}


			sf::SoundBuffer *m_sound;
			Type m_type;
			int m_id;
			bool m_bPlaying = false;
			bool m_bLoop = false;
			
		}; //Struct

		std::map<std::string,CustomSound> m_audioClass;

		static AudioManager *s_audioManager;
		std::vector<sf::Sound *> m_sound;
		std::vector<sf::Music *> m_music;

		int m_countPlaying = 0;

		int m_audioID = 0;
		

		int m_countSoundID = 0;
		int m_countMusicID = 0;


	public:
		AudioManager();

		void addAudio(std::string filename,enum Type obj);
		void checkIsPlaying();


		void addSound(const std::string &filename);
		void addMusic(const std::string &filename);

		void play(const std::string &filename);
		void pause(const std::string &filename);

		void pauseAllMusic();
		void pauseAllSounds();

};


#endif
