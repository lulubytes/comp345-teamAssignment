
#include "..\header\GameInitializer.h"
#include <filesystem>





namespace fs = std::experimental::filesystem;




GameInitializer::GameInitializer() {

	this->map = nullptr;
	this->mapLoader = nullptr;
	for (vector<Player*> ::iterator it = this->players.begin(); it != this->players.end(); it++) {
		*it = NULL;
	}

}

GameInitializer::~GameInitializer() {
	if (this->mapLoader != NULL) {
		delete mapLoader;
		mapLoader = NULL;
	}
	if (this->map != NULL) {
		delete map;
		map = NULL;
	}
	for (vector<Player*>::iterator it = this->players.begin(); it != this->players.end(); it++) {
		delete *it;
		*it = NULL;
	}

}

void GameInitializer::game_Show() {
	cout << "*************************************************************" << endl;
	cout << "**************                            *******************" << endl;
	cout << "**************   Eight-Minutes Empire     *******************" << endl;
	cout << "**************                            *******************" << endl;
	cout << "*************************************************************" << endl;

}

void GameInitializer::show_Menu() {
	cout << "*************************************************************************" << endl;
	cout << "***********   WELCOME TO THE EIGHT-MINUTE EMPIRE GAME  ******************" << endl;
	cout << "**************       1. CHOSE MAP                    ********************" << endl;
	cout << "**************       2. START PLAY THE GAME         *********************" << endl;
	cout << "**************       3. EXIT THE GAME               *********************" << endl;
	cout << "*************************************************************************" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl;

}

Map* GameInitializer::choose_Map() {
	Map* m1 = new Map();
	int choice;
	string fileName;

	//1 -- Rectangular Shap_1    read from ("mapFiles\\map5.json") 
	//2 -- L Shape_1             read from ("mapFiles\\map6.json")    
	//3 -- Invalid Map_1         read from ("mapFiles\\map4.json") 
	//4 -- Rectangular Shap_2    read from ("mapFiles\\map1.json") 
	//5 -- L Shape_2             read from ("mapFiles\\map2.json") 
	//6 -- Invalid Map_2         read from ("mapFiles\\map3.json") 
	cout << "What's kind of map you would like to play? \n1 -- Rectangular Shap_1\n2 -- L Shape_1\n3 -- Invalid Map_1"
		<< "\n4 -- Rectangular Shap_2\n5 -- L Shape_2\n6 -- Invalid Map_2" << endl;
	cin >> choice;
	while (true) {
		//1 -- Rectangular Shap_1    read from ("mapFiles\\map5.json") 
		if (choice == 1) {
			cout << "reading Rectangular Shape map from mapFiles\\map5.json" << endl;
			fileName = "mapFiles\\map5.json";
			system("pause");
			system("cls");

			this->game_Show();
			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);

			// LOAD SUCCESSFULLY
			this->getCurrentMap()->validate();

			m1 = this->getCurrentMap();
			system("pause");
			system("cls");

			this->game_Show();
			cout << *m1;
			system("pause");
			system("cls");

			this->game_Show();
			this->printMapInRectangleShape(m1);
			system("pause");
			system("cls");

			break;

		}
		//2 -- L Shape_1             read from ("mapFiles\\map6.json")    
		else if (choice == 2) {
			cout << "reading L Shape map from mapFiles\\map6.json" << endl;
			fileName = "mapFiles\\map6.json";
			system("pause");
			system("cls");

			this->game_Show();
			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);

			// LOAD SUCCESSFULLY
			this->getCurrentMap()->validate();



			m1 = this->getCurrentMap();
			system("pause");
			system("cls");


			this->game_Show();
			cout << *m1;
			system("pause");
			system("cls");

			this->game_Show();
			this->printMapInLShape(m1);
			system("pause");
			system("cls");

			break;
		}
		//3 -- Invalid Map_1         read from ("mapFiles\\map4.json") 

		else if (choice == 3) {

			cout << "reading Invalid map from mapFiles\\map4.json" << endl;
			fileName = "mapFiles\\map4.json";
			//system("cls");

			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);
			system("cls");
			break;
		}

		//4 -- Rectangular Shap_2    read from ("mapFiles\\map1.json") 
		if (choice == 4) {
			cout << "reading Rectangular Shape map from mapFiles\\map1.json" << endl;
			fileName = "mapFiles\\map1.json";
			system("pause");
			system("cls");

			this->game_Show();
			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);

			// LOAD SUCCESSFULLY
			this->getCurrentMap()->validate();

			m1 = this->getCurrentMap();
			system("pause");
			system("cls");

			this->game_Show();
			cout << *m1;
			system("pause");
			system("cls");

			this->game_Show();
			this->printMapInRectangleShape2(m1);
			system("pause");
			system("cls");

			break;

		}

		//5 -- L Shape_2             read from ("mapFiles\\map2.json") 
		else if (choice == 5) {
			cout << "reading L Shape map from mapFiles\\map2.json" << endl;
			fileName = "mapFiles\\map2.json";
			system("pause");
			system("cls");

			this->game_Show();
			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);

			// LOAD SUCCESSFULLY
			this->getCurrentMap()->validate();



			m1 = this->getCurrentMap();
			system("pause");
			system("cls");


			this->game_Show();
			cout << *m1;
			system("pause");
			system("cls");

			this->game_Show();
			this->printMapInLShape2(m1);
			system("pause");
			system("cls");

			break;
		}
		else if (choice == 6) {
			//6 -- Invalid Map_2         read from ("mapFiles\\map3.json") 
			cout << "reading Invalid map from mapFiles\\map3.json" << endl;
			fileName = "mapFiles\\map3.json";
			//system("cls");

			// IF LOAD FALID ==> STOP SYSTEM !!!
			this->loadMap(fileName);
			system("cls");
			break;
		}


		else {
			cout << "Only 1, 2, 3，4，5，6  are permited! Please try again!\n";
			cout << "What's kind of map you would like to play? \n1 -- Rectangular Shap_1\n2 -- L Shape_1\n3 -- Invalid Map_1"
				<< "\n4 -- Rectangular Shap_2\n5 -- L Shape_2\n6 -- Invalid Map_2" << endl;
			cin >> choice;
		}
	}

	return m1;


}


