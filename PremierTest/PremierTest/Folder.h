#pragma once
#include <vector>
using namespace std;
class MessageTest;
class Folder
{
public:
	Folder(void);
	virtual ~Folder(void);
public:
	void addMsg( const MessageTest*thisMessageTest);
	void remMsg( const MessageTest*thisMessageTest);
};

