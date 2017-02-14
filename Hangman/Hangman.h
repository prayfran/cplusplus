/*
Parker Franks
04-16-2014
CS253
Hangman
*/
#ifndef Hangman_include
#define Hangman_include


#include <vector>
#include <string>
#include <string.h>
#include <gtkmm.h>

class Hangman : public Gtk::Window { 

public:

	Hangman();
	~Hangman();
	std::string get_word(std::vector<std::string> words);
	void read_library(std::string word, int length);
	std::vector<std::string> words;
	std::vector<int> places;
	void on_button_clicked();
	Gtk::Box m_box;
	Gtk::Button m_button;
	Gtk::Image *m_image;
	Gtk::Label m_label;
	Gtk::Entry m_entry;
	std::string underscores;
	std::string letters;
	int fuckups;
	int length;
	bool on_key_press_event(GdkEventKey *event);
	std::string finalword;
	int count;
	std::string tguesses;
	std::string fguesses;
};
#endif 