//initialize the player
vector<Player*>& GameInitializer::choose_Player() {

	int  choice = 0;
	string color1;
	string color2;
	string name1;
	string name2;
	string winner;
	Bidding *b1;
	Bidding *b2;
	vector<Bidding*> vBid;
	vector<Territory*> t1;
	vector<Territory*>t2;

	vector<Card*> c1;
	vector<Card*>c2;

	cout << "How kind of mode do you want to play ? \n1 -- Two Human PLAYERS\n2 -- one human player and  one computer player\n3 --two compters players" << endl;
	cin >> choice;
	while (true) {
		if (choice == 1) {

			system("cls");
			this->game_Show();
			cout << "Please insert first Player's name" << endl;
			cin >> name1;
			while (name1 == "") {
				cout << "Player's name can not be empty, please enter again" << endl;
				cin >> name1;
			}
			cout << "Please choose a color \n*****red*****\n*****yellow*****\n*****blue*****\n*****green*****" << endl;
			cin >> color1;
			while (true) {
				if ((color1 == "red") || (color1 == "yellow") || (color1 == "blue") || (color1 == "green"))
					break;
				else {
					cout << "This color does not exist, please insert the color color!" << endl;
					cin >> color1;
				}
			}

			b1 = new Bidding(name1, 0);
			Player *p1 = new Player(name1, 14, 0, t1, c1, b1, color1);

			p1->getBid()->SetBid();

			cout << "Please insert second Player's name" << endl;
			cin >> name2;
			while (name2 == "" || name2 == name1) {
				if (name2 == "") {
					cout << "Player's name can not be empty, please insert again" << endl;
					cin >> name2;
				}
				else {
					cout << "Player's name can not be the same as the first player, Please insert again." << endl;
					cin >> name2;
				}

			}

			cout << "Please choose a color \n*****red*****\n*****yellow*****\n*****blue*****\n*****green*****" << endl;
			cin >> color2;
			cout << endl;
			while (true) {
				if ((color1 != color2) && (color2 == "red" || color2 == "yellow" || color2 == "blue" || color2 == "green"))
					break;
				else if (color1 == color2) {
					cout << "Color can not be the same as the first player's color, Please choose again!" << endl;
					cin >> color2;
					cout << endl;
				}
				else {
					cout << "This color does not exist, please insert the color color!!" << endl;
					cin >> color2;
					cout << endl;
				}

			}
			b2 = new Bidding(name2, 0);
			Player *p2 = new Player(name2, 14, 0, t1, c1, b2, color2);
			p2->getBid()->SetBid();

			system("pauser");
			system("cls");
			this->game_Show();
			cout << "Players Information:\n\n**First Player**  " << *p1 << "  \n**Second Player**  " << *p2 << "  " << endl;

			this->players.push_back(p1);
			this->players.push_back(p2);

			cout << " ** " << p1->GetName() << " **  and  ** " << p2->GetName() << " ** \n*****welcome to the game , Hope you enjoy the Game!*****\n" << endl;

			vBid.push_back(b1);
			vBid.push_back(b2);
			int winnerIndex;
			winner = Bidding::CompareBid(vBid);



			for (int i = 0; i < players.size(); i++) {
				if (players[i]->GetName() == winner) {
					winnerIndex = i;
				}
			}
			this->assignCoin();
			for (int i = 0; i < players.size(); i++) {
				if (players[i]->GetName() == winner) {
					//winner pay coins
					players[i]->PayCoin(players[i]->getBid()->GetBid());
					//pool receive coins;
					this->pool += players[i]->getBid()->GetBid();

				}
			}


			// set original region for each players
			this->SetInitialRegion(winnerIndex);











			//Part 2 point 1 remove 3 and 4 cards
			cout << "\nWe have " << players.size() << " of players, so remove the \"4\" and \"3\" cards\n" << endl;

			//this->deckInitial();
			Deck* deck = new Deck(players.size());//creat the deck 

			deck->generateDeck();//generate the deck



			cout << "\n*************************Before the Shuffle********************************" << endl;
			cout << *deck;

			deck->shuffleDeck();//shuffle the Deck
			cout << "****************************After the Shuffle**************************************" << endl;
			cout << *deck;




			//loop for the game until the end
			Hand* hand = new Hand(deck);//drwa the 6 face-up card from the deck

			Score *s = new Score();

			//player get card for each term ,until both of them get 13 cards.
			while (players[winnerIndex]->GetHandCard().size() <= 3 && players[1 - winnerIndex]->GetHandCard().size() <= 3) {
				this->playGame(winnerIndex, hand, deck,this);
				system("pause");
				this->playGame(1 - winnerIndex, hand, deck,this);
			}

			s->computeScores(players[0], players[1], this->map);



			cout << "----------------------------------------  THE END--------------------------------------------------" << endl;

			system("pause");

			break;
		}
		else if (choice == 2) {


			system("cls");
			this->game_Show();
			cout << "Please insert Human Player's name" << endl;
			cin >> name1;
			while (name1 == "") {
				cout << "Player's name can not be empty, please enter again" << endl;
				cin >> name1;
			}
			cout << "Please choose a color \n*****red*****\n*****yellow*****\n*****blue*****\n*****green*****" << endl;
			cin >> color1;
			while (true) {
				if ((color1 == "red") || (color1 == "yellow") || (color1 == "blue") || (color1 == "green"))
					break;
				else {
					cout << "This color does not exist, please insert the color color!" << endl;
					cin >> color1;
				}
			}

			b1 = new Bidding(name1, 0);
			Player *p1 = new Player(name1, 10, 0, t1, c1, b1, color1);

			p1->getBid()->SetBid();


			int computerChoice;

			cout << "what's kind of computer you woud like to play with? \n1-- Greedy Computer \n2 --Moderate computer" << endl;
			cin >> computerChoice;
			Player *p2;
			while (true) {

				int ran = 0;
				if (computerChoice == 1) {
					ran = rand() % 15;

					b2 = new Bidding("Greedy Player", ran);

					p2 = new Player("Greedy Player", 14, 0, t1, c1, b2, color2);
					break;
				}

				else if (computerChoice == 2) {
					ran = rand() % 15;
					b2 = new Bidding("Moderate Player", ran);

					p2 = new Player("Moderate Player", 14, 0, t1, c1, b2, color2);
					break;
				}
				else {
					cout << "invalid input, please try again" << endl;
					cin >> computerChoice;
				}
			}


			system("pauser");
			system("cls");
			this->game_Show();
			cout << "Players Information:\n\n**First Player**  " << *p1 << "  \n**Second Player**  " << *p2 << "  " << endl;

			this->players.push_back(p1);
			this->players.push_back(p2);

			cout << " ** " << p1->GetName() << " **  and  ** " << p2->GetName() << " ** \n*****welcome to the game , Hope you enjoy the Game!*****\n" << endl;

			vBid.push_back(b1);
			vBid.push_back(b2);
			int winnerIndex;
			winner = Bidding::CompareBid(vBid);
			for (int i = 0; i < players.size(); i++) {
				if (players[i]->GetName() == winner) {
					winnerIndex = i;
				}
			}
			this->assignCoin();
			for (int i = 0; i < players.size(); i++) {
				if (players[i]->GetName() == winner) {
					//winner pay coins
					players[i]->PayCoin(players[i]->getBid()->GetBid());
					//pool receive coins;
					this->pool += players[i]->getBid()->GetBid();

				}
			}


			// set original region for each players
			this->SetInitialRegion(winnerIndex);



			//Part 2 point 1 remove 3 and 4 cards
			cout << "\nWe have " << players.size() << " of players, so remove the \"4\" and \"3\" cards\n" << endl;

			//this->deckInitial();
			Deck* deck = new Deck(players.size());//creat the deck 

			deck->generateDeck();//generate the deck



			cout << "\n*************************Before the Shuffle********************************" << endl;
			cout << *deck;

			deck->shuffleDeck();//shuffle the Deck
			cout << "****************************After the Shuffle**************************************" << endl;
			cout << *deck;




			//loop for the game until the end
			Hand* hand = new Hand(deck);//drwa the 6 face-up card from the deck

			Score *s = new Score();

			//player get card for each term ,until both of them get 13 cards.
			while (players[winnerIndex]->GetHandCard().size() < 10 && players[1 - winnerIndex]->GetHandCard().size() < 10) {
				this->playGame(winnerIndex, hand, deck,this);
				system("pause");
				this->playGame(1 - winnerIndex, hand, deck,this);
			}



			s->computeScores(players[0], players[1], this->map);



			cout << "----------------------------------------  THE END--------------------------------------------------" << endl;

			system("pause");

			break;

		}
		else if (choice == 3) {

			int ran = rand() % 15;
			cout << ran << endl;
			b1 = new Bidding("Greedy Player", ran);
			Player *	p1 = new Player("Greedy Player", 14, 0, t1, c1, b1, color2);


			int ran2 = rand() % 15;
			cout << ran << endl;
			b2 = new Bidding("Moderate Player", ran2);
			Player *	p2 = new Player("Moderate Player", 14, 0, t1, c1, b2, color2);

			system("pauser");
			system("cls");
			this->game_Show();
			cout << "Players Information:\n\n**First Player**  " << *p1 << "  \n**Second Player**  " << *p2 << "  " << endl;

			this->players.push_back(p1);
			this->players.push_back(p2);

			cout << " ** " << p1->GetName() << " **  and  ** " << p2->GetName() << " ** \n*****welcome to the game , Hope you enjoy the Game!*****\n" << endl;

			vBid.push_back(b1);

			vBid.push_back(b2);

			int winnerIndex;

			winner = Bidding::CompareBid(vBid);

			for (int i = 0; i < players.size(); i++) {

				if (players[i]->GetName() == winner) {
					winnerIndex = i;

				}
			}
			this->assignCoin();
			for (int i = 0; i < players.size(); i++) {
				if (players[i]->GetName() == winner) {
					//winner pay coins
					players[i]->PayCoin(players[i]->getBid()->GetBid());
					//pool receive coins;
					this->pool += players[i]->getBid()->GetBid();

				}
			}


			// set original region for each players
			this->SetInitialRegion(winnerIndex);


			//Part 2 point 1 remove 3 and 4 cards
			cout << "\nWe have " << players.size() << " of players, so remove the \"4\" and \"3\" cards\n" << endl;

			//this->deckInitial();
			Deck* deck = new Deck(players.size());//creat the deck 

			deck->generateDeck();//generate the deck



			cout << "\n*************************Before the Shuffle********************************" << endl;
			cout << *deck;

			deck->shuffleDeck();//shuffle the Deck
			cout << "****************************After the Shuffle**************************************" << endl;
			cout << *deck;


			//loop for the game until the end
			Hand* hand = new Hand(deck);//drwa the 6 face-up card from the deck

			Score *s = new Score();

			//player get card for each term ,until both of them get 13 cards.
			while (players[winnerIndex]->GetHandCard().size() < 10 && players[1 - winnerIndex]->GetHandCard().size() < 10) {
				this->playGame(winnerIndex, hand, deck,this);
				system("pause");
				this->playGame(1 - winnerIndex, hand, deck,this);
			}

			s->computeScores(players[0], players[1], this->map);



			cout << "----------------------------------------  THE END--------------------------------------------------" << endl;

			system("pause");

			break;


		}
		else {
			cout << "Invalid Number, please try again, \n1 -- 2	PLAYERS\n2 -- 3 PLAYERS\n3 -- four PLAYERS" << endl;
			cin >> choice;
		}

	}


	return this->players;

}



