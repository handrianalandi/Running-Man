#include "Game.h"


void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 300;
	this->window = new sf::RenderWindow(this->videoMode, "Running Man", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	//trees
	treeSpawnTimerMax = 100.f;
	treeSpawnTimer = treeSpawnTimerMax;
	maxTrees = 10;

	//coins
	coinSpawnTimerMax = 80.f;
	coinSpawnTimer = 0;
	maxCoins = 4;

	//points
	Points = 0;
	highscore = 0;
	

	//player
	die = 0; nyawaasli = 1; nyawa = nyawaasli;

	//powerups
	powerup = 0;
	magnet = 0;
	ghost = 0;
	powerupSpawnTimerMax = 120.f;
	powerupSpawnTimer = 0;
	maxPowerup = 1;
	waktu = 10;

	//enemy
	enemySpawnTimerMax = 70.f;
	enemySpawnTimer = 0;
	maxEnemy = 3;

	//menus
	mainmenu = 1;
	ingame = 0;
	pause = 0;
	lose = 0;
	info = 0;

	//soundsbool
	musicmenu = 1;
	soundeffekt = 1;

	//mouse
	mouseheld = 0;

	//timer
	difficultyTimer = seconds(0);
}

void Game::initBackground()
{
	backgroundTexture.loadFromFile("images/background.png");
	background.setTexture(backgroundTexture);
}

void Game::initText()
{
	(font.loadFromFile("fonts/try1.ttf"));
	textPoint.setFont(font);
	textPoint.setOutlineColor(Color::Black);
	textPoint.setOutlineThickness(3.f);
	textPoint.setCharacterSize(15);
	textPoint.setPosition(10.f, 5.f);
	poweruptext.setFont(font);
	poweruptext.setOutlineColor(Color::Black);
	poweruptext.setOutlineThickness(3.f);
	poweruptext.setCharacterSize(10);
	poweruptext.setPosition(10.f, 40.f);
	highscoreText.setFont(font);
	highscoreText.setOutlineColor(Color::Black);
	highscoreText.setOutlineThickness(3.f);
	highscoreText.setCharacterSize(10);
	highscoreText.setPosition(10.f, 25.f);
	LoadHighscore();
	//text info
	textInfo.setFont(font);
	/*textInfo.setColor(sf::Color::Black);*/
	textInfo.setOutlineThickness(2.f);
	textInfo.setOutlineColor(Color::Black);
	textInfo.setCharacterSize(12.f);
	textInfo.setPosition(10.f, 10.f);
	textInfo.setLetterSpacing(1.f);
	textInfo.setLineSpacing(2.f);
	textInfo.setStyle(Text::Italic);
		//isi
	infostring << "	      CREDIT\n" << std::endl << "Nyoto Wijaya c14190059\n\nKevin Jonathan c14190207\n\nJeremy Mulyawan c14190227\n\nHandrian Alandi c14190231\n\n\n\n\n\n\n\n\n\nSpecial Thanks to :\nKo Stefanus Surya\nBu Liliana\nAnd our beloved PCU";
	textInfo.setString(infostring.str());
	
	//tes nyawa
	test.setFont(font);
	test.setOutlineThickness(2.f);
	test.setOutlineColor(Color::Black);
	test.setCharacterSize(12.f);
	test.setPosition(10.f, 580.f);
	
}

