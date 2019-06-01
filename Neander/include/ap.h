#ifndef AP_H
#define AP_H

class AP{

	public:
		
		AP(){
			end = 0;
			oldEnd = 0;
		}

		void increase();

		void setPosition(int _end);

		int getPosition();

		void zerar();

	private:
		int end;
		int oldEnd;
};

#endif