void GameInitializer::exitSystem() {
	cout << "~~~~~WELCOME BACK NEXT TIME *_* ~~~~~" << endl;
	system("pause");
	exit(0);
}

Map * GameInitializer::getCurrentMap() {
	try {
		return this->map;
	}
	catch (runtime_error) {
		cout << "File is not falid" << endl;
	}
}

vector<string> GameInitializer::getGameMapFiles() {
	vector<string> maps;
	for (const auto & entry : fs::directory_iterator(mapFileFolder)) {
		std::cout << entry.path() << std::endl;
		maps.push_back(entry.path().string());
	}
	return maps;
}

void GameInitializer::loadMap(string mapFileName) {
	this->mapLoader = new MapLoader(mapFileName);
	if (this->mapLoader->readMapFile()) {
		this->map = this->mapLoader->getMap();
	}
	else {
		cout << "MAP INVALID TO LOAD...EXIT PROGRAM NOW\n";
		system("pause");
	}
}



void GameInitializer::addPlayer(string playerName) {
	vector<Card*> cards;
	Bidding* bid = new Bidding();
	Player* player = new Player(playerName, cards, bid);

}

string GameInitializer::getMapFileFolder() {
	return this->mapFileFolder;
}




//Rectangule Shape read from mapFiles\\map5.json
void GameInitializer::printMapInRectangleShape(Map* m1) {

	cout << "Rectuangule shape map Read from mapFiles\\map5.json..." << endl;
	cout << "\n*********************  MAP IN RECTANGULE SHAPE  ***************\n\n";
	for (int i = 0; i < m1->GetContinentCount(); i++) {
		cout << " ~~~" << m1->continents[i]->GetName() << "~~~ " << "    ";

	}
	cout << "\n***************************************************************************************\n\n" << endl;
	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 1) cout << " [ *" << m1->continents[i]->territorys[3]->GetName() << "* ] " << "____";
		else if (i == 3) cout << " [ *" << m1->continents[i]->territorys[3]->GetName() << "* ] " << "    ";
		else cout << " [ *" << m1->continents[i]->territorys[0]->GetName() << "* ] " << "    ";

	}
	cout << endl;

	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 1) cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "    ";
		else if (i == 3) cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "    ";
		else cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";

	}
	cout << endl;

	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 1) cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
		else if (i == 3) cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
		else cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "    ";
	}
	cout << endl;
	cout << "\t|_____________" << " [ *" << m1->continents[1]->territorys[0]->GetName() << "* ] " << "           |_______________";
	cout << "[ *" << m1->continents[3]->territorys[0]->GetName() << "* ] " << "    " << endl;
	cout << "\n\n***************************************************************************************\n\n" << endl;

}
//Rectangule Shape read from mapFiles\\map1.json