void Game::initGUI()
{
	startTexture.loadFromFile("images/GUI/start.png");
	spritestart.setTexture(startTexture);
	pauseTexture.loadFromFile("images/GUI/pause.png");
	spritepause.setTexture(pauseTexture);
	spritestart.setScale(0.645f, 0.581f);
	spritepause.setScale(0.350f, 0.350f);
	spritestart.setPosition(100.f, 375.f);
	spritepause.setPosition(240.f, 10.f);
	playagainTexture.loadFromFile("images/GUI/playagain.png");
	backtomenuTexture.loadFromFile("images/GUI/backtomenu.png");
	spritePlayAgain.setTexture(playagainTexture);
	spriteBacktomenu.setTexture(backtomenuTexture);
	spritePlayAgain.setScale(0.250f, 0.250f);
	spriteBacktomenu.setScale(0.250f, 0.250f);
	spritePlayAgain.setPosition(90.f, 450.f);
	spriteBacktomenu.setPosition(240.f, 540.f);
	//info
	infoTexture.loadFromFile("images/GUI/info.png");
	spriteInfo.setTexture(infoTexture);
	spriteInfo.setPosition(10.f, 10.f);
	spriteInfo.setScale(0.5f, 0.5f);
	
	//music
	musicTexture.loadFromFile("images/GUI/music.png");
	spriteMusic.setTexture(musicTexture);
	spriteMusic.setPosition(10.f, 540.f);
	spriteMusic.setScale(0.5f, 0.5f);
	
	//soundeffect
	soundeffectTexture.loadFromFile("images/GUI/soundeffect.png");
	spriteSoundeffect.setTexture(soundeffectTexture);
	spriteSoundeffect.setPosition(70.f, 540.f);
	spriteSoundeffect.setScale(0.5f, 0.5f);
	
	//RUNNINGMAN!
	runningmanTexture.loadFromFile("images/runningman.png");
	spriteRunningman.setTexture(runningmanTexture);
	spriteRunningman.setPosition(60.f, 100.f);
	spriteRunningman.setScale(0.33f, 0.33f);
	/*spriteRunningman.setColor(Color::Black);*/
	spriteRunningman.setColor(Color(200, 200, 200, 225));
}

void Game::initSound()
{
	bufferselect.loadFromFile("sfx/basicselect.wav");
	soundselect.setBuffer(bufferselect);
	buffertoingame.loadFromFile("sfx/toingame.wav");
	soundtoingame.setBuffer(buffertoingame);
	//player
	bufferletsgo.loadFromFile("sfx/letsgo.wav");
	letsgo.setBuffer(bufferletsgo);

	//coins
	bufferSilver.loadFromFile("sfx/Pickup_coin 112.wav");
	bufferGold.loadFromFile("sfx/Pickup_coin 123.wav");
	bufferRuby.loadFromFile("sfx/Pickup_coin 98.wav");
	coinSilver.setBuffer(bufferSilver);
	coinGold.setBuffer(bufferGold);
	coinRuby.setBuffer(bufferRuby);
	coinSilver.setVolume(20);
	coinGold.setVolume(20);
	coinRuby.setVolume(20);


	//powerup
	bufferGhost.loadFromFile("sfx/ghost.wav");
	bufferMagnet.loadFromFile("sfx/magnet.wav");
	magnetSound.setBuffer(bufferMagnet);
	ghostSound.setBuffer(bufferGhost);

	//enemy
	bufferGranny.loadFromFile("sfx/crashgranny.wav");
	bufferFence.loadFromFile("sfx/crashwood.wav");
	bufferDrunk.loadFromFile("sfx/crashdrunk.wav");
	grannySound.setBuffer(bufferGranny);
	fenceSound.setBuffer(bufferFence);
	drunkSound.setBuffer(bufferDrunk);
}

void Game::initMusic()
{
	musicMenu.openFromFile("music/mainmenu.wav");
	musicMenu.setLoop(true);
	musicMenu.setVolume(10);
	musicMenu.setLoopPoints(Music::TimeSpan(seconds(10), seconds(52)));
	musicRunning.openFromFile("music/run.wav");
	musicRunning.setLoop(true);
	musicRunning.setVolume(100);
	musicMagnet.openFromFile("music/magnetmusic.wav");
	musicMagnet.setLoop(true);
	musicMagnet.setVolume(20);
	musicDizzy.openFromFile("music/dizzy.wav");
	musicDizzy.setLoop(1);
}

