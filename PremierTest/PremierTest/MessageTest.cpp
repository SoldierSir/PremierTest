#include "StdAfx.h"
#include "MessageTest.h"
#include "Folder.h"

MessageTest::MessageTest(void)
{
}

MessageTest& MessageTest::operator = (const MessageTest&rhs)
{
	if (&rhs!=this)
	{
		Remove_Msg_From_Folders();
		contents = rhs.GetContents();
		folders = rhs.GetFolders();
		put_Msg_in_Folders(rhs.GetFolders());
	}
	return *this;
}

MessageTest::~MessageTest(void)
{
	Remove_Msg_From_Folders();
}

void MessageTest::put_Msg_in_Folders( const std::set<Folder*>&rhs )
{
	for (std::set<Folder*>::const_iterator beg = rhs.begin();beg!=rhs.end();beg++)
	{
		(*beg)->addMsg(this);
	}	
}

void MessageTest::Remove_Msg_From_Folders()
{
	for (set<Folder*>::const_iterator beg = folders.begin();beg!=folders.end();beg++)
	{
		(*beg)->remMsg(this);
	}
}