void GameInitializer::printMapInRectangleShape2(Map* m1) {

	cout << "Rectuangule shape map Read from mapFiles\\map1.json..." << endl;
	cout << "\n*********************  MAP IN RECTANGULE SHAPE 2  ***************\n\n";
	for (int i = 0; i < m1->GetContinentCount(); i++) {
		cout << " ~~~" << m1->continents[i]->GetName() << "~~~ " << "    ";

	}
	cout << "\n***************************************************************************************\n\n" << endl;

	cout << " [ *" << m1->continents[0]->territorys[0]->GetName() << "* ] " << "\t\t\t\t\t\t" << "   [ *" << m1->continents[3]->territorys[3]->GetName() << "* ] " << endl;

	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 0) cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";

		else if (i == 1) cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "____";

		else if (i == 2) cout << " [ *" << m1->continents[i]->territorys[0]->GetName() << "* ] " << "    ";

		else cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "    ";

	}
	cout << endl;



	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 0)cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "    ";
		else if (i == 1) cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
		else if (i == 2) cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
		else cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
	}
	cout << endl;
	for (int i = 0; i < m1->GetContinentCount(); i++) {
		if (i == 0)cout << " [ *" << m1->continents[i]->territorys[3]->GetName() << "* ] " << "____";
		else if (i == 1) cout << " [ *" << m1->continents[i]->territorys[0]->GetName() << "* ] " << "    ";
		else if (i == 2) cout << " [ *" << m1->continents[i]->territorys[2]->GetName() << "* ] " << "___";
		else cout << " [ *" << m1->continents[i]->territorys[0]->GetName() << "* ] " << "    ";
	}

	cout << "\n\n***************************************************************************************\n\n" << endl;

}


//Rectangule Shape read from mapFiles\\map6.json
void GameInitializer::printMapInLShape(Map* m1) {
	cout << "L shape map Read from mapFiles\\map6.json..." << endl;
	cout << "\n*********************  MAP IN L SHAPE  ***************\n\n";

	cout << "\n***************************************************************************************\n\n" << endl;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m1->continents[i]->getTerritoryCount(); j++) {
			cout << " [ *" << m1->continents[i]->territorys[j]->GetName() << "* ] " << endl;
		}
		cout << "\t|" << endl;
		cout << "\t|" << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << " [ *" << m1->continents[2]->territorys[i]->GetName() << "* ] " << "    ";
		cout << " [ *" << m1->continents[3]->territorys[3 - i]->GetName() << "* ] " << "    \n";
	}
	cout << " [ *" << m1->continents[2]->territorys[3]->GetName() << "* ] " << "____";
	cout << " [ *" << m1->continents[3]->territorys[0]->GetName() << "* ] " << "    ";
	cout << "\n\n***************************************************************************************\n\n" << endl;

}

//Rectangule Shape read from mapFiles\\map6.json
void GameInitializer::printMapInLShape2(Map* m1) {
	cout << "L shape map Read from mapFiles\\map2.json..." << endl;
	cout << "\n*********************  MAP IN L SHAPE 2 ***************\n\n";

	cout << "\n***************************************************************************************\n\n" << endl;
	for (int i = 0; i < map->continents[0]->getTerritoryCount(); i++) {
		cout << " [ *" << m1->continents[0]->territorys[i]->GetName() << "* ] " << endl;
	}
	cout << "\t|" << endl;
	cout << "\t|" << endl;



	cout << " [ *" << m1->continents[1]->territorys[0]->GetName() << "* ] " << "    ";
	cout << " [ *" << m1->continents[2]->territorys[2]->GetName() << "*] " << "____";
	cout << " [ *" << m1->continents[3]->territorys[0]->GetName() << "* ] " << "    " << endl;

	for (int i = 1; i < map->continentCount; i++) {
		cout << " [ *" << m1->continents[i]->territorys[1]->GetName() << "* ] " << "    ";
	}
	cout << endl;

	cout << " [ *" << m1->continents[1]->territorys[2]->GetName() << "* ] " << "____";
	cout << " [ *" << m1->continents[2]->territorys[0]->GetName() << "* ] " << "    ";
	cout << " [ *" << m1->continents[3]->territorys[2]->GetName() << "* ] " << "    " << endl;


	cout << "\n\n***************************************************************************************\n\n" << endl;

}



void GameInitializer::assignCoin() {
	int coin = 0;
	if (players.size() == 4)
		coin = 9;
	if (players.size() == 3)
		coin = 11;
	if (players.size() == 2)
		coin = 14;

	for (int i = 0; i < players.size(); i++) {
		players[i]->SetCoin(coin);
	}
}




//loop 



void GameInitializer::playGame(int playerNumber, Hand* hand, Deck* deck,GameInitializer *gm) {
	hand->printHand();
	int index = 0;

	Strategy st(new Greedy());

	if (players[playerNumber]->GetName() == "Greedy Player") {

		index = st.pick(hand);

	}
	else if (players[playerNumber]->GetName() == "Moderate Player") {
		st.set_strategy(new Moderate());
		index = st.pick(hand);
	}
	else {
		st.set_strategy(new Human());
		index = st.pick(hand);
	}



	while (index >= 6 || index < 0) {
		cout << players[playerNumber]->GetName() << " your index input is invalid, please insert ** 0 - 5** " << endl;
		cin >> index;
	}


	if (players[playerNumber]->GetCoin() < hand->getCost(index)) {
		index = 0;
	}

		

	Card *card = hand->exchange(index);

	players[playerNumber]->SetHandCard(card);//select the card from the row

	players[playerNumber]->PayCoin(hand->getCost(index));//pay the coin of that card
	this->pool += hand->getCost(index);// put it at the top of the board

	Phase* p1 = new Phase(hand, players[playerNumber], index+1);//Phase object
	Viewer* v1 = new Viewer(p1);
	Controller* c1 = new Controller(p1, v1);
	c1->controll();//use controllor to play the game;
	
	State* s1 = new State(hand, players[playerNumber], this->getCurrentMap(), index + 1);//Phase object
	stateViewer* v2 = new stateViewer(s1);
	stateController* c2 = new stateController(s1, v2);
	c2->controll(this);

	////if(players[playerNumber]->GetHandCard()[0]->getAction1()=="Add2")
	//cout << "" << players[playerNumber]->GetHandCard()[0]->getAbility();
	//cout << "" << players[playerNumber]->GetHandCard()[0]->getAction1();
	//cout << "" << players[playerNumber]->GetHandCard()[0]->getAction2();
	//cout << "" << players[playerNumber]->GetHandCard()[0]->getGood();

	//cout << pool << endl;
	//cout << hand->getCost(index);


	//cout << "***************************************" << endl;



}




