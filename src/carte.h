#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "element.h"

class Tuile {
	char input;
	bool interdit = false;
	int value = 0; // 0 = already pass, 1 or 10 for value of the tuile that can be won
	std::vector<Element*> lst;

public:
	Tuile() { input = '\0'; }
	void setChar(char c) 
	{ 
		input = c; 
		// init value of the tuile to 1 if it's a pillule
		if( !isWall() )
			value = 1;	
	}
	char getChar() { return input; }
	
	bool isWall() { return input == '#'; }
	bool isFree() { return !isWall()&&!interdit; }
	void clearPass() {
		lst.clear();
		interdit = false;
	}
	void addEl(Element& e) {
		if (e.isPac())
			passer();
		lst.push_back(&e);
	}
	void delEl(Element& e) {
		//tester que le dernier �l�ment est bien ce qu�on supprime.
		std::vector<Element*>::iterator trouve = lst.end();
		for (std::vector<Element*>::iterator it = lst.begin();
			it != lst.end() && trouve == lst.end();
			++it) {
			if ((*it)->getId() == e.getId() && (*it)->isMine() == e.isMine()) {
				trouve = it;
			}
		}
		if (trouve != lst.end())
			lst.erase(trouve);
	}
	double getPoid(Element::Echifoumi chi) {
		double a = Singleton::get().getPoidVide();
		for (std::vector<Element*>::iterator it = lst.begin(); it != lst.end(); ++it) {
			a += (*it)->getPoid(chi);
		}
		if( value>0 )
			a += Singleton::get().getPoidBouffe() * value;
		else
			a += Singleton::get().getPoidVisite() * value;
		return a;
	}
	void passer() { if( value >0) value = 0; else --value;}
	void clearVisite() { value = 1; }
	bool isPasser() { return value<=0; }
	void deplacement() { interdit = true; passer(); }
	bool isPilluleOnIt() {

		for (std::vector<Element*>::iterator it = lst.begin(); it != lst.end(); ++it) {
			if (!(*it)->isPac())
				return true;
		}
		return false;
	}
};

class Carte {
	int width;
	int height;
	Tuile** cart;
	Point init;
public:
	Carte(int w, int h) :width(w), height(h) {
		cart = new Tuile * [w];
		for (int i = 0; i < w; ++i)
			cart[i] = new Tuile[h];
	}
	~Carte(){
		for (int i = 0; i < width; ++i)
			delete[] cart[i];
		delete []cart;

	}
	void reinitCarte() {
		for (int i = 0; i < width; ++i)
			delete[] cart[i];
		delete[]cart;
		cart = NULL;
	}
	Carte& operator=(const Carte& c) {
		reinitCarte();
		this->width = c.width;
		this->height=c.height;
		this->init = c.init;

		Tuile** cart;
		cart = new Tuile * [width];
		for (int i = 0; i < width; ++i) {
			cart[i] = new Tuile[height];
			for (int j = 0; j < height; ++j) {
				this->cart[i][j] = c.cart[i][j];
			}
		}
	}

	int getNbBouffeInitial() {
		int nb = 0;
		for (int i = 0; i < width; ++i) {
			for (int j = 0; j < height;++j) {
				if (cart[i][j].getChar() == ' ')
					++nb;
			}
		}
		return nb;
	}
	void addTuile(int i, int j, char in) {
		cart[i][j].setChar(in);
	}
	void addLine(int i, std::string line) {
		std::vector < Tuile> v;
		for (int j = 0; j < width; ++j) {
			cart[j][i].setChar(line[j]);
		}
	}
	bool isWall(Point p) {
		return cart[p.x][p.y].isWall();
	}

	bool deplacementPossible(Point p,Point from) {
		return p!=from && cart[p.x][p.y].isFree();
	}
	void position(Point p) {
		cart[p.x][p.y].passer();
	}
	void delPac(PacMan& e) {
		cart[e.getX()][e.getY()].delEl(e);
	}
	void addEl(Element& e) {
		cart[e.getX()][e.getY()].addEl(e);
		//only if add my pac
		if (e.isMine()&&e.isPac()&&!e.isDead()) {
			checkVisibility('N', Point(e.getX(), e.getY()), height);
			checkVisibility('S', Point(e.getX(), e.getY()), height);
			checkVisibility('E', Point(e.getX(), e.getY()), width);
			checkVisibility('W', Point(e.getX(), e.getY()), width);
		}
	}

	void checkVisibility(char direction,Point p, int prof) {
		if (cart[p.x][p.y].isWall() || prof == 0)
			return;
		if (!cart[p.x][p.y].isPilluleOnIt())
			cart[p.x][p.y].passer();
		prof--;
		checkVisibility(direction, p.get(direction), prof);
	}
	double getPoid(Point& p,Element::Echifoumi monType) {
		return cart[p.x][p.y].getPoid(monType);
	}
	void printCarte() {
		if (true) {
			
			for (int j = 0; j < height; ++j)
			{
				std::cerr << "	g.addCarteLine(" << j<<",\"";
				for (int i = 0; i < width; ++i)
				{
					std::cerr << cart[i][j].getChar();
				}
				std::cerr<< "\");"<<std::endl;
			}
			
			for (int j = 0; j < height; ++j)
			{
				for (int i = 0; i < width; ++i)
				{
					if (cart[i][j].isWall())
						std::cerr << "#";
					else
						std::cerr << cart[i][j].isPasser() ? "1":"0";
				}
				std::cerr << "" << std::endl;
			}
			
		}
	}
	void clear() {
		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				cart[i][j].clearPass();
			}
		}
	}
	void deplacement(Point p) {
		cart[p.x][p.y].deplacement();
	}
	void pass(Point& p) {
		cart[p.x][p.y].passer();
	}
	/**
	for debug TU add all pass to tuile
	*/
	void allPass() {
		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				cart[i][j].passer();
			}
		}

	}
	void notPass(int a, int b) {
		cart[a][b].clearVisite();
	}
	bool isPasser(Point p) {
		return cart[p.x][p.y].isPasser();
	}
	void clearPillule() {
		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j) {
					cart[i][j].passer();
			}
		}
	}	
};