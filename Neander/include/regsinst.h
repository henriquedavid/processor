#ifndef REGSI_H
#define REGSI_H

class RegsI{
	
	public:
	
		RegsI(){
			regsi = new int[1];
			regsi[0] = 0;
		}				

		int readRI();

		void writeRI(int value);

	private:
		int *regsi;

};

#endif