//bidPhase

//void GameInitializer::bidPhase() {
//  cout << " now starting the Bidding phase: " << endl;
//  vector<Bidding*> Biddings;
//  for (int i = 0; i < players.size(); i++) {
//   cout << players[i]->GetName() << ": your turn to bid." << endl;
//   players[i]->getBid()->SetBid();
//   Biddings.push_back(players[i]->getBid());
//  }//set the Bid
//  
//  Bidding::CompareBid(Biddings);//Bid the phase,record the winner
//   
//  
// }









void GameInitializer::actions(Player* p, string action) {
	int ter = 0;
	int startRegion;
	int moveStep;

	vector<Territory*> reachableTerri;
	vector<Territory*> reachableTerri1;
	vector<Territory*> reachableTerri2;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();//get all territorys


	if (action == "Move2") {

		if ((p->GetName() == "Greedy Player") || (p->GetName() == "Moderate Player")) {

			p->SetMove(2);
			int move = p->GetMove();
			while (move > 0) {

				vector<int> temp;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							temp.push_back(allTerritories[i]->GetID());
						}
						
					}
				}

				startRegion = temp[rand() % temp.size()];
				moveStep = rand() % (move+1);
			
				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}
				if (reachableTerri.size() == 0) {
					break;
				}
				int index = rand() % reachableTerri.size();
				

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}



		}
		else {

			p->SetMove(2);
			int move = p->GetMove();
			while (move > 0) {
				cout << "Your start region list :  " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							
						}
					}
				}
				cout << "where is your start region?" << endl;

				cin >> startRegion;

				cout << "How many step do you want to move?  your remaing move is : " << move << endl;

				cin >> moveStep;

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				int index;
				cout << "Where do you want to move? 0 - for the first territory from above territory list." << endl;
				cin >> index;

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}

		}



	}

	else if (action == "Move3") {



		if ((p->GetName() == "Greedy Player") || (p->GetName() == "Moderate Player")) {




			p->SetMove(3);

			int move = p->GetMove();
			while (move > 0) {

				vector<int> temp;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							temp.push_back(allTerritories[i]->GetID());
						}
					}
				}

				startRegion = temp[rand() % temp.size()];
				moveStep = rand() % (move + 1);

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}
				if (reachableTerri.size() == 0) {
					break;
				}
				int index = rand() % reachableTerri.size();


				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}



		}
		else {

			p->SetMove(3);
			int move = p->GetMove();
			while (move > 0) {
				cout << "Your start region list :  " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							
						}
					}
				}
				cout << "where is your start region?" << endl;

				cin >> startRegion;

				cout << "How many step do you want to move?  your remaing move is : " << move << endl;

				cin >> moveStep;

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				int index;
				cout << "Where do you want to move? 0 - for the first territory from above territory list." << endl;
				cin >> index;

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}

		}

	
	}

	else if (action == "Move4") {




		if ((p->GetName() == "Greedy Player") || (p->GetName() == "Moderate Player")) {


			p->SetMove(4);

			int move = p->GetMove();
			while (move > 0) {

				vector<int> temp;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							temp.push_back(allTerritories[i]->GetID());
						}
					}
				}

				startRegion = temp[rand() % temp.size()];
				moveStep = rand() % (move + 1);

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}
				if (reachableTerri.size() == 0){
					break;
				}
				int index = rand() % reachableTerri.size();



				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}



		}
		else {

			p->SetMove(4);
			int move = p->GetMove();
			while (move > 0) {
				cout << "Your start region list :  " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							
						}
					}
				}
				cout << "where is your start region?" << endl;

				cin >> startRegion;

				cout << "How many step do you want to move?  your remaing move is : " << move << endl;

				cin >> moveStep;

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				int index;
				cout << "Where do you want to move? 0 - for the first territory from above territory list." << endl;
				cin >> index;

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}

		}
		
	}

	else if (action == "Move5") {

		if ((p->GetName() == "Greedy Player") || (p->GetName() == "Moderate Player")) {




			p->SetMove(5);

			int move = p->GetMove();
			while (move > 0) {

				vector<int> temp;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							temp.push_back(allTerritories[i]->GetID());
						}
					}
				}

				startRegion = temp[rand() % temp.size()];
				moveStep = rand() % (move + 1);

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}


			

				if (reachableTerri.size() == 0) {
					break;
				}
				int index = rand() % reachableTerri.size();
				

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}



		}
		else {

			p->SetMove(5);
			int move = p->GetMove();
			while (move > 0) {
				cout << "Your start region list :  " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
						
						}
					}
				}
				cout << "where is your start region?" << endl;

				cin >> startRegion;

				cout << "How many step do you want to move?  your remaing move is : " << move << endl;

				cin >> moveStep;

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				int index;
				cout << "Where do you want to move? 0 - for the first territory from above territory list." << endl;
				cin >> index;

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}

		}
	}

	else if (action == "Move6") {

		if ((p->GetName() == "Greedy Player") || (p->GetName() == "Moderate Player")) {




			p->SetMove(6);

			int move = p->GetMove();
			while (move > 0) {

				vector<int> temp;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							temp.push_back(allTerritories[i]->GetID());
						}
					}
				}

				startRegion = temp[rand() % temp.size()];
				moveStep = rand() % (move + 1);

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				if (reachableTerri.size() == 0) {
					break;
				}
				int index = rand() % reachableTerri.size();


				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}



		}
		else {

			p->SetMove(6);
			int move = p->GetMove();
			while (move > 0) {
				cout << "Your start region list :  " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() == p->GetName()) {
						if (allTerritories[i]->GetArmyNum() != 0) {
							cout << allTerritories[i]->GetID() << endl;
							
						}
					}
				}
				cout << "where is your start region?" << endl;

				cin >> startRegion;

				cout << "How many step do you want to move?  your remaing move is : " << move << endl;

				cin >> moveStep;

				if (moveStep > move) {
					cout << "Invalide input " << endl;
					continue;
				}
				reachableTerri = this->ReachableTerritoryInner(IDtoTerri(startRegion), moveStep, p);
				for (int i = 0; i < reachableTerri.size(); i++) {
					cout << i << "------    " << *reachableTerri[i] << endl;
				}

				int index;
				cout << "Where do you want to move? 0 - for the first territory from above territory list." << endl;
				cin >> index;

				p->MoveArmies(IDtoTerri(startRegion), reachableTerri[index], 1);
				if (IDtoTerri(startRegion)->GetArmyNum() == 0 && IDtoTerri(startRegion)->GetBuildCity() == false) {
					IDtoTerri(startRegion)->SetPlayer("");
				}
				reachableTerri[index]->SetPlayer(p->GetName());

				cout << *IDtoTerri(startRegion) << endl << endl;
				cout << *reachableTerri[index] << endl << endl;
				move -= moveStep;

			}

		}
	}
	else if (action == "Add2") {
		p->PlaceNewArmies(p->GetTerritorys()[0], 2);
		
		cout <<" added 2 armies "<< endl;
	}

	else if (action == "Add3") {
		p->PlaceNewArmies(p->GetTerritorys()[0], 3);

		cout << " added 3 armies " << endl;
	}

	else if (action == "Add4") {

		p->PlaceNewArmies(p->GetTerritorys()[0], 4);

		cout << " added 4 armies " << endl;
	}

	else if (action == "BuildCity") {
		if (p->GetName() == "Greedy Player" || p->GetName() == "Moderate Player") {

			vector <int> temp;
			int temp2 = 0;
			for (int i = 0; i < allTerritories.size(); i++) {

				if (allTerritories[i]->GetPlayer() == p->GetName()) {
					temp.push_back(i);
					temp2 = rand() % temp.size();
					p->BuildCity(allTerritories[temp2]);//biuld the city if the name of territories is yours
					cout << "You get a token in your territory" << endl;
					allTerritories[i]->SetTokenName("token");
					allTerritories[i]->SetIsToken(true);

				}

			}

		}
		else {
			do {
				cout << "Where do you want to biuld city? insert 1-" << allTerritories.size() << endl;
				cin >> ter;
				if (ter > 0 && ter <= allTerritories.size()) {
					bool flage = false;
					for (int i = 0; i < allTerritories.size(); i++) {

						if (allTerritories[i]->GetID() == ter && allTerritories[i]->GetPlayer() == p->GetName()) {
							p->BuildCity(allTerritories[i]);//biuld the city if the name of territories is yours
							cout << "You get a token in your territory" << endl;
							allTerritories[i]->SetTokenName("token");
							allTerritories[i]->SetIsToken(true);
							flage = true;
							break;
						}

					}
					if (flage = false) {
						cout << " this is not your territorie, you can not build city here!" << endl;
						actions(p, "BuildCity");
					}
				}
				else
					cout << "you entered an invalidate number, please reenter!" << endl;
			} while (ter <= 0 || ter > allTerritories.size());
		}
	}
	else {
		string name = "";
		if (p->GetName() == "Greedy Player" || p->GetName() == "Moderate Player") {
			vector<int> temp;
			for (int i = 0; i < allTerritories.size(); i++) {
				if (allTerritories[i]->GetPlayer() != "") {
					temp.push_back(allTerritories[i]->GetID());
				}
			}
			ter = temp[rand() % temp.size()];


			for (int i = 0; i < allTerritories.size(); i++) {
				if (allTerritories[i]->GetID() == ter && allTerritories[i]->GetArmyNum() > 0) {
					name = allTerritories[i]->GetPlayer();
					for (int i = 0; i < players.size(); i++) {

						if (players[i]->GetName() == name) {
							if (players[i]->getIm() == false) {

								p->DestroyArmy(allTerritories[i], 1);
							}
							else {
								players[i]->setIm(false);

								cout << "The player is immute to be attacked once!" << endl;
							}
						}
					}


					//find the territories and destory 1 army

				}

			}

		}



		else {
			do {
				cout << "The army from where you want to destory? " << endl;
				cout << "you have " << endl;
				for (int i = 0; i < allTerritories.size(); i++) {
					if (allTerritories[i]->GetPlayer() != "") {
						cout << allTerritories[i]->GetID() << "         ";
					}
				}
				cout << "   territories can be destory! please insert id" << endl;
				cin >> ter;
				if (ter > 0 && ter <= allTerritories.size()) {
					bool flag = false;

					for (int i = 0; i < allTerritories.size(); i++) {
						if (allTerritories[i]->GetID() == ter && allTerritories[i]->GetArmyNum() > 0) {
							name = allTerritories[i]->GetPlayer();
							for (int i = 0; i < players.size(); i++) {

								if (players[i]->GetName() == name) {
									if (players[i]->getIm() == false) {

										p->DestroyArmy(allTerritories[i], 1);
									}
									else {
										players[i]->setIm(false);

										cout << "The player is immute to be attacked once!" << endl;
									}
								}
							}


							//find the territories and destory 1 army
							flag = true;
							break;
						}

					}

					if (flag = false) {
						cout << "There is no army on this territories." << endl;
						actions(p, "Destory");
					}

				}
				else
					cout << "you entered an invalidate number, please reenter!" << endl;
			} while (ter <= 0 || ter > allTerritories.size());
		}




























	}
}



