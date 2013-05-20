#ifndef KILLABLE_H
#define KILLABLE_H

class Killable{
public:
	Killable();

	bool getSlated();
	virtual void kill() = 0; //Use this function to perform any death animation and call slateForRemoval()

protected:
	void slateForRemoval();

private:
	bool slatedForRemoval;
};

#endif