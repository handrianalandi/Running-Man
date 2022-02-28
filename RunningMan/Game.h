#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/Window.hpp>
#include"CPlayer.h"
#include"CTree.h"
#include"CGranny.h"
#include"CGhost.h"
#include"CFence.h"
#include"CMusuh.h"
#include"CGold.h"
#include"CSilver.h"
#include"CRuby.h"
#include"CPowerUp.h"
#include"CMagnet.h"
#include"CDrunk.h"
#include<ctime>
#include<vector>
#include<sstream>
#include<fstream>
//jalan=60,120,180-240
class Game
{
private:
	//variables
	sf::RenderWindow *window;
	sf::VideoMode videoMode;
	sf::Event ev;
	sf::Clock timeAnimation;
	sf::Font font;
	sf::Text textPoint;
	sf::Text poweruptext;
	sf::Text highscoreText;
	sf::SoundBuffer bufferselect;
	sf::SoundBuffer buffertoingame;
	sf::Sound soundselect;
	sf::Sound soundtoingame;
	sf::Music musicMenu;
	sf::Music musicDizzy;

	float treeSpawnTimer, treeSpawnTimerMax,coinSpawnTimer,coinSpawnTimerMax,powerupSpawnTimer,powerupSpawnTimerMax,enemySpawnTimer,enemySpawnTimerMax;
	int maxTrees,maxCoins,maxPowerup,maxEnemy,Points;

	//backgrounds
	sf::Sprite background;
	sf::Texture backgroundTexture;
	std::vector<CTree>trees; CTree tree;
	
	
	//mouse position
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	bool mouseheld;


	//file
	std::fstream file;


	//main vars
	//player
	CPlayer player;
	Sound letsgo;
	SoundBuffer bufferletsgo;
	Music musicRunning;
	int nyawa,nyawaasli;

	//coins
	std::vector<CCoin*>coins;
	CCoin* coin;

	//powerup
	std::vector<CPowerUp*>PowerUps;
	CPowerUp* powup;
	bool powerup;
	bool magnet;
	bool ghost;
	int waktu;
	Clock powuptime;
	Time powupstime;
	Sound magnetSound, ghostSound;
	SoundBuffer bufferMagnet, bufferGhost;
	Music musicMagnet;

	//enemy
	std::vector<CMusuh*>Enemies;
	CMusuh* enemy;
	Sound grannySound, drunkSound, fenceSound;
	SoundBuffer bufferGranny, bufferDrunk, bufferFence;

	Time difficultyTimer;
	Clock timer;
	Clock grannywalk;
	bool die;
	int highscore;
	
	//gui
	bool mainmenu, ingame,pause,lose,musicmenu,soundeffekt,info;
	Sprite spritestart,spritepause,spritePlayAgain,spriteBacktomenu,spriteInfo,
		spriteMusic,spriteSoundeffect,spriteRunningman;
	Texture pauseTexture,startTexture,playagainTexture,backtomenuTexture,infoTexture,
		musicTexture,soundeffectTexture,runningmanTexture;
	Clock pausetime;


	//coinsounds
	Sound coinSilver, coinGold, coinRuby;
	SoundBuffer bufferSilver, bufferGold, bufferRuby;


	//text info
	Text textInfo;
	std::stringstream infostring;
	//tes
	Text test;
	std::stringstream testing;

	//initializations
	void initWindow();
	void initVariables();
	void initBackground();
	void initText();
	void initGUI();
	void initSound();
	void initMusic();
public:
	Game();
	~Game();
	//PAMs
	const bool isRunning()const;
	const bool isDead() const;

	//spawning
	void treeSpawn();
	void coinSpawn();
	void powerUpSpawn();
	void enemySpawn();
	//player editing
	void killPlayer();

	//event polling
	void pollEvents();
	
	
	//updates
	void update();
	void updateTrees();
	void updateCoins();
	void updateText();
	void updatePowUps();
	void updateEnemies();
	void updateMousePosition();
	void updateGUI();

	//renders
	void render();
	void renderBackground();
	void renderTree();
	void renderCoins();
	void renderText();
	void renderPowerUps();
	void renderEnemies();

	//save;
	void SaveHighscore();
	void LoadHighscore();
};

