#ifndef AP_H
#define AP_H

class AP{

	public:
		
		AP(){
			end = 0;
		}

		void increase()
		{
			end += 2;
		}

		void setPosition(int _end)
		{
			end = _end;
		}

		int getPosition()
		{
			return end;
		}

		void zerar()
		{
			end = 0;
		}

	private:
		int end;
};

#endif