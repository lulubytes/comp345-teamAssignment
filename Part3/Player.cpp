#include "Player.h";


using namespace std;

Player::Player()
{
	move = 0;
	coin = 0;
	army = 18;
	city = 3;
	name = "Player";
	bid = new bidding();
}

Player::Player(string name, int coin, int move, vector<Territory*> territory, vector<Cards*> handCard, bidding* bid)
{
	this->name = name;
	this->coin = coin;
	this->move = move;
	this->army = 18;
	this->city = 3;
	this->territory = territory;
	this->handCard = handCard;
	this->bid = bid;
}


Player::Player(const Player& other)
{
	this->name = other.name;
	this->coin = other.coin;
	this->move = other.move;
	this->army = other.army;
	this->city = other.city;
	for (int i = 0; i < other.handCard.size(); i++)
	{
		this->handCard[i] = new Cards(*other.handCard[i]);
	}
	for (int i = 0; i < other.territory.size(); i++) 
	{
		this->territory[i] = new Territory(*other.territory[i]);
	}
	this->bid = new bidding(*(other.bid));
}


Player& Player::operator=(const Player& other) 
{
	this->name = other.name;
	this->coin = other.coin;
	this->move = other.move;
	this->army = other.army;
	this->city = other.city;
	for (int i = 0; i < other.handCard.size(); i++) 
	{
		this->handCard[i] = new Cards(*other.handCard[i]);
	}
	for (int i = 0; i < other.territory.size(); i++) 
	{
		this->territory[i] = new Territory(*other.territory[i]);
	}
	this->bid = new bidding(*(other.bid));
	return *this;
}


Player::~Player()
{
	name = "";
	coin = 0;
	move = 0;
	army = 0;
	city = 0;

	for (int i = 0; i < handCard.size(); i++)
	{
		delete handCard.at(i);
		handCard[i] = nullptr;
	}

	for (int i = 0; i < territory.size(); i++) 
	{
		delete territory.at(i);
		territory[i] = nullptr;
	}

	territory.clear();
	handCard.clear();

	delete bid;
	bid = nullptr;
};


void Player::PayCoin(int coin) 
{
	this->coin = this->coin - coin;
}

void Player::BuildCity(Territory* territory) 
{
	territory->SetBuildCity();
	city = city - 1;
}

void Player::PlaceNewArmies(Territory* territory, int army) 
{
	if (this->territory.empty()) 
	{
		territory->SetPlayer(GetName());
		territory->AddArmy(army);
		AddArmy(4);
		territory->SetBuildCity();
		this->territory.push_back(territory);
	}
	else if (territory->GetBuildCity() == true) 
	{
		territory->AddArmy(army);
		AddArmy(4);
	}
	else 
	{
		cout << "You can not place new armies in the territory without a city." << endl;
	}
}


void Player::MoveArmies(Territory* pointA, Territory* pointB, int army)
{
	if (pointB->GetPlayer().empty()) 
	{
		pointA->AddArmy(-army);
		pointB->AddArmy(army);
		pointB->SetPlayer(GetName());
		territory.push_back(pointB);
		SetMove(-army);
	}
	else if (pointB->GetPlayer().compare(GetName()) == 0) 
	{
		pointA->AddArmy(-army);
		pointB->AddArmy(army);
		SetMove(-army);
	}
	else 
	{
		cout << "Your destination has been occupied by other players." << endl;
	}
}

void Player::MoveOverLand(Territory* pointA, Territory* pointB, int army) 
{

	if (pointA->GetContinentName().compare(pointB->GetContinentName()) != 0) 
	{
		if (GetMove() > 3) 
		{
			if (pointB->GetPlayer().empty()) 
			{
				pointA->AddArmy(-army);
				pointB->AddArmy(army);
				pointB->SetPlayer(GetName());
				territory.push_back(pointB);
				SetMove(-army - 3);
			}
			else if (pointB->GetPlayer().compare(GetName()) == 0) 
			{
				pointA->AddArmy(-army);
				pointB->AddArmy(army);
				SetMove(-army - 3);
			}
			else 
			{
				cout << "Your destination has been occupied by other players." << endl;
			}
		}
		else 
		{
			cout << "You need more than three movement to cross continent." << endl;
		}
	}
	else 
	{
		cout << "You destination is in the same continent." << endl;
	}
}

void Player::DestroyArmy(Territory* territory, int num) 
{
	territory->AddArmy(-num);
}


void Player::AddArmy(int army)
{
	this->army -= army;
}

void Player::SetMove(int move) 
{
	this->move += move;
}

void Player::SetCoin(int coin) 
{
	this->coin -= coin;
}

void Player::SetHandCard(Cards* other) 
{
	this->handCard.push_back(other);
}

string Player::GetName() 
{
	return name;
}

int Player::GetMove() 
{
	return move;
}

int Player::GetCoin() 
{
	return coin;
}

vector<Territory*> Player::GetTerritorys() 
{
	return territory;
}
vector<Cards*> Player::GetHandCard() 
{
	return handCard;
}


bool Player::CheckTerritory(Territory* other) 
{
	for (int i = 0; i < territory.size(); i++) 
	{
		if (territory[i]->GetPlayer().compare(other->GetPlayer()) == 0) {
			return false;
		}
	}
	return true;
}

void Player::DisplayTerritory()
{
	for (int i = 0; i < territory.size(); i++) 
	{
		cout << *territory[i];
	}
}

ostream& operator<< (ostream& output, const Player& other) 
{
	output << "Player name: " << other.name << " movement: " << other.move << " coin: " << other.coin << " army: " << other.army << " city: " << other.city << endl;
	if (other.handCard.size() != 0) 
	{
		output << "Player hand card : ";
		output << endl;
		for (int i = 0; i < other.handCard.size(); i++) 
		{
			output << i + 1;
			output << ": " << *(other.handCard[i]);
		}
	}
	if (other.territory.size() != 0) 
	{
		output << "Player Territory : ";
		output << endl;
		for (int i = 0; i < other.territory.size(); i++) 
		{
			output << i + 1;
			output << ": " << *(other.territory[i]);
		}
	}
	return output;
}