//set initial Region
void GameInitializer::SetInitialRegion(int winnerIndex) {
	int regionNumber1;
	int regionNumber2;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();
	system("pause");
	system("cls");
	this->game_Show();
	cout << "Start Initial Region for Players...\n";

	// For first Player==> winner <======================================

	if (players[winnerIndex]->GetName() == "Greedy Player" || players[winnerIndex]->GetName() == "Moderate Player") {
		// For HUMAN
		cout << "\nSelecting the starting Region for " << players[winnerIndex]->GetName() << " ==> [chose from 1 to " << allTerritories.size() << " ]..." << endl;
		regionNumber1 = ((rand() % allTerritories.size()) + 1); // from 1 to maxsize

	}
	else {
		// For HUMAN
		cout << "\nSelect the starting Region for First Player(Winner) ==> [chose from 1 to " << allTerritories.size() << " ]\n\n"
			<< players[winnerIndex]->GetName() << "  Plaese choose your starting region: \n";
		cin >> regionNumber1;
		cout << endl;
		while (regionNumber1 <= 0 || regionNumber1 > allTerritories.size()) {
			cout << "Invalid Territory Input, Please insert number from 1 to " << allTerritories.size() << endl;
			cin >> regionNumber1;
		}

	}
	for (int i = 0; i < allTerritories.size(); i++) {
		// first one to select, do not need to check if territories occupied 
		if (allTerritories[i]->GetID() == regionNumber1) {
			allTerritories[i]->SetPlayer(players[winnerIndex]->GetName());
			allTerritories[i]->SetArmyNum(allTerritories[i]->GetArmyNum() + 4);
			players[winnerIndex]->setArmy(players[1 - winnerIndex]->getArmy() - 4);
			players[winnerIndex]->setTerritories(allTerritories[i]);
			break;
		}
	}

	// For second Player===================================

	if (players[1 - winnerIndex]->GetName() == "Greedy Player" || players[1 - winnerIndex]->GetName() == "Moderate Player") {
		// For HUMAN
		cout << "\nSelecting the starting Region for " << players[1 - winnerIndex]->GetName() << " ==> [chose from 1 to " << allTerritories.size() << " ]..." << endl;
		regionNumber2 = ((rand() % allTerritories.size()) + 1); // from 1 to max size
																// check if region has been occupied
		while (regionNumber2 == regionNumber1) {
			cout << "Region has been occupied!!! Please Seclect Another Region....\n";
			regionNumber2 = ((rand() % allTerritories.size()) + 1); //re-choosing
		}
	}
	else {
		// For second Player
		cout << "Select the starting Region for Second Player ==> [choose from 1 to " << allTerritories.size() << " ]\n\n"
			<< players[1 - winnerIndex]->GetName() << "  Please choose your starting region: \n";
		cin >> regionNumber2;
		cout << endl;
		while (regionNumber2 <= 0 || regionNumber2 > allTerritories.size()) {
			cout << "Invalid Territory Input, Please insert number from 1 to " << allTerritories.size() << endl;
			cin >> regionNumber2;
		}
		// check if region has been occupied
		while (regionNumber2 == regionNumber1) {
			cout << "Region has been occupied!!! Please Seclect Another Region....\n";
			cin >> regionNumber2;
		}
	}

	for (int j = 0; j < allTerritories.size(); j++) {
		if (allTerritories[j]->GetID() == regionNumber2) {
			allTerritories[j]->SetPlayer(players[1 - winnerIndex]->GetName());
			allTerritories[j]->SetArmyNum(allTerritories[j]->GetArmyNum() + 4);


			players[1 - winnerIndex]->setArmy(players[1 - winnerIndex]->getArmy() - 4);
			players[1 - winnerIndex]->setTerritories(allTerritories[j]);
			break;
		}
	}

	cout << "After selected starting region, Player " << players[winnerIndex]->GetName() << " remains Army : " << players[winnerIndex]->getArmy() << "\n";
	cout << "After selected starting region, Player " << players[1 - winnerIndex]->GetName() << " remains Army : " << players[1 - winnerIndex]->getArmy() << "\n\n";
	cout << "Player " << players[winnerIndex]->GetName() << " has initial rigion: " << *players[winnerIndex]->GetTerritorys()[0];
	cout << "Player " << players[1 - winnerIndex]->GetName() << " has initial rigion: " << *players[1 - winnerIndex]->GetTerritorys()[0] << endl;


	system("pause");
	system("cls");
	this->game_Show();

}




