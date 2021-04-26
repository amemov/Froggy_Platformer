// Written by Anton Shepelev, University of South Florida Computer Science Student.  
// Establishes Level class
/* Provides information about level for save load files	
	- in the future, it will be used to draw levels		*/
#ifndef LEVEL_H
#define LEVEL_H
class Level {
	private:
		std::string level_name;
	    int level_count;
	public:
		Level();
		int get_count() { return level_count; };
		void update_name();
		void update_count();
		void level_one();
};
#endif