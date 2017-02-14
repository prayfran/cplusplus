/*
Parker Franks
04-16-2014
CS253
Hangman
*/
#include "Hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>


using namespace std;
// initalize the first window at the beginning of the game
Hangman::Hangman()
:  m_box(Gtk::ORIENTATION_VERTICAL),
   m_button("Quit"),
   m_label(" Word: \n Letters Guessed: ")
{
	 
	add(m_box);

	m_image =(Gtk::manage(new Gtk::Image("Hangman1.png")));
	
	set_border_width(100);
	m_button.signal_clicked().connect(sigc::mem_fun(*this, &Hangman::on_button_clicked));
	set_title("Hangman");

	
	m_box.pack_start(*m_image);
	m_box.pack_start(m_label);
	m_box.pack_end(m_button, Gtk:: PACK_SHRINK, 5);
	
	show_all_children();

	
}

Hangman::~Hangman(){}
//gets a random word from the library
string Hangman::get_word(vector<string> words1){
int number = rand() % words1.size();
return words1[number];
}
//reads the file library into a vector of strings
void Hangman::read_library(string word, int length1){
       if(word.size() <= (unsigned) length1){
	words.push_back(word);
       }
}
//looks for the quit button and exits if hit
void Hangman::on_button_clicked(){
exit(0);
}
//deals with all user entered letters and keeps track of the points in the game
//will reset the game when the user wins or loses
bool Hangman::on_key_press_event(GdkEventKey* event1)
{       bool fexists = false;
	bool texists = false;
	char c = static_cast<char>(event1->keyval);
	if(isalpha(c)){
	bool succ = false;
	c = tolower(c);

	for(unsigned int i = 0; i < finalword.length(); i++){
		if(!isalpha(finalword[i])){
		    underscores[i+6] = finalword[i];
		}else{
			if(c == tolower(finalword[i])){
			
			underscores[i+6] = c;
			succ = true;
			for(unsigned int f =0; f < tguesses.size(); f++){
				if(tguesses[f] == c){
				texists = true;
				}
			}

			if(texists == false){
				count++;
			}
		}
		}
	}
	if(succ == true){
	m_label.set_text(underscores);
	if(texists == false){
	tguesses.push_back(c);	
	}
	}
	

	if(succ == false){
	m_label.set_text(underscores);
	for(unsigned int i =0; i < fguesses.size(); i++){
	if(fguesses[i] == c){
	fexists = true;
	}
	}
	if(fexists == false){
	underscores.push_back(c);
	fguesses.push_back(c);
	fuckups = fuckups + 1;
	}
	}
	if(fuckups == 1){
	m_label.set_text(underscores);
	m_image->set("Hangman2.png");

	}
	else if(fuckups == 2){
	m_label.set_text(underscores);
	m_image->set("Hangman3.png");
	}
	else if(fuckups == 3){
	m_label.set_text(underscores);
	m_image->set("Hangman4.png");
	}
	else if(fuckups == 4){
	m_label.set_text(underscores);
	m_image->set("Hangman5.png");
	}
	else if(fuckups == 5){
	m_label.set_text(underscores);
	m_image->set("Hangman6.png");
	}
	
	else if (fuckups == 6){
	m_label.set_text(underscores);
	m_image->set("Hangman7.png");

	Gtk::Window fwin;
	Gtk::Image image("1-Artist.gif");
	fwin.set_border_width(100);
	fwin.add(image);
	fwin.set_title("You Lose, The word you wanted was: " + std::string(finalword));
	fwin.show_all_children();
	Gtk::Main::run(fwin);
	count =0;
	fuckups =0;
	underscores = "Word: ";
	letters = "\nLetters Guessed: ";
	string word1;
	read_library(word1, length);
	finalword = get_word(words);
	for(unsigned int i =0; (unsigned) i <= finalword.size()-1; i++)
	{
		underscores.push_back('*');
		
	}
	tguesses.clear();
	fguesses.clear();
	underscores = std:: string(underscores) + letters; 
	m_image->set("Hangman1.png");
	fexists = false;
	texists = false;
	}
	
	if((unsigned)count == finalword.size()){

	Gtk::Window fwin;
	Gtk::Image image("89f410d409b7933d37a10193a879c823.gif");
	fwin.set_border_width(100);
	fwin.add(image);
	fwin.set_title("You win, " + std::string(finalword));
	fwin.show_all_children();
	Gtk::Main::run(fwin);
	count =0;
	fuckups =0;
	underscores = "Word: ";
	letters = "\nLetters Guessed: ";
	string word1;
	read_library(word1, length);
	finalword = get_word(words);
	for(unsigned int i =0; (unsigned) i <= finalword.size()-1; i++)
	{
		underscores.push_back('*');
		
	}
	tguesses.clear();
	fguesses.clear();
	underscores = std:: string(underscores) + letters; 
	m_image->set("Hangman1.png");
	fexists = false;
	texists = false;
	}
	}
	m_label.set_text(underscores);
 	fexists = false;
	texists = false;
	return true;

}
//the original read in of the library and the max length of the word
int main (int argc, char* argv[])
{
	if(argc > 3 || argc < 3){
	cerr<< "To many or to few arguments"<<endl;
	return 1;
	}
	if(atoi(argv[2]) == 0){
	cerr << "Second agrument is not a integer" <<endl;
	return 1;	
	}	
	ifstream lib;
	string word;
	Gtk::Main kit(argc, argv);
	Hangman hang;
	hang.underscores = "Word: ";
	hang.letters = "\nLetters Guessed: ";
	try{	
		lib.open(argv[1]);
	}catch(ifstream::failure e){
		cerr << "Can't open give library\n"<<endl;
		return 1;
	}
		
  	if (lib.is_open())
 	{
     		while (lib.good())
     		{     
			getline(lib,word);
			
			for(unsigned int i =0; i < word.size(); i++)
			{
			  if(!isalpha(word[i]))
				{
				if(word[i] == ' '){
				cerr << "The File contains a space please go find it"<<endl;
				
				return 1;
			  }
			}
			}
			hang.length = atoi(argv[2]);
			hang.read_library(word, hang.length);
	
     		}	
  	}

	hang.finalword = hang.get_word(hang.words);
	

	for(unsigned int i =0; (unsigned) i <= hang.finalword.size()-1; i++)
	{
		hang.underscores.push_back('*');
		
	}
	hang.count = 0;
	hang.fuckups = 0;
	hang.underscores = std:: string(hang.underscores) + hang.letters; 
	hang.m_label.set_text(hang.underscores);
 	Gtk::Main::run(hang);
	
}