// doAction
void GameInitializer::doAction(Player* p, Card* c1) {
	string action1 = "";
	string action2 = "";
	int choice = 0;
	if (c1->getAndOr() == "") {
		action1 = c1->getAction1();
		actions(p, action1);
	}
	else if (c1->getAndOr() == "and") {
		action1 = c1->getAction1();
		action2 = c1->getAction2();
		actions(p, action1);
		actions(p, action2);
	}
	else {
		action1 = c1->getAction1();
		action2 = c1->getAction2();
		cout << " The actions are: action1: " << action1 << " action2: " << action2 << endl;
		do {
			if (p->GetName() == "Greedy Player" || p->GetName() == "Moderate Player") {

				choice = (rand() % 2) + 1; // 1 or 2
			}
			else {

				cout << "which action you wants to do? ( insert 1 or 2 ) " << endl;
				cin >> choice;
				if (choice == 1)
					actions(p, action1);
				else if (choice == 2)
					actions(p, action2);
				else
					cout << "you have entered a wrong number, please reenter!" << endl;
			}

		} while (choice != 1 && choice != 2);

	}


}





vector<Territory*> GameInitializer::transferNearTerri(Territory* currentTerri) {
	vector<Territory*> copyTerri;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();

	// if have near terri on same continent
	if (currentTerri->GetNearTerritorySameContinent().size() != 0) {
		//copy = currentTerri->GetNearTerritorySameContinent();
		for (int i = 0; i < currentTerri->GetNearTerritorySameContinent().size(); i++) {
			for (int t = 0; t < allTerritories.size(); t++) {
				// first one to select, do not need to check if territories occupied 
				if (allTerritories[t]->GetID() == currentTerri->GetNearTerritorySameContinent()[i]) {
					copyTerri.push_back(allTerritories[t]);
					break;
				}
			}
		}
		return copyTerri;
	}
	return copyTerri;

}


//remove duplicates resource
vector<Territory*> GameInitializer::removeDuplicates(vector<Territory*> vec)
{
	vector<Territory*> temp;

	for (int i = 0; i < vec.size(); i++) {
		if (temp.size() != 0) {
			bool equal = false;
			for (int j = 0; j < temp.size(); j++) {
				if (temp[j]->GetID() == vec[i]->GetID()) {
					equal = true;
					break;
				}
			}
			if (equal == false) {
				temp.push_back(vec[i]);
			}
		}
		else {
			temp.push_back(vec[0]);
		}

	}

	return temp;
}



vector<Territory*> GameInitializer::ReachableTerritoryInner(Territory* startTerri, int step, Player* p) {
	vector<Territory*> temp;
	vector<Territory*> temp1;
	vector<Territory*> reachableTerri;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();

	// step 2-6 check all terri on different inner continent
	// first step
	if (step == 1) {
		temp1 = transferNearTerri(startTerri);
		if (temp1.size() != 0) {
			reachableTerri = NotPlayerName(temp1, p);
		}
		return reachableTerri;
	}
	// if step>2
	else {
		temp1 = transferNearTerri(startTerri);
		if (temp1.size() != 0) {
			for (int j = step - 1; j > 0; j--) {
				vector<Territory*> temp2;
				// second step ==> find next reachable Territories for each territory in temp list
				if (temp1.size() != 0) {
					for (int k = 0; k < temp1.size(); k++) {
						vector<Territory*> copy;
						copy = transferNearTerri(temp1[k]);
						if (copy.size() != 0) {
							for (int t = 0; t < copy.size(); t++) {
								temp2.push_back(copy[t]);
							}
						}
					}
					// remove duplicates and previous territories(prevent backward)
					temp = removeDuplicates(temp2);//==============================================
					temp1 = temp;
				}
				else {
					return temp;
				}
			}
			// remove not your territory (player != current name)
			reachableTerri = NotPlayerName(temp, p);
		}
		else {
			cout << "No Territory connected to Current Territory on this Continent!!!" << endl;
			return temp1;
		}

		return reachableTerri;
	}

}