Game::Game()
{
	this->initWindow();
	this->initBackground();
	this->initVariables();
	this->initText();
	this->initGUI();
	this->initSound();
	this->initMusic();
	this->musicMenu.play();
	std::cout << "ALL FILES SUCCESSFULLY INITIALIZED!" << std::endl;
}

Game::~Game()
{
	delete this->window;
	for (auto p : coins) {
		delete p;
	}

	for (auto e : PowerUps)
	{
		delete e;
	}
	for (auto e : Enemies)
	{
		delete e;
	}
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

const bool Game::isDead() const
{
	return die;
}

void Game::treeSpawn()
{
	if (!die) {
		if (trees.size() < maxTrees) {

			if (treeSpawnTimer >= treeSpawnTimerMax) {
				tree.randomize();
				trees.push_back(tree);
				treeSpawnTimer = 0.f;
			}
			else {
				treeSpawnTimer += 1.f;
			}

		}
	}
}

void Game::coinSpawn()
{
	if (!die) {
		if (coins.size() < maxCoins) {
			if (coinSpawnTimer > coinSpawnTimerMax) {
				coinSpawnTimer = 0.f;
				int type = rand() % 7;
				switch (type)
				{
				case 1:
					coin = new CGold;
					coins.push_back(coin);
					break;
				case 2:
					coin = new CGold;
					coins.push_back(coin);
					break;
				case 3:
					coin = new CRuby;
					coins.push_back(coin);
					break;
				default:
					coin = new CSilver;
					coins.push_back(coin);
					break;
				}
			}
			else {
				coinSpawnTimer += 1.f;
			}
		}
	}
}



void Game::powerUpSpawn()
{
	if (!die) {
		if (PowerUps.size() < maxPowerup) {
			if (powerupSpawnTimer >= powerupSpawnTimerMax) {
				powerupSpawnTimer = 0.f;
				int type = rand() % 2;
				switch (type)
				{
				case 0:
					powup = new CMagnet;
					PowerUps.push_back(powup);
					break;
				case 1:
					powup = new CGhost;
					PowerUps.push_back(powup);
					break;
				default:
					break;
				}
			}
			else {
				powerupSpawnTimer += 1.f;
			}
		}
	}
}

void Game::enemySpawn()
{
	if (!die) {
		if (Enemies.size() < maxEnemy) {
			if (enemySpawnTimer >= enemySpawnTimerMax) {
				enemySpawnTimer = 0.f;
				int type = rand() % 4;
				switch (type)
				{
				case 0:
					enemy = new CGranny;
					Enemies.push_back(enemy);
					break;
				case 1:
					enemy = new CDrunk;
					Enemies.push_back(enemy);
					break;
				case 2:
					enemy = new CFence;
					Enemies.push_back(enemy);
					break;

				default:
					break;
				}
			}
			else {
				enemySpawnTimer += 1.f;
			}
		}
	}
}

void Game::killPlayer()
{
	for (auto e : trees)
	{
		e.setDirection(0.f, 0.f);
	}
	for (auto e : coins) {
		e->setDirection(0.f, 0.f);
	}
	player.getTexture().loadFromFile("images/die.png");
	player.getIntRect().height = 752;
	player.getIntRect().left = 0;
	player.getIntRect().top = 0;
	player.getIntRect().width = 539;
	player.setMaxSize(1078);
	player.setplusWidth(539);
	player.getSprite().setTexture(player.getTexture());
	die = 1;
	musicRunning.stop();
}

void Game::update()
{
	this->pollEvents();

	//updates

	if (ingame) {
		player.update(die);
		updateTrees();
		updateCoins();
		updateText();
		updatePowUps();
		updateEnemies();
	}
	if (mainmenu) {
		player.update(die);
		if (player.getSprite().getPosition().x != 100.f) {
			player.getSprite().setPosition(100.f, 150.f);
		}
		updateTrees();
		updateCoins();
		updateText();
		updatePowUps();
		updateEnemies();
		timer.restart();
	}
	if (info) {
		player.update(die);
		updateTrees();
		updateCoins();
		updateText();
		updatePowUps();
		updateEnemies();
	}
	if (lose) {
		player.update(die);
		updateTrees();
		updateCoins();
		updateText();
		updatePowUps();
		updateEnemies();
	}
	if (pause) {
		powuptime.restart();
		timer.restart();
	}
	updateGUI();
	updateMousePosition();

}
void Game::updateTrees()
{
	this->treeSpawn();
	for (int i = 0; i < trees.size(); i++)
	{
		this->trees[i].update(die);
		if (trees[i].getSprite().getPosition().y > this->window->getSize().y) {
			this->trees.erase(trees.begin() + i);
		}
	}

}
void Game::updateCoins()
{
	coinSpawn();
	for (auto e : coins)
	{
		e->update(die);
	}
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i]->getSprite().getPosition().y > this->window->getSize().y) {
			coins.erase(coins.begin() + i);
		}
	}
	if (ingame) {
		for (int i = 0; i < coins.size(); i++)
		{
			if (player.getSprite().getGlobalBounds().intersects(coins[i]->getSprite().getGlobalBounds())) {
				switch (coins[i]->getType())
				{
				case 0:
					if (soundeffekt) {
						coinSilver.play();
					}
					Points += 1;
					coins.erase(coins.begin() + i);
					break;
				case 1:
					if (soundeffekt) {
						coinGold.play();
					}
					Points += 3;
					coins.erase(coins.begin() + i);
					break;

				case 2:
					if (soundeffekt) {
						coinRuby.play();
					}
					Points += 5;
					coins.erase(coins.begin() + i);
					break;
				default:
					break;
				}
			}
		}
		if (Points > highscore) {
			highscore = Points;
			SaveHighscore();
		}
	}
}
void Game::updateText()
{
	std::stringstream ss;
	ss << "Points : " << this->Points;
	textPoint.setString(ss.str());
	ss.str("");
	if (magnet) {
		ss << "Magnet: " << int(waktu) - static_cast<int>(powupstime.asSeconds()) << " Second(s)!";
	}
	if (ghost) {
		ss << "Ghost Mode: " << int(waktu) - static_cast<int>(powupstime.asSeconds()) << " Second(s)!";
	}
	poweruptext.setString(ss.str());
	ss.str("");
	ss << "Highscore: " << highscore;
	highscoreText.setString(ss.str());
	
	ss.str("");
	ss << "Nyawa: " << nyawa;
	test.setString(ss.str());
}
void Game::updatePowUps()
{
	if (!powerup) {
		powerUpSpawn();
	}
	for (auto e : PowerUps)
	{
		e->update(die);
	}
	for (int i = 0; i < PowerUps.size(); i++)
	{
		if (PowerUps[i]->getSprite().getPosition().y > window->getSize().y) {
			PowerUps.erase(PowerUps.begin() + i);
		}
	}
	if (ingame) {
		for (int i = 0; i < PowerUps.size(); i++ && !die)
		{
			if (player.getSprite().getGlobalBounds().intersects(PowerUps[i]->getSprite().getGlobalBounds())) {
				powupstime = seconds(0);
				powuptime.restart();
				switch (PowerUps[i]->getType())
				{
				case 0:
					if (soundeffekt) {
						magnetSound.play();
						musicMagnet.play();
					}
					magnet = 1;
					powerup = 1;
					PowerUps.erase(PowerUps.begin() + i);
					break;
				case 1:
					if (soundeffekt) {
						ghostSound.play();
					}
					ghost = 1;
					powerup = 1;
					PowerUps.erase(PowerUps.begin() + i);
					//low alpha
					player.getSprite().setColor(sf::Color(255, 255, 255, 100));
					break;
				default:
					break;
				}
			}
		}
		if (magnet) {
			if (powupstime.asSeconds() >= waktu) {
				magnet = 0;
				powerup = 0;
				musicMagnet.stop();
			}
			else {
				if (powuptime.getElapsedTime().asSeconds() >= 1) {
					powuptime.restart();
					powupstime = powupstime + seconds(1);
				}
				for (auto e : coins)
				{
					if (player.getSprite().getPosition().y - e->getSprite().getPosition().y < 100) {
						e->getSprite().move(((player.getSprite().getPosition().x + (player.getSprite().getTexture()->getSize().x * player.getSprite().getScale().x / 5)) - e->getSprite().getPosition().x) / float(20), 2.f);

					}
				}
			}
		}
		if (ghost) {
			if (powupstime.asSeconds() >= waktu) {
				ghost = 0;
				powerup = 0;
				player.getSprite().setColor(sf::Color(255, 255, 255, 255));
			}
			else {
				if (powuptime.getElapsedTime().asSeconds() >= 1) {
					powuptime.restart();
					powupstime = powupstime + seconds(1);
				}
			}
		}
	}
}
void Game::updateEnemies()
{
	
	if (timer.getElapsedTime().asSeconds() >= 1) {
		difficultyTimer = difficultyTimer + seconds(1);
		timer.restart();
	}
	if (difficultyTimer.asSeconds() > 180) {
		maxEnemy = 5; 
	}
	else if (difficultyTimer.asSeconds() > 120.f) {
		maxEnemy = 4;
	}
	if (difficultyTimer.asSeconds() > 75.f)
	{
		 enemySpawnTimerMax = 45.f;
	}
	else if (difficultyTimer.asSeconds() > 30.f) {
		enemySpawnTimerMax = 60.f;
	}
	enemySpawn();
	for (auto e : Enemies)
	{
		e->update(die);

	}
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (Enemies[i]->getSprite().getPosition().y > this->window->getSize().y) {
			Enemies.erase(Enemies.begin() + i);
		}
	}
	for (int i = 0; i < Enemies.size(); i++)
	{
		if (!ghost && !mainmenu&&!info) {
			if (player.getSprite().getPosition().y - Enemies[i]->getSprite().getPosition().y < 50 && player.getSprite().getGlobalBounds().intersects(Enemies[i]->getSprite().getGlobalBounds()) && player.getSprite().getPosition().y>Enemies[i]->getSprite().getPosition().y) {
				switch (Enemies[i]->getType())
				{
				case 0:
					if (soundeffekt) {
						grannySound.play();
					}
					break;
				case 1:
					if (soundeffekt) {
						drunkSound.play();
					}
					break;
				case 2:
					if (soundeffekt) {
						fenceSound.play();
					}
					break;
				default:
					break;
				}
				Enemies.erase(Enemies.begin() + i);
				nyawa--;
				if (nyawa <= 0) {
					killPlayer();
					if (magnet) {
						musicMagnet.stop();
					}
					if (soundeffekt) {
						musicDizzy.play();
					}
					lose = 1;
					ingame = 0;
					player.getSprite().setScale(0.360f, 0.360f);
					player.getSprite().setPosition(60.f, 175.f);
					textPoint.setScale(2.f, 2.f);
					textPoint.setPosition(20.f, 100.f);
					powupstime = seconds(7);
					spriteBacktomenu.setPosition(150.f, 450.f);
				}
			}
		}
	}
}
void Game::updateMousePosition()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}
void Game::updateGUI()
{
	if (mainmenu) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritestart.getGlobalBounds().contains(mousePosView)) {
					nyawa = nyawaasli;
					difficultyTimer = seconds(0);
					spritestart.setPosition(100.f, 225.f);
					/*if (musicmenu) {
						musicMenu.stop();
					}*/
					if (soundeffekt) {
						musicRunning.play();
						soundtoingame.play();
						letsgo.play();
					}
					ingame = 1;
					mainmenu = 0;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(60.f, 600.f - 100.5f);
					player.getSprite().setScale(0.123f, 0.123f);
					player.getTexture().loadFromFile("images/player.png");
					player.getIntRect().height = 685;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 488;
					player.setMaxSize(488);
					player.setplusWidth(488);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
					this->PowerUps.clear();
					this->trees.clear();
					powerup = 0;
					ghost = 0;
					magnet = 0;
					player.getSprite().setColor(Color(255, 255, 255, 255));
				}
				if (spriteMusic.getGlobalBounds().contains(this->mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
					}
					if (musicmenu) {
						musicMenu.stop();
						spriteMusic.setColor(Color(255, 255, 255, 200));
						musicmenu = 0;
					}
					else {
						musicMenu.play();
						spriteMusic.setColor(Color(255, 255, 255, 255));
						musicmenu = 1;
					}
				}
				if (spriteSoundeffect.getGlobalBounds().contains(this->mousePosView)) {
					if (!soundeffekt) {
						soundselect.play();
					}
					if (soundeffekt) {
						soundeffekt = 0;
						spriteSoundeffect.setColor(Color(255, 255, 255, 200));
					}
					else {
						soundeffekt = 1;
						spriteSoundeffect.setColor(Color(255, 255, 255, 255));
					}
				}
				if (spriteInfo.getGlobalBounds().contains(this->mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
					}
					info = 1;
					mainmenu = 0;
					spriteBacktomenu.setPosition(240.f, 540.f);
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (ingame) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritepause.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
						musicRunning.stop();
						if (magnet) {
							musicMagnet.stop();
						}
					}
					ingame = 0;
					pause = 1;
					pausetime.restart();
					spriteBacktomenu.setPosition(240.f, 540.f);
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (pause) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritestart.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
						musicRunning.play();
						if (magnet) {
							musicMagnet.play();
						}
					}
					ingame = 1;
					pause = 0;
				}
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					difficultyTimer = seconds(0);
					if (musicmenu) {
						musicMenu.stop();
					}
					if (musicmenu) {
						musicMenu.play();
					}
					if (soundeffekt) {
						soundselect.play();
					}
					spritestart.setPosition(100.f, 375.f);
					mainmenu = 1;
					Points = 0;
					lose = 0;
					pause = 0;
					die = 0;
					player.getSprite().setPosition(100.f, 225.f);
					player.getSprite().setScale(0.21f, 0.2f);
					player.getTexture().loadFromFile("images/idlemenu.png");
					player.getIntRect().height = 747;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 530;
					player.setMaxSize(3710);
					player.setplusWidth(530);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
					this->PowerUps.clear();
					this->trees.clear();
					player.getSprite().setColor(Color(255, 255, 255, 255));
				}
				if (spriteSoundeffect.getGlobalBounds().contains(this->mousePosView)) {
					if (!soundeffekt) {
						soundselect.play();
					}
					if (soundeffekt) {
						soundeffekt = 0;
						spriteSoundeffect.setColor(Color(255, 255, 255, 200));
					}
					else {
						soundeffekt = 1;
						spriteSoundeffect.setColor(Color(255, 255, 255, 255));
					}
				}
				if (spriteMusic.getGlobalBounds().contains(this->mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
					}
					if (musicmenu) {
						spriteMusic.setColor(Color(255, 255, 255, 200));
						musicMenu.stop();
						musicmenu = 0;
					}
					else {
						musicMenu.play();
						spriteMusic.setColor(Color(255, 255, 255, 255));
						musicmenu = 1;
					}
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (lose) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spritePlayAgain.getGlobalBounds().contains(mousePosView)) {
					nyawa = nyawaasli;
					difficultyTimer = seconds(0);
					if (soundeffekt) {
						soundtoingame.play(); letsgo.play(); musicRunning.play();
						musicDizzy.stop();
					}
					ingame = 1;
					mainmenu = 0;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(60.f, 600.f - 100.5f);
					player.getSprite().setScale(0.123f, 0.123f);
					player.getTexture().loadFromFile("images/player.png");
					player.getIntRect().height = 685;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 488;
					player.setMaxSize(488);
					player.setplusWidth(488);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
					this->PowerUps.clear();
					this->trees.clear();
					powerup = 0;
					ghost = 0;
					magnet = 0;
					player.getSprite().setColor(Color(255, 255, 255, 255));
				}
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					if (musicmenu) {
						musicMenu.stop();
					}
					if (musicmenu) {
						musicMenu.play();
					}
					if (soundeffekt) {
						soundselect.play(); musicDizzy.stop();
					}
					difficultyTimer = seconds(0);
					spritestart.setPosition(100.f, 375.f);
					mainmenu = 1;
					Points = 0;
					lose = 0;
					die = 0;
					player.getSprite().setPosition(100.f, 225.f);
					player.getSprite().setScale(0.21f, 0.2f);
					player.getTexture().loadFromFile("images/idlemenu.png");
					player.getIntRect().height = 747;
					player.getIntRect().left = 0;
					player.getIntRect().top = 0;
					player.getIntRect().width = 530;
					player.setMaxSize(3710);
					player.setplusWidth(530);
					player.getSprite().setTexture(player.getTexture());
					textPoint.setScale(1.f, 1.f);
					textPoint.setPosition(10.f, 5.f);
					this->Enemies.clear();
					this->coins.clear();
					this->PowerUps.clear();
					this->trees.clear();
					player.getSprite().setColor(Color(255, 255, 255, 255));
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
	if (info) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (!mouseheld) {
				mouseheld = 1;
				if (spriteBacktomenu.getGlobalBounds().contains(mousePosView)) {
					if (soundeffekt) {
						soundselect.play();
					}
					info = 0;
					mainmenu = 1;
					spriteBacktomenu.setPosition(240.f, 540.f);
				}
			}
		}
		else {
			mouseheld = 0;
		}
	}
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}
void Game::render()
{
	this->window->clear();
	renderBackground();
	//render everything
	if (ingame) {
		renderTree();
		renderCoins();
		renderPowerUps();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spritepause);
		renderText();
	}
	if (mainmenu) {

		renderTree();
		renderCoins();
		renderPowerUps();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spritestart);
		window->draw(this->spriteInfo);
		window->draw(this->spriteMusic);
		window->draw(this->spriteSoundeffect);
		window->draw(this->spriteRunningman);
	}
	if (lose) {
		renderTree();
		renderCoins();
		renderPowerUps();
		renderEnemies();
		player.render(*this->window);
		renderText();
		window->draw(this->spriteBacktomenu);
		window->draw(this->spritePlayAgain);
	}
	if (pause) {
		renderTree();
		renderCoins();
		renderPowerUps();
		renderEnemies();
		player.render(*this->window);
		window->draw(this->spriteBacktomenu);
		window->draw(this->spritestart);
		window->draw(this->spriteMusic);
		window->draw(this->spriteSoundeffect);
	}
	if (info) {
		renderTree();
		renderCoins();
		renderPowerUps();
		renderEnemies();
		window->draw(textInfo);
		window->draw(spriteBacktomenu);
	}

	this->window->display();


}

void Game::renderBackground()
{
	this->window->draw(background);
}

void Game::renderTree()
{
	for (int i = 0; i < trees.size(); i++)
	{
		trees[i].render(*this->window);
	}
}

void Game::renderCoins()
{
	for (auto e : coins)
	{
		e->render(*this->window);
	}
}

void Game::renderText()
{
	if (powerup) {
		this->window->draw(poweruptext);
	}
	this->window->draw(textPoint);
	this->window->draw(highscoreText);
	/*this->window->draw(this->test);*/
}

void Game::renderPowerUps()
{

	for (auto e : PowerUps)
	{
		e->render(*this->window);
	}
}

void Game::renderEnemies()
{
	for (auto e : Enemies)
	{
		e->render(*this->window);
	}
}

void Game::SaveHighscore()
{
	file.open("score/highscore.txt", std::ios::out);
	file << highscore;
	file.close();
}

void Game::LoadHighscore()
{
	file.open("score/highscore.txt", std::ios::in);
	file >> highscore;
	file.close();
}