Territory* GameInitializer::IDtoTerri(int id) {
	Territory* T = new Territory();
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();
	for (int i = 0; i < allTerritories.size(); i++) {
		if (allTerritories[i]->GetID() == id) {
			T = allTerritories[i];
		}
	}
	return T;
}



vector<Territory*> GameInitializer::NotPlayerName(vector<Territory*> list, Player* p) {
	vector<Territory*> result;
	for (int i = 0; i < list.size(); i++) {
		if (list[i]->GetPlayer() == p->GetName()) {
			result.push_back(list[i]);
		}
		if (list[i]->GetPlayer() == "") {
			result.push_back(list[i]);
		}
		// if not current player name ==> do nothing
	}
	return result;
}

vector<Territory*> GameInitializer::transferNearTerriOverSea(Territory* currentTerri) {
	vector<Territory*> seaTerri;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();

	// if have connected terri oversea
	if (currentTerri->GetNearTerritory().size() != 0) {

		for (int i = 0; i < currentTerri->GetNearTerritory().size(); i++) {
			for (int t = 0; t < allTerritories.size(); t++) {
				if (allTerritories[t]->GetID() == currentTerri->GetNearTerritory()[i]) {
					seaTerri.push_back(allTerritories[t]);
					break;
				}
			}
		}

	}
	return seaTerri;

}

vector<Territory*>  GameInitializer::overseaTwice(Territory* outerStartTerri) {
	vector<Territory*> foreign;
	vector<Territory*> result;
	vector<Territory*> temp;
	// once oversea
	result = transferNearTerriOverSea(outerStartTerri);
	// twice oversea
	if (result.size() != 0) {
		for (int i = 0; i < result.size(); i++) {
			vector<Territory*> copy;
			copy = transferNearTerriOverSea(result[i]);
			if (copy.size() != 0) {
				for (int t = 0; t < copy.size(); t++) {
					temp.push_back(copy[t]);
				}
			}
		}
		// remove duplicates(allow backwards)
		foreign = removeDuplicates(temp);
	}
	return foreign;
}

// call this function only when step >=3
vector<Territory*> GameInitializer::merge(vector<Territory*> inner, vector<Territory*> outer) {
	vector<Territory*> merge;
	if (inner.size() == 0 && outer.size() == 0)
		return inner;
	else if (inner.size() == 0 && outer.size() != 0)
		return outer;
	else if (inner.size() != 0 && outer.size() == 0)
		return inner;
	else {
		for (int k = 0; k < outer.size(); k++) {
			inner.push_back(outer[k]);
		}
		merge = removeDuplicates(inner);
		return merge;
	}
}




void GameInitializer::doAbility(Player* p, Card* c1) {
	if (c1->getAbility() == "+1 Move")
		p->SetMove(p->GetMove() + 1);
	if (c1->getAbility() == "+1 Army")
		p->AddArmy(1);
	if (c1->getAbility() == "Flying")
		cout << " we can fly reduce the move from 3 to 2" << endl;
	if (c1->getAbility() == "Immune to attack") {
		cout << "we are unstoppable" << endl;
		p->setIm(true);
	}

}








// if step >= 3
vector<Territory*> GameInitializer::ReachableTerritoryouter(Territory* outerStartTerri, int step, Player* p) {
	int newStep = 0;
	vector<Territory*> continentTerri;
	vector<Territory*> reachableTerri;
	vector<Territory*> result1;
	vector<Territory*> result2;
	vector<Territory*> result3;
	vector<Territory*> result2Temp2;
	vector<Territory*> result;
	vector<Territory*> allTerritories;
	allTerritories = map->GetAllTerritorys();

	//check avalible continent terri first
	// if step =6, could oversea exactly twice/ on step left then

	continentTerri = transferNearTerriOverSea(outerStartTerri);
	newStep = step - 3;

	if (newStep == 0) {
		if (continentTerri.size() != 0) {
			result3 = NotPlayerName(continentTerri, p);
		}
	}
	else {
		//========================= 1 -- oversea first, then check other land ==============================
		if (continentTerri.size() != 0) {
			for (int t = 0; t < continentTerri.size(); t++) {
				vector<Territory*> copyTerri;
				copyTerri = ReachableTerritoryInner(continentTerri[t], newStep, p);
				if (copyTerri.size() != 0) {
					for (int j = 0; j < copyTerri.size(); j++) {
						reachableTerri.push_back(copyTerri[j]);
					}
				}
			}
			// remove duplicates(allow backwards)
			if (reachableTerri.size() != 0) {
				result1 = removeDuplicates(reachableTerri); // final all terri could access on other continent with oversea once
			}

		}
		//========================= 2 -- check inner reachable boundary each step, then over sea, then, check remaining step on other land ==============================

		int rem = newStep;
		while (newStep > 0) {
			int remainingStep = rem - newStep;
			vector<Territory*> overseaTerri;
			vector<Territory*> overseaTerriTemp1;
			vector<Territory*> overseaTerriTemp2;
			vector<Territory*> terri1;
			vector<Territory*> ttt;


			terri1 = ReachableTerritoryInner(outerStartTerri, newStep, p);
			if (terri1.size() != 0) {
				for (int p = 0; p < terri1.size(); p++) {
					vector<Territory*> terri2;
					terri2 = transferNearTerriOverSea(terri1[p]);//cost 3
					if (terri2.size() != 0) {
						for (int q = 0; q < terri2.size(); q++) {
							overseaTerri.push_back(terri2[q]);
						}
					}
				}
			}

			if (remainingStep > 0) {
				if (overseaTerri.size() != 0) {
					for (int i = 0; i < overseaTerri.size(); i++) {
						overseaTerriTemp1 = ReachableTerritoryInner(overseaTerri[i], remainingStep, p);
						if (overseaTerriTemp1.size() != 0) {
							for (int j = 0; j < overseaTerriTemp1.size(); j++) {
								overseaTerriTemp2.push_back(overseaTerriTemp1[j]);
							}
						}

					}
				}
				overseaTerri.clear();
			}

			ttt = merge(overseaTerri, overseaTerriTemp2);

			if (ttt.size() != 0) {
				for (int i = 0; i < ttt.size(); i++) {
					result2.push_back(ttt[i]);
				}
			}
			newStep = newStep - 1;
		}

		if (result2.size() != 0) {
			vector<Territory*> result2Temp;
			result2Temp = removeDuplicates(result2);
			result2Temp2 = NotPlayerName(result2Temp, p);
		}

		result3 = merge(result1, result2Temp2);

		if (step == 6) {
			vector<Territory*> special;
			vector<Territory*> specialTemp;
			vector<Territory*> specialResult;
			specialTemp = overseaTwice(outerStartTerri);
			special = NotPlayerName(specialTemp, p);
			specialResult = merge(result3, special);
			return specialResult;
		}
	}
	return result3;
}


